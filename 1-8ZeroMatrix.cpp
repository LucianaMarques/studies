#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print_matrix(vector<vector<int>> matrix);
vector<set<int>> find_zeros(vector<vector<int>> matrix);
void add_zeros(vector<vector<int>>& matrix, vector<set<int>> zeros);

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,0}};
    vector<set<int>> cl = find_zeros(matrix);
    add_zeros(matrix,cl);
    print_matrix(matrix);
    return 0;
}

void print_matrix(vector<vector<int>> matrix){
    for (int i =0 ; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void add_zeros(vector<vector<int>>& matrix, vector<set<int>> zeros){
    set<int> lines = zeros[0];
    set<int> columns = zeros[1];
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            if (lines.find(i) != lines.end() || columns.find(j) != columns.end())
                matrix[i][j] = 0;
        }
    }
}

vector<set<int>> find_zeros(vector<vector<int>> matrix){
    set<int> columns;
    set<int> lines;
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix[0].size(); j++){
            if (matrix[i][j] == 0){
                if (columns.find(j) == columns.end()) columns.insert(j);
                if (lines.find(j) == lines.end()) lines.insert(i);
            }
        }
    }
    return {lines,columns};
}

