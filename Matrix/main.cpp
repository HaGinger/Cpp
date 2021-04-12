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

   
    o.close();
    delete[] rm;
    delete[] rc;
    rm=NULL;
    rc=NULL;
return 0;
}
