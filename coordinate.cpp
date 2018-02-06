#include<iostream>
#include<cmath>
#include"coordinate.h"
#include"sset.h"
using namespace std;

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
	double pi=3.1415926535898；
	double rad_1=lat*pi/180;
	double rad_2=des.lat*pi/180;
	double rad_3=abs(lng-des.lng)*pi/180;//转化为弧度制
	double cos_alpha=1-0.5*(pow(cos(rad_1),2)+pow(cos(rad_2),2))+cos(rad_1)*cos(rad_2)*cos(rad_3)-0.5*pow(sin(rad_1)-sin(rad_2),2);
	double alpha=acos(cos_alpha);
	return r*alpha;
}

int coord::neibor(coord x,double rr,sset<coord>s)
{
	int n=s.size();
	int num=0;
	for(int i=0;i<=n-1;i++)
	{
		if(x.distance(s[i])<=rr)num++;
	}
	return num;
}
