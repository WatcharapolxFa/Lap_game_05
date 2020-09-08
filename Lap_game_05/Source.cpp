#include<stdio.h>
#include<conio.h>
#include<windows.h>

void draw_ship(int, int);
void gotoxy(int, int);
void erase_ship(int, int);
void setcursor(bool);
void setcolor(int, int);
void bullet(int ,int);

int main()

{
	char ch = ' ';
	int direct = 0;
	int x = 38, y = 20;
	draw_ship(x, y);

	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { direct = 1; }
			if (ch == 'd' ) { direct = 2; }
			if (ch == 'w') { direct = 3; }
			if (ch == 's' ) { direct = 4; }
			if (ch == ' ') { direct = 5; }
			fflush(stdin);
		}
		if (direct > 0)
		{
			if (direct==1 && x > 0) { erase_ship(x, y); draw_ship(--x, y); }
			if (direct == 2 && x < 113) { erase_ship(x, y); draw_ship(++x, y); }
			//if (direct == 3 && y > 0) { erase_ship(x, y); draw_ship(x, --y); }
			if (direct == 4 && y < 30) { erase_ship(x, y); draw_ship(x, y); }
			if (direct == 5 && y < 30) { bullet(x, y); draw_ship(x, --y); }
		}
		Sleep(100);
		setcolor(2, 0);
	} while (ch != 'x');
	return 0;
}

void draw_ship(int x, int y)
{
	setcursor(0);
	setcolor(2, 4);
	gotoxy(x, y);
	printf(" <-0-> ");
}

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("       ");
	
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void bullet(int x, int y)
{
	gotoxy(x, y);
	printf("|");
}