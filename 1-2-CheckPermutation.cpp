#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*
    Given two strings, write a method to decide if one is a permutations of the other

*/

bool is_permutation(string s1, string s2);

int main(){
    string s1 = "LOREAL";
    string s2 = "LLOREV";
    cout << is_permutation(s1, s2) << endl;
    return 0;
}

bool is_permutation(string s1, string s2){
    if (s1.size() != s2.size()){
        return false;
    }
    else
    {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for (auto i = 0; i < s1.length(); i ++)
        {
            if (m1.find(s1[i]) == m1.end())
                m1.insert(pair<char,int> (s1[i], 1));
            else 
                m1[s1[i]]++;

            if (m2.find(s2[i]) == m2.end())
                m2.insert(pair<char,int> (s2[i], 1));
            else 
                m2[s2[i]]++;
        }
        while(!m1.empty()){
            if (m2.find(m1.begin()->first) == m2.end())
                return false;
            else if(m1.begin()->second != m2[m1.begin()->first])
                return false;
            else
            {
                m1.erase(m1.begin());
            }
        }
    }
    return true;
}