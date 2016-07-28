//  http://www.spoj.com/status/b_babtsov/
//
//
//  Created by Ben on 4/16/16.
//

#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<long long> & vect, vector<long long> & aux, long long left, long long mid, long long right) {
    long long count = 0, l = left, r = mid, merged = left;
    for (;(l <= mid - 1) && r <= right; merged++) {
        if (vect[l] <= vect[r]) {
            aux[merged] = vect[l];
            l++;
        } else {
            aux[merged] = vect[r];
            count += mid - l;
            r++;
        }
    }
    for (;r <= right; r++) {
        aux[merged] = vect[r];
        merged++;
    }
    for (;l <= mid - 1; l++) {
        aux[merged] = vect[l];
        merged++;
    }
    for (l=left; l <= right; l++) {
        vect[l] = aux[l];
    }
    return count;
}

long long recur_merge_sort(vector<long long> & vect, vector<long long> & aux, long long left, long long right) {
    if (left < right) {
        long long count = 0;
        long long mid = (right + left)/2;
        count += recur_merge_sort(vect, aux, mid + 1, right);
        count += recur_merge_sort(vect, aux, left, mid);
        count += merge(vect, aux, left, mid + 1, right);
        return count;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        long long size;
        cin >> size;
        vector<long long> vect(size);
        for (int i = 0; i < size; i++) {
            cin >> vect[i];
        }
        vector<long long> aux(vect.size());
        cout << recur_merge_sort(vect, aux, 0, vect.size() - 1) << endl;
    }
}
