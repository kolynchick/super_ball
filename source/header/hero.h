#include "hgesprite.h"
#include "general.h"
//����� ����������� ����� ���, �.�. �������� �����
class hero: public general
{
private:
	float win_x, win_y;//���������� ��� �������� �������� ���������
	float dist, speed;// ���������� ��� ���������� ����� ������� � �������� ������������
	vector<int> way_x;
	vector<int> way_y;
	int count_route;//������� ����
public:
	hero()//����������� ������, �������� ����������
	{
		win_x = 0.f; win_y = 0.f;
		position_x = 0.f; position_y = 0.f;
		finish_x = 0.f; finish_y = 0.f;
		count_route = 0;
		speed = 3.0f;
	}
	virtual ~hero(){}//���������� ������, � ��� ������� ������
	void SetPosition(float x,float y){position_x = x; position_y = y; finish_x = x; finish_y = y;}//������������� ������� ������
	bool Thorns(vector<vector<char>>&);
	void Select(vector<vector<char>>&,float,float);//����� ��� �������� �� ������ �������
	void Win (float x,float y){win_x = x; win_y = y;}//������� �������� ����������
	bool Update();//����� ��� ���������� ������������
	bool lee(vector<vector<char>>&,int,int,int,int by);//�������� �� ��� ������ ���� �� ������ (ax, ay) � ������ (bx, by)
};