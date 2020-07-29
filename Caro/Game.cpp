#include "Game.h"
#include "Common.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <thread>
using namespace std;
_Game::_Game(int pSize, int pLeft, int pTop) {
	_b = new _Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1; // Assign turn and default key
	_x = pLeft; _y = pTop;
}
_Game::~_Game() { delete _b; }

int _Game::getCommand() {
	return _command;
}
bool _Game::isContinue() {
	return _loop;
}

char _Game::askContinue() {
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
	return waitKeyBoard();
}

char _Game::waitKeyBoard() {
	_command = toupper(_getch());
	return _command;
}

void _Game::startGame() {
	system("cls");
	_Common::drawBorder(0,0,30,119);
	_b->resetData();// Setting the original data
	_b->drawBoard(); // Draw boad
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);
}

void _Game::exitGame() {
	system("cls");
	//Maybe save game before stopping
	_loop = false;

}

bool _Game::processCheckBoard() {
	switch (_b->checkBoard(_x, _y, _turn)) {
		_Common::gotoXY(70, 14);
	case -1:
		_Common::gotoXY(_x, _y);
		printf("X");
		break;
	case 1:
		_Common::gotoXY(_x, _y);
		printf("O");
		break;
	case 0: return false; // Tick the cell marked

	}
	return true;
}

int _Game::processFinish() {
	// Move to the reasonable place to print string win/lose/draw
	_Common::gotoXY(70,14);
	int pWhoWin = _b->testBoard(_turn);
	switch (pWhoWin) {
	case -1:
		if(_turn==0)
			cout << "X win \n";
		else {
			cout << "0 win \n";
		}
		break;
	case 1:
		if (_turn == 1)
			cout << "X win \n";
		else {
			cout << "0 win \n";
		}
		break;
	case 0:
		printf("The player %d draw with the player %d\n", false, true);
		break;
	case 2:
		_turn = !_turn; // change turn if nothing happen
	}
	_Common::gotoXY(_x, _y);// Return the current position of cursor
	return pWhoWin;
}

void _Game::moveRight() {
	if (_x < _b->getXAt(_b->getSize() - 2, _b->getSize() - 2)) {
		_x += 4;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize()-2, _b->getSize()-2)) {
		_y += 2;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0)) {
		_y -= 2;
		_Common::gotoXY(_x, _y);
	}
}

void _Game::newGame() {
	_Game g(16, 1,1); // You yourself define some constants
	g.startGame();
	while (g.isContinue()) {
		_Common::gotoXY(70, 14);
		if (g._turn == 1)
			cout << "X";
		else cout << "O";
		_Common::gotoXY(g._x, g._y);
		g.waitKeyBoard();
		if (g.getCommand() == 27) g.exitGame();
		else {
			switch (g.getCommand()) {
			case 'A':
				PlaySound(TEXT("sfx_menu_move4.wav"), NULL, SND_ASYNC);
				g.moveLeft();
				break;
			case 'W':
				PlaySound(TEXT("sfx_menu_move4.wav"), NULL, SND_ASYNC);
				g.moveUp();
				break;
			case 'S':
				PlaySound(TEXT("sfx_menu_move4.wav"), NULL, SND_ASYNC);
				g.moveDown();
				break;
			case 'D':
				PlaySound(TEXT("sfx_menu_move4.wav"), NULL, SND_ASYNC);
				g.moveRight();
				break;
			case 13:
				PlaySound(TEXT("sfx_sound_neutral8.wav"), NULL, SND_ASYNC);
				//Mark the board, then check and process win/lose/draw/continue
				if (g.processCheckBoard()) {
					switch (g.processFinish()) {
					case -1: case 1: case 0:
						PlaySound(TEXT("WinSquare.wav"), NULL, SND_LOOP);
						if (g.askContinue() != 'Y') {
							g.exitGame();
						}
						else g.startGame();
					}
				}
			}
		}
	}
}