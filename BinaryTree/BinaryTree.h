#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <iostream>
#include <stack>

using namespace std;

enum Tags{L,R};
template<typename T>
class BinaryTree;
template<typename T>
class BinaryTreeNode
{
	friend class BinaryTree<T>;

private:
	T info;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;
	BinaryTreeNode<T> *parent;
public:
	BinaryTreeNode() { left = NULL; right = NULL; parent = NULL; }
	BinaryTreeNode(const T& data) { info = data; left = NULL; right = NULL; parent = NULL; }
	BinaryTreeNode(const T& data, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r, BinaryTreeNode<T> *p);

	T value() const { return info; }
	BinaryTreeNode<T> *leftchild() const { return left; }
	BinaryTreeNode<T> *rightchild() const { return right; }
	BinaryTreeNode<T> *Parent() const { return parent; }
	void setLeftchild(BinaryTreeNode<T> *l) { left = l; l->parent=this;}
	void setRightchild(BinaryTreeNode<T> *r) { right = r; r->parent=this;}
	void setParent(BinaryTreeNode<T> *p) { parent = p; if(p->leftchild()==NULL)p->setLeftchild(this);else p->setRightchild(this);}
	void setValue(const T &v) { info = v; }
	bool isLeaf() const;
	BinaryTreeNode<T> operator=(const BinaryTreeNode<T> &Node);


};

//BinaryTreeNode

template<typename T>
class BinaryTree
{
	friend class BinaryTreeNode<T>;
private:
	BinaryTreeNode<T> *root;
	//BinaryTree<T> leftTree;
	//BinaryTree<T> rightTree;
public:
	BinaryTree() { root = NULL; }
	BinaryTree(BinaryTreeNode<T> *tmproot){ root = tmproot; }
	~BinaryTree() { deleteTree(root); }

	bool isEmpty()const { return root == NULL ? 1 : 0; }
	BinaryTreeNode<T> *Root() const { return root; }
	BinaryTreeNode<T> *sibling(BinaryTreeNode<T> *current) const;

	void createTree(const T &data, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r);
	void preOrder(BinaryTreeNode<T> *tmproot);
	void inOrder(BinaryTreeNode<T> *tmproot);
	void postOrder(BinaryTreeNode<T> *tmproot);
	void levelOrder(BinaryTreeNode<T> *tmproot);
	void deleteTree(BinaryTreeNode<T> *tmproot);
};

template<typename T>
class stackElement
{
public:
    BinaryTreeNode<T> *pointer;
    Tags tag;
};
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T& data, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r, BinaryTreeNode<T> *p)
{
	info = data;
	left = l;
	right = r;
	parent = p;
}
template<typename T>
bool BinaryTreeNode<T>::isLeaf() const
{
	if (left == NULL && right == NULL)
		return 1;
	else
		return 0;
}

template<typename T>
BinaryTreeNode<T> BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> &Node)
{
    info=Node.info;

    return *this;
}

//BinaryTree

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::sibling(BinaryTreeNode<T> *current) const
{
	BinaryTreeNode<T> *p = current->parent;
	if (p == NULL)return NULL;
	else
		return p->left == current ? p->right : p->left;
}
template<typename T>
void BinaryTree<T>::createTree(const T &data, BinaryTreeNode<T> *l, BinaryTreeNode<T> *r)
{
	root->info = data;
	root->left = l;
	root->right = r;
}
template<typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *tmproot)
{
	stack<BinaryTreeNode<T> *> treeStack;
	BinaryTreeNode<T> *tmp = tmproot;
	treeStack.push(NULL);
	while (tmp)
	{
		cout << tmp->info << " ";
		if(tmp->right!=NULL)treeStack.push(tmp->right);
		if (tmp->left != NULL)tmp = tmp->left;
		else
		{
			tmp = treeStack.top();
			treeStack.pop();
		}
	}
	cout<<endl;
}
template<typename T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> *tmproot)
{
    stack<BinaryTreeNode<T> *>treeStack;
    BinaryTreeNode<T> *p=tmproot;
    while(!treeStack.empty() || p)
    {
        if(p)
        {
            treeStack.push(p);
            p=p->leftchild();
        }
        else
        {
            p=treeStack.top();
            treeStack.pop();
            cout<<p->value()<<" ";
            p=p->rightchild();
        }
    }
    cout<<endl;
}
template<typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *tmproot)
{
    stackElement<T> ele;
    stack<stackElement<T> >eleStack;
    BinaryTreeNode<T> *p=tmproot;
    if(tmproot==NULL)return;
    while(!eleStack.empty() || p!=NULL)
    {
        while(p!=NULL)
        {
            ele.pointer=p;
            ele.tag=L;
            eleStack.push(ele);
            p=p->leftchild();
        }
        ele=eleStack.top();
        eleStack.pop();
        if(ele.tag==L)
        {
            ele.tag=R;
            eleStack.push(ele);
            p=p->rightchild();
        }
        else
        {
            cout<<ele.pointer->value()<<" ";
            p=NULL;
        }


    }
    cout<<endl;
}
template<typename T>
void BinaryTree<T>::deleteTree(BinaryTreeNode<T> *tmproot)
{
	tmproot = NULL;
}

#endif // BINARYTREE_H_INCLUDED
