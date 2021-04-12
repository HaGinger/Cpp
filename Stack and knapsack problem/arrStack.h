#ifndef ARRSTACK_H_INCLUDED
#define ARRSTACK_H_INCLUDED

#include<iostream>

using namespace std;

template<typename T>
class arrStack
{
    int max_size;

    T *st_arr;

public:
    int top_pos;
    arrStack(int size);
    arrStack(){max_size=1;top_pos=-1;st_arr=new T[1];}
    ~arrStack();

    void clear(){top_pos=-1;}
    bool isEmpty(){if(top_pos==-1)return true;else return false;}
    bool isFull(){if(top_pos==max_size-1)return true;else return false;}

    bool push(const T value);
    bool pop(T &value);
    bool top(T &value);
};

template<typename T>
arrStack<T>::arrStack(int size)
{
    max_size=size;
    top_pos=-1;
    st_arr=new T[size];
}

template<typename T>
arrStack<T>::~arrStack()
{
    delete[] st_arr;
}

template<typename T>
bool arrStack<T>::push(const T value)
{
    if(isFull())
    {
        max_size*=2;
        T *newarr=new T[max_size];
        for(int i=0;i<=top_pos;++i)
            newarr[i]=st_arr[i];
        delete[] st_arr;
        st_arr=newarr;
    }
    st_arr[++top_pos]=value;
    return true;
}

template<typename T>
bool arrStack<T>::pop(T &value)
{
    if(isEmpty())
    {
        cout<<"empty stack"<<endl;
        return false;
    }
    value=st_arr[top_pos--];
    return true;
}

template<typename T>
bool arrStack<T>::top(T &value)
{
    if(top_pos==-1)
    {
        cout<<"empty stack"<<endl;
        return false;
    }
    value=st_arr[top_pos];
    return true;
}

#endif // ARRSTACK_H_INCLUDED
