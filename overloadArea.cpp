#include <iostream>
#include <cmath>
using namespace std;
int fnCalcArea(int);
float fnCalcArea(float);
int fnCalcArea(int, int);
float fnCalcArea(int, int, int);
int main()
{
	double dRes;
	cout << fnCalcArea(8) << endl;
	cout << fnCalcArea(8.5f) << endl;
	cout << fnCalcArea(8,4) << endl;
	cout << fnCalcArea(3,4,5) << endl;
	return 0;
}
int fnCalcArea(int side)
{
	return side * side;
}
float fnCalcArea(float radius)
{
	return (float)M_PI * radius * radius;
}
int fnCalcArea(int length , int breadth)
{
	return length * breadth;
}
float fnCalcArea(int base , int height1, int height2)
{
	return 0.5f*(height1+height2)*base;
}
