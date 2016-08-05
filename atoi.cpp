#include <iostream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stack>
#include <string>

//implement min-stack

using namespace std;

int atoi(char* str){
    int res=0;
    bool negnum = false;
    
    if (*str - '0' < -1){
        negnum = true;
        str++;
    }
    for (;*str;str++){
        res = res*10 + *str - '0';
    }
    
    if (negnum){
        res = -res;
    }
    
    return res;
}


int main(){
    cout << atoi("-332132121");
}