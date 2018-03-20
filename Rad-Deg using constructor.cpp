#include <iostream>
#include <cmath>
using namespace std;
class Degree{
    int degVal;
    public:
    Degree(){degVal = 0;}
    Degree(int val) {degVal = val;}
    void readDeg(){cin >> degVal;}
    void displayDeg(){cout << "Degree : " << degVal << endl;}
    int fetchDegVal(){ return degVal;}
};
    class Radian{
        float radVal;
		public:
		Radian(){radVal = 0.0;}
		Radian(Degree d)
		{
		    cout << "\nconstructor called\n";
		    radVal = d.fetchDegVal() * M_PI/180;
		}
		void readRad(){cin >> radVal;}
		void displayRad(){cout << "Radian : " << radVal << endl;}
		operator Degree() const;
	};
	Radian :: operator Degree() const
	{
		cout << "\nConversion Operator called\n";
		int degree;
		degree = int (round(radVal * 180/M_PI));
		return Degree(degree);
	}
	int main()
	{
		Degree dAng;
		cout << "\nEnter an angle in degrees" << endl;
		dAng.readDeg();
		dAng.displayDeg();
		cout << "\nDegree to Radian Conversion\n";
		Radian rAng(dAng);
		rAng.displayRad();
		cout << "\nRadian to Degree Conversion\n";
		Degree newAng = static_cast<Degree>(rAng);
		newAng.displayDeg();
		return 0;
	}
