#include <iostream>
#include <stdio.h>
#include <map>
#include <math.h>

using namespace std;

int main(){
    int factor = 101;
    
    for (int i = 1; i <= sqrt(factor) ; i++){
        if (factor%i == 0){
            cout << i << "*" << factor/i << "\n";
        }
    }
}