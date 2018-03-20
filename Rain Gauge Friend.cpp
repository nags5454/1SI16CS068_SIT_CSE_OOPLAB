#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class RainGauge
{
    friend double fnCalcAvg(RainGauge [], int);
	private:
    double dRainInCm;
    char cLocation[20];
    public:
    RainGauge();
    void fnReadMeasurement();
    void fnDispReading();
};
RainGauge :: RainGauge()
{
    dRainInCm = 0.0;
    strcpy(cLocation, "\0");
}
void RainGauge :: fnReadMeasurement()
{
	int iRandVal;
    cout << "\nEnter Location of the RainGauge\n";
    cin >> cLocation;
	iRandVal = rand()%20;
    dRainInCm = drand48() + iRandVal;

}
void RainGauge :: fnDispReading()
{
    cout << cLocation << " : " << dRainInCm << " cms\n";
}
double fnCalcAvg(RainGauge r[], int iNum)
{
    int i;
    double dAvgRain = 0.0;
    for(i=0; i<iNum;i++)
    {
        dAvgRain += r[i].dRainInCm;
    }
    dAvgRain /= iNum;
    return dAvgRain;
}
int main()
{
    RainGauge rainSensorArray[10];
    double dAvgRainFall;
    int i, iNum;
    srand(time(NULL));
    cout << "\nEnter the number of cities\n";
    cin >> iNum;
    for(i=0;i<iNum;i++)
    {
        rainSensorArray[i].fnReadMeasurement();
    }
    cout << "\nRainfall Information\n";
    cout << "========================\n";
    for(i=0;i<iNum;i++)
    {
        rainSensorArray[i].fnDispReading();
    }
    dAvgRainFall = fnCalcAvg(rainSensorArray, iNum);
    cout << "\nAverage RainFall recieved is " << dAvgRainFall << " cms\n";
    return 0;
}
