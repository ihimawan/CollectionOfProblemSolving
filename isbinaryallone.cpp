#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

bool isAllOne(int number){

    int temp = number;
    bool flag = true;
    
    while (temp!=0 && flag){
        if (temp%2==0){ // if even number. alternative: if ((temp&1) == 0)
            flag = false;
        }
            temp = temp >> 1;
    }
    
    if (flag){
        cout << "yes";
    }else{
        cout << "nope";
    }
    
    return flag;
}

int main (){
    isAllOne(15);
}