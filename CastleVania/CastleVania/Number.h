#pragma once
#include<vector>
#include "BaseObject.h"
#include"NumberChar.h"
class Number :
	public BaseObject
{
	vector<NumberChar*> listNumber;
	int length;
public:
	void Run(int _number, int posX, int posY);
	void Draw();
	Number(int _length);
	~Number();
};

