

class sset
{
	sset * m_ptr;//数组头指针
	int m_size;//数组实际数据元素个数
	int m_capacity;//数组当前容量
	
	void clear();//清空（或使用初始化数组中的所有元素）
	void enlarge();//扩充数组容量
	
public:
	sset(int capacity = 0);//构造函数，默认初始元素为//intSet();
	~sset(void);
	void insert(sset item);
	sset operator[](int n);
	int size();
};

