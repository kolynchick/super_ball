#include "menu.h"
menu create;
//Главная функция программы (как и в WinAPI) на вход подается дескриптор окна, класс окна, создание окна, возвращение значения при неудаче
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){create.Start(false);}
