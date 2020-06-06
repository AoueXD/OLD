#include <iostream>
#include <cmath>

using namespace std;

double MyAbs(double value);

class xyPlane {
public:
	xyPlane(double xValue, double yValue);
	xyPlane();
	double getX();
	double getY();
	xyPlane difference(xyPlane P);
	double length();
	void output() {cout << "(" << x << ", " << y << ")";};
private:
	double x;
	double y;
};

double area (xyPlane p, xyPlane q, xyPlane r);
double perimeter(xyPlane p, xyPlane q, xyPlane r);

double RRRRR(int size);

int main() {
	double x, y;
	xyPlane p(1, 3), q, r, temp;
	
	cout << "The x-coordinate of the third vector: ";
	cin >> x;
	cout << "The y-coordinate of the third vector: ";
	cin >> y;
	r = xyPlane(x, y);
	
	cout << "The area is " << area(p, q, r) << endl;
	cout << "The perimeter is " << perimeter(p, q, r) << endl;
	
	return 0;
}

double RRRRR(double size) {
	if(size < 0)
		size * -1;
}

xyPlane::xyPlane(double xValue, double yValue){
	double d;
	
	d.x = d + d.x;
	d.y = d + d.y;
	
	return d;
} 

double xyPlane::getX(){
	return x;
}

double xyPlane::getY() {
	return y;
}

double area (xyPlane p, xyPlane q, xyPlane r) {
	double x1, y1, x2, y2, x3, y3;
	
	x1 = r.x;
	y1 = r.y;
	
	cout << "Please cin >> x2 >> x3 >> y2 >> y3: ";
	cin >> x2 >> x3 >> y2 >> y3;
	
	RRRRR(((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2);
}
