#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_

#include "BaseObject.h"
#include"Point.h"
#include"dxManager.h"

class StaticObject : public BaseObject
{
	int _sprwidth;
	int _sprheight;
public:
	StaticObject();
	void Draw();
	~StaticObject();
};

#endif