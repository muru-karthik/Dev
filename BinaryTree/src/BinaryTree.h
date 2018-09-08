/*
 * BinaryTree.h
 *
 *  Created on: 08-Sep-2018
 *      Author: mkarthik
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <list>

class Node {
public:
	int data;
	Node* left;
	Node* right;

public:
	Node();
	~Node();
};

// Builds a binary tree from the array of integers that are passed in
Node*
BuildBinaryTree(const std::list<int> &ar);

void
LevelOrderTraversal(const Node* root);


#endif /* BINARYTREE_H_ */
