#include "menu.h"
bool menu::Render()//Функция рисования
{
	hge->Gfx_BeginScene();//Начинаем вывод графики
	hge->Gfx_Clear(0);//Чистим окно
	gui->Render();//Рисуем объекты
	main->Render(width/2,height*0.2f);//Рисуем картинку
	if(author_visible)//Если активно "окно" авторов
	{	//Выводим текст, указывающий авторов
		font->printfb(width/2-50,height * 0.4f,100,40,HGETEXT_CENTER,"Authors");
		font->printfb(width/2-150,height * 0.6f,300,40,HGETEXT_CENTER,"Developer:\nIvont'ev Nikolay");
	}
	if(setting_visible)//Если активно "окно" настроек
	{
		font->printfb(width/2-50,height*0.37f,100,40,HGETEXT_CENTER,"Setting");
		switch(select_screen)//В зависимости от значения выводит текущий параметр
		{
		case 0: font->printfb(width/2,height*0.45f,120,30,HGETEXT_CENTER,"Desktop"); break;
		case 1: font->printfb(width/2,height*0.45f,120,30,HGETEXT_CENTER,"800x600"); break;
		case 2: font->printfb(width/2,height*0.45f,120,30,HGETEXT_CENTER,"1024x768"); break;
		case 3: font->printfb(width/2,height*0.45f,120,30,HGETEXT_CENTER,"1280x720"); break;
		case 4: font->printfb(width/2,height*0.45f,120,30,HGETEXT_CENTER,"1280x1024"); break;
		}
		font->printfb(width/2-150,height*0.45f,100,30,HGETEXT_LEFT,"Display");
		font->printfb(width/2-100,height*0.6f,100,40,HGETEXT_LEFT,"Sound");
		font->printfb(width/2-100,height*0.7f,200,40,HGETEXT_LEFT,"Full Screen");
	}
	if(game_visible)//Если активно "окно" выбора уровня
	{
		font->printfb(width/2-150,height*0.37f,300,40,HGETEXT_CENTER,"Select save for game");
		font->printfb(width/2-100,height*0.55f,200,30,HGETEXT_CENTER,save[select_level].substr(0,save[select_level].size()-4).c_str());
	}
	hge->Input_GetMousePos(&point.x, &point.y);//Забираем координаты мыши
	cursor->Render(point.x,point.y); //Рисуем курсор
	hge->Gfx_EndScene();//Заканчиваем вывод графики
	return false;
}