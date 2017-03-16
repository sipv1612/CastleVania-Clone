#include "Animation.h"


Animation::Animation(DirectXGame* dx, int spritePerColumn, int spritePerRow, int fps, char* fileName, D3DCOLOR transparentColor, Direction defautDirection) :DXTexture(dx)
{
	_defaultDirection = defautDirection;
	LoadTexture(fileName, transparentColor);
	_spritePerColumn = spritePerColumn;
	_spritePerRow = spritePerRow;
	_gametime = new GameTime(fps);
	_sprwidth = _width / spritePerRow;
	_sprheight = _height / spritePerColumn;
}
int Animation::getCount()
{
	return _spritePerColumn*_spritePerRow;
}
D3DXMATRIX Animation::flipMatrix(Point p)
{
	return D3DXMATRIX(-1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 2 * p.X, 0, 0, 1);
}
D3DXMATRIX Animation::flipMatrixVertical(Point p)
{
	//D3DXVECTOR3 pos= D3DXVECTOR3(r->X - Camera::GetInstance()->Left(), r->Top() - Camera::GetInstance()->Top(), 0);
	return D3DXMATRIX(1, 0, 0, 0,
		0, -1, 0, 0,
		0, 0, 1, 0,
		0, 2 * p.Y, 0, 1);
}
int Animation::NextFrame(int index)
{
	return (index + 1) % (_spritePerRow*_spritePerColumn);
	return index;
}

void Animation::Draw(BaseObject* p, int index, Direction direction)
{
	Rect r(_sprwidth*(index%_spritePerRow), _sprheight*(index / _spritePerRow), _sprwidth + 1, _sprheight + 1);

	D3DXVECTOR2 pos;
	pos.x = p->position.X - Camera::GetInstance()->position.X;
	pos.y = p->position.Y - Camera::GetInstance()->position.Y;
	pos.x += (p->width - r.Width) / 2;
	pos.y += (p->height - r.Height) / 2;
	D3DXMATRIX baseMatrix;
	if (direction != _defaultDirection)
	{
		_dxGame.GetSprite()->GetTransform(&baseMatrix);
		_dxGame.GetSprite()->SetTransform(&(baseMatrix*flipMatrix(Point(pos.x + r.Width / 2, pos.y))));
	}


	_dxGame.DrawTexture(this, &pos, &r.ToRECT(), D3DCOLOR_XRGB(255, 255, 255));


	if (direction != _defaultDirection)
	{
		_dxGame.GetSprite()->SetTransform(&baseMatrix);
	}
}

Animation::~Animation()
{
	//delete _gametime;
}
