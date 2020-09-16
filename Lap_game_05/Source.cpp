#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>


void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void setcolor(int, int);
void setcursor(bool);
void bullet(int, int);
void bullet_ship(int, int);


int main()
{
	setcursor(0);
	int nub[2];
	int bullet[5];
	int position_x[5];
	int position_y[5];
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	for (int i = 0; i < 5; i++)
	{
		position_x[i] = x;
		position_y[i] = y;
	}
	do {
		if (kbhit()) {
			ch = getch();

			if (ch == 'w')
			{
				nub[0] = 1;
			}

			if (ch == 'a')
			{
				nub[0] = 2;
			}

			if (ch == 's')
			{
				nub[0] = 3;
			}

			if (ch == 'd')
			{
				nub[0] = 4;
			}

			if (ch == ' ')
			{
				nub[0] = 5;
			}
			fflush(stdin);


		}
		if (nub[0] == 1 && x > 0)
		{
			erase_ship(x, y); draw_ship(x, y);
		}
		if (nub[0] == 2 && x < 113)
		{
			erase_ship(x, y); draw_ship(--x, y);
		}
		if (nub[0] == 3 && y > 0)
		{
			erase_ship(x, y); draw_ship(x, y);
		}
		if (nub[0] == 4 && y < 30)
		{
			erase_ship(x, y); draw_ship(++x, y);
		}
		if (nub[0] == 5)
		{

		}

		Sleep(100);
		setcolor(2, 0);
	} while (ch != 'x');

	return 0;
}



// Ship position
void gotoxy(int x, int y)
{
	COORD c = { x , y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


// Draw_ship
void draw_ship(int x, int y)
{
	setcursor(0);
	setcolor(2, 4);
	gotoxy(x, y); printf(" <-0-> ");
}

// erase_ship
void erase_ship(int x, int y)
{
	gotoxy(x, y); printf("       ");
}
//set color
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
// setcursor
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
// Draw_bullet
void bullet(int x, int y)
{


	setcolor(2, 0);
	gotoxy(x, y); printf(" < ^ > ");

}
// bullet_ship
void bullet_ship(int x, int y)
{
	gotoxy(x, y); printf("       ");
}
