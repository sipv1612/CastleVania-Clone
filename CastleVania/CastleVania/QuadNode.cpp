#include "QuadNode.h"


QuadNode::QuadNode()
{
	rect = new BaseObject();
}

QuadNode::QuadNode(char* path)
{

}

QuadNode::QuadNode(int id, BaseObject* r)
{
	this->tl = NULL;
	this->tr = NULL;
	this->br = NULL;
	this->bl = NULL;
	this->ID = id;
	this->rect = r;
}

int QuadNode::GetID()
{
	return this->ID;
}

int QuadNode::GetNum_Node()
{
	return this->num_node;
}

int QuadNode::GetNum_Obj()
{
	return this->num_obj;
}

QuadNode* QuadNode::GetChildNode(int i)
{
	switch (i)
	{
	case 1:
		return this->tl;
	case 2:
		return this->tr;
	case 3:
		return this->bl;
	case 4:
		return this->br;
	}
}


void QuadNode::CreateSubNode()
{
	this->tl = new QuadNode();
	this->tr = new QuadNode();
	this->bl = new QuadNode();
	this->br = new QuadNode();
}

void QuadNode::LoadNode(ifstream *f, vector<BaseObject*> listObj)
{
	(*f) >> rect->position.X;
	(*f) >> rect->position.Y;
	(*f) >> rect->width;
	(*f) >> rect->height;
	(*f) >> num_node;
	(*f) >> num_obj;



	if (num_node == 0 && num_obj == 0)
	{
		return;
	}

	if (num_node == 4)
	{
		CreateSubNode();
		tl->LoadNode(f, listObj);
		tr->LoadNode(f, listObj);
		bl->LoadNode(f, listObj);
		br->LoadNode(f, listObj);
	}
	else
	{
		for (int i = 0; i < num_obj; i++)
		{
			int k; (*f) >> k;
			ListObjectInNode.push_back(listObj.at(k));
		}
	}
}

BaseObject* QuadNode::GetRect()
{
	return rect;
}

vector<BaseObject *> QuadNode::getListObjInNode()
{
	return ListObjectInNode;
}



QuadNode::~QuadNode()
{
}
