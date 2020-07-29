#ifndef Menu_H
#define Menu_H
#include <fstream>
#include <string>

using namespace std;

class _Menu {
	int leftMargin = 55;
	int  topMargin = 16;
	int botMargin = 20;
public:
	void printMenu();
	void printLogo(const string ,int ,int ,int);
	int selecMenu();
	void updateMenu(int);
	void switchMenu(int);
	void selectMode();
	//void newGame();
	void loadGame();
	void setting();
	void help();
	void updateGameMode(int);
};

#endif // !Menu_H
