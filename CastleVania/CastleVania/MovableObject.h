#pragma once
#include "BaseObject.h"
#include"SpriteManager.h"
#include"Collision.h"
#define Gametime gametime
#define GRAVITY 0.0004

class MovableObject : public BaseObject
{
protected:
	int _time;
	Sprite* _listAction;
public:
	static int gametime; // thoi gian doi tuong di chuyen
	Direction _direction; // huong di chuyen
	GameTime* _timeDelay; // thoi gian delay
	int X, Y, Width, Height; // toa do of doi tuong, width, height
	float vyJump; // van toc theo phuong y
	float _deltaTime;
	int _curAction;
	int _curFrame;
	int _actionCount; //so hanh dong
public:
	MovableObject();
	MovableObject(int actionCount, Direction defaultDirection);
	void setAction(int action);
	virtual void Update(GameTime *);
	virtual void Draw();
	virtual void Run();
	virtual void UpdatePosition(); //cap nhat vi tri cua vat
	virtual void UpdateAnimation(); // cap nhat animation

	virtual void Dead();

};

