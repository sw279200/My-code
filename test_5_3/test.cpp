#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//���Բ��λ�ù�ϵ
class Point 
{
public:
	int get_x()//��ȡ������
	{
		return p_x;
	}
	void set_x(int x)//���ú�����
	{
		p_x = x;
	}
	int get_y()//��ȡ������
	{
		return p_y;
	}
	void set_y(int y)//����������
	{
		p_y = y;
	}
private:
	int p_x;//������
	int p_y;//������

};

class Circle
{
public:
	Point get_center()//��ȡԲ��
	{
		return center;
	}
	void set_center(Point pc)//����Բ��
	{
		center = pc;
	}

	int getR()//��ȡ�뾶
	{
		return radius;
	}
	void setR(int R)//���ð뾶
	{
		radius = R;
	}
private:
	Point center;
	int radius;
};


void Is_inCircle(Circle c, Point p)
{
	//��㵽Բ�ľ����ƽ��
	int distance =
		(c.get_center().get_x() - p.get_x()) * (c.get_center().get_x() - p.get_x()) +
		(c.get_center().get_y() - p.get_y()) * (c.get_center().get_y() - p.get_y());
	//����뾶��ƽ��
	int Rdistance = (c.getR() * c.getR());

	if (Rdistance == distance)
	{
		cout << "����Բ��" << endl;
	}
	else if (Rdistance > distance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}
		
int main()
{	
	//����һ����
	Point p;
	p.set_x(11);
	p.set_y(10);
	//����һ��Բ
	Circle c;
	Point center;
	center.set_x(10);
	center.set_y(0);
	c.setR(10);
	c.set_center(center);

	//�жϵ��Բ֮���λ�ù�ϵ
	Is_inCircle(c, p);
	return 0;
}