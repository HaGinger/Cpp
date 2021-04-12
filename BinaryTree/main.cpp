#include <iostream>
#include<string>
#include"BinaryTree.h"

using namespace std;

int main()
{
    BinaryTreeNode<char> a[9];
    for(int i=1;i<=9;++i)
    {
        a[i-1]=BinaryTreeNode<char>(64+i);
    }

    a[0].setLeftchild(a+1);
    a[0].setRightchild(a+2);
    a[1].setLeftchild(a+3);
    a[1].setRightchild(a+4);
    a[4].setLeftchild(a+6);
    a[2].setRightchild(a+5);
    a[5].setLeftchild(a+7);
    a[5].setRightchild(a+8);
    BinaryTree<char> Tree(a);
    cout<<a[8].value()<<endl;
    Tree.postOrder(a);
    Tree.preOrder(a);
    Tree.inOrder(a);

}
