#include "Map.h"

int x, y, w, h;

Map::Map()
{
}

Map::Map(DirectXGame *g)
{
	bg = new DXSurface(g);
}

void Map::loadResource(int index)
{
	if (index == 0)
	{
		bg->LoadSurface("introScene.png", NULL);
		getMapInfo("Quadtree//intro.txt");
		LoadQuadtreeFromFile("Quadtree//introQuadtree.txt");
		width = bg->GetWidth();
		height = bg->GetHeight();
	}
	if (index == 1)
	{
		bg->LoadSurface("level-2b.png", NULL);
		getMapInfo("Quadtree//test.txt");
		LoadQuadtreeFromFile("Quadtree//testQuadtree.txt");
		width = bg->GetWidth();
		height = bg->GetHeight();
		getDoor("Quadtree//Doors.txt");
		getPaddle("Quadtree//Paddles.txt");
		getEnemies("Quadtree//Enemies.txt");
		getCandle("Quadtree//Item.txt");
		getBrick("Quadtree//Brick.txt");
	}

}

void Map::getMapInfo(char * path)
{
	BaseObject* obj = new BaseObject();
	fstream f;
	f.open(path);
	int n;
	f >> n;
	for (int i = 0; i<n; i++)
	{
		int id;
		f >> id;
		int index = 0;
		switch (id)
		{
		case 0:
			obj = new Ground();
			break;
		case 1:
			obj = new Stair();
			break;
		}
		f >> obj->position.X;
		f >> obj->position.Y;
		f >> obj->width;
		f >> obj->height;

		obj->oldX = obj->position.X;
		obj->oldY = obj->position.Y;
		obj->oldObj = new BaseObject();
		obj->oldObj->init(obj->position.X, obj->position.Y, obj->width, obj->height);
		listObj.push_back(obj);
		obj->id = id;
		obj->setObjectFromID();
	}
	f.close();
}

void Map::getDoor(char * path)
{
	int _lvl, _isEnable, _posX, _posY;
	fstream f;
	f.open(path);
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> _lvl;
		f >> _isEnable;
		f >> _posX;
		f >> _posY;
		listDoor.push_back(new Door(_lvl, _isEnable, _posX, _posY));
	}
	f.close();
}

void Map::getPaddle(char * path)
{
	int posX, posY, range;
	fstream f;
	f.open(path);
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> posX;
		f >> posY;
		f >> range;

		listPaddle.push_back(new Paddle(posX, posY, range));
	}
	f.close();

}

void Map::getEnemies(char * path)
{
	Enemy* enemy = new Enemy();
	fstream f;
	f.open(path);
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		int id;
		f >> id;
		switch (id)
		{
		case 1:
			enemy = new Bat();
			break;
		case 2:
			enemy = new SpearGuard();
			break;
		case 3:
			enemy = new BonePillar();
			break;
		case 4:
			enemy = new Ghost();
			break;
		case 5:
			enemy = new MedusaHead();
			break;
		case 6: 
			enemy = new BossMedusa();
			break;
		}
		f >> enemy->position.X;
		f >> enemy->position.Y;
		f >> enemy->width;
		f >> enemy->height;

		enemy->oldX = enemy->position.X;
		enemy->oldY = enemy->position.Y;
		enemy->oldObj = new BaseObject();
		enemy->oldObj->init(enemy->position.X, enemy->position.Y, enemy->width, enemy->height);
		listEnemy.push_back(enemy);
		enemy->id = id;
		enemy->setObjectFromID();
	}
	f.close();
}

void Map::getCandle(char * path)
{
	int id, _posX, _posY, empty;
	ItemType type;
	fstream f;
	f.open(path);
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> id;
		f >> _posX;
		f >> _posY;
		f >> empty;
		f >> empty;
		type = static_cast<ItemType>(id);
		if (type == ItemMoney1 || type == ItemMoney4 || type == ItemMoney5 || type == ItemSpiritBall)
		{
			ItemObject *item = new ItemObject(false, type, _posX, _posY);
			item->alive = false;
			listHiddenObj.push_back(item);
			continue;
		}
		listCandle.push_back(new ItemObject(true, type, _posX, _posY));
	}
	f.close();
}

void Map::getBrick(char * path)
{
	int id, _posX, _posY, empty;
	ItemType type;
	Brick* brick;
	fstream f;
	f.open(path);
	int n;
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> id;
		f >> _posX;
		f >> _posY;
		f >> empty;
		f >> empty;
		type = static_cast<ItemType>(id);
		brick = new Brick(type, _posX, _posY);
		listBrick.push_back(brick);
		if (type == ItemMoney1 || type == ItemMoney4 || type == ItemMoney5)
			for each (ItemObject* item in listHiddenObj)
				if (item->getType() == type)
				{
					brick->setHiddenItem(item);
					break;
				}
	}
	f.close();
}

vector<Enemy*> Map::getListEnemy()
{
	return listEnemy;
}

void Map::CreateObjFromFile()
{
	for (int i = 0; i < listObj.size(); i++)
	{
		for each(BaseObject* obj in listObj)
		{
			obj->createObject(x, y, w, h);
		}
	}
}

void Map::LoadQuadtreeFromFile(char* path)
{

	tree = new Quadtree();
	ifstream file(path);

	tree->getListObject(listObj);

	tree->getRootNode()->LoadNode(&file, listObj);
	file.close();
}

void Map::run()
{
	for (int i = 0; i < Camera::GetInstance()->GetListObj()->size();)//doi tuong nam trong camera, neu checkAABB sai thi se xoa ra khoi camera
	{
		if (!Collision::checkAABB(Camera::GetInstance(), Camera::GetInstance()->GetListObj()->at(i)))
			Camera::GetInstance()->GetListObj()->erase(Camera::GetInstance()->GetListObj()->begin() + i);
		else
			i++;
	}
	tree->FindNodeInView(tree->getRootNode());// tim khong gian roi nhet doi tuong do vao camera
	Camera::GetInstance()->AddObjectToListCol();

	//Ground
	for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
		obj->run();
	for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
	{
		Collision::CheckCollision(SimonCharacter::GetInstance(), obj);
		Collision::CheckCollision(SubWeapon::GetInstance(), obj);
	}

	//Subweapon
	Collision::CheckCollision(SimonCharacter::GetInstance(), SubWeapon::GetInstance());

	////Stair
	//for each (BaseObject* obj in *Camera::GetInstance()->GetListStair())
	//	obj->run();

	//Enemy
	Enemy* special;
	for each (Enemy* enemy in listEnemy)
	{
		if (SimonCharacter::GetInstance()->iHealth > 0)
		{
			if (Collision::checkAABB(Camera::GetInstance(), enemy) || enemy->id == 6)
			{
				if (enemy->id == 4 && enemy->getStatus() != EnemyOutOfHealth)
				{
					special = enemy;
					special = (Ghost*)special;
					((Ghost*)special)->checkActive();
				}
				if (enemy->id == 5)
				{
					special = enemy;
					special = (MedusaHead*)special;
					if (((MedusaHead*)special)->createPosition.X == 0 && ((MedusaHead*)special)->createPosition.Y == 0)
						((MedusaHead*)special)->createPosition = enemy->position;
					((MedusaHead*)special)->reNew();
				}
				if (enemy->id == 6)
				{
					special = enemy;
					special = (BossMedusa*)special;
					((BossMedusa*)special)->checkActive();
				}
				enemy->Run();
				Collision::CheckCollision(enemy, SimonCharacter::GetInstance());
				Collision::CheckCollision(enemy, SubWeapon::GetInstance());
				Collision::CheckCollision(enemy, Whip::GetInstance());
				for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
					Collision::CheckCollision(enemy, obj);
			}
		}
		else
			if (enemy->iHealth <= 0)
				enemy->reLoad();
	}

	for each(Door* door in listDoor)
		if (Collision::checkAABB(Camera::GetInstance(), door))
		{
			door->Run();
			Collision::CheckCollision(SimonCharacter::GetInstance(), door);
		}

	for each (Paddle* paddle in listPaddle)
		if (Collision::checkAABB(Camera::GetInstance(), paddle))
		{
			paddle->Run();
			Collision::CheckCollision(SimonCharacter::GetInstance(), paddle);
			for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
				Collision::CheckCollision(paddle, obj);
		}
	for each (ItemObject* candle in listCandle)
		if (Collision::checkAABB(Camera::GetInstance(), candle))
		{
			candle->Run();
			Collision::CheckCollision(SimonCharacter::GetInstance(), candle);
			Collision::CheckCollision(Whip::GetInstance(), candle);
			Collision::CheckCollision(SubWeapon::GetInstance(), candle);
			for each (BaseObject* obj in *Camera::GetInstance()->GetListObj())
				if (obj->_collType == CollGround)
					Collision::CheckCollision(obj, candle);
		}
	for each (Brick* brick in listBrick)
		if (Collision::checkAABB(Camera::GetInstance(), brick))
		{
			if (brick->getType() == ItemDoubleShot || brick->getType() == ItemTripleShot)
			{
				if (SimonCharacter::GetInstance()->doubleShot || SimonCharacter::GetInstance()->tripleShot)
					brick->setItemType(ItemTripleShot);
				else
					brick->setItemType(ItemDoubleShot);
			}
			brick->Run();
			Collision::CheckCollision(SimonCharacter::GetInstance(), brick);
			Collision::CheckCollision(Whip::GetInstance(), brick);
			for each (BaseObject* obj in *Camera::GetInstance()->GetListObj())
				if (obj->_collType == CollGround)
					Collision::CheckCollision(obj, brick);
		}
	for each (ItemObject* hiddenItem in listHiddenObj)
	{
		if (BossMedusa::GetInstance()->getStatus() == EnemyOutOfHealth && BossMedusa::GetInstance()->alive)
		{
			if (hiddenItem->getType() == ItemSpiritBall)
				hiddenItem->alive = true;
		}
		hiddenItem->Run();
		Collision::CheckCollision(SimonCharacter::GetInstance(), hiddenItem);
		for each (BaseObject* obj in *Camera::GetInstance()->GetListObj())
			if (obj->_collType == CollGround)
				Collision::CheckCollision(obj, hiddenItem);
	}
	//for each (ItemObject* hiddenItem in listHiddenObj)
	//	if (Collision::checkAABB(Camera::GetInstance(), hiddenItem))
	//	{
	//		hiddenItem->Run();
	//		Collision::CheckCollision(SimonCharacter::GetInstance(), hiddenItem);
	//		for each (BaseObject* obj in *Camera::GetInstance()->GetListObj())
	//			if (obj->_collType == CollGround)
	//				Collision::CheckCollision(obj, hiddenItem);
	//	}
}

void Map::draw()
{
	bg->Draw();
	for each (Enemy* enemy in listEnemy)
		if (Collision::checkAABB(Camera::GetInstance(), enemy))
			enemy->Draw();
	//for each (BaseObject* obj in *Camera::GetInstance()->GetListGround())
	//	obj->draw();
	//for each (BaseObject* obj in *Camera::GetInstance()->GetListStair())
	//	obj->draw();
	for each(Door* door in listDoor)
		if (Collision::checkAABB(Camera::GetInstance(), door))
			door->Draw();
	for each (Paddle* paddle in listPaddle)
		if (Collision::checkAABB(Camera::GetInstance(), paddle))
			paddle->Draw();
	for each (ItemObject* candle in listCandle)
		if (Collision::checkAABB(Camera::GetInstance(), candle))
			candle->Draw();
	for each(Brick* brick in listBrick)
		if (Collision::checkAABB(Camera::GetInstance(), brick))
			brick->Draw();
	for each(ItemObject* item in listHiddenObj)
		if (item->getType() == ItemSpiritBall)
			item->Draw();
}

Map::~Map()
{
}
