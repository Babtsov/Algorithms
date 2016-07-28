/*
 ID: nika1231
 PROG: milk2
 LANG: C++11
 */
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

struct interval {
    int beginTime;
    int endTime;
};
bool compare(interval lhv, interval rhv){
    return lhv.beginTime < rhv.beginTime;
}

int main(int argc, char const *argv[])
{
    ifstream cin("milk2.in");
    ofstream cout("milk2.out");
    int N;
    cin >> N;
    interval milkingIntervals[N];
    
    for (int i = 0; i < N; ++i) {
        interval scannedInterval;
        cin >> scannedInterval.beginTime >> scannedInterval.endTime;
        milkingIntervals[i] = scannedInterval;
    }
    
    sort(milkingIntervals,milkingIntervals+N, compare);
    int currentBeginTime = milkingIntervals[0].beginTime;
    int maxEndTime = milkingIntervals[0].endTime;
    int maxMilkingInterval = maxEndTime - currentBeginTime;
    
    int maxIdleTime = 0;
    for (int i = 1; i < N; ++i) {
        if (milkingIntervals[i].beginTime > maxEndTime) { // we have an overlap
            if (milkingIntervals[i].beginTime - maxEndTime > maxIdleTime) //see if we get a new idle time
                maxIdleTime = milkingIntervals[i].beginTime - maxEndTime;
            currentBeginTime = milkingIntervals[i].beginTime;
            maxEndTime = milkingIntervals[i].endTime;
        }
        else if ( milkingIntervals[i].beginTime == maxEndTime )
            maxEndTime = milkingIntervals[i].endTime;
        if (milkingIntervals[i].endTime > maxEndTime)
            maxEndTime = milkingIntervals[i].endTime;
        if (maxEndTime - currentBeginTime > maxMilkingInterval)
            maxMilkingInterval = maxEndTime - currentBeginTime;
    }
    
    cout << maxMilkingInterval << " " << maxIdleTime << endl;
    return 0;
}