#include "Rect.h"


Rect::Rect(int x, int y, int w, int h)
{
	Set(x, y, w, h);
}

void Rect::Set(int x, int y, int w, int h)
{
	X = x;
	Y = y;
	SetWidthHeight(w, h);
}
void Rect::SetWidthHeight(int w, int h)
{
	Width = w;
	Height = h;
}

RECT Rect::ToRECT()
{
	RECT r;
	r.left = X;
	r.top = Y;
	r.right = X + Width - 1;
	r.bottom = Y + Height - 1;
	return r;
}

int Rect::Top()
{
	return Y;
}
int Rect::Left()
{
	return X;
}
int Rect::Right()
{
	return X + Width - 1;
}
int Rect::Bottom()
{
	return Y + Height - 1;
}

Rect::~Rect()
{
}
