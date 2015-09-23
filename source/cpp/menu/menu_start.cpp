#include "menu.h"
menu* menu::c_menu = NULL;//Обнуляем синглтон
void menu::Start(bool restart)//Стартовая, и даже рестартовая функция
{
	hge = hgeCreate(HGE_VERSION);//Создаем объект для HGE
	hge->System_SetState(HGE_LOGFILE, "hge_log.log");//Указываем,что нам нужнен файл прокотола, и пишем имя файла
	hge->System_SetState(HGE_FRAMEFUNC,Call_Update);//Указываем название функции для функции кадра(тута сторонние функции)
	hge->System_SetState(HGE_RENDERFUNC,Call_Render);//Указываем название функции для рисовании графики
	hge->System_SetState(HGE_DONTSUSPEND, true);
	hge->System_SetState(HGE_TITLE, "Super Ball");//Указываем загаловок окна
	hge->System_SetState(HGE_WINDOWED, select_window);//Перейдем в оконный режим
	hge->System_SetState(HGE_SCREENWIDTH, int(width));//Указываем ширину окна
	hge->System_SetState(HGE_SCREENHEIGHT, int(height));//Указываем высоту окна
	hge->System_SetState(HGE_SCREENBPP, 32);//Указываем глубину цвета экрана
	hge->System_SetState(HGE_FPS, 100);//Укажем частоту с которой будут вызываться функция кадра
	if(hge->System_Initiate()) //Если инициализация прошла успешно
	{
		cursor = new hgeSprite(hge->Texture_Load("obj/cursor.png"),0,0,16,22);//Создаем курсор
		main = new hgeSprite(hge->Texture_Load("obj/main.png"),0,0,300,200);//Создаем главную картинку в меню
		main->SetHotSpot(150,100);//Устанавливаем центр
		gui = new hgeGUI();//Создаем для объектов
		gui->AddCtrl(new hgeGUIButton(1,width/2-150,height*0.4f,300,50,hge->Texture_Load("obj/game.png"),0,0));//Добавляем кнопки
		gui->AddCtrl(new hgeGUIButton(2,width/2-150,height*0.55f,300,50,hge->Texture_Load("obj/setting.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(3,width/2-150,height*0.7f,300,50,hge->Texture_Load("obj/author.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(4,width/2-150,height*0.85f,300,50,hge->Texture_Load("obj/exit.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(5,width/2-150,height*0.85f,300,50,hge->Texture_Load("obj/back.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(6,width/2-150,height*0.85f,300,50,hge->Texture_Load("obj/back.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(7,width/2-30,height*0.45f,30,30,hge->Texture_Load("obj/left.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(8,width/2+120,height*0.45f,30,30,hge->Texture_Load("obj/right.png"),0,0));
		Button = new hgeGUIButton(9,width/2-150,height*0.6f,40,30,hge->Texture_Load("obj/check.png"),0,0);//Это не просто кнопка, а переключатель
		Button->SetMode(true);//Указываем, что это не кнопка
		gui->AddCtrl(Button);//Отдаем под контроль
		Button = new hgeGUIButton(10,width/2-150,height*0.7f,40,30,hge->Texture_Load("obj/check.png"),0,0);
		Button->SetMode(true);
		if(select_window) Button->SetState(true);
		gui->AddCtrl(Button);
		gui->AddCtrl(new hgeGUIButton(11,width/2-150,height*0.85f,300,50,hge->Texture_Load("obj/back.png"),0,0));//Продолжим добавлять кнопки
		gui->AddCtrl(new hgeGUIButton(12,width/2-150,height*0.7f,300,50,hge->Texture_Load("obj/load.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(13,width/2-130,height*0.55f,30,30,hge->Texture_Load("obj/left.png"),0,0));
		gui->AddCtrl(new hgeGUIButton(14,width/2+100,height*0.55f,30,30,hge->Texture_Load("obj/right.png"),0,0));
		Button_sound = hge->Effect_Load("obj/menu.wav");//Загружаем звуковой эффект
		font = new hgeFont("font.fnt");//Загружаем шрифт
		font->SetColor(DWORD(0xFFE6E6FA));//Устанавливаем цвет
		if(restart)//Если проходит перезапуск
		{
			for(int i = 1;i <= 5;i++)//Необходимо остаться в настройках
			{
			gui->EnableCtrl(i,false);//Деактивируем объект
			gui->ShowCtrl(i,false);//Скрываем объект
			}
			for(int i = 11;i < 15;i++)
			{
			gui->EnableCtrl(i,false);//Деактивируем объект
			gui->ShowCtrl(i,false);//Скрываем объект
			}
			}
		else
		{
		save.push_back(hge->Resource_EnumFiles("level/*.sav"));//Добавляем в вектор все имена файлов, которые имеют расширение .sav
		for(;;)//Небольшой шаманизм, чтобы красиво выйти из цикла
		{
		char *filename = hge->Resource_EnumFiles(0);//Продолжаем считывание
		if(filename != 0) save.push_back(filename);//Если меняется указатель, то меняется и содержимое вектора, поэтому необходимо пересоздавать указатель
		else break;//Если файлы закончились выходим
		}
		for(int i = 5;i < 15;i++)//Скрываем объекты
		{
			gui->EnableCtrl(i,false);//Деактивируем объект
			gui->ShowCtrl(i,false);//Скрываем объект
		}
		}
		hge->System_Start();//Запускаем аппарат 
	}
	else 
	{	//Если по каким то причинам не возможно запустить процесс, то попадаем сюда
		MessageBoxA(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);//Выводим сообщение об ошибке
		hge->System_Shutdown();//Освобождаем ресурсы
		hge->Release();//Освобождаем интерфейс HGE
	}
	hge->System_Shutdown();//Освобождаем ресурсы
	hge->Release();//Освобождаем интерфейс HGE
	ExitProcess(0);
}
bool menu::Call_Update(void) {return c_menu->Update();}
bool menu::Call_Render(void) {return c_menu->Render();}