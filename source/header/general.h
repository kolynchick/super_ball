#include <hgesprite.h>
#include <vector>
#include <math.h>
using namespace std;
#pragma once
//�����-�������� ��� ���� ��������
class general
{
protected:
	float start_x,start_y;//���������� ��� �������� ��������� ���������
	float finish_x,finish_y;//���������� ��� �������� �������� ���������
	float position_x,position_y;//���������� ��� �������� ������� ���������
	hgeSprite *CurrentSprite;//������, �������� ����
public:
	float GetPositionX() const{return position_x;}//������ ������� �� X
	float GetPositionY() const{return position_y;}//������ ������� �� Y
	void Create(HTEXTURE tex,float x,float y,float w,float h,float center_x,float center_y)//����� ��� �������� �������
	{
		CurrentSprite = new hgeSprite(tex,x,y,w,h);//�������������� ������ ����
		CurrentSprite->SetHotSpot(center_x,center_y);//������������� �����
	}
	void SetPosition(float x,float y){position_x = x; position_y = y;}//������������� ��������� ������� ����
	void Render(){ CurrentSprite->Render(position_x,position_y);}//������ ������
	static bool Entry(float x,float y,float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
	{//�������� �� ��������� � �������
		if((y1-y2)*x + (x2-x1)*y + (x1*y2-x2*y1) > 0 && 
		   (y2-y3)*x + (x3-x2)*y + (x2*y3-x3*y2) > 0 && 
		   (y3-y4)*x + (x4-x3)*y + (x3*y4-x4*y3) > 0 && 
		   (y4-y1)*x + (x1-x4)*y + (x4*y1-x1*y4) > 0) return true;
		else return false;
	}
};