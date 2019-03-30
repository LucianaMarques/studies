#include <iostream>
#include <vector>
#include "stdlib.h"
#include "stdio.h"
using namespace std;

void rotate_matrix(vector<vector<int>>& matrix);
void print_matrix(vector<vector<int>> matrix);

int main(){
    vector<vector<int>> matrix = {{1,1,2,7},{2,3,3,8},{5,4,4,9},{2,5,6,5}};
    print_matrix(matrix);
    rotate_matrix(matrix);
    cout << "------------" << endl;
    print_matrix(matrix);
    return 0;
}

void rotate_matrix(vector<vector<int>>& matrix){
    int upper = 0, lower = matrix.size() - 1, right = matrix.size() - 1, left = 0;
    int origin, destiny;
    while(upper < matrix.size()/2){
        for (int i = 0; i + left < right; i ++){
            //rotate 1
            origin = matrix[upper][left + i];
            destiny = matrix[lower - i][left];
            matrix[lower - i][left] = origin;
            //cout << matrix[lower - i][left] << endl;
            //rotate 2
            origin = destiny;
            destiny = matrix[lower][right - i];
            matrix[lower][right - i] = origin;
            //cout << matrix[lower][right -i] << endl;
            //rotate 3
            origin = destiny;
            destiny = matrix[upper + i][right];
            matrix[upper + i][right] = origin;
            //cout << matrix[upper + i][right] << endl;
            //rotate 4
            origin = destiny;
            destiny = matrix[upper][left + i];
            matrix[upper][left + i] = origin;
            //cout << matrix[upper][left + i] << endl;
        }
        //update borders
        upper ++;
        left ++;
        right --;
        lower --;
    }
}

void print_matrix(vector<vector<int>> matrix){
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j < matrix.size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}