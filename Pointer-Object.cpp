#include <iostream>
using namespace std;
class cl {
	int i;
	public:
	cl(int j) { i=j; }
	int show_i() { return i; }
};
int main()
{
	cl ob(88), *p;
	cl obArr[2]={4,5};
	p = &ob;
	cout << p->show_i() << endl
	p = obArr;
	for(int i=0;i<2;i++)
	{
		cout << p->show_i() << endl;
		p++;
	}
	return 0;
}
