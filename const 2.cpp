#include<iostream>
using namespace std;
void fetchModify( const int * );
int main()
{
   int iaArr[10] = {1,2,3,4,5,6,7,8,9,10};
   fetchModify(iaArr);
   iaArr[7] = 17;
   return 0;
}
void fetchModify( const int *xPtr )
{
	int i;
	for(i=0;i<10;i++)
		cout << xPtr[i];
	cout << endl;
	for(i=0;i<10;i++)
		xPtr[i] = 0;
	cout << endl;
	for(i=0;i<10;i++)
		cout << xPtr[i];
	cout << endl;
}


