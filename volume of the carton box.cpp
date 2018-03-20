#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Box
{
	private:
	double length;
	double width;
	double height;
	public:
	Box(double lv, double wv, double hv) : length (lv), width (wv), height (hv) {}
	Box(): length (1.0), width (1.0), height (1.0){}
	double volume() const
	{ return length*width*height; }
	double getLength() const { return length; }
	double getWidth() const { return width; }
	double getHeight() const { return height; }
	friend ostream& operator<<(ostream& stream, const Box& box);
};
ostream& operator<<(ostream& stream, const Box& box)
{
	stream << " Box(" << setw(2) << box.length << ","
	<< setw(2) << box.width << ","
	<< setw(2) << box.height << ")";
	return stream;
}
class Carton : public Box
{
	private:
	string material;
	public:
	Carton(const string desc = "Cardboard") : material(desc) {}
	void showDetails()
	{
		cout << "\nMaterial = " << material;
		cout << "\nLength = " << getLength();
		cout << "\nWidth = " << getWidth();
		cout << "\nHeight = " << getHeight();
		cout << endl;
	}
};
int main()
{
	Box box (40.0, 30.0, 20.0);
	Carton carton;
	Carton candyCarton ("Thin cardboard");
	cout << "box occupies " << sizeof box << " bytes" << endl;
	cout << "carton occupies " << sizeof carton << " bytes" << endl;
	cout << "candyCarton occupies " << sizeof candyCarton << " bytes" << endl;
	cout << "box volume is " << box.volume() << endl;
	cout << "carton volume is " << carton.volume() << endl;
	cout << "candyCarton volume is " << candyCarton.volume() << endl;
	cout << "candyCarton length is " << candyCarton.getLength() << endl;
	carton.showDetails();
	candyCarton.showDetails();
	return 0;
}

