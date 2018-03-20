#include <iostream>
using namespace std;
class cl {
	static int resource;
	public:
	static int get_resource();
	void free_resource() { resource = 0; }
};
int cl::resource;
int cl::get_resource()
{
	if(resource)
		return 0;
	else
	{
		resource = 1;
		return 1;
	}
}
int main()
{
	cl ob1, ob2;
	if(cl::get_resource()) cout << "locking resource\n";
	if(!cl::get_resource()) cout << "resource already allocated\n";
	ob1.free_resource();
	if(ob2.get_resource()) // can still call using object syntax
	cout << "ob2 can now use resource\n";
	return 0;
}
