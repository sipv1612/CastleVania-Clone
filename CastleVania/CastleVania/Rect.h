#pragma once
#include<Windows.h>
class Rect
{
public:
	int X, Y, Width, Height;
	Rect(int x = 0, int y = 0, int w = 0, int h = 0);
	void Set(int x = 0, int y = 0, int w = 0, int h = 0);
	void SetWidthHeight(int w, int h);
	RECT ToRECT();
	int Top();
	int Left();
	int Right();
	int Bottom();
	~Rect();
};

