
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#define _USE_MATH_DEFINES
//массив стилей линий

void coordinate_plane(int midx, int midy){

	line(midx/4, 10, midx/4, getmaxy()-10);
	line(10, midy, getmaxx()-10,  midy);

	line(getmaxx()-10, midy, getmaxx()-15, midy+3);
	line(getmaxx()-10, midy, getmaxx()-15, midy-3);

	line(midx/4, 10, midx/4+3, 15);
	line(midx/4, 10, midx/4 -3, 15);
	setcolor(1);
	outtextxy(getmaxx()-18, midy+8,"X");
	outtextxy(midx/4-12, 12,"Y");

}

void output_text(int midx, int midy, float x, float y){
	char xx[64],yy[64];

	sprintf(xx,"%.4g",x);
	sprintf(yy,"%.4g",y);

	setcolor(8);
	outtextxy(midx/4+((24/M_PI)*x), midy+10,xx);
	outtextxy(midx/4-50, midy-(y*(64/M_PI)),yy);

	setcolor(1);
	moveto( midx/4 -3 ,midy-(y*(64/M_PI)));
	lineto( midx/4 +3, midy-(y*(64/M_PI)));

	moveto( midx/4+((24/M_PI)*x),midy-3);
	lineto(midx/4+((24/M_PI)*x), midy+3);
}

void print_max_value(float max_arg, float max_val){
	char c_x[64],c_y[64];
	sprintf(c_x,"The function reaches a maximum  = %f",max_val);
	sprintf(c_y,"When x = %f",max_arg);
	setcolor(8);
	rectangle( getmaxx()-410, getmaxy()-80, getmaxx()-60, getmaxy()-35);
	outtextxy(getmaxx()-400,getmaxy()-70,c_x);
	outtextxy(getmaxx()-400,getmaxy()-50,c_y);

}

int main(){

	int  graph_mode, graph_error_code,graph_driver = DETECT;
	int style, midx, midy, flag = 1;
	float x = (3*M_PI)/2,y, max_arg, max_val = 0;

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
	bar	(10,10,getmaxx()-10,getmaxy()-10);


	setcolor(1);
	setlinestyle(SOLID_LINE, 1, 1); 

	coordinate_plane(midx,midy);

	setcolor(2);
	y = (sin(x/4)*sin(x/4)) + sqrt(x);
	output_text(midx,midy, x, y);

	do{
		delay(5);

		setcolor(2);
		moveto( midx/4+((24/M_PI)*x), midy-(y*(64/M_PI)));

		y = (sin(x/4)*sin(x/4)) + sqrt(x);

		lineto(midx/4+((24/M_PI)*x), midy-(y*(64/M_PI)));

		if(y>max_val){
			max_val  = y;
			max_arg = x;
		}

		if( flag /100 > (flag-1)/100){

			output_text(midx,midy, x, y);

		}

		flag++;

		x += M_PI/32;
	}while(x<17*M_PI);

	print_max_value(max_arg, max_val);

	getch();
	cleardevice(); //очищаем экран
	closegraph(); //возвращаемся в текстовый режим
	return 0;
}