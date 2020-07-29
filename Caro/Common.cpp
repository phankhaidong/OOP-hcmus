#include "Common.h"
#include <Windows.h>
#include <iostream>
using namespace std;

void _Common::gotoXY(int pX, int pY) {
	COORD coord;

	coord.X = pX;

	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void _Common::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	/*SetWindowLong(consoleWindow, GWL_STYLE, style);*/    SetWindowLong(consoleWindow, GWL_STYLE, style);}void _Common::TextColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void _Common::clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void _Common::drawBorder(int x, int y, int height, int width) {
    for (int i = x; i < width; i++) {
        _Common::gotoXY(i, y);
        cout << char(205);
        _Common::gotoXY(i, y+height);
        cout << char(205);
    }
    for (int i = y; i < height; i++) {
        _Common::gotoXY(x, i);
        cout << char(186);
        _Common::gotoXY(x+width, i);
        cout << char(186);
    }
    _Common::gotoXY(x, y);
    cout << char(201);
    _Common::gotoXY(x+width,y );
    cout << char(187);
    _Common::gotoXY(x, y+height);
    cout << char(200);
    _Common::gotoXY(x+width, y+height);
    cout << char(188);
    _Common::gotoXY(0, 0);
}

void _Common::setConsoleWindow() {
    fixConsoleWindow();
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 900, 550, TRUE);
}