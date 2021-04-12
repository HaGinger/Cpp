#include <iostream>
#include"Matrix.h"
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int n=80;
    vector< double> u,v;
    srand((unsigned)3);
    for(int i=0;i<n*n;++i)
        u.push_back(rand()/(double)(RAND_MAX));
    srand((unsigned)44);
    for(int i=0;i<n*n;++i)
        v.push_back(rand()/( double)(RAND_MAX));
    Matrix< double> U(n,n,u);
    Matrix< double> V(n,n,v);
    Matrix< double> S(n,n);
    S.MakeZero();

    for(int i=0;i<n;++i)
        S[i][i]=pow(2,-i-1);

    Matrix< double> x(U*S);

    Matrix< double> A(x*V);

    Matrix< double> QC,RC,QM,RM;

    A.CQRD(QC,RC);
    A.MQRD(QM,RM);
    double *rm=new double[n];
    double *rc=new double[n];
    //int a=8;
    //int b=10;
    for(int i=0;i<n;++i)
    {
        rc[i]=log(RC[i][i])/log(10);
        //cout<<setw(10)<<-(log(RC[i][i])/log(10));
    }
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        rm[i]=log(RM[i][i])/log(10);
        //cout<<setw(10)<<(log(RM[i][i])/log(10));
    }
    ofstream o;
    o.open("a.txt");
    for(int i=0;i<n;++i)
        o<<rc[i]<<" ";
    o<<endl;
    for(int i=0;i<n;++i)
        o<<rm[i]<<" ";

    /*for(int i=0;i<25*a;++i)
    {
        if(i%5*a==0)o<<setw(6)<<"10^-"<<setw(2)<<i/a;
        if(i%5*a!=0)o<<"        ";

        if(i%a!=0)o<<"|";
        if(i%a==0)o<<"+";
        int front=-1;
        int last=0;
        for(int j=0;j<n;++j)
        {
            if((i-2==rc[j] && i-2==rm[j]) || (i+2==rc[j] && i+2==rm[j]))
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"* * * * *";
            }
            else if((i+1==rc[j] && i+1==rm[j]) || (i-1==rc[j] && i-1==rm[j]))
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"* *   * *";
            }
            else if((i==rc[j] && i==rm[j]))
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"*   *   *";
            }

            else if(i+2==rc[j] || i-2==rc[j] )
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"* * * * *";
            }
            else if(i+1==rc[j] || i-1==rc[j])
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"*       *";
            }
            else if(i==rc[j])
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"*   *   *";
            }
            else if(i+2==rm[j] || i-2==rm[j])
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"*       *";
            }
            else if(i+1==rm[j] || i-1==rm[j])
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"*   *";
            }
            else if(i==rm[j])
            {
                last=(j+1)*b;
                o<<setw(last-front)<<"  *  ";
            }
            front=last;
        }
        o<<endl;
    }
    o<<setw(6)<<"10^-"<<25;
    for(int i=0;i<n*b;++i)
    {
        if(i%(10*b)==0)o<<"+";
        else o<<"-";
    }
    o<<endl;
    o<<"        0";
    for(int i=1;i<n/10;++i)
    {
        o<<setw(10*b)<<i*10;
    }*/
    o.close();
    delete[] rm;
    delete[] rc;
    rm=NULL;
    rc=NULL;
return 0;
}
