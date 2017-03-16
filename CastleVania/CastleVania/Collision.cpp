#include "Collision.h"



Collision::Collision()
{
}

float Collision::sweptAABB(BaseObject * b1, BaseObject * b2, int & normalx, int & normaly)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	if (b1->dx > 0.0f)
	{
		xInvEntry = b2->position.X - (b1->position.X + b1->width);
		xInvExit = (b2->position.X + b2->width) - b1->position.X;
	}
	else
	{
		xInvEntry = (b2->position.X + b2->width) - b1->position.X;
		xInvExit = b2->position.X - (b1->position.X + b1->width);
	}

	if (b1->dy > 0.0f)
	{
		yInvEntry = b2->position.Y - (b1->position.Y + b1->height);
		yInvExit = (b2->position.Y + b2->height) - b1->position.Y;
	}
	else
	{
		yInvEntry = (b2->position.Y + b2->height) - b1->position.Y;
		yInvExit = b2->position.Y - (b1->position.Y + b1->height);
	}

	float xEntry, yEntry;
	float xExit, yExit;

	if (b1->dx == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / b1->dx;
		xExit = xInvExit / b1->dx;
	}

	if (b1->dy == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / b1->dy;
		yExit = yInvExit / b1->dy;
	}

	float entryTime = MAX(xEntry, yEntry);
	float exitTime = MIN(xExit, yExit);

	if (entryTime > exitTime || xEntry < 0.0f && yEntry < 0.0f || xEntry > 1.0f || yEntry > 1.0f)
	{
		normalx = 0.0f;
		normaly = 0.0f;
		return 1.0f;
	}
	else
	{
		if (xEntry > yEntry)
		{
			if (b1->dx <= 0.0f)
			{
				normalx = 1.0f;
				normaly = 0.0f;
			}
			else
			{
				normalx = -1.0f;
				normaly = 0.0f;
			}

		}
		else
		{
			if (b1->dy <= 0.0f)
			{
				normalx = 0.0f;
				normaly = 1.0f;
			}
			else
			{
				normalx = 0.0f;
				normaly = -1.0f;
			}

		}
		return entryTime;
	}
}
void Collision::CheckCollision(BaseObject* b1, BaseObject* b2)
{

	if (!b1->alive || !b2->alive)
		return;
	if (b1 == b2)
		return;

	if (checkAABB(b1, b2))
	{
		b1->OnInterSerct(b2);
		b2->OnInterSerct(b1);
	}
	if (b1->isDead || b2->isDead)
		return;
	BaseObject* broadphase = getSweptBroadPhaseBox(b1);
	if (checkAABB(broadphase, b2))
	{
		int normalx, normaly;
		int collisionTime = sweptAABB(b1, b2, normalx, normaly);

		if (normalx != 0)
			b1->normalX = normalx;
		if (normaly != 0)
		{
			b1->normalY = normaly;
		}
		if (b1->_collType == CollItem || b2->_collType == CollItem)
		{
			b1->OnCollision(b2, normalx, normaly);
			b2->OnCollision(b1, normalx, normaly);
			return;
		}
		if (b2->_collType == CollBrick && b1->_collType == CollWhip)
		{
			b2->OnCollision(b1, normalx, normaly);
			return;
		}
		if (b2->_collType == CollSimon && (b1->_collType == CollDoor || b1->_collType == CollEnemy))
		{
			b1->OnCollision(b2, normalx, normaly);
			b2->OnCollision(b1, normalx, normaly);
			return;
		}
		if (b1->_collType != CollEnemy && b2->_collType == CollSubWeapon)
		{
			b1->OnCollision(b2, normalx, normaly);
			b2->OnCollision(b1, normalx, normaly);
			return;
		}
		if (b1->_collType == CollEnemy && (b2->_collType == CollSubWeapon || b2->_collType == CollWhip))
		{
			b1->OnCollision(b2, normalx, normaly);
			b2->OnCollision(b1, normalx, normaly);
			return;
		}
		if (collisionTime < 1)
		{
			b1->OnCollision(b2, normalx, normaly);
			b2->OnCollision(b1, normalx, normaly);
			return;
		}
	}
	delete broadphase;
}
void Collision::preventMove(BaseObject* b1, BaseObject* b2, int nx, int ny)
{
	if (b2->id == 0)
		b1->c = true;
	else
		b1->c = false;

	if (b1->top()<b2->bottom() && b1->bottom()>b2->top())
	{
		if (b2->left() - b1->right() < b1->dx && b1->dx > 0)
		{
			b1->dx = b2->left() - b1->right();
			if (nx != 0)
			{
				b1->vx = 0;
				b1->ax = 0;
			}

		}
		if (b2->right() - b1->left() > b1->dx && b1->dx < 0)
		{
			b1->dx = b2->right() - b1->left();
			if (nx != 0)
			{
				b1->vx = 0;
				b1->ax = 0;
			}
		}

		/*if (abs(b1->dx) > abs(b1->dx*collisionTime))
		b1->dx *= -normalX*collisionTime;*/
	}
	else
		b1->normalX = 0;
	//va cham tren duoi
	if (b1->left()<b2->right() && b1->right()>b2->left())
	{
		if (b2->top() - b1->bottom() < b1->dy && b1->dy > 0)
		{
			b1->dy = b2->top() - b1->bottom();
			b1->vy = 0;

		}
		if (b2->bottom() - b1->top() > b1->dy && b1->dy < 0)
		{
			b1->dy = b2->bottom() - b1->top() + 1;
			b1->vy = 0;
		}

		b1->c = false;
		/*if (abs(b1->dy)> abs(b1->dy*collisionTime))
		b1->dy *= -normalY*collisionTime;*/
	}
	else
		b1->normalY = 0;
}
BaseObject* Collision::getSweptBroadPhaseBox(BaseObject* B)
{
	int x, y, w, h;
	x = B->dx > 0 ? B->position.X : B->position.X + B->dx;
	y = B->dy > 0 ? B->position.Y : B->position.Y + B->dy;
	w = B->dx > 0 ? B->width + B->dx : B->width - B->dx;
	h = B->dy > 0 ? B->height + B->dy : B->height - B->dy;
	BaseObject* broadphasebox = BaseObject::createObject(x, y, w, h);
	return broadphasebox;
}
bool Collision::checkAABB(BaseObject * b1, BaseObject * b2)
{
	return !(b1->top() > b2->bottom() || b2->top() > b1->bottom() || b1->left() > b2->right() || b1->right()  < b2->left());
}

Collision::~Collision()
{
}
