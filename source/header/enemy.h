#include "hgesprite.h"
#include "general.h"
//����� ����������� ����������
class enemy: public general
{
private:
	float speed;//���������� ��� �������� ��������
	bool prov;//���������� ��� ����������� ��������: true - ����, false - �����
	int line;//���������� ��� �������� ������� �����
	int start;//���������� ��� ������ ������������
	int finish;//���������� ��� ��������� ������������
public:
	enemy()//����������� ������, �������� ����������
	{
		start_x = 0.f; start_y = 0.f; position_x = 0.f; position_y = 0.f; finish_x = 0.f; finish_y = 0.f;
		prov = true; start = 0; finish = 0; line = 0; speed = 0.02f; 
	}
	~enemy(){}//���������� ������, � ��� ������� ������
	void Route(float,float,float,float,int,int,int);//����� ��� ����������� ��������
	bool Update(vector<vector<char>>,float, float);//����� ��� ���������� ������������, � �������� ������� ������ ���� ���������� ������
};