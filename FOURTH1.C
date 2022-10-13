#include <conio.h>
#include <stdio.h>
#include <dos.h>

void set_background(){
	window(1,1,80,25);
	textbackground(0);
	clrscr();
}
void text(){
	textcolor(15);
	gotoxy(12,1);
	cprintf("The program is designed to control the symbol movement \"*\"\n\r");
	gotoxy(17,2);
	cprintf("F1 - shift to the right F2 - shift to the left");
	}

void draw_window(int x, int y){
	window(19,4,61,16);
	textbackground(2);
	clrscr();	
	window(20,5,60,15);
	textcolor(1);
	textbackground(7);
	clrscr();
	gotoxy(x,y);
	cprintf("*");
}


int main(){
	int x = 1 ,y = 1;
	int current_button;

	clrscr();

	set_background();
	text();
	draw_window(x,y);

	while(1){

		gotoxy(10,30);
		current_button = getch();
		if(current_button == 27){
		break;
		}
		else if(current_button == 59){
			clrscr();
			if(x>1 && x<41){
				x--;
			}
			else{
				y++;
				y = y%12;
				x = 1;
			}
			
			gotoxy(x,y);
			cprintf("*");
		}
		else if (current_button == 60){
			clrscr();
			if(x>0 && x<40){
				x++;
			}
			else{ 
				y++;
				y = y%11;
				x = 1;
			}
			gotoxy(x,y);
			cprintf("*");

		}
	}



	return 0;
}