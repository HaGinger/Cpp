#include <iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cmath>
#include"arrStack.h"
//#include"Calculator.h"
#include"knap.h"
#include"knapopt.h"
#include<time.h>
using namespace std;

bool knap(int s,int *w,int n);

int main()
{
    int N=25;
    int m=333;
    int *w=new int[N];

    for(int i=0;i<N;++i)
        w[i]=2*(i+1);

    clock_t startTime,endTime;

    startTime = clock();
    nonRecKnapOpt(m,w,N);
    cout<<endl;
    endTime = clock();
    cout << "ÓÅ»¯Õ»Total Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    startTime = clock();
    nonRecKnap(m,w,N);
    endTime = clock();
    cout << "Õ»Total Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;


    startTime = clock();
    knap(m,w,N);
    cout<<endl;
    endTime = clock();
    cout << "µÝ¹éTotal Time : " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

    delete[] w;
    w=NULL;
}


bool knap(int s,int* w,int n)
{
    if(s == 0)return true;
    if(s<0 || (s>0 && n<1))return false;
    if(knap(s-w[n-1],w,n-1))
    {
        cout<<w[n-1]<<" ";
        return true;
    }
    else return knap(s,w,n-1);
}
