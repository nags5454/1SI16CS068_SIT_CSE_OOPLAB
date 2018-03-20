#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class time12
{
    private:
        bool pm;
        int hrs;
        int mins;
    public:

        time12() : pm(true), hrs(0), mins(0)
        { }
        time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m)
        { }
        void display() const
        {
            cout << hrs << ':';
            if(mins < 10)
                cout << '0';
            cout << mins << ' ';
            string am_pm = pm ? "p.m." : "a.m.";
            cout << am_pm;
        }
};
class time24
{
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        time24() : hours(0), minutes(0), seconds(0)
        { }
        time24(int h, int m, int s) :hours(h), minutes(m), seconds(s)//3-arg constructor
        { }
        void display() const
        {
			cout << setw(2) << setfill('0') << hours << ":";
			cout << setw(2) << setfill('0') << minutes << ":";
			cout << setw(2) << setfill('0') << seconds << endl;
        }
        operator time12() const;
};
time24::operator time12() const
{
    int hrs24 = hours;
    bool pm = hours < 12 ? false : true;
    int roundMins = seconds < 30 ? minutes : minutes+1;
    if(roundMins == 60)
    {
        roundMins=0;
        ++hrs24;
        if(hrs24 == 12 || hrs24 == 24)
        pm = (pm==true) ? false : true;
    }
    int hrs12 = (hrs24 < 13) ? hrs24 : hrs24-12;
    if(hrs12==0)
    {
        hrs12=12; pm=false;
    }
    return time12(pm, hrs12, roundMins);
}
int main()
{
    int h, m, s;
    while(true)
    {
        cout << "Enter 24-hour time: \n";
        cout << "   Hours (0 to 23): "; cin >> h;
        if(h > 23)
            return(1);
        cout << "   Minutes (0 to 59): "; cin >> m;
        if(m > 59)
            return(1);
        cout << "   Seconds (0 to 59): "; cin >> s;
        if(s > 59)
            return(1);
        time24 t24(h, m, s);
        cout << "You entered: ";
        t24.display();
        time12 t12 = t24;
        cout << "\n12-hour time: ";
        t12.display();
        cout << "\n\n";
    }
    return 0;
}
