#include <iostream>
#include <string>
using namespace std;
class petType
{
public:
	virtual void print();
	petType(){}
	petType(string n){	name = n;	}
protected:
	string name;
};
void petType::print()
{
	cout << "Name: " << name;
}
class dogType: public petType
{
public:
	void print();
	dogType(){}
	dogType(string n, string b)
	{
		name = n;
		breed = b;
	}
private:
	string breed;
};
void dogType::print()
{
	petType::print();
	cout << ", Breed: " << breed << endl;
}
void callPrint(petType *p);
int main()
{
	petType *q;
	dogType *r;
	q = new petType("Lucky");
	r = new dogType("Tommy", "German Shepherd");
	q->print();
	cout << endl;
	r->print();
	cout << "*** Calling the function callPrint ***" << endl;
	callPrint(q);
	cout << endl;
	callPrint(r);
	cout << endl;
	return 0;
}
void callPrint(petType *p)
{
	p->print();
}
