//
//  main.cpp
//  HW2
//
//  Created by Ben on 1/28/16.
//  Copyright © 2016 Ben. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode * next;
    ListNode(int val) {
        this->val = val;
    }
};

void printList(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    while (head != nullptr && head->next != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    if (head != nullptr) {
        cout << head->val << endl;
    }
}

ListNode* scanList() {
    int length;
    cin >> length;
    ListNode* head = nullptr;
    ListNode* prev = nullptr;
    for (int i = 0; i < length; i++) {
        int val;
        cin >> val;
        if (prev == nullptr) {
            head = new ListNode(val);
            prev = head;
            continue;
        }
        ListNode* current = new ListNode(val);
        prev->next = current;
        prev = current;
    }
    prev->next = nullptr;
    return head;
}

int main(int argc, const char * argv[]) {
    ListNode* combinedList = scanList();
    int numOfLists;
    cin >> numOfLists;
    for (int i = 0; i < numOfLists; i++) {
        int step;
        cin >> step;
        ListNode* combinedListptr = combinedList;
        ListNode* additionalList = scanList();
        while (additionalList != nullptr && combinedListptr != nullptr) {
            for(int j = 0; j < step - 1 && combinedListptr != nullptr; j++) {
                combinedListptr = combinedListptr->next;
            }
            ListNode* temp = combinedListptr->next;
            combinedListptr->next = additionalList;
            ListNode* tempAdditional = additionalList->next;
            additionalList->next = temp;
            additionalList = tempAdditional;
            combinedListptr = combinedListptr->next->next;
        }
    }
    printList(combinedList);
    return 0;
}


