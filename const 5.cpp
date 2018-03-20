#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const int x = 7;
	cout << "The value of constant variable x is: " << x << endl;
	const int arraySize = 10;
	int s[ arraySize ];
	for ( int i = 0; i < arraySize; ++i )
		s[i] = 2 + 2 * i;
	cout << "Element" << setw(13) << "Value" << endl;
	for ( int j = 0; j < arraySize; ++j )
		cout << setw(7) << j << setw(13) << s[j] << endl;
	return 0;
}
