#include "Sprite.h"


Sprite::Sprite(int count)
{
	index = 0;
	_count = count;
	_list = new Animation*[count];
}

Animation* Sprite::get(int i)
{
	return _list[i];
}

void Sprite::Add(Animation* item)
{
	_list[index] = item;
	index++;
}

Sprite::~Sprite()
{
}
