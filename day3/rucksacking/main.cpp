#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getPriority(char item){
    string abc= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < abc.length(); ++i) {
        if(abc.at(i)==item){
            return i+1;
        }
    }
}


char getIntersection(const string& rucksack){
    string firstCompartment=rucksack.substr(0, rucksack.length()/2);
    string secondCompartment=rucksack.substr(rucksack.length()/2);
    for(char item1 : firstCompartment){
        for(char item2 : secondCompartment){
            if(item1==item2){
               return item1;
            }
        }
    }
}

char getTeamBadge(string firstMember, string secondMember, string thirdMember){
    for(char item1 : firstMember){
        for(char item2 : secondMember){
            for(char item3 : thirdMember){
                if(item1==item2 && item1 == item3){
                    return item1;
                }
            }
        }
    }
}


int main () {
    //Part 1
    string line;
    int prioritySum=0;
    ifstream myFile ("input.txt");
    if (myFile.is_open())
    {
        while ( getline (myFile,line) )
        {
            prioritySum+= getPriority(getIntersection(line));
        }
        myFile.close();
    }
    cout<<prioritySum<<endl;

    //Part 2
    string member;
    int badgeSum=0;
    ifstream secondFile ("input2.txt");
    if (secondFile.is_open())
    {
        int count=0;
        string firstMember, secondMember, thirdMember;

        while ( getline (secondFile,member) )
        {
            int tmp = count%3;
            switch (tmp) {
                case 0:{
                    firstMember=member;
                    break;
                }
                case 1: {
                    secondMember=member;
                    break;
                }
                default: {
                    thirdMember=member;
                    char teamBadge =getTeamBadge(firstMember, secondMember, thirdMember);
                    badgeSum+= getPriority(teamBadge);
                    break;
                }
            }
            count++;
        }
        myFile.close();
    }
    cout<<badgeSum<<endl;
    return 0;
}
