#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include"stdlib.h"
#include<time.h>

using namespace std;

template<typename T>
class Matrix
{
    T *_head;//第一个元素的地址
    int _row;//行数
    int _colm;//列数

    void MakeEmpty();//置为空矩阵
    Matrix(int m,int n,T *a);

public:
	Matrix() :_row(1), _colm(1) { _head = new T[1]; }
    Matrix(int m,int n);
    Matrix(int m,int n,vector<T> a);
    Matrix(const Matrix<T> &copy_A);
    ~Matrix();

    bool getrow(int m,Matrix<T> &a);
    bool getcolm(int n,Matrix<T> &b);
    bool setrow(int m,Matrix<T> &a);
    bool setcolm(int n,Matrix<T> &b);
    bool change(int m,int n);
    void trans();//转置
    void top();//化为上三角形矩阵
    void diag();//化为对角型矩阵
    void inver();//逆矩阵
    void random(double a,double b);//随机生成每个元素在(a,b)的矩阵

    void MakeZero();//置为0矩阵
    void MakeOne();
	void SetValue(const T &value);
	void SetValue(Matrix<T> value);

    int row() const{return _row;}
    int colm() const{return _colm;}
    int rank()const;//矩阵的秩
    T det()const;//行列式的值
    T _2norm();
    T maxele()const;//返回最大元素绝对值

    T *operator[](int m)const;
    void operator=(const Matrix<T> &eql_B);
    Matrix<T> operator+(const Matrix<T> &plus_B);
    Matrix<T> operator-(const Matrix<T> &plus_B);
    Matrix<T> operator*(const Matrix<T> &mul_B);
    Matrix<T> operator*(const T &mul_t);
    Matrix<T> operator/(const T &dev_t);

    bool MQRD(Matrix<T> &Q,Matrix<T> &R);
    bool CQRD(Matrix<T> &Q,Matrix<T> &R);
    bool eigen(Matrix<T> &V,Matrix<T> &Ei);
    bool SVD(Matrix<T> &U,Matrix<T> &Sigma,Matrix<T> &V);
    bool SVD(Matrix<T> &Sigma);

    void print();
    void ex();

};

template<typename T>
Matrix<T>::Matrix(int m,int n)
{
    _head=new T[m*n];
    _row=m;
    _colm=n;
}

template<typename T>
Matrix<T>::Matrix(int m,int n,T *a)
{
    _head=a;
    _row=m;
    _colm=n;
}

template<typename T>
Matrix<T>::Matrix(int m,int n,vector<T> a)
{
    int num=a.size();
    if(num!=m*n)
    {
        cout<<"num doesnt match"<<endl;
        exit(0);
    }
    else _head=new T[m*n];
    for(int i=0;i<=m*n-1;i++)
    {
        *(_head+i)=a[i];
    }
    _row=m;
    _colm=n;
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &copy_A)
{

    _head=new T[copy_A._row*copy_A._colm];
    for(int i=0;i<=copy_A._row*copy_A._colm-1;i++)
    *(_head+i)=*(copy_A._head+i);
    _row=copy_A._row;
    _colm=copy_A._colm;

}

template<typename T>
Matrix<T>::~Matrix()
{
    delete[] _head;
    _head=NULL;
}

template<typename T>
void Matrix<T>::MakeEmpty()
{
    if(_head!=NULL)_head=NULL;
}

template<typename T>
void Matrix<T>::MakeZero()
{
    for(int i=0;i<=_row*_colm-1;i++)*(_head+i)=T(0);
}

template<typename T>
void Matrix<T>::MakeOne()
{
    for(int i=0;i<=_row*_colm-1;i++)*(_head+i)=T(1);
}

template<typename T>
void Matrix<T>::SetValue(const T &value)
{
	for (int i = 0; i < _row*_colm; ++i)
		*(_head + i) = value;
}

template<typename T>
void Matrix<T>::SetValue(Matrix<T> value)
{
	for (int i = 0; i < _row*_colm; ++i)
			*(_head+i) = *(value._head+i);
}

template<typename T>
bool Matrix<T>::getrow(int m,Matrix<T> &a)
{
    if(m>_row-1 || a._row>1 || a._colm!=_colm)return false;
    else
    {
        for(int i=0;i<_colm;++i)
        {
            *(a._head+i)=*(_head+m*_colm+i);
        }
        return true;
    }
}

template<typename T>
bool Matrix<T>::getcolm(int n,Matrix<T> &b)
{
    if(n>_colm-1 || b._colm>1 || b._row!=_row)return false;
    else
    {
        for(int i=0;i<_row;++i)
        {
            b[i][0]=_head[i*_colm+n];
        }
        return true;
    }
}

template<typename T>
bool Matrix<T>::setrow(int m,Matrix<T> &a)
{
    if(m>_row-1 || a._row>1 || a._colm!=_colm)return false;
    else
    {
        for(int i=0;i<_colm;++i)
        {
            _head[m*_colm+i]=a[0][i];
        }
        return true;
    }
}

template<typename T>
bool Matrix<T>::setcolm(int n,Matrix<T> &b)
{
    if(n>_colm-1 || b._colm>1 || b._row!=_row)return false;
    else
    {
        for(int i=0;i<_row;++i)
        {
            _head[i*_colm+n]=b[i][0];
        }
        return true;
    }
}

template<typename T>
bool Matrix<T>::change(int m,int n)
{
    if(_row==m && _colm==n)return false;
    else{
            delete[] _head;
            _row=m;
            _colm=n;
            _head=new T[m*n];
            return true;
        }
}

template<typename T>
void Matrix<T>::trans()
{
    T *a=new T[_row*_colm];
    for(int i=0;i<=_row*_colm-1;i++)a[i]=*(_head+i);
    for(int j=0;j<=_colm-1;j++)
    {
        for(int i=0;i<=_row-1;i++)
        {
            *(_head+j*_row+i)=a[i*_colm+j];
        }
    }
    delete[] a;
    a=NULL;
    int __row=_row;
    _row=_colm;
    _colm=__row;
}

template<typename T>
void Matrix<T>::top()
{
    T *temp=new T[_colm];
    int count;
    for(int k=0;k<=min(_row,_colm)-2;k++)
    {
        count=k;
        temp[0]=*(_head+count*_colm+k);
        while(count<_row-1 && temp[0]==0)//回去看看
        {
            ++count;
            temp[0]=*(_head+count*_colm+k);
        }
        if(temp[0]!=0)
        {
            for(int j=k;j<_colm;++j)
            {
                temp[j-k]=*(_head+count*_colm+j);
                *(_head+count*_colm+j)=*(_head+k*_colm+j);
                *(_head+k*_colm+j)=temp[j-k];
            }
            for(int i=k+1;i<=_row-1;i++)
            {
                temp[0]=*(_head+i*_colm+k);

                for(int j=k;j<=_colm-1;j++)
                {
                    *(_head+i*_colm+j)-=*(_head+k*_colm+j)/(*(_head+k*_colm+k))*temp[0];
                }
            }
        }
    }
    delete[] temp;
    temp=NULL;
    if(_row>_colm)
    {
        for(int i=_colm+1;i<=_row;i++)
            *(_head+i*_colm-1)=0;
    }
}

template<typename T>
void Matrix<T>::diag()
{
    this->top();
    this->trans();
    this->top();
    this->trans();
}

template<typename T>
void Matrix<T>::ex()
{


}

template<typename T>
void Matrix<T>::inver()
{

    if(_colm!=_row)
    {
        cerr<<"mathematical error"<<endl;
        exit(0);
    }
    T *b=_head;
    T *a=new T[_row*_colm*2];
    for(int i=0;i<=_row-1;++i)
    {
        for(int k=0;k<_colm;++k)
        {
            a[i*_colm*2+k]=*(_head+i*_colm+k);
        }
        for(int j=_colm;j<=_colm*2-1;++j)
        {
            a[i*_colm*2+j]=0;
            if(i==j-_colm)a[i*_colm*2+j]=1;

        }
    }
    _head=a;
    _colm*=2;
    this->top();
    for(int i=0;i<_row;i++)
    {
        if(*(_head+i*_colm+i)==0)
        {
            delete[] a;
            a=NULL;
            cerr<<"rank is not full"<<endl;
            exit(0);
        }
    }
    _colm/=2;
    T temp;

    temp=a[(_row-1)*_colm*2+_colm-1];
    for(int i=0;i<_colm;i++)
    {
        a[_row*_colm*2-1-i]/=temp;
    }
    for(int j=1;j<=_row-1;++j)
    {

        for(int k=0;k<=j-1;++k)
        {
            temp=a[(_row-1-j)*_colm*2+_colm-1-k];
            for(int i=0;i<=_colm-1;++i)
            {
                a[(_row-j)*_colm*2-1-i]-=temp*a[(_row-k)*_colm*2-1-i];
            }
        }
        temp=a[(_row-1-j)*_colm*2+_colm-1-j];
        for(int i=0;i<_colm;++i)
        {
            a[(_row-j)*_colm*2-1-i]/=temp;
        }
    }
    for(int i=0;i<=_row-1;++i)
    {
        for(int j=0;j<=_colm-1;++j)
        {
            b[i*_colm+j]=a[i*_colm*2+_colm+j];
        }
    }
    delete[] a;
    a=NULL;
    _head=b;
    b=NULL;
}

template<typename T>
void Matrix<T>::random(double a,double b)
{
    srand((unsigned)time(NULL));
    for(int i=0;i<_row;++i)
        for(int j=0;j<_colm;++j)
            _head[i*_colm+j]=(rand()%RAND_MAX)*(b-a)/RAND_MAX+a;
}

template<typename T>
int Matrix<T>::rank()const
{
    int _rank=0;
    for(int i=0;i<=min(_row,_colm)-1;i++)
    {
        if(*(_head+i*_colm+i)!=0)_rank++;
    }
    return _rank;
}

template<typename T>
T Matrix<T>::det()const
{
    if(_row!=_colm)
    {
        cerr<<"mathematical error"<<endl;
        exit(0);
    }

    Matrix<T> copy_A(*this);
    copy_A.diag();
    T _det=1;
    for(int i=0;i<=_row-1;++i)
    {
        _det*=*(copy_A._head+i*_colm+i);
    }
    return _det;
}


template<typename T>
T Matrix<T>::_2norm()
{
    T sum=0;
    if(_colm==1 || _row==1)
    {
        for(int i=0;i<_row*_colm;++i)
        {
            sum+=_head[i]*_head[i];
        }
        return pow(sum,0.5);
    }

    else exit(0);
}
template<typename T>
T Matrix<T>::maxele()const
{
    T m=abs(_head[0]);
    T n;
    for(int i=1;i<_row*_colm;++i)
    {
        n=abs(_head[i]);
        m=max(m,n);
    }
    return m;
}

template<typename T>
T* Matrix<T>::operator[](int m)const
{
    if(m>_row-1)
    {
        cerr<<"illegal position"<<endl;
        exit(0);
    }
    return _head+m*_colm;
}

template<typename T>
void Matrix<T>::operator=(const Matrix<T> &eql_B)
{
    if(_head!=NULL)delete[] _head;
    _head=new T[eql_B._colm*eql_B._row];
    for(int i=0;i<=eql_B._colm*eql_B._row-1;i++)
    {
        *(_head+i)=*(eql_B._head+i);
    }
    _colm=eql_B._colm;
    _row=eql_B._row;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &plus_B)
{
    if(!(_row==plus_B._row && _colm==plus_B._colm))
    {
        cerr<<"num doesnt match"<<endl;
        exit(0);
    }
    Matrix<T> sum_C(_row,_colm);
    for(int i=0;i<_row;i++)
        for(int j=0;j<_colm;++j)
            sum_C[i][j]=*(_head+i*_colm+j)+plus_B[i][j];
    return sum_C;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &plus_B)
{
    if(!(_row==plus_B._row && _colm==plus_B._colm))
    {
        cerr<<"num doesnt match"<<endl;
        exit(0);

    }
    Matrix<T> sum_C(_row,_colm);
    for(int i=0;i<_row;i++)
        for(int j=0;j<_colm;++j)
            sum_C[i][j]=*(_head+i*_colm+j)-plus_B[i][j];
    return sum_C;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &mul_B)
{
    if(_colm!=mul_B._row)
    {
        cerr<<"mathematical error"<<endl;
        exit(0);
    }
    Matrix<T> mul_C(_row,mul_B._colm);
    T sum;
    for(int i=0;i<=_row-1;i++)
        for(int k=0;k<=mul_B._colm-1;k++)
        {
            sum=0;
            for(int j=0;j<=_colm-1;j++)
                sum+=*(_head+i*_colm+j)*mul_B[j][k];
            mul_C[i][k]=sum;
        }
    return mul_C;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &mul_t)
{
    Matrix<T> mul_C(_row,_colm);
    for(int i=0;i<_row;++i)
        for(int j=0;j<_colm;++j)
            mul_C[i][j]=*(_head+i*_colm+j)*mul_t;
    return mul_C;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T &dev_t)
{
    Matrix<T> mul_C(_row,_colm);
    for(int i=0;i<_row;++i)
        for(int j=0;j<_colm;++j)
            mul_C[i][j]=*(_head+i*_colm+j)/dev_t;
    return mul_C;
}

template<typename T>
bool Matrix<T>::MQRD(Matrix<T> &Q,Matrix<T> &R)
{
    if(_row<_colm || this->rank()<_colm) return false;
    else
    {
        Q.change(_row,_colm);
        R.change(_colm,_colm);
        Matrix<T> copy_A(*this);
        Matrix<T> temp_v(_row,1);
        T sum=0;
        for(int i=0;i<_colm;++i)
        {
            copy_A.getcolm(i,temp_v);
            R[i][i]=temp_v._2norm();
            Matrix<T> temp_q(temp_v/R[i][i]);
            Q.setcolm(i,temp_q);
            for(int j=i+1;j<_colm;++j)
            {
                copy_A.getcolm(j,temp_v);
                sum=0;
                for(int k=0;k<_row;++k)
                {
                    sum+=temp_q[k][0]*temp_v[k][0];
                }
                R[i][j]=sum;
                Matrix<T> yyy(temp_q*R[i][j]);
                Matrix<T> zzz(temp_v-yyy);
                copy_A.setcolm(j,zzz);
            }
        }
        return true;
    }
}

template<typename T>
bool Matrix<T>::CQRD(Matrix<T> &Q,Matrix<T> &R)
{
    if(_row<_colm || this->rank()<_colm) return false;
    else
    {
        Q.change(_row,_colm);
        R.change(_colm,_colm);
        Matrix<T> temp_v(_row,1);
        Matrix<T> temp_q(_row,1);
        Matrix<T> temp_a(_row,1);
        T sum;
        for(int i=0;i<_colm;++i)
        {
            this->getcolm(i,temp_v);
            for(int j=0;j<i;++j)
            {
                this->getcolm(i,temp_a);
                Q.getcolm(j,temp_q);
                sum=0;
                for(int k=0;k<_row;++k)
                    sum+=temp_a[k][0]*temp_q[k][0];
                R[j][i]=sum;
                Matrix<T> xxx(temp_q*sum);
                Matrix<T> yyy(temp_v-xxx);
                temp_v=yyy;
            }
            for(int j=i+1;j<_colm;++j)
                R[j][i]=0;
            R[i][i]=temp_v._2norm();
            Matrix<T> zzz(temp_v/R[i][i]);
            Q.setcolm(i,zzz);

        }
        return true;
    }
}
/*
template<typename T>
bool Matrix<T>::eigen(Matrix<T> &V,Matrix<T> &Ei)
{

}

template<typename T>
bool Matrix<T>::SVD(Matrix<T> &U,Matrix<T> &Sigma,Matrix<T> &V)
{

}

template<typename T>
bool Matrix<T>::SVD(Matrix<T> &Sigma)
{

}
*/





template<typename T>
void Matrix<T>::print()
{
    for(int i=0;i<=_row*_colm-1;i++)
    {
        cout<<setw(sizeof(T)+2)<<*(_head+i);
        if((i+1)%_colm==0)cout<<endl;
    }
}



#endif // MATRIX_H_INCLUDED
