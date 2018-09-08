//============================================================================
// Name        : BinaryTree.cpp
// Author      : Muruganand K
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

#include "BinaryTree.h"

using namespace std;

Node* root = NULL;

Node::Node()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

Node::~Node()
{
	if (left) {
		delete(left);
	}

	if (right) {
		delete(right);
	}

	left = right = NULL;
}

Node*
BuildBinaryTree(const list<int> &ar)
{
	queue<Node**> q;
	Node *root = NULL;
	Node **tmp = NULL;

	if (!ar.empty()) {
		root = new Node();

		q.push(&root);

		for (const int& i : ar) {
			tmp = q.front();
			q.pop();

			if (*tmp == NULL) {
				*tmp = new Node();
			}

			q.push(&((*tmp)->left));
			q.push(&((*tmp)->right));

			(*tmp)->data = i;
		}
	}

	return root;
}

void
LevelOrderTraversal(const Node* root)
{
	queue<const Node*> q;
	const Node *tmp = NULL;

	q.push(root);

	while(!q.empty()) {
		tmp = q.front();
		q.pop();

		if (tmp) {
			cout << tmp->data << ", ";

			if (tmp->left)
				q.push(tmp->left);

			if (tmp->right)
				q.push(tmp->right);
		}
	}

	cout << endl;
}

void
InOrderTraversal(const Node* root)
{
	if (root) {
		InOrderTraversal(root->left);
		cout << root->data << ", ";
		InOrderTraversal(root->right);
	}
}

int main() {
	ifstream fin;
	int num;

	list<int> ar;

	fin.open("/home/mkarthik/Dev/BinaryTree/src/input.txt");

	while (fin >> num) {
		ar.push_back(num);
	}

	fin.close();

	cout << "Building binary tree..." << endl;
	root = BuildBinaryTree(ar);

	cout << "Printing level order traversal..." << endl;
	LevelOrderTraversal(root);

	cout << "Printing in order traversal..." << endl;
	InOrderTraversal(root);

	cout << endl << "Done!" << endl;

	delete(root);

	return 0;
}
