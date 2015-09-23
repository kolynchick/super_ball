#include "bullet.h"
bool bullet::Update(vector<vector<char>> &mas,float x, float y)//����� ��� ���������� ������������, � �������� ������� ������ ���� ���������� ������
{
	if (position_x != finish_x && position_y != finish_y)//���� �� �� �� �������� �������
	{
		bool pr = true;//���������� ��� �������� ������� ����� �� ����
		if(pos == 0)//���� ��������� ���� �� ������������ �����
		{
			for(int i = start;i <= finish;i++)//��������� �� ������� ������
			{
				if(mas[line][i] == '1' && position_x < 46*(i-line) && position_y < 18*(i+line)) //���� ��������� ����,� �� ��������� ����� ���
				{
					finish_x = 46.f*((i-1)-line)+25;//��������� �������� ����������
					finish_y = 18.f*((i-1)+line)-22;
					dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//�������� ���������
					pr = false;//���� ������, ��� �� ��������� ����
					break;//������ �� �����
				}
				else if(mas[line][i] == '1') break;//���� ��������� ����,� �� ��������� �� ���, �� ������ ������ �� �����
			}
			if(pr) //���� �� ��������� ����
			{
				finish_x = 46.f*(finish-line)+25; //���������� ����������� �������� �����
				finish_y = 18.f*(finish+line)-22;
				dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//�������� ����
			}
		}
		if(pos == 1)//���� ��������� ���� �� �������������� �����
		{
			for(int i = start;i <= finish;i++)//��������� �� ������� ������
			{
				if(mas[i][line] == '1' && position_x > 46*(line-i) && position_y < 18*(line+i)) //���� ��������� ����,� �� ��������� ����� ���
				{
					finish_x = 46.f*(line-(i-1))-25;//��������� �������� ���������� 
					finish_y = 18.f*(line+(i-1))-22;
					dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//�������� ���������
					pr = false;//���� ������, ��� �� ��������� ����
					break;//������ �� �����
				}
				else if(mas[i][line] == '1') break;//���� ��������� ����,� �� ��������� �� ���, �� ������ ������ �� �����
			}
			if(pr) //���� �� ��������� ����
			{
				finish_x = 46.f*(line-finish)-25; //���������� ����������� �������� �����
				finish_y = 18.f*(line+finish)-22;
				dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//�������� ����
			}
		}

		position_x += (finish_x - start_x)/dist * speed;//���������� ������ �� X
		position_y += (finish_y - start_y)/dist * speed;//���������� ������ �� Y

		if(Entry(position_x,position_y,finish_x,finish_y+6,finish_x-6,finish_y,finish_x,finish_y-6,finish_x+6,finish_y))
		{position_x = start_x; position_y = start_y;}//�.�. ����� �� ������ ������ ������ � ������ �����,���������� ������ ���
	}
	if(Entry(x,y,position_x,position_y+42,position_x-20,position_y+22,position_x,position_y+2,position_x+20,position_y+22)) return true;//���� ������������ ����� � �������
	return false;
}