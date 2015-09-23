#include "bullet.h"
bool bullet::Update(vector<vector<char>> &mas,float x, float y)//Метод для обновления передвижения, в качестве входных данных идут координаты игрока
{
	if (position_x != finish_x && position_y != finish_y)//Если мы не на конечной позиции
	{
		bool pr = true;//Переменная для проверки наличия блока на пути
		if(pos == 0)//Если проверяем пулю от вертикальной стены
		{
			for(int i = start;i <= finish;i++)//Проверяем на наличие блоков
			{
				if(mas[line][i] == '1' && position_x < 46*(i-line) && position_y < 18*(i+line)) //Если обнаружен блок,а мы находимся перед ним
				{
					finish_x = 46.f*((i-1)-line)+25;//Обновляем конечные координаты
					finish_y = 18.f*((i-1)+line)-22;
					dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//Измеряем дистанцию
					pr = false;//Даем понять, что мы встретили блок
					break;//Уходим из цикла
				}
				else if(mas[line][i] == '1') break;//Если обнаружен блок,а мы находимся за ним, то просто уходим из цикла
			}
			if(pr) //Если не встретили блок
			{
				finish_x = 46.f*(finish-line)+25; //Записываем стандартную конечную точку
				finish_y = 18.f*(finish+line)-22;
				dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//Измеряем путь
			}
		}
		if(pos == 1)//Если проверяем пулю от горизонтальной стены
		{
			for(int i = start;i <= finish;i++)//Проверяем на наличие блоков
			{
				if(mas[i][line] == '1' && position_x > 46*(line-i) && position_y < 18*(line+i)) //Если обнаружен блок,а мы находимся перед ним
				{
					finish_x = 46.f*(line-(i-1))-25;//Обновляем конечные координаты 
					finish_y = 18.f*(line+(i-1))-22;
					dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//Измеряем дистанцию
					pr = false;//Даем понять, что мы встретили блок
					break;//Уходим из цикла
				}
				else if(mas[i][line] == '1') break;//Если обнаружен блок,а мы находимся за ним, то просто уходим из цикла
			}
			if(pr) //Если не встретили блок
			{
				finish_x = 46.f*(line-finish)-25; //Записываем стандартную конечную точку
				finish_y = 18.f*(line+finish)-22;
				dist = sqrt(pow(finish_x - start_x,2)+pow(finish_y - start_y,2));//Измеряем путь
			}
		}

		position_x += (finish_x - start_x)/dist * speed;//Перемещаем игрока по X
		position_y += (finish_y - start_y)/dist * speed;//Перемещаем игрока по Y

		if(Entry(position_x,position_y,finish_x,finish_y+6,finish_x-6,finish_y,finish_x,finish_y-6,finish_x+6,finish_y))
		{position_x = start_x; position_y = start_y;}//Т.к. игрок не сможет встать именно в нужную точку,необходимо помочь ему
	}
	if(Entry(x,y,position_x,position_y+42,position_x-20,position_y+22,position_x,position_y+2,position_x+20,position_y+22)) return true;//Если пересекаемся рядом с игроком
	return false;
}