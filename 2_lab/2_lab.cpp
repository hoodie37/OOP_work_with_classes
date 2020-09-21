#include "pch.h"
#include <iostream>
using namespace std;

class Point {
protected:	int x, y;
public:

	Point() {
		printf("Point()\n");
		x = 0;
		y = 0;
	}

	Point(int x, int y) {
		printf("Point(int x, int y)\n");
		this->x = x;
		this->y = y;
	}

	Point(const Point &p) {
		printf("Point(const Point &p)\n");
		x = p.x;
		y = p.y;
	}

	~Point() {
		printf("~Point\n");
		printf("%d, %d\n", x, y);
	}

	virtual void Move(int x, int y) {
		this->x += x;
		this->y += y;
	}

	void Reset() {
		x = 0;
		y = 0;
	}
};


class TrexMern : public Point {
protected:
	int z;

public:
	TrexMern() : Point() {
		printf("TrexMern()\n");
		z = 0;
	}

	TrexMern(int x, int y, int z) : Point(x, y) {
		printf("TrexMern(int x, int y, int z)\n");
		this->z = z;
	}

	TrexMern(const TrexMern &t) {
		printf("TrexMern(const TrexMern &t)\n");
		x = t.x;
		y = t.y;
		z = t.z;
	}

	~TrexMern() {
		printf("~TrexMern\n");
		printf("%d, %d , %d\n", x, y, z);
	}

	void Move(int x, int y, int z) {
		this->x += x;
		this->y += y;
		this->z += z;
	}
};

class Rect {
protected:
	Point *p1;
	Point *p2;
	Point *p3;
	Point *p4;
public:
	Rect() {
		printf("Rect()\n");
		p1 = new Point;
		p2 = new Point;
	}

	Rect(int x1, int y1, int x2, int y2) {
		printf("Rect(int x1,int y1,int x2,int y2)\n");
		p1 = new Point(x1, x2);
		p2 = new Point(x2, y2);
		p3 = new Point(x1, y2);
		p4 = new Point(x2, y1);
	}

	Rect(const Rect &r) {
		printf("Rect(const Rect &r)\n");
		p1 = new Point(*(r.p1));
		p2 = new Point(*(r.p2));
		p3 = new Point(*(r.p3));
		p4 = new Point(*(r.p4));
	}

	~Rect() {
		delete p1;
		delete p2;
		delete p3;
		delete p4;
		printf("~Rect()");
	}

	/*void Perimeter(const Rect &r) {
		int P = 0;
		if (p1.x2 > x1 && y2 > y1) {
			P = (x2 - x1) * 2 + (y2 - y1) * 2;
		}
		if (x2 > x1 && y2 < y1) {
			P = (x2 - x1) * 2 + (y1 - y2) * 2;
		}
		if (x2<x1 && y2>y1) {
			P = (x1 - x2) * 2 + (y2 - y1) * 2;
		}
		if (x2 < x1 && y2 < y1) {
			P = (x1 - x2) * 2 + (y1 - y2) * 2;
		}
		//return P;
		printf("%d", P);
	}

	int Ploshad(int x1, int y1, int x2, int y2) {
		int S = 0;
		if (x2 > x1 && y2 > y1) {

			S = (x2 - x1) * (y2 - y1);
		}
		if (x2 > x1 && y2 < y1) {

			S = (x2 - x1)*(y1 - y2);
		}
		if (x2<x1 && y2>y1) {

			S = (x1 - x2)*(y2 - y1);
		}
		if (x2 < x1 && y2 < y1) {

			S = (x1 - x2)*(y1 - y2);
		}
		return  S;
	}*/
};

int main()
{
	//Статическое создание и удаление
	{
		Point p;
		Point p2(10, 10);
		Point p3(p2);
	}

	// Динамическое создание и удаление объектов

	Point *p = new Point();
	Point *p2 = new Point(10, 15);
	Point *p3 = new Point(*p2);

	p2->Move(5, 5);
	p3->Reset();
	delete p;
	delete p2;
	delete p3;
	printf("\n\n");

	Point *t = new TrexMern();
	Point *t2 = new TrexMern(10, 10, 10);
	TrexMern *t3 = new TrexMern(10, 15, 20);
	TrexMern *t4 = new TrexMern(*t3);
	printf("\n");

	delete t;
	delete t2;
	delete t3;
	delete t4;
	printf("\n\n");

	Rect *r = new Rect();
	Rect *r2 = new Rect(10, 10, 20, 20);
	Rect *r3 = new Rect(*r2);
	printf("\n");
	//r2->Perimeter();

	delete r;
	delete r2;
	delete r3;

	return 0;
}