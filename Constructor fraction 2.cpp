#include <iostream>
#include <cmath>
using namespace std;
class FractionType
{
    private:
        int iNum, iDen;
    public:
        void fnSetFraction(int, int);
        void fnSetFraction(int);
        void fnShowFraction();
        void fnReduceFraction();
        FractionType fnAddFraction(FractionType&);
        FractionType fnAddFraction(int);
};
int main(void)
{
    FractionType f1,f2,f3;
    f1.fnShowFraction();
    f2.fnShowFraction();
    f1.fnSetFraction(1,4);
    f2.fnSetFraction(1,4);
    f1.fnShowFraction();
    f2.fnShowFraction();
    f3 = f1.fnAddFraction(f2);
    f3.fnShowFraction();
    f3 = f1.fnAddFraction(1);
    f3.fnShowFraction();
    FractionType f4;
    f4.fnShowFraction();
    return 0;
}
void FractionType :: fnSetFraction(int iN, int iD)
{
    iNum = iN;
    iDen = iD;
}
void FractionType :: fnSetFraction(int iN)
{
    iNum = iN;
    iDen = 1;
}
void FractionType :: fnShowFraction()
{
    cout << "Fraction : " << "( " << iNum << " / " << iDen << " )" << endl;
}
FractionType FractionType :: fnAddFraction(FractionType &b)
{
    FractionType res;

    res.iNum = (iNum * b.iDen + iDen * b.iNum);
    res.iDen = (iDen * b.iDen);
    return res;
}
FractionType FractionType :: fnAddFraction(int b)
{
    FractionType res;

    res.iNum = (iNum  + iDen * b);
    res.iDen = (iDen);
    return res;
}
