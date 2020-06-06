#include <iostream>

using namespace std;

class Cubic {
	public:
		Cubic(double lvalue, double bvalue, double hcalue);
		Cubic();
		double Volume;
		double Surface;
	private:
		double length;
		double breadth;
		double height;
};

int main() {
	Cubic C1(3.5, 1.2, 1.0);
	Cubic C2(7.5, 6.0, 2.0);
	Cubic C3;
	double length, breadth, height;
	
	cout << "Input the length, breadth and height for C3:" << endl;
	cout << "length = ";
	cin >> length;
	cout << "breadth = ";
	cin >> breadth;
	cout << "height = ";
	cin >> height;
	
	C3 = Cubic(length, breadth, height);
	
	cout << "The C1's volume is " << C1.Volume;
	cout << "and surface is " << C1.Surface << endl;
	
	cout << "The C2's volume is " << C2.Volume;
	cout << "and surface is " << C2.Surface << endl;
	
	cout << "The C3's volume is " << C3.Volume;
	cout << "and surface is " << C3.Surface << endl;
	
	return 0;
}

Cubic::Cubic(double lvalue, double bvalue, double hcalue)	{
	return length; 
	return breadth; 
	return height;
}
	
Cubic::Cubic():
	length(1), breadth(1), height(1){};
	
double Cubic::Volume{
	return (length * breadth + length * height + height * breadth) * 2 ;
}
double Cubic::Surface{
	return lenght * breadth * height;
}
