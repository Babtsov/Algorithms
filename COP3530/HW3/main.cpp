//
//  main.cpp
//  HW3
//
//  Created by Ben on 2/6/16.
//

#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;

struct MatrixNode{
    int index;
    int val;
    MatrixNode* next;
    MatrixNode(int index, int val) {
        this->index = index;
        this->val = val;
        this->next = nullptr;
    }
};

class SparseMatrix {
private:
    MatrixNode** row_array;
    int row_num; // Every matrix should know how many rows it has
    static inline MatrixNode* incAndClean(MatrixNode* node) {
        auto temp = node;
        node = node->next;
        delete temp;
        return node;
    }
public:
    int getRowNumber() const {
        return row_num;
    }
    SparseMatrix(int rows){
        this->row_array = new MatrixNode*[rows];
        this->row_num = rows;
    }
    MatrixNode* getRow(int rowIndex) const {
        if (rowIndex >= row_num || rowIndex < 0) {
            return nullptr;
        }
        return row_array[rowIndex];
    }
    void setRow(int index, MatrixNode* head) {
        row_array[index] = head;
    }
    void operator+=(const SparseMatrix& other) {
//        assert(this->row_num == other.row_num);
        for (int i = 0; i < this->row_num; i++) {
            MatrixNode *thisColPtr = row_array[i], *otherColPtr = other.getRow(i);
            MatrixNode *prev = nullptr, *head = thisColPtr;
            while (thisColPtr != nullptr || otherColPtr != nullptr) {
                MatrixNode* combined = nullptr;
                if (otherColPtr == nullptr ) {
                    combined = new MatrixNode(thisColPtr->index,thisColPtr->val);
                    thisColPtr = incAndClean(thisColPtr);
                } else if (thisColPtr == nullptr) {
                    combined = new MatrixNode(otherColPtr->index,otherColPtr->val);
                    otherColPtr = otherColPtr->next;
                } else if (thisColPtr->index < otherColPtr->index) {
                    combined = new MatrixNode(thisColPtr->index,thisColPtr->val);
                    thisColPtr = incAndClean(thisColPtr);
                } else if (thisColPtr->index > otherColPtr->index) {
                    combined = new MatrixNode(otherColPtr->index,otherColPtr->val);
                    otherColPtr = otherColPtr->next;
                } else { // thisColPtr->index == otherColPtr->index
                    if (thisColPtr->val + otherColPtr->val == 0) { // don't bother with elements equal to zero
                        thisColPtr = incAndClean(thisColPtr);
                        otherColPtr = otherColPtr->next;
                        continue;
                    }
                    combined = new MatrixNode(thisColPtr->index,thisColPtr->val + otherColPtr->val);
                    thisColPtr = incAndClean(thisColPtr);
                    otherColPtr = otherColPtr->next;
                }
                if (prev == nullptr) {
                    prev = combined;
                    head = combined;
                } else {
                    prev->next = combined;
                    prev = combined;
                }
            }
            row_array[i] = head;
        }
    }
    vector<pair<int,int>> findValue(int val) {
        vector<pair<int,int>> search_result;
        for (int i = 0; i < this->row_num; i++) {
            for (MatrixNode* colmnPtr = row_array[i]; colmnPtr != nullptr; colmnPtr = colmnPtr->next) {
                if (val == colmnPtr->val) {
                    search_result.push_back(make_pair(i,colmnPtr->index));
                }
            }
        }
        return search_result;
    }
};

MatrixNode* scanList() {
    int length;
    cin >> length;
    MatrixNode* head = nullptr;
    MatrixNode* prev = nullptr;
    for (int i = 0; i < length; i++) {
        int index, val;
        cin >> index;
        cin >> val;
        if (val == 0) {
            continue; // no reason to store entries with 0 value
        }
        if (prev == nullptr) {
            head = new MatrixNode(index, val);
            prev = head;
            continue;
        }
        MatrixNode* current = new MatrixNode(index, val);
        prev->next = current;
        prev = current;
    }
    prev->next = nullptr;
    return head;
}

void ScanAndPopulateMatrix(SparseMatrix& matrix, int row_num) {
    for (int i = 0; i < row_num; i++) {
        MatrixNode* row = scanList();
        matrix.setRow(i, row);
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int row_num;
    cin >> row_num;
    SparseMatrix matrix1 = SparseMatrix(row_num);
    ScanAndPopulateMatrix(matrix1,row_num);
    cin >> row_num;
    SparseMatrix matrix2 = SparseMatrix(row_num);
    ScanAndPopulateMatrix(matrix2,row_num);
    matrix1 += matrix2;
    int searches;
    cin >> searches;
    for (int i = 0; i < searches; i++) {
        int valueToSearchFor;
        cin >> valueToSearchFor;
        vector<pair<int,int>> result = matrix1.findValue(valueToSearchFor);
        for (auto resultPair : result) {
            cout << resultPair.first << " " << resultPair.second << " ";
        }
        cout << "\n";
    }
    return 0;
}