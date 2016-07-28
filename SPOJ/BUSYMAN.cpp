//  http://www.spoj.com/status/b_babtsov/
//
//
//  Created by Ben on 4/9/16.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> intervals;
        intervals.reserve(n);
        for (int i = 0; i < n; i++) {
            pair<int,int> interval;
            cin >> interval.first >> interval.second;
            intervals.push_back(interval);
        }
        sort(intervals.begin(),intervals.end(),[](pair<int,int> a,pair<int,int> b){ return a.second < b.second;});
        int max_activities = 0, end = 0;
        for (auto elem : intervals) {
            if (elem.first >= end) {
                max_activities++;
                end = elem.second;
            }
        }
        cout << max_activities << endl;
    }
}