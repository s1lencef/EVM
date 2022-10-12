#include <conio.h>
#include <stdio.h>
#include <dos.h>
/**/
void scroll(int direction, char l_row, char l_col, char r_row, char r_col, char attr){
	union REGS r;
	if(direction){
	r.h.al = 1;
	r.h.ah = 7;
	}
	else{
	r.h.al = 0;
	r.h.ah = 6;
	}
	r.h.al = attr;
	r.h.ch = l_row;
	r.h.cl = l_col;
	r.h.dh = r_row;
	r.h.dl = r_col;
	int86(0x10,&r,&r);
	}

void read_cursor(char *x, char *y)
{
	union REGS r;

	r.h.ah = 3;
	r.h.bh = 0;

	int86(0x10,&r,&r);

	*y = r.h.dl;
	*x = r.h.dh;
}
int main(){
	int i,j;
	int *c_x,*c_y;
	clrscr();
	window(19,4,61,16);
	textbackground(1);
	clrscr();
	window(20,5,60,15);
	textbackground(0);
	clrscr();

	for(i = 0; i<16;i++){
		for(j = 0; j<16;j++){
			textbackground(i);
			textcolor(j);
			cprintf("\n\r");	
			read_cursor(c_x, c_y);
			cprintf(" Background color is %d,Text color is %d\n\n \r", i,j);
			if (c_y == 12824 && c_x == -28908){
				scroll(1, 20,5,60,15, 3);
			}
		delay(500);
		}
	}
getch();
window(1,1,80,25);
textbackground(0);
textcolor(7);
clrscr();


return 0;
}