#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class Link
{
public:
    T data;
    Link<T> *next;
    Link(const T goumt,Link<T> *nextValue=NULL)
    {
        data=goumt;
        next=nextValue;
    }
    Link(Link<T> *nextValue)
    {
        next=nextValue;
    }
    Link(){next=NULL;}
};

template<typename T>
class lnkList
{
    Link<T> *head,*tail;
    Link<T> *setPos(const int pos);

public:
    lnkList();
    ~lnkList();

    bool isEmpty();
    void clear();
    void print();

    int length();
    bool append(const T value);
    bool insert(const int pos,const T value);
    bool delete_(const int pos);
    bool setValue(const int pos,const T value);
    bool getValue(const int pos,T &value);
    bool getPos(int &pos,const T value);
};

template<typename T>
Link<T> *lnkList<T>::setPos(const int pos)
{
    if(pos==-1)return head;
    Link<T> *p=head;
    int count=-1;
    while(p!=NULL && count<pos)
    {
        p=p->next;
        ++count;
    }
    return p;
}
template<typename T>
lnkList<T>::lnkList()
{
    head=tail=new Link<T>;
}

template<typename T>
lnkList<T>::~lnkList()
{
    Link<T> *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        delete temp;
    }
}

template<typename T>
bool lnkList<T>::isEmpty()
{
    if(head->next=NULL)return true;
    return false;
}

template<typename T>
void lnkList<T>::clear()
{
    Link<T> *p=head->next;
    head->next=NULL;
    Link<T> *temp;
    while(p!=NULL)
    {
        temp=p;
        p=p->next;
        delete temp;
    }
}

template<typename T>
void lnkList<T>::print()
{
    if(head->next==NULL)
    {
        cout<<"empty list"<<endl;
    }
    Link<T> *p=head->next;
    while(p!=NULL)
    {
        cout<<setw(5)<<p->data;
        p=p->next;
    }
    cout<<endl;
}
template<typename T>
int lnkList<T>::length()
{
    Link<T> *p=head->next;
    int count=0;
    while(p!=NULL)
    {
        p=p->next;
        ++count;
    }
    return count;
}

template<typename T>
bool lnkList<T>::append(const T value)
{

    Link<T> *newlink=new Link<T>(value,NULL);
    tail->next=newlink;
    tail=newlink;
    return true;
}

template<typename T>
bool lnkList<T>::insert(const int pos,const T value)
{
    Link<T> *p,*q;
    p=setPos(pos-1);
    if(p==NULL)
    {
        cout<<"illegal position"<<endl;
        return false;
    }
    q=new Link<T>(value,p->next);
    p->next=q;
    if(p==tail)
        tail=q;
    return true;
}

template<typename T>
bool lnkList<T>::delete_(const int pos)
{
    Link<T> *p,*q;
    p=setPos(pos-1);

    if(p==NULL||p->next==NULL||pos<0)
    {
        cout<<"illegal position"<<endl;
        return false;
    }
    q=p->next;
    if(q->next==NULL)
    {
        tail=p;
        p->next=NULL;
        delete q;
    }
    else
    {
        p->next=q->next;
        delete q;
    }
    return true;
}

template<typename T>
bool lnkList<T>::getValue(const int pos,T &value)
{
    Link<T> *p=setPos(pos);
    if(p==NULL)
    {
        cout<<"illegal position"<<endl;
        return false;
    }
    value=p->data;
    return true;
}

template<typename T>
bool lnkList<T>::getPos(int& pos,const T value)
{
    int count=0;
    Link<T> *p=head->next;
    while(p!=NULL && p->data!=value)
    {
        p=p->next;
        ++count;
    }
    if(p==NULL)
    {
        cout<<"no such value"<<endl;
        return false;
    }
    pos=count;
    return true;
}

#endif // LINKLIST_H_INCLUDED
