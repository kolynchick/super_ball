#include "bullet.h"
void bullet::Route(float x1,float y1,float x2,float y2,int str,int s,int f,int n)//Метод для составление маршрута
{	//Заносим начальные и конечные координаты маршрута
	start_x = x1;
	start_y = y1;
	finish_x = x2;
	finish_y = y2;
	line = str;
	pos = n;
	start = s;
	finish = f;
	dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//Вычисляем дистанцию до конечной точки
}