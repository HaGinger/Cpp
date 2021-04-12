#ifndef DLINKLIST_H_INCLUDED
#define DLINKLIST_H_INCLUDED

#include<iostream>
#include<iomanip>
using namespace std;

template<typename T>
class DLink
{
public:
    T data;
    DLink<T> *next;
    DLink<T> *prev;

    DLink(const T value,DLink<T> *prevLink,DLink<T> *nextLink)
    {
        data=value;
        next=nextLink;
        prev=prevLink;
    }
    DLink(const T value):data(value),prev(NULL),next(NULL){}
    DLink(DLink<T> *prevLink,DLink<T> *nextLink):prev(prevLink),next(nextLink){}
    DLink():prev(NULL),next(NULL){}

};

template<typename T>
class DlnkList
{
    DLink<T> *head;
    DLink<T> *tail;

    DLink<T> *setPos(const int pos);


public:
    DlnkList();
    ~DlnkList();

    bool insert(const int pos,const T value);
    bool delete_(const int pos);
    void print();
};


template<typename T>
DLink<T> *DlnkList<T>::setPos(const int pos)
{
    if(pos==-1)return head;
    DLink<T> *p=head;
    int count=-1;
    while(p!=NULL && count<pos)
    {
        p=p->next;
        ++count;
    }
    return p;
}

template<typename T>
DlnkList<T>::DlnkList()
{
    head=tail=new DLink<T>;
}

template<typename T>
DlnkList<T>::~DlnkList()
{
    DLink<T> *p;
    while(head!=NULL)
    {
        p=head;
        head=head->next;
        p->prev=NULL;
        p->next=NULL;
        delete p;
    }
}

template<typename T>
bool DlnkList<T>::insert(const int pos,const T value)
{
    DLink<T> *p,*newList;
    p=setPos(pos-1);
    if(p==NULL)
    {
        cout<<"illegal position"<<endl;
        return false;
    }
    newList=new DLink<T>(value,p,p->next);
    p->next=newList;
    if(newList->next!=NULL)
    {
        (newList->next)->prev=newList;
        return true;
    }
    tail=newList;
    return true;
}

template<typename T>
bool DlnkList<T>::delete_(const int pos)
{
    DLink<T> *p=setPos(pos);
    if(pos<0||p==NULL)
    {
        cout<<"illegal position"<<endl;
        return false;
    }
    DLink<T> *q=p->prev;
    q->next=p->next;

    if(p->next==NULL)
    {
        tail=q;
    }
    else (p->next)->prev=q;
    p->next=NULL;
    p->prev=NULL;
    delete p;
    return true;
}

template<typename T>
void DlnkList<T>::print()
{
    if(head->next==NULL)
    {
        cout<<"empty list"<<endl;
    }
    DLink<T> *p=head->next;
    while(p!=NULL)
    {
        cout<<setw(5)<<p->data;
        p=p->next;
    }
    cout<<endl;
}
#endif // DLINKLIST_H_INCLUDED
