
#include "Enemy.h"
class Snake :
	public Enemy
{
	bool onTheGround;
public:
	void reNew();
	void runAI();
	void OnCollision(BaseObject * obj, int nx, int ny);
	Snake(int posX, int posY);
	~Snake();
};
