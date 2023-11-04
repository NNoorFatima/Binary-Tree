#pragma once
#include <iostream>
using namespace std;
#include "queue"
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		data = d;
		left = right = nullptr;
	}
};

class BinaryTree
{

public:
	Node* Root;
	BinaryTree()
	{
		Root = nullptr;
	}
	void insert(int a)
	{
		Node* n = new Node(a);
		if (Root == nullptr)
			Root = n;
		else
		{
			queue<Node*> q;
			q.push(Root);
			while (q.empty() != 1)
			{
				Node* t = q.front();
				q.pop();
				if (t->left == nullptr)
				{
					t->left = n;
					break;
				}
				else
				{
					q.push(t->left);
				}
				if (t->right == nullptr)
				{
					t->right = n;
					break;
				}
				else
				{
					q.push(t->right);
				}
			}
		}
	}
	void inorderTransversal(Node* treeNode)
	{
		if (treeNode == nullptr)
			return;
		else
		{
			inorderTransversal(treeNode->left);
			cout << treeNode->data << " ";
			inorderTransversal(treeNode->right);
		}
	}
	void display()
	{
		inorderTransversal(Root);
		cout << endl;
	}

};
