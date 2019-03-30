#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool is_one_away(string s1, string s2);

int main(){
    cout << is_one_away("pale", "bale") << endl;
    return 0;
}

bool is_one_away(string s1, string s2){
    if (abs((long)s1.size() - (long)s2.size()) > 1) return false;
    bool found = false;
    for (int i = 0, j = 0; i < s1.size() && j < s2.size(); i++){
        if (s1[i] != s2[j]){
            if (found) return false;
            else{
                found = true;
                if (s1.size() > s2.size()) i++;
                else if (s1.size() < s2.size()) j++;
            }
        } 
        j++;
    }
    if (found == false && abs((long)s1.size() - (long)s2.size()) == 1) return true;
    return found;
}