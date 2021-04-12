#ifndef KMP_H_INCLUDED
#define KMP_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

int *findNext(const string &P);
bool KMPExtMatching(const string &T,const string &P,int &pos);


int *findNext(const string &P)
{
    int k=-1;
    int m=P.length();
    int *next=new int[m];
    next[0]=-1;
    for(int i=1;i<m;++i)
    {
        while(k>=0 && P[k]!=P[i-1])
            k=next[k];
        ++k;
        if(P[i]==P[k]) next[i]=next[k];
        else next[i]=k;
    }
    return next;
}

bool KMPExtMatching(const string &T,const string &P,int &pos)
{
    int n=T.length();
    int m=P.length();
    int i=0;
    int j=0;
    if(m>n)
    {
        cout<<"pattern string is out of size";
        pos=-1;
        return false;
    }
    else
    {
        int *next=new int[m];
        next=findNext(P);
        while(j<n && i<m)
        {
            if(i!=-1 && T[j]!=P[i])
                i=next[i];
            ++j;
            ++i;
        }
        delete[] next;
        next=NULL;
        if(i==m)
        {
            pos=j-m;
            return true;
        }
        else
        {
            pos=-1;
            return false;
        }
    }
}


#endif // KMP_H_INCLUDED
