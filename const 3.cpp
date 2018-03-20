#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int x, y;
	int * const ptr = &x;
	*ptr = 7;
	cout << "\nx = " << x << endl;
	x++;
	cout << "\nx = " << x << endl;
	(*ptr)++;
	cout << "\nx = " << x << endl;
	return 0;
}
