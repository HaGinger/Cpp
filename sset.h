

class sset
{
	int * m_ptr;//数组头指针
	int m_size;//数组实际数据元素个数
	int m_capacity;//数组当前容量
	
	void clear();//清空（或使用初始化数组中的所有元素）
	void moveItems(int index);//将index之后的所有元素，向后移动一个位置
	void enlarge();//扩充数组容量
	
public:
	sset(int capacity = 0);//构造函数，默认初始元素为//intSet();
	sset(const sset & set);//赋值（拷贝）构造函数
	~sset(void);
	int size();
};

sset::~sset(void)
{
	if(m_ptr != NULL)
		delete [] m_ptr;
}
