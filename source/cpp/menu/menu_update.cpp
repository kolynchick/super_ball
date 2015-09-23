#include "menu.h"
bool menu::Update()//Функция обработки кадра
{
	float dt=hge->Timer_GetDelta();//Время между вызовом кадров
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) {return true;} //Если нажата клавиша Escape, то выходим в меню
	int id = gui->Update(dt);//Получаем id кнопки, если произошло нажатие
	switch(id)//Обработаем нажатие
	{
	case 1: //Если нажата кнопка "game"
		for(int i = 1;i < 5;i++)//Скрываем текущие окно
		{
			gui->EnableCtrl(i,false);
			gui->ShowCtrl(i,false);
		}
		for(int i = 11;i < 15;i++)//Показываем нужное окно
		{
			gui->EnableCtrl(i,true);
			gui->ShowCtrl(i,true);
		}
		game_visible = true;//Уведомляем о том,что перешли, для рисования текста
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		break;//Выходим
	case 2: //Если нажата кнопка "setting"
		for(int i = 1;i < 5;i++)//Скрываем текущие окно
		{
			gui->EnableCtrl(i,false);
			gui->ShowCtrl(i,false);
		}
		for(int i = 5;i <= 10;i++)//Показываем нужное окно
		{
			gui->EnableCtrl(i,true);
			gui->ShowCtrl(i,true);
		}
		setting_visible = true;//Уведомляем о том,что перешли, для рисования текста
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		break;//Выходим
	case 3://Если нажата кнопка "authors"
		for(int i = 1;i < 5;i++)//Скрываем текущие окно
			gui->ShowCtrl(i,false);
		gui->EnableCtrl(5,true);//Показываем нужное окно
		gui->ShowCtrl(5,true);
		author_visible = true;//Уведомляем о том,что перешли, для рисования текста
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		break;//Выходим
	case 4://Если нажата кнопка "exit"
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		return true;//Выходим из игры
	case 5://Если нажата кнопка "back" в окне авторов
		for(int i = 1;i < 5;i++)//Скрываем текущие окно
			gui->ShowCtrl(i,true);
		gui->EnableCtrl(5,false);//Показываем нужное окно
		gui->ShowCtrl(5,false);
		author_visible = false;//Уведомляем о том,что перешли, для рисования текста
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		break;//Выходим
	case 6://Если нажата кнопка "back" в окне настроек
		for(int i = 1;i < 5;i++)//Скрываем текущие окно
		{
			gui->EnableCtrl(i,true);
			gui->ShowCtrl(i,true);
		}
		for(int i = 5;i <= 10;i++)//Показываем нужное окно
		{
			gui->EnableCtrl(i,false);
			gui->ShowCtrl(i,false);
		}
		setting_visible = false;//Уведомляем о том,что перешли, для рисования текста
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		break;//Выходим
	case 7://Если нажата кнопка "left" в окне настроек
		select_screen--;//Декрементируем 
		switch(select_screen)//Выбираем размер
		{
		case 0: width = float(GetSystemMetrics(SM_CXSCREEN)); height = float(GetSystemMetrics(SM_CYSCREEN)); break;
		case 1: width = 800; height = 600; break;
		case 2: width = 1024; height = 768; break;
		case 3: width = 1280; height = 720; break;
		case 4:	width = 1280; height = 1024; break;
		default: select_screen = 4; width = 1280; height = 1024; break;
		}
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		hge->System_Shutdown();//Освобождаем ресурсы
		hge->Release();//Освобождаем интерфейс HGE
		Start(true);//Рестарт
		break;//Выходим
	case 8://Если нажата кнопка "right" в окне настроек
		select_screen++;//Инкрементируем
		switch(select_screen)//Выбираем размер
		{
		case 0: width = float(GetSystemMetrics(SM_CXSCREEN)); height = float(GetSystemMetrics(SM_CYSCREEN)); break;
		case 1: width = 800; height = 600; break;
		case 2: width = 1024; height = 768; break;
		case 3: width = 1280; height = 720; break;
		case 4:	width = 1280; height = 1024; break;
		default: select_screen = 0; width = float(GetSystemMetrics(SM_CXSCREEN)); height = float(GetSystemMetrics(SM_CYSCREEN)); break;
		}
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		hge->System_Shutdown();//Освобождаем ресурсы
		hge->Release();//Освобождаем интерфейс HGE
		Start(true);//Рестарт
		break;//Выходим
	case 9://Если нажат переключатель звука в окне настроек
		if(select_sound){ hge->Effect_Play(Button_sound); select_sound = false;}//Если звук включен, то отключаем
		else select_sound = true;//Иначе включаем
		break;//Выходим
	case 10://Если нажат переключатель окна в окне настроек
		if(select_window) select_window = false;//Если активен полноэкранный режим, переходим в оконный
		else select_window = true;//Иначе в полноэкранный
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		hge->System_SetState(HGE_WINDOWED, select_window);//Перейдем в оконный режим
		break;//Выходим
	case 11://Если нажата кнопка "back" в окне выбора уровня
		for(int i = 1;i < 5;i++)//Скрываем текущие окно
		{
			gui->EnableCtrl(i,true);
			gui->ShowCtrl(i,true);
		}
		for(int i = 11;i < 15;i++)//Показываем нужное окно
		{
			gui->EnableCtrl(i,false);
			gui->ShowCtrl(i,false);
		}
		game_visible = false;//Уведомляем о том,что перешли, для рисования текста
		if(select_sound) hge->Effect_Play(Button_sound);//Воспроизводим звуковой эффект
		break;//Выходим
	case 12:
		select_start = true;//Уведомляем о том что переходим в игру
		break;//Выходим
	case 13:
		select_level--;//Декрементируем
		if(select_level < 0){select_level = save.size()-1;}//Если меньше 0, то считаем с конца
		break;
	case 14:
		select_level++;//Инкрементируем
		if(select_level > int(save.size())-1){select_level = 0;}//Если вышло за границы, то считаем сначала
		break;
	}
	if(select_start)//Если необходимо перейти в основную игру
	{
		select_start = false;//Чтобы обратно не зайти
		game start_game;//Создаем экземпляр класса
		start_game.hge = hge;//Передаем интерфейс
		start_game.Create(save[select_level],width,height);//Запускаем, передаем имя уровня, высоту и ширину экрана для камеры
	}
	return false;//Обязательно вернуть false, если true, то произойдет выход
}