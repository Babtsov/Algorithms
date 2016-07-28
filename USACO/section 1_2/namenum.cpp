/*
 ID: nika1231
 PROG: namenum
 LANG: C++11
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <fstream>
#include <cmath>
using namespace std;

class Enumerator {
public:
    Enumerator(vector<vector<char>> combinations) :
    counters(combinations.size(),0)
    {
        this->combinations = combinations;
        Groups = (int)combinations.size();
        lettersPerGroup = (int)combinations[0].size();
    }
    string getNextWord(){
        // extract current string to be returned
        string currentString;
        for (int i = 0; i < Groups; ++i) {
            int counter = counters[i];
            currentString += combinations[i][counter];
        }
        //increment the counters array from right to left.
        int carry = 1;
        for (int i = Groups - 1; i >= 0 && carry == 1; --i) {
            counters[i]++;
            if (counters[i] == lettersPerGroup) // we have an overflow. carry 1 to the next counter
                counters[i] = 0;
            else
                carry = 0; // no overflow. terminate the loop
        }
        return currentString;
    }
    int Groups;
    int lettersPerGroup;
private:
    vector<vector<char>> combinations;
    vector<int> counters;

};

int main(int argc, char const *argv[]) {

    ifstream cin("namenum.in");
    ofstream cout("namenum.out");
    unordered_set<string> dictionary;
    string dictWord;
    ifstream dictFile("dict.txt");
    while (dictFile >> dictWord) {
        dictionary.insert(dictWord);
    }
    
    map<char,vector<char>> combinationBank{
        {'2',{'A','B','C'}},
        {'3',{'D','E','F'}},
        {'4',{'G','H','I'}},
        {'5',{'J','K','L'}},
        {'6',{'M','N','O'}},
        {'7',{'P','R','S'}},
        {'8',{'T','U','V'}},
        {'9',{'W','X','Y'}}};
    
    string userInput;
    cin >> userInput;
    // produce a combination vector of vectors for the user input
    vector<vector<char>> combination;
    for (char number : userInput) {
        vector<char> correspondingVect = combinationBank[number];
        combination.push_back(correspondingVect);
    }
    
    // create an object that will spit all the possible letter combinations
    Enumerator enumerator = Enumerator(combination);
    
    // iterate through all possible combinations, checking if each one is in the dictionary
    long long totalCombinations = pow(enumerator.lettersPerGroup,userInput.length());
    bool isWordFound = false;
    for (int i = 0; i < totalCombinations; ++i) {
        string combinationString = enumerator.getNextWord();
        auto foundWord = dictionary.find(combinationString);
        if (foundWord != dictionary.end()) {
            cout << combinationString << endl;
            isWordFound = true;
        }
    }
    if (!isWordFound)
        cout << "NONE" << endl;
    
    return 0;
}