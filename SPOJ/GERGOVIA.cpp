//  http://www.spoj.com/status/b_babtsov/
//
//
//  Created by Ben on 4/10/16.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    while(true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        long long int sum = 0, work = 0, elem;
        for (int i = 0; i < N; i++) {
            cin >> elem;
            sum += elem;
            work += abs(sum);
        }
        cout << work << endl;
    }
}