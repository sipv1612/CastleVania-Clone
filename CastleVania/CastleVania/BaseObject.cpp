#include "BaseObject.h"



BaseObject::BaseObject()
{
	alive = true;
	isDead = false;
}
BaseObject *BaseObject::createObject(int x, int y, int width, int height)
{
	BaseObject* b = new BaseObject();
	b->position.X = x;
	b->position.Y = y;
	b->width = width;
	b->height = height;
	return b;
}
void BaseObject::run()
{
}
void BaseObject::draw()
{

}
void BaseObject::setObjectFromID()
{
	position.X = oldX;
	position.Y = oldY;
}
void BaseObject::init(int x, int y, int w, int h)
{
	position.X = x;
	position.Y = y;
	width = w;
	height = h;
}

void BaseObject::setPosition(int x,int y)
{
	position.X = x;
	position.Y = y;
}

Point BaseObject::getPosition()
{
	return position;
}

int BaseObject::xCenter()
{
	return position.X+width/2;
}

int BaseObject::right()
{
	return position.X + width;
}

int BaseObject::left()
{
	return position.X;
}

int BaseObject::top()
{
	return position.Y;
}

int BaseObject::bottom()
{
	return position.Y + height;
}

void BaseObject::updatePosition()
{
}

BaseObject::~BaseObject()
{
}
