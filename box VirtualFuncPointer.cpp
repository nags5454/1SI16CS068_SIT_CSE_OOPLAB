#include <iostream>
using namespace std;
class Box
{
    protected:
    double length ;
    double width ;
    double height ;
    public:
    Box() { length = width = height = 1.0; }
    Box(double lv, double wv, double hv) : length(lv), width(wv), height(hv) {}
    void showVolume() const
    { cout << "Box usable volume is " << volume() << endl; }
    virtual double volume() const { return length*width*height; }
};
class ToughPack : public Box
{
    public:
    ToughPack(double lv, double wv, double hv) : Box (lv, wv, hv) {}
    double volume() const { return 0.85*length*width*height; }
};
int main()
{
    Box box(20.0, 30.0, 40.0);
    ToughPack hardcase(20.0, 30.0, 40.0);
    box.showVolume();
    hardcase.showVolume();
    Box *pBox;
    pBox = &box;
    pBox->showVolume();
    pBox = &hardcase;
    pBox->showVolume();
    cout << "hardcase volume through pBox is " << pBox->volume() << endl;
    return 0;
}
