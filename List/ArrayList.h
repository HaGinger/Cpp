#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED
#include<iostream>
using namespace std;
template<typename T>
class arrList
{
    T *aList;
    int maxSize;
    int curLen;
    int position;

public:
    arrList(const int size)
    {
        maxSize=size;
        aList=new T[maxSize];
        curLen=position=0;
    }
    ~arrList(){delete[] aList;}

    void clear();

    int length();
    bool append(const T value);
    bool insert(const int p,const T value);
    bool delete_(const int p);
    bool setValue(const int p,const T value);
    bool getValue(const int p,T &value);
    bool getPos(int &p,const T value);
};

template<typename T>
void arrList<T>::clear()
{
    delete[] aList;
    curLen=position=0;
    aList=new T[maxSize];
}

template<typename T>
int arrList<T>::length()
{
    return curLen;
}

template<typename T>
bool arrList<T>::append(const T value)
{
    if(curLen>=maxSize)
    {
        cout<<"overflow"<<endl;
        return false;
    }
    aList[curLen]=value;
    ++curLen;
    return true;
}

template<typename T>
bool arrList<T>::insert(const int p,const T value)
{
    if(curLen>=maxSize)
    {
        cout<<"overflow"<<endl;
        return false;
    }
    if(p<0||p>curLen)
    {
        cout<<"position is illegal"<<endl;
        return false;
    }
    for(int i=curLen;i>p;++i)
        aList[i]=aList[i-1];
    aList[p]=value;
    ++curLen;
    return true;
}

template<typename T>
bool arrList<T>::delete_(const int p)
{
    if(curLen==0)
    {
        cout<<"empty list"<<endl;
        return false;
    }
    if(p<0||p>curLen-1)
    {
        cout<<"position is illegal"<<endl;
        return false;
    }
    for(int i=p;i<curLen;++i)
        aList[i]=aList[i+1];
    --curLen;
    return true;
}

template<typename T>
bool arrList<T>::setValue(const int p,const T value)
{
    if(p<0||p>curLen-1)
    {
        cout<<"position is illegal"<<endl;
        return false;
    }
    aList[p]=value;
    return true;
}

template<typename T>
bool arrList<T>::getValue(const int p,T &value)
{
    if(p<0||p>curLen-1)
    {
        cout<<"position is illegal"<<endl;
        return false;
    }
    value=aList[p];
    return true;
}

template<typename T>
bool arrList<T>::getPos(int &p,const T value)
{
    for(int i=0;i<curLen;++i)
        if(value==aList[i])
        {
            p=i;
            return true;
        }
    return false;
}

#endif // ARRAYLIST_H_INCLUDED
