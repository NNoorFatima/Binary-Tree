#include <iostream>
using namespace std;
char tree[10];
void root(char a)
{
    if(tree[0]!='\0')
        cout<<"root already set\n";
    else
        tree[0]=a;
}
void setleft(char a,int parent_index)
{
    if(tree[parent_index]=='\0')
        cout<<"parent doesnt exist\n";
    else
        tree[2*parent_index+1]=a;        //when starting from index 0 if index was started from 1 then 2k
}
void setright(char a,int parent_index)
{
    if(tree[parent_index]=='\0')
        cout<<"parent doesnt exist\n";
    else
        tree[2*parent_index+2]=a;        //when starting from index 0 if index was started from 1 then 2k+1
}
void print()
{
    if(tree[0]=='\0')
        cout<<"tree is empty\n";
    else
    {
        for(int i=0 ;i<10 ;i++)
        {
            if(tree[i]!='\0')
                cout<<tree[i]<<" ";
            else
                cout<<" - ";
        }
    }
}
bool isEmpty()
{
    if(tree[0]=='\0')
        return 1;
    return 0;
}
bool isRoot(char a)
{
    if(tree[0]==a)
        return 1;
    return 0;
}
int main()
{
   root('a');
   setleft('b',0);
   setright('c',0);
   setleft('d',1);
   setright('e',1);
   setleft('f',2);
   setright('g',2);
   print();
   
    return 0;
}
