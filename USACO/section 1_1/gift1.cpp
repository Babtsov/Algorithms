/*
 ID: nika1231
 PROG: gift1
 LANG: C++11
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

struct person {
    int initMoney;
    int recievedMoney;
    std::vector<string> friends;
};

int main(){
    
    ofstream cout("gift1.out");
    ifstream cin("gift1.in");
    
    int numOfPeople;
    cin >> numOfPeople;
    map<string,person*> people;
    std::vector<string> names; //to arrange them in order
    
    for (int i = 0; i < numOfPeople; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
        people[name] = new person();
    }
    
    int money, numOfRecipients;
    for (int i = 0; i < numOfPeople; ++i) {
        string name;
        
        cin >> name;
        cin >> money >> numOfRecipients;
        
        people[name]->initMoney = money;
        
        for (int i = 0; i < numOfRecipients; ++i) {
            string recipientName;
            cin >> recipientName;
            people[name]->friends.push_back(recipientName);
        }
    }
    
    for (const auto& giverPair : people) {
        person* giver = giverPair.second;
        
        for (string recieverStr: giver->friends) {
            person* reciver = people[recieverStr];
            reciver->recievedMoney += giver->initMoney / giver->friends.size();
        }
        if (giver->friends.size() != 0)
            giver->recievedMoney += (giver->initMoney % giver->friends.size());
    }
    
    for (auto name : names) 
        cout << name << " " << people[name]->recievedMoney - people[name]->initMoney << endl;
    
    return 0;
}