#ifndef COORDINATE_H_INCLUDED
#define COORDINATE_H_INCLUDED

#include<cmath>
#include"sset.h"
class coord//同一半球且不跨本初子午线
{
	double a;//赤道半径
	double b;//极半径
	double r;//平均半径
	double lng;//经度
	double lat;//纬度

public:
	coord();
	coord(double x,double y);
	~coord();
	double distance(coord des);
	int neibor(double rr,sset<coord> s);
};

coord::coord()
{
	lat=0;
	lng=0;
	a=6378137;//赤道半径
	b=6356752;//极半径
	r=pow(a*a*b,1.0/3);//平均半径
}
coord::coord(double x,double y)//初始化经纬度
{
	lat=x;
	lng=y;
	a=6378137;//赤道半径
	b=6356752;//极半径
	r=pow(a*a*b,1.0/3);//平均半径
}

coord::~coord(){}

double coord::distance(coord des)//根据经纬度计算两点间距离（目前是近似为球体）
{
	double pi=3.1415926535898;
	double rad_1=lat*pi/180;
	double rad_2=des.lat*pi/180;
	double rad_3=abs(lng-des.lng)*pi/180;//转化为弧度制
	double cos_alpha=1-0.5*(pow(cos(rad_1),2)+pow(cos(rad_2),2))+cos(rad_1)*cos(rad_2)*cos(rad_3)-0.5*pow(sin(rad_1)-sin(rad_2),2);
	double alpha=acos(cos_alpha);
	return r*alpha;
}

int coord::neibor(double rr,sset<coord> s)//计算集合s中与其距离小于等于rr的元素个数
{
	int n=s.size();
	int num=0;
	for(int i=0;i<=n-1;i++)
	{
		if(distance(s[i])<=rr)num++;
	}
	return num;
}

#endif // COORDINATE_H_INCLUDED
