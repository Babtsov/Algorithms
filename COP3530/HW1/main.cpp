//
//  main.cpp
//  HW1
//
//  Created by Benjamin Babtsov on 1/17/16.
//  Copyright © 2016 Ben. All rights reserved.
//

#include <iostream>
using namespace std;

//void insertion_sort(int arr[],int size) {
//    if (size < 2) {
//        return;
//    }
//    for (int i = 1; i < size; i++) {
//        for (int j = i; j > 0; j--) {
//            if (arr[j] < arr[j - 1]) {
//                int temp = arr[j - 1];
//                arr[j - 1] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//}

void insertion_sort(int arr[],int size) {
    if (size < 2) {
        return;
    }
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j;
        for (j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    insertion_sort(nums, N);
    for (int i = 0; i < N; i++) {
        cout  << nums[i] << endl;
    }
    return 0;
}
