#ifndef SSET_H_INCLUDED
#define SSET_H_INCLUDED



using namespace std;


template<typename T>
class sset
{
	T *m_ptr;//数组头指针
	int m_size;//数组实际数据元素个数
	int m_capacity;//数组当前容量
	void clear();
	void enlarge();
public:
	sset(int capacity = 0);
	~sset();
	void insert(T item);
	T operator[](int n);
	int size();
};


template<typename T>
void sset<T>::clear()
{
    T b;
	for(int i = 0 ; i < m_capacity ;i++)
		*(m_ptr+i) = b;
}//清空（或使用初始化数组中的所有元素）

template<typename T>
void sset<T>::enlarge()
{
	//将当前数组空间扩充为（原有容量+1）*2
	//+1考虑，如果原来容量为，那么*2无效的情况
	m_capacity = (m_capacity+1) * 2;

	//下面复制原来数组的元素，到新分配的数组中
	T * older = m_ptr;
	m_ptr = (T*)operator new(sizeof(T)*m_capacity);

	for(int i = 0 ; i < m_size ; i++)
		*(m_ptr+i) = *(older+i);

	//是否原有数组的空间
	if(older != NULL)
		operator delete(older);
		older = NULL;

}//扩充数组容量

template<typename T>
sset<T>::sset(int capacity)
{

    if(capacity == 0)//当初始容量为时
        m_ptr = NULL;//数组为空
	else
		m_ptr = (T*)operator new(sizeof(T)*capacity);//为数组分配新空间
	m_size = 0;//起始数组中并没有元素
	m_capacity = capacity;//起始数组的容量
	clear();//为数组赋初值

}//构造函数，默认初始元素为//sset();

template<typename T>
sset<T>::~sset()
{
	if(m_ptr != NULL)
		operator delete(m_ptr);
		m_ptr = NULL;
}

template<typename T>
void sset<T>::insert(T item)
{
	//如果当前的数组已经填满
	if(m_size >= m_capacity)
	{
		enlarge();//扩充当前数组容量
	}
	//这个元素应该放到数组的最后
	*(m_ptr+m_size) = item;
	m_size++;

}

template<typename T>
T sset<T>::operator[](int n)
{
	if(n>m_size-1)cerr<<"over number"<<endl;
	else
		return *(m_ptr+n);
}

template<typename T>
int sset<T>::size()
{
	return m_size;
}



#endif // SSET_H_INCLUDED

