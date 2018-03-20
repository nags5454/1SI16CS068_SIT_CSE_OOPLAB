#include <iostream>
using namespace std;
class Distance
{
    private:
    static const float MTF = 3.280833F;
    int feet;
    float inches;
    public:
    Distance() : feet(0), inches(0.0)
    { }
    Distance(float meters)
    {
        float fltfeet = MTF * meters;
        feet = int(fltfeet);
        inches = 12*(fltfeet-feet);
        cout << "\nOne arg\n";
        cout << "Basic to Class type Conversion" << endl;
    }
    Distance(int ft, float in) : feet(ft),inches(in)
    {
        cout << "\nTwo args\n";
    }
    void getdist()
    {
        cout << "\nEnter feet: "; cin >> feet;
        cout << "Enter inches: "; cin >> inches;
    }
    void showdist() const    //display distance
    {
        cout << feet << "\':" << inches << '\"';
    }
    operator float() const
    {
        cout << "\nconversion operator\n";
        float fracfeet = inches/12;
        fracfeet += static_cast<float>(feet);
        return fracfeet/MTF;
    }
    void operator=(float meters)
    {
        float fltfeet = MTF * meters;
        feet = int(fltfeet);
        inches = 12*(fltfeet-feet);
        cout << "\nOverload =\n";
    }
};
int main()
{
    float mtrs;
    cout << "\ndist1 = ";
    dist1.showdist();
    cout << "\n=========================" << endl;
    cout << "Press enter to continue";
	cin.get();
    mtrs = static_cast<float>(dist1);
    cout << "\ndist1 = " << mtrs << " meters\n";
    cout << "\n=========================" << endl;
    cout << "Press enter to continue";
    cin.get();
    Distance dist2(7, 10.25);
    mtrs = dist2;
    cout << "\ndist2 = " << mtrs << " meters\n";
    cout << "\n=========================" << endl;
    cout << "Press enter to continue";
    cin.get();
    Distance dist3;
    dist3 = 5.6f;
    cout << "\ndist3 = ";
    dist3.showdist();
    cout << "\n=========================" << endl;
    cout << "Press enter to continue";
    cin.get();

    return 0;
}
