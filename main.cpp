#include <fstream>
#include <iostream>
#include <conio.h>
#include "BinarySearchTree.h"
#include "msoftcon.h"

using namespace std;

int height(node *t)
{
	int r = 0, l = 0;

	if (t->left)
	{
		l = height(t->left) + 1;
	}

	if (t->right)
	{
		r = height(t->right) + 1;
	}

	if (r > l)
	{
		return r;
	}
	else
	{
		return l;
	}
}

void printTree(node *, int, int, int);
void clearTree(node *, int, int, int);

int main()
{
	int a = 0;
	BinarySearchTree T;
	ifstream in("input.txt");
	while(!in.eof())
	{
		in >> a;
		T.insert(a);
	}
	in.close();
	int l = height(T.root); // высота дерева
	int L = 1;
	for (int i = 0; i < (l - 1); i++)
	{
		L *= 2;
	}
	init_graphics();
	printTree(T.root, 40, 2, L*3);
	set_cursor_pos(1, 1);
	cout << "Input: ";
	cin >> a;
	clearTree(T.root, 40, 2, L * 3);
	T.remove(a);
	printTree(T.root, 40, 2, L*3);
	_getch();
	return 0;
}

void printTree(node *root, int x, int y, int L)
{
	if (!root)
	{
		return;
	}

	set_cursor_pos(x, y);
	cout << root->data;
	if (root->left)
	{
		printTree(root->left, x - L, y + 2, L / 2);
	}
	if (root->right)
	{
		printTree(root->right, x + L, y + 2, L / 2);
	}
}

void clearTree(node *root, int x, int y, int L)
{
	if (!root)
	{
		return;
	}

	set_cursor_pos(x, y);
	clear_line();
	if (root->left)
	{
		clearTree(root->left, x - L, y + 2, L / 2);
	}
	if (root->right)
	{
		clearTree(root->right, x + L, y + 2, L / 2);
	}
}

