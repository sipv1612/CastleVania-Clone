#include "Whip.h"

Whip*Whip::instance = 0;

Whip::Whip() :MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteWhip];
	_collType = CollWhip;
	position.X = 0;
	position.Y = 0;
	oldX = 0;
	oldY = 0;
	vx = 0;
	vy = 0;
	width = 9;
	height = 24;
	ay = 0;
	_direction = RIGHT;
	_curState = 0;
	iDamage = 1;
	_curWhipAction = state1;
	_curType = Chain_Whip;
	delayIndexChange = new GameTime(1 / TIME_INDEX_CHANGE);
}

Whip * Whip::GetInstance()
{
	if (instance == 0)
	{
		instance = new Whip();
	}
	return instance;
}

void Whip::setType(WhipType _type)
{
	_curType = _type;
	switch (_curType)
	{
	case Vampire_Killer:
		iDamage = 1;
		break;
	case Chain_Whip:
		iDamage = 2;
		break;
	case Morning_Star:
		iDamage = 2;
		break;
	default:
		break;
	}
}

void Whip::Run(bool Active, int SimonX, int SimonY, int curFrame, Direction direction)
{
	if (!Active)
	{
		alive = false;
		return;
	}
	vy = Gametime * GRAVITY;
	alive = true;
	_direction = direction;
	setPosition(SimonX, SimonY, curFrame);
	changeType();
	MovableObject::Run();
}

void Whip::setPosition(int SimonX, int SimonY, int Frame)
{
	if(_direction == RIGHT)
	{
		if (Frame == 0)
		{
			if (_curType == Vampire_Killer)
			{
				_curWhipAction = state1;
				_curFrame = 0;
			}
			if (_curType == Chain_Whip)
			{
				_curWhipAction = state1;
				_curFrame = 1;
			}
			if (_curType == Morning_Star)
			{
				_curWhipAction = state1;
				_curFrame = 2;
			}
			width = 9;
			height = 24;
			position.X = SimonX - 15;
			position.Y = SimonY + 7;
		}
		if (Frame == 1)
		{
			if (_curType == Vampire_Killer)
			{
				_curWhipAction = state2;
				_curFrame = 0;
			}
			if (_curType == Chain_Whip)
			{
				_curWhipAction = state2;
				_curFrame = 1;
			}
			if (_curType == Morning_Star)
			{
				_curWhipAction = state2;
				_curFrame = 2;
			}
			width = 16;
			height = 18;
			position.X = SimonX - 15;
			position.Y = SimonY + 3;
		}
		if (Frame == 2)
		{
			if (_curType == Vampire_Killer)
			{
				_curWhipAction = state3_1;
				_curFrame = 0;
				width = 25;
				height = 7;
				position.X = SimonX + 22;
				position.Y = SimonY + 7;
			}
			if (_curType == Chain_Whip)
			{
				_curWhipAction = state3_2;
				_curFrame = 0;
				width = 36;
				height = 6;
				position.X = SimonX + 17;
				position.Y = SimonY + 9;
			}
			if (_curType == Morning_Star)
			{
				_curWhipAction = state3_3;
				_curFrame = 0;
				width = 44;
				height = 6;
				position.X = SimonX + 17;
				position.Y = SimonY + 9;
			}
		}
	}
	else
	{
		if (Frame == 0)
		{
			if (_curType == Vampire_Killer)
			{
				_curWhipAction = state1;
				_curFrame = 0;
			}
			if (_curType == Chain_Whip)
			{
				_curWhipAction = state1;
				_curFrame = 1;
			}
			if (_curType == Morning_Star)
			{
				_curWhipAction = state1;
				_curFrame = 2;
			}
			width = 9;
			height = 24;
			position.X = SimonX + 20;
			position.Y = SimonY + 7;
		}
		if (Frame == 1)
		{
			if (_curType == Vampire_Killer)
			{
				_curWhipAction = state2;
				_curFrame = 0;
			}
			if (_curType == Chain_Whip)
			{
				_curWhipAction = state2;
				_curFrame = 1;
			}
			if (_curType == Morning_Star)
			{
				_curWhipAction = state2;
				_curFrame = 2;
			}
			width = 16;
			height = 18;
			position.X = SimonX + 15;
			position.Y = SimonY + 3;
		}
		if (Frame == 2)
		{
			if (_curType == Vampire_Killer)
			{
				_curWhipAction = state3_1;
				_curFrame = 0;
				width = 25;
				height = 7;
				position.X = SimonX - 32;
				position.Y = SimonY + 7;
			}
			if (_curType == Chain_Whip)
			{
				_curWhipAction = state3_2;
				_curFrame = 0;
				width = 36;
				height = 6;
				position.X = SimonX - 37;
				position.Y = SimonY + 9;
			}
			if (_curType == Morning_Star)
			{
				_curWhipAction = state3_3;
				_curFrame = 0;
				width = 44;
				height = 6;
				position.X = SimonX - 45;
				position.Y = SimonY + 9;
			}
		}
	}
}
