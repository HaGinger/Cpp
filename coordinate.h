

class coord//同一半球且不跨本初子午线
{
	double a;//赤道半径
	double b;//极半径
	double r;//平均半径
	double lng;//经度
	double lat;//纬度
    
public:
	coord(double x,double y);
	~coord();
	double distance(coord des);
	int neibor(coord x,double rr,sset<coord>s);
};
