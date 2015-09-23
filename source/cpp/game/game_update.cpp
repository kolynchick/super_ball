#include "game.h"
//функция для указателя на пользовательскую функцию кадра
bool game::Update()
{
	if(hge->Input_GetEvent(&ev)) //Вход в условие для фиксирования событий
	{
		if(ev.type == INPUT_KEYUP && ev.key == HGEK_ESCAPE) return true; //Если нажата клавиша Escape, то выходим из игры
		if(ev.type == INPUT_KEYUP && ev.key == HGEK_P && select_win == false && select_lose == false)//Если нажата P
		{
			if(select_pause) select_pause = false;
			else select_pause = true;
		}
		if(ev.type == INPUT_MBUTTONDOWN && ev.key == HGEK_RBUTTON && select_pause == false && select_win == false && select_lose == false) //Если нажата ПКМ
		{
			hge->Input_GetMousePos(&rmouse.x, &rmouse.y);//Забираем координаты мышки
			for(int i = 0;i < int(position_level.size());i++)//Исследуем поле
			{
				for(int j = 0;j < int(position_level[i].size());j++)
				{	//Если координаты входят в ограничивающий сектор
					if(player.Entry(rmouse.x-(width/2-player.GetPositionX()),rmouse.y-(height/2-player.GetPositionY()),46.f*(j-i),18.f*(j+i)+9,46.f*(j-i)-45,18.f*(j+i)-10,46.f*(j-i),18.f*(j+i)-28,46.f*(j-i)+45,18.f*(j+i)-10))
					{	//Если это пол и не находится рядом с пушкой
						if(position_level[i][j] == '#' && barrier_fuel == false && position_level[i-1][j] != 'V' && position_level[i][j-1] != 'G')
						{
							position_level[i][j] = '1';//Ставим барьер
							build_level[j+i*position_level[i].size()].Create(hge->Texture_Load("obj/barrier.png"),0,0,100,102,50,92);//Создаем текстуру барьера
							barrier_fuel = true;//Даём понять, что больше нельзя ставить барьер
							break;//Уходим
						}
						if(position_level[i][j] == '1')//Если барьер
						{
							position_level[i][j] = '#';//Ставим пол
							build_level[j+i*position_level[i].size()].Create(hge->Texture_Load("obj/cell.png"),0,0,100,62,50,31);//Создаем текстуру пола
							barrier_fuel = false;//Уходим
						}
					}
				}
			}
		}
		if(ev.type == INPUT_MBUTTONDOWN && ev.key == HGEK_LBUTTON && select_pause == false && select_win == false && select_lose == false) //Если нажата ПКМ
		{
			hge->Input_GetMousePos(&mouse.x, &mouse.y); //Забираем координаты мышки
			player.Select(position_level,mouse.x-(width/2-player.GetPositionX()),mouse.y-(height/2-player.GetPositionY())); //Вызываем из класса метод, делающий проверку на вхождение в область
		}
	}
	if(select_pause != true && select_win != true && select_lose != true)//Если не произошло никаких событий
	{
		if(player.Update()){select_win = true; return false;}//Проверяем на победу
		if(player.Thorns(position_level)){select_lose = true; return false;}//Проверяем на поражение
		for(int i = 0;i < int(enemy_level.size());i++)
			if(enemy_level[i].Update(position_level,player.GetPositionX(),player.GetPositionY())){select_lose = true; return false;}//Проверяем на поражение
		for(int i = 0;i < int(bullet_level.size());i++)
			if(bullet_level[i].Update(position_level,player.GetPositionX(),player.GetPositionY())){select_lose = true; return false;}//Проверяем на поражение
	}
	return false;//Продолжаем выполнять функцию
}