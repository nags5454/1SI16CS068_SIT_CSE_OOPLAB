#include <iostream>
using namespace std;
int main()
{
	int *ptr;
	int iaArr[10], i;
	ptr = iaArr;
	cout << "\nEnter array elements\n";
	for(i=0;i<5;i++)
	{
		cin >> ptr[i];
	}
	cout << "\nArray contents are\n";
	for(i=0;i<5;i++)
	{
		cout << iaArr[i];
	}
	return 0;
}
