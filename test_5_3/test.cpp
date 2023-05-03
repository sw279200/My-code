#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//点和圆的位置关系
class Point 
{
public:
	int get_x()//获取横坐标
	{
		return p_x;
	}
	void set_x(int x)//设置横坐标
	{
		p_x = x;
	}
	int get_y()//获取纵坐标
	{
		return p_y;
	}
	void set_y(int y)//设置纵坐标
	{
		p_y = y;
	}
private:
	int p_x;//横坐标
	int p_y;//纵坐标

};

class Circle
{
public:
	Point get_center()//获取圆心
	{
		return center;
	}
	void set_center(Point pc)//设置圆心
	{
		center = pc;
	}

	int getR()//获取半径
	{
		return radius;
	}
	void setR(int R)//设置半径
	{
		radius = R;
	}
private:
	Point center;
	int radius;
};


void Is_inCircle(Circle c, Point p)
{
	//求点到圆心距离的平方
	int distance =
		(c.get_center().get_x() - p.get_x()) * (c.get_center().get_x() - p.get_x()) +
		(c.get_center().get_y() - p.get_y()) * (c.get_center().get_y() - p.get_y());
	//再求半径的平方
	int Rdistance = (c.getR() * c.getR());

	if (Rdistance == distance)
	{
		cout << "点在圆上" << endl;
	}
	else if (Rdistance > distance)
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}
		
int main()
{	
	//创建一个点
	Point p;
	p.set_x(11);
	p.set_y(10);
	//创建一个圆
	Circle c;
	Point center;
	center.set_x(10);
	center.set_y(0);
	c.setR(10);
	c.set_center(center);

	//判断点和圆之间的位置关系
	Is_inCircle(c, p);
	return 0;
}