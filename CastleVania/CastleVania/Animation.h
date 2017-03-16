#pragma once
#include"DXManager.h"
#include "GameTime.h"
#include "Point.h"
#include"Rect.h"


enum Direction
{
	LEFT = -1,
	RIGHT = 1
};

class Animation : public DXTexture
{
	int _spritePerColumn;
	int _spritePerRow;
	int _sprwidth;
	int _sprheight;
	GameTime *_gametime;
	Direction _defaultDirection;


public:
	Animation() {  }
	static D3DXMATRIX flipMatrix(Point p);
	static D3DXMATRIX flipMatrixVertical(Point p);
	int getCount();
	int GetSpriteWidth()
	{
		return _sprwidth;
	}
	int GetSpriteHeight()
	{
		return _sprheight;
	}
	Animation(DirectXGame*, int spritePerColumn, int spritePerRow, int fps, char* fileName, D3DCOLOR transparentColor, Direction defautDirection);
	int NextFrame(int index);
	void Draw(BaseObject* p, int index, Direction direction);
	~Animation();
};

