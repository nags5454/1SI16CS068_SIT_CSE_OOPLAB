#include <iostream>
using namespace std;
class FractionType
{
	private:
	    int iNum, iDen;
	public:
		FractionType(){}
	    FractionType(int,int);
	    void fnSetFraction(int, int);
	    void fnShowFraction();
		friend FractionType operator+ (const FractionType&, const FractionType&);
		friend FractionType operator+(const FractionType&,int);
		friend FractionType operator+(int, const FractionType&);
		friend bool operator==(const FractionType& , const FractionType&);
		FractionType operator=(const FractionType&);
		friend FractionType operator-(FractionType&);
		friend ostream& operator<<(ostream&, const FractionType&);
};
ostream& operator<<(ostream &out, const FractionType &f)
{
	out << "Fraction : " << "( " << f.iNum << " / " << f.iDen << " )" << endl;
	return out;
}
FractionType operator-(FractionType &f1)
{
	f1.iNum = -1 * f1.iNum;
}
FractionType FractionType :: operator=(const FractionType &f2)
{
	iNum = f2.iNum;
	iDen = f2.iDen;
	return *this;
}
FractionType operator+(const FractionType &f1, int val)
{
	FractionType f3;
	f3.iNum = f1.iNum + f1.iDen * val;
	f3.iDen = f1.iDen;
	return f3;
}
FractionType operator+( int val, const FractionType &f1)
{
	FractionType f3;
	f3.iNum = f1.iNum + f1.iDen * val;
	f3.iDen = f1.iDen;
	return f3;
}
bool operator==(const FractionType &f1, const FractionType &f2)
{
	if(f1.iNum * f2.iDen == f1.iDen * f2.iNum)
		return true;
	else
		return false;
}
FractionType operator+(const FractionType &f1, const FractionType &f2)
{
	FractionType f3;
	f3.iNum = f1.iNum * f2.iDen + f1.iDen * f2.iNum;
	f3.iDen = f1.iDen * f2.iDen;
	return f3;
}
FractionType :: FractionType(int iVal1, int iVal2)
{
	iNum = iVal1;
	iDen = iVal2;
}
void FractionType :: fnSetFraction(int iN, int iD)
{
	iNum = iN;
	iDen = iD;
}
void FractionType :: fnShowFraction()
{
	cout << "Fraction : " << "( " << iNum << " / " << iDen << " )" << endl;
}
int main()
{
	int a = 2, b = 7, c;
	FractionType p(3,4), q(1,3);
	FractionType r;
	r = p + q;
	cout << p;
	cout << q;
	cout << r;
	r = q + 2;
	cout << q;
	cout << r;
	cout << q;
	cout << r;

	-r;
	cout << r;
	return 0;

}
