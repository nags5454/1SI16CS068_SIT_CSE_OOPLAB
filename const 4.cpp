#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int x = 6, y;
	const int * const ptr = &x;
	cout << setw(4) << *ptr << endl;
	x++;
	cout << *ptr << endl;
	return 0;
}
