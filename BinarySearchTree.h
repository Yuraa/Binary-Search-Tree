#include "msoftcon.h"

struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		data = 0;
		left = 0;
		right = 0;
	}
};

class BinarySearchTree
{
private:
	node **findAssist(int);

public:

	node *root;

	//BinarySearchTree *leftSubtree;
	//BinarySearchTree *rightSubtree;
	//int value;

	node *find(int);
	void insert(int);
	int remove(int);
	
	void inorder(node *&);
	void postorder(node *&);

	BinarySearchTree()
	{
		root = 0;
	}
	~BinarySearchTree();
};




