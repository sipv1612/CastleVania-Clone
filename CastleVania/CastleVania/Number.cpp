#include "Number.h"



void Number::Run(int _number, int posX, int posY)
{
	position.X = posX;
	position.Y = posY;
	int bigNum, num, x, y;
	bigNum = _number;
	x = position.X + 8 * (length - 1);
	y = position.Y;
	for (int i = length - 1; i >= 0; i--)
	{
		num = bigNum % 10;
		bigNum /= 10;
		listNumber[i]->Run(num, x, y);
		x -= 8;
	}
}

void Number::Draw()
{
	for (int i = 0; i < length; i++)
		listNumber[i]->Draw();
}

Number::Number(int _length)
{
	length = _length;
	for (int i = 0; i < length; i++)
		listNumber.push_back(new NumberChar());
}


Number::~Number()
{
}
