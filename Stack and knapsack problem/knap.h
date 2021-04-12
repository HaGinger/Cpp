#ifndef KNAP_H_INCLUDED
#define KNAP_H_INCLUDED


#include<iostream>
#include"arrStack.h"
using namespace std;

enum rdType {A=0,B=1,C=2};

class knapNode
{public :
    int s,n;
    rdType rd;
    bool k;
};
knapNode x,tmp;
arrStack<knapNode> stack;
bool nonRecKnap(int s,int *w,int n)
{
    tmp.s=s,tmp.n=n,tmp.rd=A;
    stack.push(tmp);
    label0:
        stack.pop(tmp);
        if(tmp.s == 0)
        {
            tmp.k=true;
            stack.push(tmp);
            goto label3;
        }
        if(tmp.s<0||(tmp.s>0&&tmp.n<1))
        {
            tmp.k=false;
            stack.push(tmp);
            goto label3;
        }
        stack.push(tmp);
        x.s=tmp.s-w[tmp.n-1];
        x.n=tmp.n-1;
        x.rd=B;
        stack.push(x);
        goto label0;

    label1:
        stack.pop(x);
        if(tmp.k==true)
        {
            x.k=true;
            stack.push(x);
            //cout<<w[x.n-1]<<" ";
            goto label3;
        }
        stack.push(x);
        tmp.s=x.s;
        tmp.n=x.n-1;
        tmp.rd=C;
        stack.push(tmp);
        goto label0;
    label2:
        stack.pop(x);
        x.k=tmp.k;
        stack.push(x);
    label3:
        stack.pop(tmp);
        switch(tmp.rd)
        {
            case A:cout<<endl;
                    return tmp.k;
            case B:goto label1;
            case C:goto label2;
        }
}



#endif // KNAP_H_INCLUDED
