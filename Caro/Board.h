#ifndef Board_H
#define Board_H
#include "Point.h"
class _Board {
private:
	int _size;
	int _left, _top;
	_Point** _pArr;
public:
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	_Board(int, int, int);
	~_Board();
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard(bool);
	int testVertical(int);
	int testHorizontal(int);
	int testDiagonalDown(int);
	int testDiagonalUp(int);
	int testDraw();
};

#endif // !Board_H
