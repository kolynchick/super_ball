#include "hgesprite.h"
#include "general.h"
// ласс, описывающий пулю
class bullet: public general
{
private:
	float dist, speed;// ѕеременна€ дл€ вычислени€ длины вектора и скорость передвижени€
	int line,pos;// ѕеременна€ дл€ вычислений на какой линии стоит пул€ и ее направление
	int start,finish;//ѕеременные дл€ ограничени€ отрезка исследовани€
public:
	bullet()// онструктор класса, обнул€ем переменные
	{
		start_x = 0.f; start_y = 0.f; position_x = 0.f; position_y  = 0.f;
		finish_x = 0.f; finish_y = 0.f; line = 0; start = 0;finish = 0; speed = 2.0f; 
	}
	~bullet(){}//ƒеструктор класса, в нем удал€ем спрайт
	void Route(float,float,float,float,int,int,int,int);//ћетод дл€ составление маршрута
	bool Update(vector<vector<char>>&,float,float);//ћетод дл€ обновлени€ передвижени€, в качестве входных данных идут координаты игрока
};