#include "SubWeapon.h"


SubWeapon*SubWeapon::instance = 0;

bool SubWeapon::isOnStopWatch()
{
	if (Type == WeaponStopWatch && CrossTimeRemain <= 0)
		onStopWatchActive = false;
	return onStopWatchActive;
}
SubWeapon::SubWeapon() : MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteSubWeapon];
	_collType = CollSubWeapon;
	Type = WeaponNone;
	iHearCost = 1;
	iDamage = 2;
	alive = false;
	isHitTheGround = false;
}

SubWeapon * SubWeapon::GetInstance()
{
	if (instance == 0)
	{
		instance = new SubWeapon();
	}
	return instance;
}

void SubWeapon::Run(bool Active, int SimonX, int SimonY, Direction direction)
{
	if (!Active)
	{
		alive = false;
		return;
	}

	if (!alive) //Khi mới bắt đầu ném
	{
		staticPositionY = SimonY + 10;
		staticDirection = direction;
		alive = true;
		isHitTheGround = false;
		_direction = direction;
		setPosition(SimonX, SimonY);
		setVelocity();
	}

	if (Type == WeaponCross)
	{
		if (CrossTimeRemain > 0)
			CrossTimeRemain -= 1;
		else
		{
			_direction = (staticDirection == RIGHT) ? LEFT : RIGHT;
			if (_direction == RIGHT)
				vx = 0.1;
			else
				vx = -0.1;
		}
	}
	if (Type == WeaponStopWatch && CrossTimeRemain <= 0)
	{
		onStopWatchActive = true;
		CrossTimeRemain = TIME_CROSS;
	}
	changeSprite();
	MovableObject::Run();
	MovableObject::UpdatePosition();
	if (Type == WeaponKnife || Type == WeaponCross || Type == WeaponStopWatch)
	{
		position.Y = staticPositionY;
	}
	if (Type == WeaponHolyWater)
	{
		if (isHitTheGround)
		{
			vx = 0;
			position.Y = staticPositionY - 5;
		}
		else
			staticPositionY = position.Y;
	}
}

void SubWeapon::setType(SubWeaponType _type)
{
	Type = _type;
	switch (Type)
	{
	case WeaponNone:
		iDamage = 0;
		break;
	case WeaponKnife:
		iDamage = 1;
		iHearCost = 1;
		break;
	case WeaponAxe:
		iDamage = 1;
		iHearCost = 1;
		break;
	case WeaponHolyWater:
		iDamage = 1;
		iHearCost = 1;
		break;
	case WeaponStopWatch:
		iDamage = 0;
		iHearCost = 5;
		break;
	case WeaponCross:
		iDamage = 1;
		iHearCost = 1;
		break;
	default:
		break;
	}
}

void SubWeapon::setPosition(int SimonX, int SimonY)
{
	if (_direction == RIGHT)
	{
		position.X = SimonX + 28;
		position.Y = SimonY + 10;
	}
	else
	{
		position.X = SimonX - 16;
		position.Y = SimonY + 10;
	}
}

void SubWeapon::setVelocity()
{
	switch (Type)
	{
	case WeaponKnife:
		if (_direction == RIGHT)
			vx = 0.1;
		else
			vx = -0.1;
		break;
	case WeaponCross:
		CrossTimeRemain = TIME_CROSS;
		if (_direction == RIGHT)
			vx = 0.1;
		else
			vx = -0.1;
		break;
	case WeaponAxe:
		vy = AXE_VERTICAL_VELOCITY;
		if (_direction == RIGHT)
			vx = 0.1;
		else
			vx = -0.1;
		break;
	case WeaponHolyWater:
		vy = HOLYWATER_VERTICAL_VELOCITY;
		if (_direction == RIGHT)
			vx = 0.1;
		else
			vx = -0.1;
		break;
	case WeaponStopWatch:;
		break;
	default:	//No Weapon
		alive = false;
		return;
		break;
	}
}

void SubWeapon::setShotNumber(int number)
{
	if (number > 2 || number < 0)
		return;
	if (number == 2)
	{
		tripleShot = true;
		doubleShot = false;
	}
	if (number == 1)
	{
		doubleShot = true;
		tripleShot = false;
	}
	if (number == 0)
		doubleShot = tripleShot = false;
}

void SubWeapon::changeSprite()
{
	switch (Type)
	{
	case WeaponKnife:
		_spriteType = Knife;
		break;
	case WeaponAxe:
		_spriteType = Axe;
		break;
	case WeaponHolyWater:
		if (!isHitTheGround)
			_spriteType = HolyWater1;
		else
			_spriteType = HolyWater2;
		break;
	case WeaponStopWatch:
		_spriteType = StopWatch;
		break;
	case WeaponCross:
		_spriteType = Cross;
		break;
	default:
		break;
	}
	setAction(_spriteType);
}

void SubWeapon::OnCollision(BaseObject * obj, int nx, int ny)
{
	if (Type == WeaponHolyWater && obj->_collType == CollGround && normalY == -1 && normalX == 0)
	{
		isHitTheGround = true;
	}
}
