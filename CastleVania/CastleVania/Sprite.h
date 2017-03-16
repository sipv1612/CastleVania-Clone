#pragma once
#include"Animation.h"
class Sprite:public Animation
{
	Animation** _list;
	int _count;
	int index;
public:
	Sprite(int);
	Animation* get(int i);

	void Add(Animation* item);
	~Sprite();
};

