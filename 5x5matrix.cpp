#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void chicken (int matrix[5][5], int x1, int y1, int x2, int y2, int pos) {
//    cout << "-> " << x1 << ", " << y1;

    static string path[100];
    
    path[pos] = "";
    path[pos] += "-> ";
    path[pos] += to_string(x1); //convert int to string
    path[pos] += ", ";
    path[pos] += to_string(y1);
    
    if (x1 == x2 && y1 == y2){
        cout << "\n";
        for (int i = 0; i <= pos; i++){
            cout << path[i];
        }
    }
    
    if (x1<x2){
        chicken (matrix, x1+1, y1, x2, y2, pos+1);
    }else if(x1>x2){
        chicken (matrix, x1-1, y1, x2, y2, pos+1);
    }
    
    if (y1<y2){
        chicken (matrix, x1, y1+1, x2,y2, pos+1);
    }else if (y1>y2){
        chicken (matrix, x1, y1-1, x2, y2, pos+1);
    }
}

int main (){

    int matrix[5][5];
    
    chicken(matrix, 1, 1, 0, 0, 0);
    
}