
// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
    BST a;
    a.insert(50);
    a.insert(30);
    a.insert(10);
    a.insert(80);
    a.insert(60);
    a.insert(90);
    a.insert(110);
    a.insert(85);
    a.insert(83);
    a.insert(95);
    a.insert(92);
    a.insert(40);
    a.insert(45);
    a.insert(39);
    a.deleteData(90);
    a.deleteData(30);
    a.insert(55);
     cout << a.search(5);
    a.print_level_order();

}
