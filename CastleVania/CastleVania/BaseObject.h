#pragma once
#include "Point.h"
enum CollisionType
{
	CollGround,
	CollStair,
	CollDoor,
	CollPaddle,
	CollSimon,
	CollWhip,
	CollSubWeapon,
	CollEnemy,
	CollItem,
	CollBrick
};
class BaseObject
{
public:
	int id;
	int iHealth;
	bool alive;
	int width, height;
	Point position;
	int curAction;
	float vx, vy, ax, ay, dx, dy;
	int oldX, oldY;
	bool c;
	bool isDead;
	int normalX, normalY;
	BaseObject();
	CollisionType _collType;
	static BaseObject* createObject(int x, int y, int width, int height);
	virtual void run();
	virtual void draw();
	BaseObject* oldObj;
	virtual void setObjectFromID();
	virtual void OnCollision(BaseObject* obj, int nx, int ny) {}
	virtual void OnInterSerct(BaseObject* obj) {}
	void init(int x, int y, int w, int h);
	void setPosition(int x, int y);
	Point getPosition();
	int xCenter();
	int right();
	int left();
	int top();
	int bottom();
	virtual void updatePosition();

	~BaseObject();
};

