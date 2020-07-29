#include "Board.h"
#include "Common.h"
#include "Game.h"
#include "Point.h"
#include "Menu.h"
#include <iostream>
using namespace std;

int main() {
	_Menu a;
	_Common::setConsoleWindow();
	system("color F0");
	a.printLogo("banner.txt",36,6,100);
	a.printMenu();
	a.selecMenu();
	return 0;
}


