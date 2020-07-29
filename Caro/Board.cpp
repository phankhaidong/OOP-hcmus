#include "Board.h"
#include "Common.h"
#include <iostream>

using namespace std;

int _Board::getSize() { return _size; }
int _Board::getLeft() { return _left; }
int _Board::getTop() { return _top; }

int _Board::getXAt(int i, int j) {
	return _pArr[i][j].getX();
}

int _Board::getYAt(int i, int j) {
	return _pArr[i][j].getY();}
_Board::_Board(int pSize, int pX, int pY) {
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new _Point * [pSize];
	for (int i = 0; i < pSize; i++) _pArr[i] = new _Point[pSize];
}

_Board::~_Board() {
	for (int i = 0; i < _size; i++) delete[] _pArr[i];
	delete[] _pArr;}void _Board::resetData() {
	if (_size == 0) return; // Firstly calling constructor before calling resetData
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2); // x-value of boardgame
			_pArr[i][j].setY(2 * i + _top + 1); // y-value of boardgame
			_pArr[i][j].setCheck(0);
		}
	}
}
void _Board::drawBoard() {
	if (_pArr == NULL) return; // firstly call constructor
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_Common::gotoXY(_left + 4 * i, _top + 2 * j);
			printf(".");
		}
	}
	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());//move to the 1
}

int _Board::checkBoard(int pX, int pY, bool pTurn) {
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0) {
				if (pTurn) _pArr[i][j].setCheck(-1);
				else _pArr[i][j].setCheck(1);
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}

int _Board::testHorizontal(int key) {
	int endCondition = 2;
	for (int row = 0; row < _size; row++) {
		int count = 1;
		for (int col = 0; col < _size; col++) {
			if (_pArr[row][col].getCheck() == key && _pArr[row][col + 1].getCheck() == key) {
				count++;
			}
			if (_pArr[row][col].getCheck() != key || _pArr[row][col + 1].getCheck() != key) {
				count = 1;
			}
			if (count == 5) {
				endCondition = 1;
				return endCondition;
			}
		}
	}
	return endCondition;
}

int _Board::testVertical(int key) {
	int endCondition = 2;
	for (int col = 0; col < _size; col++) {
		int count = 1;
		for (int row = 0; row < _size; row++) {
			if (_pArr[row][col].getCheck() == key && _pArr[row+1][col].getCheck() == key)
				count++;
			if (_pArr[row][col].getCheck() != key || _pArr[row+1][col].getCheck() != key)
				count = 1;
			if (count == 5) {
				endCondition = 1;
				return endCondition;
			}
		}
	}
	return endCondition;
}

int _Board::testDiagonalDown(int key) {
	int endCondition = 2;
	for (int row = 0; row < _size; row++) {
		for (int col = 0; col < _size; col++) {
			int count = 1;
			int i = row;
			int j = col;
			while (i < _size&& j < _size) {
				if (_pArr[i][j].getCheck() == key && _pArr[i + 1][j+1].getCheck() == key)
					count++;
				if (_pArr[i][j].getCheck() != key || _pArr[i + 1][j+1].getCheck() != key)
					count = 1;
				if (count == 5) {
					endCondition = 1;
					return endCondition;
				}
				i++;
				j++;
			}
		}
	}
	return endCondition;
}

int _Board::testDiagonalUp(int key) {
	int endCondition = 2;
	for (int row = _size; row >0; row--) {
		for (int col = _size; col >0; col--) {
			int count = 1;
			int i = row;
			int j = col;
			while (i < _size && j < _size) {
				if (_pArr[i][j].getCheck() == key && _pArr[i - 1][j + 1].getCheck() == key)
					count++;
				if (_pArr[i][j].getCheck() != key || _pArr[i - 1][j + 1].getCheck() != key)
					count = 1;
				if (count == 5) {
					endCondition = 1;
					return endCondition;
				}
				i++;
				j++;
			}
		}
	}
	return endCondition;
}

int _Board::testBoard(bool pTurn) {
	int key = 0;
	if (pTurn == 0)
		key = 1;
	else key = -1;
	if (testVertical(key) != 2)
		return testVertical(key);
	if (testHorizontal(key) != 2)
		return testHorizontal(key);
	if (testDiagonalDown(key != 2))
		return testDiagonalDown(key);
	if (testDiagonalUp(key != 2))
		return testDiagonalUp(key);
	return 0;
}