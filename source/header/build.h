#include "general.h"
//Класс для строительства уровня
class build: public general
{
public:
	build(){position_x = 0.f; position_y = 0.f;}//Конструктор
	virtual ~build(){}//Деструктор
};