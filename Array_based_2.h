#pragma once
#include <iostream>
#include "queue";
using namespace std;
class BinaryTree
{
public:
	int* treeArray;
	int capacity;
	int root;;
	int current_index;
	BinaryTree()
	{
		capacity = 100;
		treeArray = new int[capacity];
		root = current_index = 0;
		for (int i = 0; i < capacity; i++)
			treeArray[i] = -1;

	}
	void insert(int a)
	{
		/*if (treeArray == nullptr)
		{
			root = 0;
			capacity = 1;
			current_index = 0;
			treeArray = new int[capacity];
			treeArray[current_index] = a;
			current_index++;
		}
		else
		{
			capacity++;
			int* nt = new int[capacity];
			for (int i = 0; i < capacity - 1; i++)
			{
				nt[i] = treeArray[i];
			}
			nt[current_index] = a;
			delete[] treeArray;
			treeArray = new int[capacity];
			for (int i = 0; i <capacity ; i++)
			{
				treeArray[i] = nt[i];
			}
			delete[]nt;
			nt = nullptr;
		}*/
		if (treeArray[0] == -1)
		{
			treeArray[current_index] = a;
			current_index++;
		}
		else if(current_index<capacity)
		{
			treeArray[current_index] = a;
			current_index++;
		}

	}
	void inorderTransversal(int index)
	{
		if (treeArray[index]==-1)
			return;
		else
		{
			inorderTransversal(2 * index + 1);
			cout << treeArray[index] << " ";
			inorderTransversal(2 * index + 2);
		}
	}
	void displayInorder()
	{
		inorderTransversal(root);
	}
};
