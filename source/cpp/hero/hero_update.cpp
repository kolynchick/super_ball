#include "hero.h"
bool hero::Update()//����� ��� ���������� ������������
{
	if (position_x != finish_x && position_y != finish_y && count_route != 0)//���� �� �� �� �������� �������
	{
		finish_x = 46.f*(way_x[count_route] - way_y[count_route]);//������� ���������� �� ��������� �����
		finish_y = 18.f*(way_x[count_route] + way_y[count_route]);

		position_x += (finish_x - position_x)/dist*speed;//���������� ������ �� X
		position_y += (finish_y - position_y)/dist*speed;//���������� ������ �� Y
		//���� �� ����� �� ������� �����
		if(finish_x - position_x <= speed && position_x - finish_x <= speed && finish_y - position_y <= speed && position_y - finish_y <= speed)
		{		
			count_route++;//��������� � ��������� ����� � ��������
			if(count_route == way_x.size())//���� ���� ����������
			{
				position_x = finish_x; position_y = finish_y; //�������� ����� � �����
				count_route = 0;//������� ������� �����
				way_x.clear();
				way_y.clear();
				return false;
			}	
			finish_x = 46.f*(way_x[count_route] - way_y[count_route]);//������� ���������� �� ��������� �����
			finish_y = 18.f*(way_x[count_route] + way_y[count_route]);
			dist = sqrt(pow(finish_x - position_x,2)+pow(finish_y - position_y,2));//������� ����

		}//�.�. ����� �� ������ ������ ������ � ������ �����,���������� ������ ���
	}
	if(position_x == win_x && position_y == win_y) return true;//���� ��������� �� �������� ���������
	return false;
}
