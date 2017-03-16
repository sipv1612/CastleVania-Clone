#include "SimonCharacter.h"

SimonCharacter::SimonCharacter() :MovableObject()
{
	_listAction = SpriteManager::GetInstance()->listAnimation[SpriteSimon];
	_collType = CollSimon;
	position.X = Camera::GetInstance()->position.X + 32;
	position.Y = Camera::GetInstance()->position.Y;
	oldX = position.X;
	oldY = position.Y;
	width = 17;
	height = 30;
	ay = 0.001;
	_direction = RIGHT;
	iHealth = 16;
	iLife = 3;
	iScore = 0;

	_whipType = Vampire_Killer;
	_weaponType = WeaponStopWatch;
	_curDoor = 0;

	flag.isStand = true;
	flag.isJump = false;
	flag.isFall = true;
	flag.isSit = false;
	flag.isSitBefore = false;
	flag.isStandBefore = false;
	flag.isWhip = false;
	flag.isThrow = false;
	flag.isThrowDone = true;
	flag.isFinishClimb = true;
	flag.inIntro = true;

	iPreFrame = 0;
	iTimeStandIntro = 0;
	iTimeBlink = 0;

	flag.isBlink = true;
	_curSimonAction = SimonStand;
	SubWeapon::GetInstance()->setShotNumber(0);

}

bool SimonCharacter::isIntro()
{
	return flag.inIntro;
}

void SimonCharacter::setSimonAction(SimonSprite action)
{
	if (_curAction != action)
	{
		_curSimonAction = action;
		//_curAction =action;
		_curFrame = 0;
	}
}

SimonCharacter*SimonCharacter::instance = 0;

SimonCharacter*SimonCharacter::GetInstance()
{
	if (instance == 0)
	{
		instance = new SimonCharacter();
	}
	return instance;
}

bool SimonCharacter::RunIntro()
{
	if (!flag.inIntro)
		return false;
	//init
	if (iTimeStandIntro == 0 && flag.inIntro)
	{
		iTimeStandIntro = TIME_STAND_INTRO;
		position.X = 220;
		position.Y = 177;
		bat1 = new IntroBat(45, 145, 0);
		bat2 = new IntroBat(250, 20, 1);
		helicopter = new IntroHelicopter(250, 60);
	}

	bat1->runAI();
	bat2->runAI();
	helicopter->runAI();
	//walking in intro scene
	if (position.X >= 120)
	{
		flag._kLeft = true;
		flag._kRight = false;
		ChangeDirection();
		Move();
		ChangeAction();
		MovableObject::Run();
		return true;
	}

	//finish walking
	_curSimonAction = SimonBack;
	ChangeAction();
	vx = 0;
	MovableObject::Run();
	iTimeStandIntro--;
	if (iTimeStandIntro <= 0)	//renew Simon
	{
		flag.inIntro = false;
		position.X = Camera::GetInstance()->position.X + 32;
		position.Y = Camera::GetInstance()->position.Y;
		oldX = Camera::GetInstance()->position.X + 64;
		oldY = Camera::GetInstance()->position.Y;
		PlaySound(start_sound);
		return false;
	}
}

void SimonCharacter::Run()
{
	if (!Menu::GetInstance()->isFinish())
		return;
	Whip::GetInstance()->alive = false;
	if (flag.isFinishLevel)
	{
		finishLevel();
		return;
	}
	if (flag.isUpgradingWhip)
	{
		upgradingWhip();
		return;
	}
	SpriteManager::GetInstance()->isDoubleShot = doubleShot;
	SpriteManager::GetInstance()->isTripleShot = tripleShot;
	SpriteManager::GetInstance()->isWeaponMax = (_whipType == Morning_Star) ? true : false;
	if (_curDoor != 0)
	{
		EnterDoor();
		Move();
		MovableObject::Run();
		return;
	}
	else	//Reset button state
	{
		flag._kMove = false;
		flag._kLeft = false;
		flag._kRight = false;
	}
	UpdateKey();
	if (!flag.isDead)	//Simon chưa hết máu
	{
		if(flag.beingAttacked && !flag.moveWhileBeingAttacked && (_curDoor == 0))
		{
			_curSimonAction = SimonBeingAttacked;
			BeingAttacked();
		}
		else
		{
			if (!flag.isWhip && flag.isDone)
			{
				// đang leo cầu thang
				if (flag.isClimb && !flag.isJump)
				{
					Climb();
					iPreFrame = _curFrame;
				}

				// đang không leo cầu thang
				else
				{
					if (_curSimonAction == SimonClimbingUp || _curSimonAction == SimonClimbingDown)
						_curSimonAction = SimonStand;
					Move();
					Jump();
					Sit();
					if (!flag._kLeft && !flag._kRight && !flag._kJump)
					{
						flag.isJump = false;
						flag.isStand = true;

					}
					if (flag.isSit)
					{
						flag.isJump = false;
						flag.isStand = false;
						flag.isFall = false;
						flag._kMove = false;
					}
				}
				ChangeDirection();
			}
			else
			{
				Attack();
			}
			Throw();
		}


		ChangeAction();
		Whip::GetInstance()->setType(_whipType);
		SubWeapon::GetInstance()->setType(_weaponType);
		Blink();
	}
	else
	{
		Dead();
		iPreFrame = _curFrame;
		if (_curFrame != 2)
		{
			iTimeDead = TIME_DEAD;
			MovableObject::Run();
		}
		else //Simon reNew
		{
			iTimeDead--;
			if (iTimeDead <= 0)
			{
				if (iLife == 0)
				{
					LoopSound(game_over);
					StopSound(lv2_bg);
					return;
				}
				iLife--;
				iHealth = 16;
				flag.isDead = false;
				_weaponType = WeaponNone;
				_whipType = Vampire_Killer;
				_curAction = SimonStand;
				doubleShot = false;
				tripleShot = false;
				position.X = oldX;
				position.Y = oldY;
				if (oldY > Camera::GetInstance()->position.Y + Camera::GetInstance()->height)
					Camera::GetInstance()->preStage();
				Camera::GetInstance()->position.X = position.X - Camera::GetInstance()->width / 2;
				SubWeapon::GetInstance()->setShotNumber(0);
				PlaySound(start_sound);
				StopSound(boss);
			}
		}
		return;
	} //Simon Die
	if (_curSimonAction != SimonClimbDown && _curSimonAction != SimonClimbUp && _curSimonAction != SimonClimbDownWhip && _curSimonAction != SimonClimbUpWhip && _curSimonAction != SimonClimbingDown && _curSimonAction != SimonClimbingUp)
		MovableObject::Run();
	else
		UpdateAnimation();
	if (position.Y > Camera::GetInstance()->position.Y + Camera::GetInstance()->height)
	{
		flag.isDead = true;
		iHealth = 0;
	}
	flag.isCollStair = false;
}

void SimonCharacter::Draw()
{
	if(flag.isBlink)
		MovableObject::Draw();
}

void SimonCharacter::UpdateKey()
{
	Keyboard::getInstance()->UpdateKeyboard();
	if (flag.isWhip && !Keyboard::getInstance()->IsKeyDown(DIK_X) && flag.isDone)
	{
		flag.isWhip = false;
		return;
	}
	if (flag.isWhip && !Keyboard::getInstance()->IsKeyDown(DIK_Z) && flag.isDone)
	{
		flag.isWhip = false;
		return;
	}

	flag._kLeft = Keyboard::getInstance()->IsKeyDown(DIK_LEFT);
	flag._kRight = Keyboard::getInstance()->IsKeyDown(DIK_RIGHT);
	flag._kUp = Keyboard::getInstance()->IsKeyDown(DIK_UP);
	flag._kDown = Keyboard::getInstance()->IsKeyDown(DIK_DOWN);
	flag._kJump = Keyboard::getInstance()->IsKeyDown(DIK_SPACE);
	flag._kWhip = Keyboard::getInstance()->IsKeyDown(DIK_Z);
	flag._kThrow = Keyboard::getInstance()->IsKeyDown(DIK_X);
	flag._kMove = flag._kLeft != flag._kRight;
	if (flag._kMove)
	{
		flag._kUp = false;
		flag._kDown = false;
	}

	if (!flag.isWhip && (flag._kWhip || (flag._kThrow && iTimeWeapon == 0)))
		flag.isWhip = true;
	if (flag._kThrow && iTimeWeapon == 0 && _weaponType != WeaponNone && SubWeapon::GetInstance()->getHeartCost() <= iHeart)
	{
		iHeart -= SubWeapon::GetInstance()->getHeartCost();
		flag._kWhip = false;
		flag.isThrow = true;
		flag.isWhip = true;
	}
	if (_weaponType == WeaponNone)
		flag._kThrow = false;
	if (checkStair() != nullptr && (flag._kDown || flag._kUp))
	{
		if (!flag.isClimb)	// Mới bắt đầu leo lên cầu thang
		{
			if (_direction == RIGHT)
				position.X = checkStair()->position.X - 8;
			else
			{
				position.X = checkStair()->position.X + 8;
			}
		}
		flag.isClimb = true;
	}
	if (checkStair() == nullptr && !flag.isChangeStage)
	{
		flag._kUp = false;
		flag.isClimb = false;
	}
}

#pragma region Simon Action
void SimonCharacter::ChangeDirection()
{
	if (flag._kLeft)
		_direction = Direction::LEFT;
	else
		if (flag._kRight)
			_direction = Direction::RIGHT;
}

void SimonCharacter::Move()
{
	if (_curSimonAction == SimonJump)
		return;
	if (flag._kLeft != flag._kRight)
	{
		if (flag._kLeft)
			vx = -0.05;
		else
			vx = 0.05;
		if (flag.isJump)
		{
			_curSimonAction = SimonJump;
			flag.isFall = true;
		}
		else
		{
			//if (isSitBefore || isStandBefore)
			//{
			//	width = 16;
			//	height = 31;
			//	position.Y -= 1;
			//	isSitBefore = false;
			//	isStandBefore = false;
			//}
			_curSimonAction = SimonWalk;
			flag.isFall = false;
		}
		flag.isStand = false;
	}
	else
		vx = 0;

}

void SimonCharacter::Jump()
{
	if (normalY == -1 && !flag.isJump && flag._kJump)//vecto phap tuyen huong len
	{
		_curSimonAction = SimonJump;
		vy = VY_JUMP;
		flag.isJump = true;
		flag.isStand = false;
	}
}

void SimonCharacter::Sit()
{
	if (flag._kDown && !flag.isFall)
	{
		vx = 0;
		_curSimonAction = SimonSit;
		flag.isJump = false;
		flag.isStand = false;
		flag.isSit = true;
		flag.isSitBefore = true;
	}
	else
		flag.isSit = false;

}

void SimonCharacter::Attack()
{
	//
	if (_curFrame == 0 && iPreFrame == 2)
	{
		iPreFrame = 0;
		flag.isDone = true;
	}
	else
	{
		if (flag._kWhip)
			flag.isDone = false;
		iPreFrame = _curFrame;
	}

	//
	if (!flag.isDone)
	{
		Whip();
		if (flag.isWhip && !flag._kThrow)
			Whip::GetInstance()->Run(true, position.X, position.Y, _curFrame, _direction);

	}
	else
	{
		if (_curSimonAction == SimonStandWhip)
			_curSimonAction = SimonStand;
		if (_curSimonAction == SimonSitWhip)
			_curSimonAction = SimonSit;
		if (_curSimonAction == SimonClimbDownWhip)
			_curSimonAction = SimonClimbDown;
		if (_curSimonAction == SimonClimbUpWhip)
			_curSimonAction = SimonClimbUp;
		Whip::GetInstance()->Run(false, position.X, position.Y, _curFrame, _direction);
		flag.isWhip = false;
	}
	if (Whip::GetInstance()->alive && _curFrame == 0)
		PlaySound(attack);
}

void SimonCharacter::Whip()
{
	if (_curSimonAction == SimonStand)
	{
		vx = 0;
		vy = 0;
		_curSimonAction = SimonStandWhip;
		flag._kDown = false;
		return;
	}
	if ((flag._kDown || flag.isJump))
	{
		_curSimonAction = SimonSitWhip;
		return;
	}
	if (flag.isClimb)
	{
		if (_curSimonAction == SimonClimbDown)
			_curSimonAction = SimonClimbDownWhip;
		if (_curSimonAction == SimonClimbUp)
			_curSimonAction = SimonClimbUpWhip;
	}
}

void SimonCharacter::Throw()
{
	if (flag.isThrow)
	{
		if (flag._kThrow && iTimeWeapon == 0 && flag.isThrowDone)
		{
			flag.isDone = false;
			flag.isThrowDone = false;
			switch (_weaponType)
			{
			case WeaponNone:
				flag.isDone = true;
				flag.isThrowDone = true;
				break;
			case WeaponKnife:
				iTimeWeapon = TIME_KNIFE_ACTIVE;
				break;
			case WeaponAxe:
				iTimeWeapon = TIME_AXE_ACTIVE;
				break;
			case WeaponHolyWater:
				iTimeWeapon = TIME_HOLYWATER_ACTIVE;
				break;
			case WeaponStopWatch:
				break;
			case WeaponCross:
				iTimeWeapon = TIME_CROSS_ACTIVE;
				break;
			default:
				break;
			}
		}
		if (iTimeWeapon > 0)
			iTimeWeapon -= 1;
		else
		{
			flag.isThrow = false;
			flag.isDone = true;
			flag.isThrowDone = true;
		}
		if (!flag.isDone)
			Attack();
		SubWeapon::GetInstance()->Run(iTimeWeapon > 0 && !flag.isThrowDone, position.X, position.Y, _direction);
		if (SubWeapon::GetInstance()->alive && _curFrame == 1)
		{
			switch (SubWeapon::GetInstance()->getType())
			{
			case WeaponAxe:
				PlaySound(axe);
				break;
			case WeaponCross:
				PlaySound(cross);
				break;
			case WeaponHolyWater:
				PlaySound(holy_water);
				break;
			case WeaponKnife:
				PlaySound(knife);
				break;
			case WeaponStopWatch:
				PlaySound(clock_sound);
			default:
				break;
			}
		}
	}
}

void SimonCharacter::Climb()
{
	flag.isChangeStage = false;
	flag.isFinishClimb = false;
	if (flag.isClimb && (flag._kDown == flag._kUp))	//đứng trên cầu thang
	{
		if (_direction == RIGHT)
			_curSimonAction = SimonClimbUp;
		else
			_curSimonAction = SimonClimbDown;
		return;
	}
	if (flag.isClimb && flag._kUp)	//leo lên cầu thang
	{
		_direction = RIGHT;
		_curSimonAction = SimonClimbingUp;
		if (_curFrame != iPreFrame)
		{
			if (SimonCharacter::GetInstance()->position.Y + SimonCharacter::GetInstance()->height - 8 <= Camera::GetInstance()->getCurStage().posY)	//qua stage mới
			{
				position.Y -= 40;
				position.X += 8;
				Camera::GetInstance()->nextStage();
				flag.isChangeStage = true;
			}
			else
			{
				position.X += 8;
				position.Y -= 8;
			}
		}
		return;
	}
	if (flag.isClimb && flag._kDown)	//leo xuống cầu thang
	{
		_direction = LEFT;
		_curSimonAction = SimonClimbingDown;
		if (_curFrame != iPreFrame)
		{
			position.X -= 8;
			position.Y += 8;
		}
	}
	if (checkStair() == nullptr)
		flag.isFinishClimb = true;
	if (flag.isFinishClimb)
	{
		flag.isClimb = false;
		if (_direction == RIGHT)
			position.Y += 7;
		else
			position.Y -= 9;
	}
}

void SimonCharacter::Dead()
{
	vx = 0;
	_curSimonAction = SimonDie;
	ChangeAction();

}

void SimonCharacter::EnterDoor()
{
	if (_curDoor == 0)
		return;
	_curSimonAction = SimonWalk;
	if (position.X > _curDoor->position.X + _curDoor->width || position.X + width < _curDoor->position.X) //Ra khỏi cửa
	{
		_curDoor->setEnable(false);
		setCurDoor(0);
		vx = 0;
		oldX = position.X;
		oldY = position.Y;
		return;
	}
	PlaySound(open_door);
	if (_direction == RIGHT)
	{
		vx = 0.05;
		flag._kRight = true;
	}
	else
	{
		vx = -0.05;
		flag._kLeft = true;
	}
	flag._kMove = true;

}

//TO DO: add event handle
void SimonCharacter::collectItem(ItemObject * item)
{
	switch (item->_curAction)
	{
	case ItemSmallHeart:
		PlaySound(collect_heart);
		iHeart += 1;
		break;
	case ItemBigHeart:
		PlaySound(collect_heart);
		iHeart += 10;
		break;
	case ItemCross:
		PlaySound(collect_weapon);
		_weaponType = WeaponCross;
		break;
	case ItemAxe:
		PlaySound(collect_weapon);
		_weaponType = WeaponAxe;
		break;
	case ItemKnife:
		PlaySound(collect_weapon);
		_weaponType = WeaponKnife;
		break;
	case ItemWhip:
		PlaySound(collect_weapon);
		flag.isUpgradingWhip = true;
		if (_whipType != Morning_Star)
		{
			if (_whipType == Vampire_Killer)
				_whipType = Chain_Whip;
			else
				_whipType = Morning_Star;
		}
		break;
	case ItemRoast:
		PlaySound(collect_item);
		iHealth += 6;
		break;
	case ItemHolyWater:
		PlaySound(collect_weapon);
		_weaponType = WeaponHolyWater;
		break;
	case ItemStopWatch:
		PlaySound(collect_weapon);
		_weaponType = WeaponStopWatch;
		break;
	case ItemDoubleShot:
		PlaySound(collect_weapon);
		doubleShot = true;
		tripleShot = false;
		SubWeapon::GetInstance()->setShotNumber(1);
		break;
	case ItemTripleShot:
		PlaySound(collect_weapon);
		tripleShot = true;
		doubleShot = false;
		SubWeapon::GetInstance()->setShotNumber(2);
		break;
	case ItemRosary:
		PlaySound(collect_item);
		//TO DO: add event handle
		break;
	case ItemLife:
		PlaySound(collect_item);
		iLife++;
		break;
	case ItemMoney1:
		PlaySound(collect_item);
		iScore += 400;
		break;
	case ItemMoney2:
		PlaySound(collect_item);
		iScore += 700;
		break;
	case ItemMoney3:
		PlaySound(collect_item);
		iScore += 1000;
		break;
	case ItemMoney4: case ItemMoney5:
		PlaySound(collect_item);
		iScore += 2000;
		break;
	case ItemPotion:
		PlaySound(collect_item);
		//TO DO: add event handle
		break;
	case ItemSpiritBall:
		PlaySound(collect_item);
		StopSound(boss);
		flag.isFinishLevel = true;
		break;
	default:
		break;
	}
}

void SimonCharacter::finishLevel()
{
	if (iHeart > 0)
	{
		iScore += 10;
		iHeart -= 1;
		iHealth += 1;
	}
	LoopSound(end_game);
	vx = 0;
	MovableObject::Run();
	_curSimonAction = SimonStand;
	ChangeAction();
}

void SimonCharacter::upgradingWhip()
{
	vx = 0;
	MovableObject::Run();
	flag._kMove = false;
	if (iTimeUpgradingWhip <= 0)
	{
		iTimeUpgradingWhip = TIME_UPGRADINGWHIP;
	}
	iTimeUpgradingWhip--;
	if (iTimeUpgradingWhip <= 0)
	{
		flag.isUpgradingWhip = false;
		return;
	}
	_curSimonAction = SimonUpgradeWhip;
	ChangeAction();
	if (iTimeUpgradingWhip % 2 == 0)
	{
		if (_curFrame == 0)
			_curFrame = 1;
		else
			_curFrame = 0;
	}
}
#pragma endregion

BaseObject* SimonCharacter::checkStair()
{
	for each (BaseObject* obj in *Camera::GetInstance()->GetListStair())
	{
		if (_direction == RIGHT)
			if (position.Y + height > obj->position.Y && position.Y + height <= obj->position.Y + obj->height)	//Oy
				if (position.X + width > obj->position.X && position.X <= obj->position.X + obj->width)			//Ox
					return obj;
		if (_direction == LEFT)
			if (position.Y + height >= obj->position.Y && position.Y + height <= obj->position.Y + obj->height)	//Oy
				if (position.X >= obj->position.X && position.X <= obj->position.X + obj->width)			//Ox
					return obj;
	}
	return nullptr;
}

void SimonCharacter::setCurDoor(Door* _door)
{
	_curDoor = _door;
}

void SimonCharacter::BeingAttacked()
{
	if (flag.beingAttacked)
	{
		if (_direction == RIGHT)
			vx = -0.05;
		else
			vx = 0.05;
		flag.isJump = true;
		flag.beingAttacked = false;
	}
}

void SimonCharacter::Blink()
{
	if (iTimeBlink > 0)
	{
		iTimeBlink -= 0.5;
		if ((int)iTimeBlink % 2 == 0)
			flag.isBlink = true;
		else
			flag.isBlink = false;
		flag.beingAttacked = true;
	}
	else
	{
		flag.isBlink = true;
		flag.beingAttacked = false;
	}
}

void SimonCharacter::OnCollision(BaseObject* obj, int nx, int ny)
{
	if (obj->_collType == CollSubWeapon && _weaponType == WeaponCross && iTimeWeapon < 75)
		iTimeWeapon = 0;
	if (obj->_collType == CollGround && !(nx == 0 && ny == 1) && vy >= 0)
	{
		if (flag.beingAttacked)
		{
			flag.moveWhileBeingAttacked = true;
			vx = 0;
		}
		if (!flag.isSit)
		{
			width = 17;
			height = 30;
			if (flag.isSitBefore)
			{
				position.Y -= 7;
				flag.isSitBefore = false;
			}
			_curSimonAction = SimonStand;
			flag.isStand = true;
			flag.isStandBefore = true;
		}
		else
		{
			width = 16;
			height = 23;
			if (flag.isStandBefore)
			{
				position.Y += 7;
				flag.isStandBefore = false;
			}
			_curSimonAction = SimonSit;
			flag.isSit = true;
			flag.isSitBefore = true;
		}
		Collision::preventMove(this, obj, nx, ny);
		flag.isJump = false;
		flag._kJump = false;
	}
	if (obj->_collType == CollEnemy && iTimeBlink <= 0 && obj->iHealth > 0)
	{
		iHealth -= 2;
		if (iHealth <= 0)
		{
			flag.isDead = true;
			return;
		}
		iTimeBlink = TIME_BLINK;
		flag.moveWhileBeingAttacked = false;
		vy = VY_JUMP;
	}
	if (obj->_collType == CollDoor)
	{
		Door* _door = (Door*)obj;
		if(_door->getEnable())
			setCurDoor(_door);
	}
	if (obj->_collType == CollPaddle && !(nx == 0 && ny == 1) && vy >= 0)
	{
		if (flag.beingAttacked)
			flag.beingAttacked = false;
		if (!flag.isSit)
		{
			width = 17;
			height = 30;
			if (flag.isSitBefore)
			{
				position.Y -= 7;
				flag.isSitBefore = false;
			}
			_curSimonAction = SimonStand;
			flag.isStand = true;
			flag.isStandBefore = true;
		}
		else
		{
			width = 16;
			height = 23;
			if (flag.isStandBefore)
			{
				position.Y += 7;
				flag.isStandBefore = false;
			}
			_curSimonAction = SimonSit;
			flag.isSit = true;
			flag.isSitBefore = true;
		}
		Collision::preventMove(this, obj, nx, ny);
		flag.isJump = false;
		flag._kJump = false;
		Collision::preventMove(this, obj, nx, ny);
		if (obj->vx > 0)
			position.X++;
		else
			position.X--;
	}
	if (obj->_collType == CollItem)
		collectItem((ItemObject*)obj);
}

void SimonCharacter::ChangeAction()
{
	setAction(_curSimonAction);
}

SimonCharacter::~SimonCharacter()
{}

