#include "enemy.h"
bool enemy::Update(vector<vector<char>> mas,float x, float y)//����� ��� ���������� ������������, � �������� ������� ������ ���� ���������� ������
{
	if(prov)//���� ��������� ����
	{
		if (position_x != finish_x && position_y != finish_y)//���� �� �������
		{
		if(finish_x > position_x){position_x += (finish_x - position_x) * speed;}//���� ������� ������� ������ ��� �������� �� X
		else if(finish_x < position_x){position_x -=(position_x - finish_x) * speed;}//���� ������� ������� ������ ��� �������� �� X
		if(finish_y > position_y){position_y += (finish_y - position_y) * speed;}//���� ������� ������� ������ ��� �������� �� Y
		else if(finish_y < position_y){finish_y -=(position_y - finish_y) * speed;}//���� ������� ������� ������ ��� �������� �� Y
		bool pr = true;//���������� ��� �������� ������� ����� �� ����
		for(int i = start;i < finish;i++)
		{
			if(mas[line][i] == '1' && position_x < 46*(i-line))//���� ��������� ����,� �� ��������� ����� ���
			{
				finish_x = 46.f*((i-1)-line);//��������� �������� ���������� ������������
				finish_y = 18.f*((i-1)+line);
				pr = false;//���� ������, ��� �� ��������� ����
				break;//������ �� �����
			}
		}
		if(pr) //���� �� ����� ���� �� ���������� �� ���� ����
		{
				finish_x = 46.f*(finish-line);//���������� ����������� �������� �����
				finish_y = 18.f*(finish+line);
		}
		if(finish_x - position_x <= speed && position_x - finish_x <= speed && finish_y - position_y <= speed && position_y - finish_y <= speed)
		{finish_x = position_x; finish_y = position_y;}//�.�. ����� �� ������ ������ ������ � ������ �����,���������� ������ ���
		}
		else{prov = false; finish_x += speed; finish_y += speed;}//���� ������� �� ����� �������
	}
	else
	{
		if (position_x != start_x && position_y != start_y)//���� �� �������
		{
		if(start_x > position_x){position_x += (start_x - position_x) * speed;}//���� ������� ������� ������ ��� �������� �� X
		else if(start_x < position_x){position_x -=(position_x - start_x) * speed;}//���� ������� ������� ������ ��� �������� �� X
		if(start_y > position_y){position_y += (start_y - position_y) * speed;}//���� ������� ������� ������ ��� �������� �� Y
		else if(start_y < position_y){position_y -=(position_y - start_y) * speed;}//���� ������� ������� ������ ��� �������� �� Y
		bool pr = true;//���������� ��� �������� ������� ����� �� ����
		for(int i = finish;i >= start;i--)//�.�. �� ���� ����� �����, �� � ��������� ������� ������ ����� ��� ��
		{
			if(mas[line][i] == '1' && position_x > 46*(i-line))//���� ��������� ����,� �� ��������� ����� ���
			{
				start_x = 46.f*((i+1)-line);//��������� ��������� ���������� ������������
				start_y = 18.f*((i+1)+line);
				pr = false;//���� ������, ��� �� ��������� ����
				break;//������ �� �����
			}
		}
		if(pr) //���� �� ����� ���� �� ���������� �� ���� ����
		{
				start_x = 46.f*(start-line); //���������� ����������� ��������� �����
				start_y = 18.f*(start+line);
		}
		if(start_x - position_x <= speed && position_x - start_x <= speed && start_y - position_y <= speed && position_y - start_y <= speed)
		{start_x = position_x; start_y = position_y;}//�.�. ����� �� ������ ������ ������ � ������ �����,���������� ������ ���
		}
		else{prov = true;}//���� ������� �� ����� �������
	}
	if(Entry(x,y,position_x,position_y+20,position_x-20,position_y,position_x,position_y-20,position_x+20,position_y)) return true;//���� ������������ � �������
	return false;
}