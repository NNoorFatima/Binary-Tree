#pragma once

#include <iostream>
using namespace std;
class B_node
{
public:
    int data;
    B_node* left;
    B_node* right;
    B_node()
    {
        data = 0;
        left = right = nullptr;
    }
    B_node(int da)
    {
        data = da;
        left = right = nullptr;
    }
};
class BST
{
public:
    B_node* root;
    BST()
    {
        root = nullptr;
    }
    void insert(int da)
    {
        B_node* n_node = new B_node(da);
        B_node* cur = root;
        if (root == nullptr)
            root = n_node;
        else
        {
            while (cur != nullptr)
            {
                if (cur->left == nullptr && da < cur->data)
                {
                    cur->left = n_node;
                    break;
                }
                else if (da < cur->data)
                {
                    cur = cur->left;
                }
                else if (cur->right == nullptr && da > cur->data)
                {
                    cur->right = n_node;
                    break;
                }
                else if (da > cur->data)
                {
                    cur = cur->right;
                }
            }
        }
    }
    void deleteData(int d)
    {
        bool found = 0;
        B_node* cur = root;
        B_node* parent = root;
        if (root == nullptr)
            return;
        else
        {
            while (cur != nullptr)//first search for val
            {
                if (d == cur->data)
                {
                    found = 1;
                    break;
                }
                else if (d < cur->data)
                {
                    parent = cur;
                    cur = cur->left;
                }
                else if (d > cur->data)
                {
                    parent = cur;
                    cur = cur->right;
                }
            }
            if (found == 0)
            {
                cout << "Sorry bo such element found in the tree\n";
            }
            else//value found in the tree
            {
                //check if it has no child
                if (cur->left == nullptr && cur->right == nullptr)
                {
                    if (parent->left == cur)
                    {
                        delete cur;
                        cur = nullptr;
                        parent->left = nullptr;
                    }
                    else if (parent->right == cur)
                    {
                        delete cur;
                        cur = nullptr;
                        parent->left = nullptr;
                    }
                }
                //if it has one child 
                else if (cur->left != nullptr && cur->right == nullptr)
                {
                    cur->data = cur->left->data;        //swap values of cur and its child
                    delete cur->left;                     //delete child
                    cur->left = nullptr;
                }
                else if (cur->left == nullptr && cur->right != nullptr)
                {
                    cur->data = cur->right->data;        //swap values of cur and its child
                    delete cur->right;                     //delete child
                    cur->right = nullptr;
                }
                //if it has do bachey 
                else if (cur->left != nullptr && cur->right != nullptr) //Find the minimum value node in the right subtree of
                {                                           //the node to delete (the leftmost node in the right subtree).
                    if (parent->right == cur)
                    {
                        B_node* temp = cur->right;
                        B_node* prev = cur->right;
                        while (temp->left != nullptr)       // finding successor
                        {
                            prev = temp;
                            temp = temp->left;
                        }
                        if (parent->right = cur)    //deleting
                        {
                            parent->right = temp;
                            temp->left = cur->left;
                            temp->right = cur->right;
                            delete cur; cur = nullptr;
                            temp = nullptr; delete temp;
                            prev->left = NULL;
                        }
                    }
                    else if (parent->left == cur)
                    {
                        B_node* temp = cur->right;
                        B_node* prev = cur->right;
                        while (temp->left != nullptr)       // finding successor
                        {
                            prev = temp;
                            temp = temp->left;
                        }
                        if (parent->left == cur)    //deleting
                        {
                            parent->left = temp;
                            temp->left = cur->left;
                            temp->right = cur->right;
                            delete cur; cur = nullptr;
                            temp = nullptr; delete temp;
                            prev->left = NULL;
                        }
                    }
                }
            }
        }
    }
    bool search(int d)
    {
        if (root == nullptr)
            return 0;
        else
        {
            B_node* cur = root;
            while (cur != nullptr)
            {
                if (cur->data == d)
                    return 1;
                else if (d < cur->data)
                {
                    cur = cur->left;
                }
                else if (d > cur->data)
                {
                    cur = cur->right;
                }
            }
            cout << "value not found\n";
        }
        return 0;
    }
    void print_level_order()    //prints accroding to breadth first transversal
    {
        queue<B_node*> q;
        q.push(root);
        cout << endl;
        while (q.empty() != 1)
        {
            B_node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
   //DFS  is inorder,preorder and postorder
};
