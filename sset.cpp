#include<iostream>
#include"sset.h"
using namespace std;

sset::sset(int capacity)
{
	if(capacity == 0)//当初始容量为时
		m_ptr = NULL;//数组为空
	else
		m_ptr = new int[capacity];//为数组分配新空间
	m_size = 0;//起始数组中并没有元素
	m_capacity = capacity;//起始数组的容量
	clear();//为数组赋初值
 
}

void intSet::clear()
{
	for(int i = 0 ; i < m_capacity ;i++)
		m_ptr[i] = 0;
}

void sset::enlarge()
{
	//将当前数组空间扩充为（原有容量+1）*2
	//+1考虑，如果原来容量为，那么*2无效的情况
	m_capacity = (m_capacity+1) * 2;
    
	//下面复制原来数组的元素，到新分配的数组中
	sset * older = m_ptr;
	m_ptr = new sset[m_capacity];
 
	for(int i = 0 ; i < m_size ; i++)
		m_ptr[i] = older[i];
 
	//是否原有数组的空间
	if(older != NULL)
		delete [] older;
 
}

void sset::insert(sset item)
{
	//如果当前的数组已经填满
	if(m_size >= m_capacity)
	{
		enlarge();//扩充当前数组容量
	}
	//这个元素应该放到数组的最后
	m_ptr[m_size++] = item;
 
}

sset sset::operator[](int n)
{
	if(n>m_size-1)cerr<<"over number"<<endl;
	else
		return *(m_ptr+n);
}

int sset::size()
{
	return m_size;
}

sset::~sset(void)
{
	if(m_ptr != NULL)
		delete [] m_ptr;
}
