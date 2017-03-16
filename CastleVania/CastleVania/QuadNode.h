#pragma once
#include "Ground.h"
#include "DXManager.h"
#include"Collision.h"
#include "BaseObject.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

class QuadNode : public BaseObject
{
protected:
	int ID;
	int x, y, w, h;
	int num_node;
	int num_obj;
	BaseObject *rect;
	vector<BaseObject*> ListObjectInNode;
public:
	QuadNode();
	QuadNode(char* path);
	QuadNode(int id, BaseObject* r);

	void LoadNode(ifstream *f, vector<BaseObject*> listObj);


	void CreateSubNode();

	QuadNode *tl, *tr, *bl, *br;
	BaseObject* GetRect();

	QuadNode* GetChildNode(int);

	int GetID();
	int GetNum_Obj();
	int GetNum_Node();

	vector<BaseObject*> getListObjInNode();

	~QuadNode();
};

