#pragma once
#include "StaticObject.h"
#include"SpriteManager.h"
class Ground : public StaticObject
{

public:
	Ground();
	void setObjectFromID();
	void Draw();

	~Ground();
};

