#include <iostream>
#include <cstring>
using namespace std;
class STR{
    char *p;
    int len;
    public:
    STR(){}
    STR(const char *str)
    {
        strcpy(p,str);
        len = strlen(p);
    }
    STR operator+(STR s2)
    {
        STR newstr;
        newstr.len = len+s2.len;
        newstr->p = strcat(this->p,s2->p);
        return newstr;
    }
    void showString()
    {
        cout << p << endl;
    }
};
int main()
{
    STR s1("Yes"), s2("No"), s3;
    s3 = s1 + s2;
    s1.showString();
    s2.showString();
    s3.showString();
    return 0;
}
