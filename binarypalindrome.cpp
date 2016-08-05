#include <iostream>
#include <stdio.h>

using namespace std;

int isBitPalindrome(int x) {
    int reversed = 0, aux = x;
    while (aux > 0) {
        reversed = (reversed  << 1) | (aux & 1);
        aux = aux >> 1;
    }
    return (reversed  == x) ? 1 : 0;
}

int main(){
    
    int value = 15;
    int x = value;
    int reversed = 0;
    
    while (x > 0){
        reversed = reversed << 1;
        reversed = reversed | (x & 1);
        x = x >> 1;
    }
    
    if (value == reversed){
        cout << "yes";
    }else{
        cout << "no";
    }
    
    if (isBitPalindrome(15)){
        cout << "yes";
    }else{
        cout << "no";
    }
    
}
