#include "Camera.h"

Camera*Camera::instance = 0;

void Camera::setMax(int _width, int _height)
{
	maxX = _width - this->width;
	maxY = _height - this->height;
}

void Camera::loadStages()
{
	Stage _stage;
	fstream f;
	f.open("Quadtree//Stages.txt");
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> _stage.lvl;
		f >> _stage.id;
		f >> _stage.posX;
		f >> _stage.posY;
		f >> _stage.width;
		f >> _stage.height;
		listStage.push_back(_stage);
	}
}

vector<Stage> Camera::getListStage()
{
	return listStage;
}

Stage Camera::getCurStage()
{
	return _curStage;
}

void Camera::nextStage()
{
	if (_curStage.id == 0)
	{
		for each (Stage _stage in listStage)
			if (_curStage.lvl < _stage.lvl)
			{
				_curStage = _stage;
				setMoveZone(new Rect(_curStage.posX, _curStage.posY, _curStage.width, _curStage.height));
				return;
			}
	}
	else
	{
		for each (Stage _stage in listStage)
		{
			if (_stage.id > _curStage.id)
			{
				_curStage = _stage;
				setMoveZone(new Rect(_curStage.posX, _curStage.posY, _curStage.width, _curStage.height));
				break;
			}
		}
	}
}

void Camera::preStage()
{
	for each (Stage _stage in listStage)
	{
		if (_curStage.id - _stage.id == 1)
		{
			_curStage = _stage;
			setMoveZone(new Rect(_curStage.posX, _curStage.posY, _curStage.width, _curStage.height));
			break;
		}
	}
}

void Camera::setMoveZone(Rect* _rect)
{
	rectMoveZone = _rect;
}

Rect* Camera::getMoveZone()
{
	return rectMoveZone;
}

Camera * Camera::GetInstance()
{
	if (instance == 0)
	{
		instance = new Camera();
	}
	return instance;
}

void Camera::init(int x, int y, int w, int h)
{
	position.X = x;
	position.Y = y;
	width = w;
	height = h;
	dx = 0;
	dy = 0;
	_curStage.id = 0;
	_curStage.lvl = 0;
}

void Camera::initPlayer(BaseObject * p)
{
	player = p;
}

void Camera::OnCollision(BaseObject* obj, int nx, int ny)
{
	Collision::preventMove(this, obj, nx, ny);
}

RECT Camera::toRect()
{
	RECT r;
	r.top = position.Y;
	r.bottom = position.Y + height;
	r.left = position.X;
	r.right = position.X + width;
	return r;
}

void Camera::updatePosition( )
{
	position.X += dx;
	if (position.X < rectMoveZone->X)
		position.X = rectMoveZone->X;
	if (position.X >  rectMoveZone->X + rectMoveZone->Width - width)
		position.X = rectMoveZone->X + rectMoveZone->Width - width;
	if (position.Y < rectMoveZone->Y)
		position.Y = rectMoveZone->Y;
	if (position.Y > rectMoveZone->Y + rectMoveZone->Height - height)
		position.Y = rectMoveZone->Y + rectMoveZone->Height - height;
	if (position.X > maxX)
		position.X = maxX;
	canUp = false;
}

void Camera::run()
{
	int x, y;
	y = position.Y + height / 1;
	x = position.X + width / 2;
	dx = 0;
	if (player->position.X + player->dx > x)
	{
		if (dx == 0)
			dx = 1;
		if (player->dx > 0)
			dx = player->dx;
	}
	if (player->position.X + player->dx < x)
	{
		if (dx == 0)
			dx = -1;
		if (player->dx < 0)
			dx = player->dx;
	}

	if (player->position.X + player->dx < 0)
	{
		player->position.X =0;
		player->dx = 0;
	}
	if (player->right() + player->dx > (maxX + this->width))
	{
		player->position.X = (maxX + this->width) - player->width;
		player->dx = 0;
	}
	updatePosition();
}
vector<BaseObject*>* Camera::GetListObj()
{
	return &ListObj;
}
vector<BaseObject*>* Camera::GetListGround()
{
	return &ListGround;
}
vector<BaseObject*>* Camera::GetListStair()
{
	return &ListStair;
}
//vector<BaseObject*>* Camera::GetListEnemy()
//{
//	return &ListEnemy;
//}
void Camera::AddObjectToListCol()
{
	ListGround.clear();

	bool allowAdd;
	for each(BaseObject* o in ListObj)
	{
		switch (o->_collType)
		{
			case CollGround:
			allowAdd = true;
			for each(BaseObject* o2 in ListGround)
			{
				if (o == o2)
				{
					allowAdd = false;
					break;
				}
			}
			if (allowAdd)
				ListGround.push_back(o);
			break;
			case CollStair:
				allowAdd = true;
				for each(BaseObject* o2 in ListStair)
				{
					if (o == o2)
					{
						allowAdd = false;
						break;
					}
				}
				if (allowAdd)
					ListStair.push_back(o);
			//case CollEnemy:
			//	allowAdd = true;
			//	for each(BaseObject* o2 in ListEnemy)
			//	{
			//		if (o == o2)
			//		{
			//			allowAdd = false;
			//			break;
			//		}
			//	}
			//	if (allowAdd)
			//		ListEnemy.push_back(o);
		}
	}
}
void Camera::ImportObject(vector<BaseObject*> listObj)
{
	bool allowAdd;
	for each(BaseObject* o1 in listObj)
	{
		allowAdd = true;
		for each(BaseObject* o2 in ListObj)
		{
			if (o1 == o2)
			{
				allowAdd = false;
				break;
			}
		}
		if (allowAdd)
		{
			if (!Collision::checkAABB(Camera::GetInstance(), o1->oldObj) && !Collision::checkAABB(Camera::GetInstance(), o1))
			{
				o1->setObjectFromID();
				o1->position.X = o1->oldX;
				o1->position.Y = o1->oldY;
			}
			ListObj.push_back(o1);
		}
	}
}

Camera::~Camera()
{
}
