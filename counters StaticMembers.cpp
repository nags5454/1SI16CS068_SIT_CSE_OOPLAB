#include <iostream>
using namespace std;
void f();
class Counter
{
	static int count;
	public:
		Counter() { count++; }
		~Counter() { count--; }
		static int fnShowCount()
		{
			return count ;
		}
};
int Counter::count;
int main(void)
{
	Counter o1;
	cout << "Objects in existence: ";
	cout << Counter::fnShowCount() << "\n";
	Counter o2;
	cout << "Objects in existence: ";
	cout << Counter::fnShowCount() << "\n";
	f();
	cout << "Objects in existence: ";
	cout << Counter::fnShowCount() << "\n";
	return 0;
}
void f()
{
	Counter temp;
	cout << "Objects in existence: ";
	cout << temp.fnShowCount() << "\n";
}
