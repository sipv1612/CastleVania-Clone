#pragma once
#include "SimonCharacter.h"

class Whip :
	public MovableObject
{
private:
	static Whip* instance;
	int iDamage;
	WhipType _curType;				// Loại whip hiện tại
	WhipSprite _curWhipAction;		// Sprite whip hiện tại
	int iPreWhipFrame;				// Index của sprite whip trước đó
	int _curState;					// Trạng thái whip hiện tại (1-3)
	GameTime *delayIndexChange;
	void changeType()
	{
		setAction(_curWhipAction);
	}
	void setPosition(int SimonX, int SimonY, int Frame);
public:
	static Whip* GetInstance();
	void setType(WhipType _type);
	void Run(bool Active, int SimonX, int SimonY, int curFrame, Direction direction);
	void Draw()
	{
		MovableObject::Draw();
	}
	int getDamage()
	{
		return iDamage;
	}
	WhipType getType()
	{
		return _curType;
	}
	int getState()
	{
		return _curState;
	}
	Whip();
	~Whip() {};
};

