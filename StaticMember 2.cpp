#include <iostream>
using namespace std;
class shared {
	public:
		static int a;
}
int shared::a;
int main()
{
	shared::a = 99;
	cout << "This is initial value of a: " << shared::a;
	cout << "\n";
	shared x;
	cout << "This is x.a: " << x.a << endl;
	return 0;
}
