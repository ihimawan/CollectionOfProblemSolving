#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

void printBinary(int number){
    stack<int> print;

    int temp = number;
    
    while (temp!=0){
        print.push(temp&1);
        temp = temp >> 1;
    }
    
    while (!print.empty()){
        cout << print.top() << " ";
        print.pop();
    }
    
}

int main (){
    printBinary(10);
}