#include <iostream>
using namespace std;
void fnCommuteTime( float = 40, float = 25);
int main(void)
{
	fnCommuteTime();
	fnCommuteTime(70);
	fnCommuteTime(30,20);
	return 0;
}
void fnCommuteTime( float velocity, float distance)
{
	cout<<"The Commute time is " << distance/velocity << " hours" << endl;
}
