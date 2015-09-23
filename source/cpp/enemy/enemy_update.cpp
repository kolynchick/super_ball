#include "enemy.h"
bool enemy::Update(vector<vector<char>> mas,float x, float y)//Метод для обновления передвижения, в качестве входных данных идут координаты игрока
{
	if(prov)//Если двигаемся вниз
	{
		if (position_x != finish_x && position_y != finish_y)//Если ни прибыли
		{
		if(finish_x > position_x){position_x += (finish_x - position_x) * speed;}//Если текущая позиция меньше чем конечная по X
		else if(finish_x < position_x){position_x -=(position_x - finish_x) * speed;}//Если текущая позиция больше чем конечная по X
		if(finish_y > position_y){position_y += (finish_y - position_y) * speed;}//Если текущая позиция меньше чем конечная по Y
		else if(finish_y < position_y){finish_y -=(position_y - finish_y) * speed;}//Если текущая позиция больше чем конечная по Y
		bool pr = true;//Переменная для проверки наличия блока на пути
		for(int i = start;i < finish;i++)
		{
			if(mas[line][i] == '1' && position_x < 46*(i-line))//Если обнаружен блок,а мы находимся перед ним
			{
				finish_x = 46.f*((i-1)-line);//Обновляем конечные координаты передвижения
				finish_y = 18.f*((i-1)+line);
				pr = false;//Даем понять, что мы встретили блок
				break;//Уходим из цикла
			}
		}
		if(pr) //Если на нашем пути не встретился ни один блок
		{
				finish_x = 46.f*(finish-line);//Записываем стандартную конечную точку
				finish_y = 18.f*(finish+line);
		}
		if(finish_x - position_x <= speed && position_x - finish_x <= speed && finish_y - position_y <= speed && position_y - finish_y <= speed)
		{finish_x = position_x; finish_y = position_y;}//Т.к. игрок не сможет встать именно в нужную точку,необходимо помочь ему
		}
		else{prov = false; finish_x += speed; finish_y += speed;}//Если прибыли то бежим обратно
	}
	else
	{
		if (position_x != start_x && position_y != start_y)//Если ни прибыли
		{
		if(start_x > position_x){position_x += (start_x - position_x) * speed;}//Если текущая позиция меньше чем конечная по X
		else if(start_x < position_x){position_x -=(position_x - start_x) * speed;}//Если текущая позиция больше чем конечная по X
		if(start_y > position_y){position_y += (start_y - position_y) * speed;}//Если текущая позиция меньше чем конечная по Y
		else if(start_y < position_y){position_y -=(position_y - start_y) * speed;}//Если текущая позиция больше чем конечная по Y
		bool pr = true;//Переменная для проверки наличия блока на пути
		for(int i = finish;i >= start;i--)//Т.к. мы идем снизу вверх, то и проверять наличие блоков нужно так же
		{
			if(mas[line][i] == '1' && position_x > 46*(i-line))//Если обнаружен блок,а мы находимся перед ним
			{
				start_x = 46.f*((i+1)-line);//Обновляем стартовые координаты передвижения
				start_y = 18.f*((i+1)+line);
				pr = false;//Даем понять, что мы встретили блок
				break;//Уходим из цикла
			}
		}
		if(pr) //Если на нашем пути не встретился ни один блок
		{
				start_x = 46.f*(start-line); //Записываем стандартную начальную точку
				start_y = 18.f*(start+line);
		}
		if(start_x - position_x <= speed && position_x - start_x <= speed && start_y - position_y <= speed && position_y - start_y <= speed)
		{start_x = position_x; start_y = position_y;}//Т.к. игрок не сможет встать именно в нужную точку,необходимо помочь ему
		}
		else{prov = true;}//Если прибыли то бежим обратно
	}
	if(Entry(x,y,position_x,position_y+20,position_x-20,position_y,position_x,position_y-20,position_x+20,position_y)) return true;//Если пересекаемся с игроком
	return false;
}