#include <iostream>
#include <iomanip>
using namespace std;
class Fraction
{
	friend void addFraction(Fraction , Fraction);
	private:
		int iNumerator;
		int iDenominator;
	public:
		Fraction(void);
		Fraction(int, int);
		void getData(void);
		void showData(void);
		void reduceFraction(void);
};
Fraction ::Fraction(void)
{
	iNumerator = 1;
	iDenominator = 1;
}
Fraction ::Fraction(int i, int j)
{
	iNumerator = i;
	iDenominator = j;
}
void Fraction :: getData(void)
{
	cout << "Enter numerator and denominator of the Fraction" << endl;
	cin >> iNumerator >> iDenominator;
}
void Fraction :: showData(void)
{
	cout << iNumerator << "/" << iDenominator << endl;
}
void Fraction :: reduceFraction(void)
{
	int iVal1,iVal2,iRem;
	iVal1 = iNumerator;
	iVal2 = iDenominator;
	while(iVal2!=0)
	{
		iRem = iVal1 % iVal2;
		iVal1 = iVal2;
		iVal2 = iRem;
	}
	iNumerator /= iVal1;
	iDenominator /= iVal1;
}
void addFraction(Fraction a, Fraction b)
{
	Fraction sum;
	sum.iNumerator = (a.iNumerator * b.iDenominator) + (b.iNumerator * a.iDenominator);
 	sum.iDenominator = a.iDenominator * b.iDenominator;
	cout << "\nSum is: ";
	sum.showData();
	sum.reduceFraction();
	cout << "\nReduced form is: ";
	sum.showData();
}
int main(void)
{
	Fraction c1(5,3),c2(6,4);
	addFraction(c1,c2);
	c1.getData();
	c2.getData();
	addFraction(c1,c2);
	cin.get();
	return 0;
}
