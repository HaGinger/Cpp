#ifndef KNAPOPT_H_INCLUDED
#define KNAPOPT_H_INCLUDED

#include<iostream>
#include"arrStack.h"
using namespace std;

enum rdType2 {A2=0,B2=1,C2=2};
class knapNode2
{
    public:
    int s;
    rdType2 rd;
};

bool nonRecKnapOpt(int s,int *w,int n)
{
    knapNode2 x,tmp;
    arrStack<knapNode2> stack;
    int t,n0=n;
    bool k=false;

    tmp.s=s,tmp.rd=A2;
    stack.push(tmp);

    while(!stack.isEmpty())
    {
        t=stack.top_pos;
        stack.top(tmp);
        while((tmp.s>=0) && (tmp.s <=0 || n0>t))
        {
            if(tmp.s ==0 )
            {
                k=true;
                break;
            }
            else
            {
                x.s=tmp.s-w[n0-1-t];
                x.rd=B2;
                stack.push(x);
            }
            t=stack.top_pos;
            stack.top(tmp);
        }
        while(!stack.isEmpty())
        {
            stack.pop(tmp);
            t=stack.top_pos;
            if(tmp.rd==A2){return k;}
            if(tmp.rd==B2)
                if(k==true)
                    {k=true;}//cout<<w[n0-1-t]<<" ";}
                else
                {
                    stack.top(x);
                    tmp.s=x.s;
                    tmp.rd=C2;
                    stack.push(tmp);
                    break;
                }
        }
    }

}



#endif // KNAPOPT_H_INCLUDED
