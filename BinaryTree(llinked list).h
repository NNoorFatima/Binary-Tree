#pragma once
#include <iostream>
using namespace std;
#include <queue>
template <typename U>
class Node
{
public:
	U data;
	Node<U>* left;
	Node<U>* right;
	Node(U d)
	{
		data = d;
		left = right = nullptr;
	}
};
template<typename T>
class BinaryTree
{

public:
	Node<T>* Root;
	BinaryTree()
	{
		Root = nullptr;
	}
	void insert(T a)
	{
		Node<T>* n = new Node(a);
		if (Root == nullptr)
			Root = n;
		else
		{
			queue<Node<T>*> q;
			q.push(Root);
			while (q.empty() != 1)
			{
				Node<T>* t = q.front();
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
	void inorderTransversal(Node<T>* treeNode)
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
	int search(T arr[], int start, int end, T value)
	{
		int i;
		for (i = start; i <= end; i++)
		{
			if (arr[i] == value)
				return i;
		}
	}
	Node<T>* create_tree(T inorder[], T preorder[], int start, int end)
	{
		static int preindex = 0;
		if (start > end)
			return nullptr;
		Node<T>* tnode = new Node<T>(preorder[preindex++]);
		if (start == end)
			return tnode;

		int index = search(inorder, start, end, tnode->data);
		tnode->left = create_tree(inorder, preorder, start, index - 1);
		tnode->right = create_tree(inorder, preorder, index + 1, end);
		
		return tnode;
	}

};
