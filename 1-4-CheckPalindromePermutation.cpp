#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool is_perm_palindrome(string s);

int main(){
    string input = "ACB";
    cout << is_perm_palindrome(input) << endl;
    return 0;
}

bool is_perm_palindrome(string s){
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i ++){
        if (s[i] != ' '){
            if (map.find(s[i]) == map.end()){
                map.insert(pair <char, int> (s[i], 1));
            }
            else {
                map[s[i]]++;
            }
        }
    }
    int count = 0; 
    while(!map.empty()){
        if(map.begin()->second%2 != 0){
            count ++; 
        }
        map.erase(map.begin());
    }
    if (count > 1)
        return false;
    else
    {
        return true;
    }   
}