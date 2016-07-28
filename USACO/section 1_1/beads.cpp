/*
ID: nika1231
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// break the necklace into groups of same color adjacent beads
class  Necklace{
private:
    int beadptr;
    int iterator;
    std::vector<char> beadType; //stores the type of the bead 'R','W','B'
    std::vector<int> groupCnt;  // # of beads in the same group
    
public:
    Necklace(string beads) {
        beadptr = 0;
        iterator = 0;
        for (auto i : beads) {
            if (beadptr != 0 && i == beadType[beadptr - 1])
                groupCnt[beadptr - 1]++;
            else {
                groupCnt.push_back(1);
                beadType.push_back(i);
                beadptr++;
            }
        }
        if (beadType[0] == beadType[beadptr - 1] && groupCnt.size() >1) {
            groupCnt[0] += groupCnt[ beadptr - 1];
            groupCnt.pop_back(); beadType.pop_back();
        }
        beadptr = (int)groupCnt.size();
    }
    int size(){
        int beadsNumber = 0;
        for (auto i : groupCnt)
            beadsNumber += i;
        return beadsNumber;
    }
    void next(){
        if (iterator == beadptr - 1)
            iterator = 0;
        else
            iterator++;
    }
    void prev(){
        if (iterator == 0)
            iterator = beadptr - 1;
        else
            iterator--;
    }
    char getCurrentBeadColor(){
        return beadType[iterator];
    }
    char getCurrentGroupCnt(){
        return groupCnt[iterator];
    }
    void setItr(int index){
        assert(index >= 0 && index <=beadptr - 1);
        iterator = index;
    }
    void printNecklace(){ //for debugging
        for (auto i : groupCnt)
            cout << i <<" ";
        cout <<endl;
        for (auto i : beadType)
            cout << i <<" ";
        cout <<endl;
        cout << "beadptr:" << beadptr <<endl;
        cout << "iterator:" << iterator << endl;
    }
    int numOfDiffGroups(){
        return beadptr;
    }
};

int breakNeclace(Necklace &necklace, int index){
    int totalBeadsCollected = 0;
    // the colors against which the beads will be compared when travesing right or left
    char rightColor, leftColor;
    necklace.setItr(index);
    
    // count the beads on the right
    totalBeadsCollected += necklace.getCurrentGroupCnt();
    rightColor = necklace.getCurrentBeadColor();
    necklace.next();
    
    while(1) {
        // check if all beads in the necklace were collected
        if (totalBeadsCollected == necklace.size())
            return totalBeadsCollected;
        
        if (necklace.getCurrentBeadColor() == 'w') //encountered group of beads is white ->
            totalBeadsCollected += necklace.getCurrentGroupCnt(); //add and go on
        //encountered group isn't white and the current right traversal group color is white ->
        else if (rightColor == 'w') {
            rightColor = necklace.getCurrentBeadColor(); //change right traversal group color to the one we encountered
            totalBeadsCollected += necklace.getCurrentGroupCnt(); // and add the # of beads to the total
        }
        else if (rightColor != necklace.getCurrentBeadColor()) // reached the end of the traversal.
            break;
        else {
            totalBeadsCollected += necklace.getCurrentGroupCnt();
        }
        necklace.next();
    }
    // count the beads on the left
    necklace.setItr(index);
    necklace.prev();
    
    totalBeadsCollected += necklace.getCurrentGroupCnt();
    leftColor = necklace.getCurrentBeadColor();
    necklace.prev();
    while(1) {
        // check if all beads in the necklace were collected
        if (totalBeadsCollected == necklace.size())
            return totalBeadsCollected;
        
        if (necklace.getCurrentBeadColor() == 'w') //encountered group of beads is white ->
            totalBeadsCollected += necklace.getCurrentGroupCnt(); //add and go on
        //encountered group isn't white and the current right traversal group color is white ->
        else if (leftColor == 'w') {
            //change left traversal group color to the one we encountered
            leftColor = necklace.getCurrentBeadColor();
            totalBeadsCollected += necklace.getCurrentGroupCnt(); // and add the # of beads to the total
        }
        else if (leftColor != necklace.getCurrentBeadColor()) // reached the end of the traversal.
            break;
        else {
            totalBeadsCollected += necklace.getCurrentGroupCnt();
        }
        necklace.prev();
    }
    return totalBeadsCollected;
}

int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    string inputStr;
    int size;
    fin >> size >> inputStr;
    Necklace necklace(inputStr);
    // if all beads are of the same color
    if (necklace.numOfDiffGroups() == 1) {
        fout << necklace.size() << endl;
        return 0;
    }
    
    int maxCollectedBeads = 0;
    for (int i = 0, n = necklace.numOfDiffGroups(); i < n; i++) {
        int collectedBeads = breakNeclace(necklace,i);
        if (collectedBeads > maxCollectedBeads)
            maxCollectedBeads = collectedBeads;
    }
    fout << maxCollectedBeads << endl;
    return 0;
}