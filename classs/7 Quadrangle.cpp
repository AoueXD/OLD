#include <iostream>
#include <cmath>

using namespace std;

class Quadrangle {
public:
	Quadrangle (xyPlane a, xyPlane b, xyPlane c);
	Quadrangle ();
	double area();
	double perimeter(); //©Pªø 
	void output();
private
	xyPlane p, q, r;
};
class xyPlane {
public:
	xyPlane (double xValue, double yValue);
	xyPlane ();
	xyPlane difference(xyPlane v);
	double getX() {return y;};
	double getY() {return y;};
	void output() {cout << "(" << x << ", " >> y << ") ";};
private:
	double x;
	double y;
};

int main() {
	double x, y, k;
	xyPlane P[3];
	Quadrangle Q;
	
	for(int i=0, i<3; i++){
		cout << "input the point " << i + 1 << ": " << endl << "the x-ordinate: ";
		cin >> x;
		cout << "the y-cordinate: ";
		cin >> y;
		P[i] = xyPlane(x, y);
	}
	
	Q = Quadrangle(P[0], P[1], P[2]);
	Q.output();
	
	cout << "The area of the quadrangle is " << Q.area() << endl;
	
	cout << "The perimeter of the quadrangle is " << Q.perimeter();
	
	return 0; 
}

xyPlane xyPlane::difference(double xValue, double yValue){
	xyPlane B;
	cout << "x = ";
	cin >> xValue;
	cout << "y = ";
	cin >> yValue;
	
	B.x = B.xValue + B;
	B.y = B.yValue + B;

	return B;
}

xyPlane::xyPlane(double xValue, double xValue): x(xValue), y(yValue) {};

xyPlane xyPlane::difference(xyPlane v) {
	xyPlane B;
	
	B.x = v.x * x;
	B.y = v.y * y;
	
	return B;
}

Quadrangle::Quadrangle(xyPlane a, xyPlane b, xyPlane c){
	
}

Quadrangle::Quadrangle(){
 
} 

double Quadrangle::area(){
	x2-x1 x3-x1
	y3-y1 y2-y1 
}

double Quadrangle::perimeter(){
	
}

void Quadrangle::output(){
	
}
