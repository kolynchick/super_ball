#include "hgesprite.h"
#include "general.h"
//�����, ����������� ����
class bullet: public general
{
private:
	float dist, speed;// ���������� ��� ���������� ����� ������� � �������� ������������
	int line,pos;// ���������� ��� ���������� �� ����� ����� ����� ���� � �� �����������
	int start,finish;//���������� ��� ����������� ������� ������������
public:
	bullet()//����������� ������, �������� ����������
	{
		start_x = 0.f; start_y = 0.f; position_x = 0.f; position_y  = 0.f;
		finish_x = 0.f; finish_y = 0.f; line = 0; start = 0;finish = 0; speed = 2.0f; 
	}
	~bullet(){}//���������� ������, � ��� ������� ������
	void Route(float,float,float,float,int,int,int,int);//����� ��� ����������� ��������
	bool Update(vector<vector<char>>&,float,float);//����� ��� ���������� ������������, � �������� ������� ������ ���� ���������� ������
};