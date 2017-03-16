#pragma once
#include"BaseObject.h"
#include<limits>
#include<algorithm>
#define MAX(a,b)a>b?a:b
#define MIN(a,b)a>b?b:a

class Collision
{
public:
	static float sweptAABB(BaseObject *b1, BaseObject *b2, int &normalx, int& normaly);
	static BaseObject* getSweptBroadPhaseBox(BaseObject* b);
	static bool checkAABB(BaseObject* b1, BaseObject* b2);
	static void preventMove(BaseObject* b1, BaseObject* b2,int nx,int ny);
	static void CheckCollision(BaseObject* b1, BaseObject* b2);//khi co va cham thi khong cho doi tuong di chuyen
	Collision();
	~Collision();
};

