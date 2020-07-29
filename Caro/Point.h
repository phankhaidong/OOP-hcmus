#ifndef Point_H
#define Point_H

class _Point {
	int _x, _y, _check;
public:
	_Point();
	_Point(int, int);
	bool setCheck(int);
	int getX();
	int getY();
	int getCheck();
	void setX(int);
	void setY(int);
};

#endif // !Point_H
