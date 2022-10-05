#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define _USE_MATH_DEFINES
//массив стилей линий
char *lname[] = {
"SOLID_LINE",
"DOTTED_LINE",
"CENTER_LINE",
"DASHED_LINE",
"USERBIT_LINE"
};

int main()
{

int  graph_mode, graph_error_code,graph_driver = DETECT;
int style, midx, midy;
char stylestr[40];

initgraph(&graph_driver, &graph_mode, "c:\\turboc3\\bgi");

//проверка возможно ли инициализировать графику
graph_error_code = graphresult(); //возвращаем код ошибки
if (graph_error_code != grOk) //и если ошибка
{
printf("Graphics error: %s\n", grapherrormsg(graph_error_code)); //Выводим стандартное сообщение
getch();
return 255; //аварийный выход из программы
}

midx = getmaxx() / 2; //находим координаты середины экрана
midy = getmaxy() / 2; //деля максимум по х и по у пополам
setbkcolor(7);
setcolor(5);
setlinestyle(SOLID_LINE, 1, 3); //устанавливаем стиль линии//копируем в строку название типа
line(midx, 0, midx, getmaxy()); 
line(0, midy, getmaxx(),  midy); 
rectangle(0, 0, getmaxx(), getmaxy()); //рис

getch();
cleardevice(); //очищаем экран
closegraph(); //возвращаемся в текстовый режим
return 0;
}