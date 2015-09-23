#include "game.h"
game* game::c_game = NULL;//Обнуляем синглтон
//Функция для создания игры
void game::Create(string filename,float w,float h)
{
	width = w; height = h;//Забираем размер окна
	hge->System_SetState(HGE_FRAMEFUNC, game::Call_Update);//Указываем название функции для функции кадра
	hge->System_SetState(HGE_RENDERFUNC, game::Call_Render);//Указываем название функции для рисовании графики
	int line = 0;//Размер поля
	int column = 0;
	string a = "level/" + filename;//Вспомогательная переменная для формирования строки
	ifstream file(a.c_str());//Открываем файл для чтения
	
	while(!file.eof())//Пока не закончиться
	{
		int buf_column = 0;//Длина строки
		position_level.resize(position_level.size()+1);//Резервируем
		for(int i = 0;!file.eof();i++)//Цикл для чтения строки
		{
			position_level[line].push_back(file.get());//Заносим символ в массив стеком
			buf_column++;//Инкрементируем
			//Если обнаружен символ конца строки или конца файла
			if(position_level[line][i] == 10 || position_level[line][i] == -1){position_level[line].pop_back(); buf_column--; break;}
		}
		if(file.eof()){break;}//Если конец, уходим
		if(buf_column > column) column = buf_column;//Ищем максимальную длину строки
		line++;//Увеличиваем столбец
	}
	file.close();//Попользовались, отдать ресурсы
	for(int i = 0; i < int(position_level.size());i++)//Резервируем размер под прямоугольник
		position_level[i].resize(column);

	for(int i = 0;i < int(position_level.size());i++)
	{
		for(int j = 0;j < int(position_level[i].size());j++)
		{
			switch(position_level[i][j])
			{
				case '#'://Если встретился обычный пол
					build_level.resize(build_level.size()+1);
					build_level.back().Create(hge->Texture_Load("obj/cell.png"),0,0,100,62,50,31);
					build_level.back().SetPosition(46.f*(j-i),18.f*(j+i));
					break;
				case 'S'://Если встретилась стартовая ячейка
					build_level.resize(build_level.size()+1);
					build_level.back().Create(hge->Texture_Load("obj/cell_start.png"),0,0,100,62,50,31);
					build_level.back().SetPosition(46.f*(j-i),18.f*(j+i));
					player.SetPosition(46.f*(j-i),18.f*(i+j));
					break;
				case 'F'://Если встретилась конечная ячейка
					build_level.resize(build_level.size()+1);
					build_level.back().Create(hge->Texture_Load("obj/cell_finish.png"),0,0,100,62,50,31);
					build_level.back().SetPosition(46.f*(j-i),18.f*(j+i));
					player.Win(46.f*(j-i),18.f*(i+j));
					break;
				case 'T'://Если встретились шипы
					build_level.resize(build_level.size()+1);
					build_level.back().Create(hge->Texture_Load("obj/thorns.png"),0,0,100,62,50,31);
					build_level.back().SetPosition(46.f*(j-i),18.f*(j+i));
					break;
				case '%'://Если встретился обычный барьер
					build_level.resize(build_level.size()+1);
					build_level.back().Create(hge->Texture_Load("obj/wall.png"),0,0,100,102,50,92);
					build_level.back().SetPosition(46.f*(j-i),18.f*(j+i));
					break;
				case 'V'://Если встретилась вертикальная пушка
					build_level.resize(build_level.size()+1);
					build_level.back().Create(hge->Texture_Load("obj/wall_gun_v.png"),0,0,100,102,50,92);
					build_level.back().SetPosition(46.f*(j-i),18.f*(j+i));
					bullet_level.resize(bullet_level.size()+1);
					bullet_level.back().Create(hge->Texture_Load("obj/bullet.png"),0,0,12,12,6,12);
					bullet_level.back().SetPosition(46.f*(j-i)-25,18.f*(j+i)-22);
					for(int k = i+1;k < int(position_level.size());k++)
					{
						if(position_level[k][j] == '%' || position_level[k][j] == 'V' || position_level[k][j] == 'G') break;
						bullet_level.back().Route(46.f*(j-i)-25,18.f*(j+i)-22,46.f*(j-k)-25,18.f*(j+k)-22,j,i+1,k,1);
					}
					break;
				case 'G'://Если встретилась горизонтальная пушка
					build_level.resize(build_level.size()+1);
					build_level.back().Create(hge->Texture_Load("obj/wall_gun_g.png"),0,0,100,102,50,92);
					build_level.back().SetPosition(46.f*(j-i),18.f*(j+i));
					bullet_level.resize(bullet_level.size()+1);
					bullet_level.back().Create(hge->Texture_Load("obj/bullet.png"),0,0,12,12,6,12);
					bullet_level.back().SetPosition(46.f*(j-i)+25,18.f*(j+i)-22);
					for(int k = j+1;k < int(position_level.size());k++)
					{
						if(position_level[i][k] == '%' || position_level[i][k] == 'V' || position_level[i][k] == 'G') break;
						bullet_level.back().Route(46.f*(j-i)+25,18.f*(i+j)-22,46.f*(k-i)+25,18.f*(k+i)-22,i,j+1,k,0);
					}
					break;
				case 'E'://Если встретился враг
					enemy_level.resize(enemy_level.size()+1);
					enemy_level.back().Create(hge->Texture_Load("obj/ball_enemy.png"),0,0,40,40,20,40);
					enemy_level.back().SetPosition(46.f*(j-i),18.f*(i+j));
					position_level[i][j] = '#';
					build_level.resize(build_level.size()+1);
					build_level.back().Create(hge->Texture_Load("obj/cell.png"),0,0,100,62,50,31);
					build_level.back().SetPosition(46.f*(j-i),18.f*(i+j));
					for(int k = j;k < int(position_level[i].size());k++)
					{
						if(position_level[i][k] != '#' && position_level[i][k] != 'T') break;
						enemy_level.back().Route(46.f*(j-i),18.f*(i+j),46.f*((k-1)-i),18.f*(i+(k-1)),i,j,k);
					}
					break;
				default://Если любой другой символ, то там ничего нет
					position_level[i][j] = '0';
					build_level.resize(build_level.size()+1);
					break;
			}
		}
	}
	player.Create(hge->Texture_Load("obj/ball_friend.png"),0,0,40,40,20,40);//Создаем героя
	cursor_sprite = new hgeSprite(hge->Texture_Load("obj/cursor.png"),0,0,16,22);//Создаем спрайт курсора
	pause_sprite = new hgeSprite(hge->Texture_Load("obj/pause.png"),0,0,400,100);//Создаем спрайт для паузы
	pause_sprite->SetHotSpot(200,50);//Центрируем
	win_sprite = new hgeSprite(hge->Texture_Load("obj/win.png"),0,0,400,100);//Создаем спрайт для победы
	win_sprite->SetHotSpot(200,50);//Центрируем
	lose_sprite = new hgeSprite(hge->Texture_Load("obj/lose.png"),0,0,400,100);//Создаем спрайт для поражения
	lose_sprite->SetHotSpot(200,50);//Центрируем
	font = new hgeFont("font.fnt");
	hge->System_Start();//Запускаем игру

	position_level.clear();//Освобождаем ресурсы
	build_level.clear();
	enemy_level.clear();
	bullet_level.clear();
	delete cursor_sprite;
	delete pause_sprite;
	delete win_sprite;
	delete lose_sprite;
	hge->Gfx_SetTransform(0,0,0,0,0,1,1);
	hge->System_SetState(HGE_FRAMEFUNC, menu::Call_Update);//Указываем название функции для функции кадра
	hge->System_SetState(HGE_RENDERFUNC, menu::Call_Render);//Указываем название функции для рисовании графики
}
bool game::Call_Update(){return c_game->Update();}//Вызов нестатичного метода,передаем адрес класса
bool game::Call_Render(){return c_game->Render();}