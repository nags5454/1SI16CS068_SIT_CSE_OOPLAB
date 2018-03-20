#include<iostream>
using namespace std;
void fetchModify( int * );
int main()
{
   int iaArr[10] = {1,2,3,4,5,6,7,8,9,10};
   int iaArr2[10] = {1,2,3,4,5,6,7,8,9,10};
   fetchModify(iaArr);
   fetchModify(iaArr2);
   return 0;
}
void fetchModify( int *xPtr )
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


