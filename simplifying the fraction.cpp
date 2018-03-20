#include <iostream>
#include <cmath>
using namespace std;
class FRACTION_TYPE
{
	int iNum, iDen;
	int gcd(int, int);
	public:
	void fnSetFraction(int, int);
	void fnShowFraction(void);
	void fnAddFraction(FRACTION_TYPE);
	void fnReduceFraction();
};
void FRACTION_TYPE :: fnSetFraction(int iN, int iD)
{
	this->iNum = iN;
	iDen = iD;
}
void FRACTION_TYPE :: fnShowFraction()
{
	cout << "(" << iNum << "/" << iDen << ")" << endl;
}
void FRACTION_TYPE :: fnAddFraction(FRACTION_TYPE f2)
{
	FRACTION_TYPE f3;
	f3.iNum = (iNum*f2.iDen) + (iDen*f2.iNum);
	f3.iDen = iDen * f2.iDen;
	cout << "The sum is ";
	f3.fnShowFraction();
	f3.fnReduceFraction();
	cout << "The sum in simplified form is ";
	f3.fnShowFraction();
}
void FRACTION_TYPE :: fnReduceFraction()
{
	int iVal;
	iVal = gcd(iNum,iDen);
	iNum = iNum / iVal;
	iDen = iDen / iVal;
}
int FRACTION_TYPE :: gcd(int m, int n)
{
	if(0==n)
		return m;
	else
		return (gcd(n, m%n));
}
int main()
{
	FRACTION_TYPE f1, f2;
	int iN, iD;
	cout << "\nEnter the numerator and denominator of Fraction 1" << endl;
	cin >> iN >> iD;
	f1.fnSetFraction(iN, iD);
	cout << "\nEnter the numerator and denominator of Fraction 2" << endl;
	cin >> iN >> iD;
	f2.fnSetFraction(iN, iD);
	cout << "\nFraction 1 : ";
	f1.fnShowFraction();
	cout << "\nFraction 2 : ";
	f2.fnShowFraction();
	f1.fnAddFraction(f2);
	return 0;
}
