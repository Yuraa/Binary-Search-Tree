#include "BinarySearchTree.h"

node **BinarySearchTree::findAssist(int data)
{
	node **current = &root;
	while (*current)
	{
		if ((*current)->data == data)
		{
			return current;
		}

		if (data < (*current)->data)
		{
			current = &((*current)->left);
			continue;
		}

		if (data > (*current)->data)
		{
			current = &((*current)->right);
			continue;
		} //if
	} // while
}

node *BinarySearchTree::find(int data)
{
	return *findAssist(data);
}

void BinarySearchTree::insert(int data)
{
	node *temp = new node;
	temp->data = data;
	if (!root)
	{
		root = temp;
	}
	else
	{
		*findAssist(data) = temp;

		/*
		node *topBuf = root;
		while (topBuf)
		{
			if (data < topBuf->data)
			{
				if (!topBuf->left)
				{
					topBuf->left = temp;
					break;
				}
				else
				{
					topBuf = topBuf->left;
				}
			}
			if (data > topBuf->data)
			{
				if (!topBuf->right)
				{
					topBuf->right = temp;
					break;
				}
				else
				{
					topBuf = topBuf->right;
				}
			}
			if (data == topBuf->data)
			{
				break;
			}
		} // while  */
	} // else
}

int BinarySearchTree::remove(int data)
{
	if (!root)
	{
		return 1;
	}
	node **prev = findAssist(data);
	node *top = *prev;

	/*while (top)
	{
		if (data < top->data)
		{
			prev = &(top->left);
			top = top->left;
			continue;
		}
		if (data > top->data)
		{
			prev = &(top->right);
			top = top->right;
			continue;
		}
		if (data == top->data)
		{
			break;
		}
	} // while  */


	if (!top)
	{
		return 1;
	}

	if (top->left == 0 && top->right == 0)
	{
		delete top;
		if (prev)
		{
			*prev = 0;
		}
		else
		{
			root = 0;
		}
		return 0;
	}
	if (top->left != 0 && top->right == 0)
	{
		if (prev)
		{
			*prev = top->left;
		}
		else
		{
			root = top->left;
		}
		delete top;
		return 0;
	}
	if (top->left == 0 && top->right != 0)
	{
		if (prev)
		{
			*prev = top->right;
		}
		else
		{
			root = top->right;
		}
		delete top;
		return 0;
	}
	if (top->left != 0 && top->right != 0)
	{
		node *p = top->left;
		node **prevP = &(top->left);
		while (p->left != 0 || p->right != 0)
		{
			if (p->right)
			{
				prevP = &(p->right);
				p = p->right;
			}
		} // while
		*prevP = 0;
		p->left = top->left;
		p->right = top->right;
		if (prev)
		{
			*prev = p;
		}
		else
		{
			root = p;
		}
		delete top;
		return 0;
	} // if
	return 1;
}

void BinarySearchTree::inorder(node *&top)
{
	if (top)
	{
		if (top->left)
		{
			inorder(top->left);
		}
		
		{
		
		}
		
		if (top->right)
		{
			inorder(top->right);
		}
	}
}

void BinarySearchTree::postorder(node *&top)
{
	if (top)
	{
		if (top->left)
		{
			postorder(top->left);
		}

		if (top->right)
		{
			postorder(top->right);
		}

		delete top;
		top = 0;
	}
}

BinarySearchTree::~BinarySearchTree()
{
	postorder(root);
}
