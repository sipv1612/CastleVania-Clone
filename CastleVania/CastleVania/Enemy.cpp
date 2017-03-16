#include "Enemy.h"



Enemy::Enemy() :MovableObject()
{
	_collType = CollEnemy;
	ay = 0.001;
	_direction = RIGHT;
	isAttack = false;
	_status = EnemyNormal;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
	alive = true;
}


Enemy::~Enemy()
{
}

void Enemy::Run()
{
	if (createPosition.X == 0 && createPosition.Y == 0)
		createPosition = position;
	if (!alive)
		return;
	if (iTimeDenyDamage > 0)	//Update thời gian từ chối sát thương
		iTimeDenyDamage--;
	if (iTimeDenyDamage != 0)	//Khi mà enemy đang bị sát thương, không cho nó di chuyển, không cho nó thay đổi khung hình
		return;
	beingAttacked();
	if (_status == EnemyOutOfHealth)
	{
		if (_curFrame == 2)
			if (_timeDelay->canCreatNewFrame())
				if(_listAction->get(_curAction)->NextFrame(_curFrame) == 0)
					alive = false;
		UpdateAnimation();		//Update Animation nhưng không Update Position
		ChangeAction();						//Thay đổi sprite
		return;
	}
	runAI();
	//MovableObject::Run()
	if(!isDisableGravity)
		vy += Gametime*GRAVITY;
	dx = (int)(vx*Gametime);
	dy = (int)(vy*Gametime);
	if (dy == 0 && !isDisableGravity)
		dy = 1;
	normalX = 0;
	normalY = 0;
	UpdateAnimation();
	UpdatePosition();
	if (_status == EnemyOutOfHealth)
	{
		position.X = oldX;
		position.Y = oldY;
	}
	c = false;
	//MoveableObject::UpdatePosition()

	//
	ChangeAction();						//Thay đổi sprite
}

void Enemy::runAI()
{
}

void Enemy::OnCollision(BaseObject * obj, int nx, int ny)	//Khi có va chạm, hàm này tự động được gọi
{
	if (iHealth <= 0)
	{
		//set location of Sprite Died
		if (_direction == RIGHT)
		{
			oldX = position.X + width / 2;
			oldY = position.Y + height / 2;
		}
		else
		{
			oldX = position.X - width / 2;
			oldY = position.Y + height / 2;
		}
		if (_status != EnemyOutOfHealth)
			SimonCharacter::GetInstance()->iScore += iPoints;
		_status = EnemyOutOfHealth;
		_curEnemyAction = 0;
	}
}

void Enemy::beingAttacked()
{
	if(Whip::GetInstance()->alive)
		if (position.X + width > Whip::GetInstance()->position.X && position.X < Whip::GetInstance()->position.X + Whip::GetInstance()->width)
			if (Whip::GetInstance()->position.Y < position.Y + height && Whip::GetInstance()->position.Y + Whip::GetInstance()->height > position.Y)
				if(iTimeDenyDamage <= 0)
				{
					iTimeDenyDamage = TIME_DENY_DAMAGE;
					iHealth -= Whip::GetInstance()->getDamage();
					PlaySound(get_hit);
				}
	if(SubWeapon::GetInstance()->alive)
		if(SubWeapon::GetInstance()->position.X < position.X + width && SubWeapon::GetInstance()->position.X + SubWeapon::GetInstance()->width > position.X)
			if(SubWeapon::GetInstance()->position.Y < position.Y + height && SubWeapon::GetInstance()->position.Y + SubWeapon::GetInstance()->height > position.Y)
				if (iTimeDenyDamage <= 0)
				{
					iTimeDenyDamage = TIME_DENY_DAMAGE;
					iHealth -= SubWeapon::GetInstance()->getDamage();
					PlaySound(get_hit);
				}
}

void Enemy::ChangeAction()
{
	setAction(_curEnemyAction);
}

//void Enemy::ChangeDirection()
//{
//}

void Enemy::Draw()
{
	if(alive)
		MovableObject::Draw();
}

void Enemy::reLoad()
{
	position = createPosition;
	if (id == 4)
		alive = false;
	else
		alive = true;
	oldX = position.X;
	oldY = position.Y;
	iHealth = defaultHealth;
	_status = EnemyNormal;
}

bool Enemy::isDied()
{
	if (_status == EnemyOutOfHealth)
		return true;
	return false;
}
