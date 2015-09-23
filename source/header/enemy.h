#include "hgesprite.h"
#include "general.h"
//Класс описывающий противника
class enemy: public general
{
private:
	float speed;//Переменная для хранения скорости
	bool prov;//Переменная для направления движения: true - вниз, false - вверх
	int line;//Переменная для хранении рабочей линии
	int start;//Переменная для начала исследования
	int finish;//Переменная для окончания исследования
public:
	enemy()//Конструктор класса, обнуляем переменные
	{
		start_x = 0.f; start_y = 0.f; position_x = 0.f; position_y = 0.f; finish_x = 0.f; finish_y = 0.f;
		prov = true; start = 0; finish = 0; line = 0; speed = 0.02f; 
	}
	~enemy(){}//Деструктор класса, в нем удаляем спрайт
	void Route(float,float,float,float,int,int,int);//Метод для составление маршрута
	bool Update(vector<vector<char>>,float, float);//Метод для обновления передвижения, в качестве входных данных идут координаты игрока
};