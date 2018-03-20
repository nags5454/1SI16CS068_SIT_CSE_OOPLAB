#include <iostream>
#include <cmath>
using namespace std;
void fnVol(int);
void fnVol(double);
void fnVol(double, int);
void fnVol(int, int, int);
int main()
{
	int iSide, iL, iB, iH;
	double dRad;
	cout << "\nEnter side length of cube" << endl;
	cin >> iSide;
	fnVol(iSide);
	cout << "\nEnter radius of sphere" << endl;
	cin >> dRad;
	fnVol(dRad);
	cout << "\nEnter side lengths of cuboid" << endl;
	cin >> iL >> iB >> iH;
	fnVol(iL, iB, iH);
	cout << "\nEnter radius and height of cylinder" << endl;
	cin >> dRad >> iH;
	fnVol(dRad, iH);
	return 0;
}
void fnVol(int iS)
{
	cout << "\nVolume of Cube is : " << iS*iS*iS << " units." << endl;
}
void fnVol(double dR)
{
	cout << "\nVolume of Sphere is : " << 4.0/3.0*M_PI*dR*dR*dR << " units." << endl;
}
void fnVol(double dR, int iH)
{
	cout << "\nVolume of Cylinder is : " << M_PI*dR*dR*iH << " units." << endl;
}
void fnVol(int iL, int iB, int iH)
{
	cout << "\nVolume of Cuboid is : " << iL*iB*iH << " units." << endl;
}
