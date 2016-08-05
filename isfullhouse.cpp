#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int main(){
    string array[] = {"10d","1c", "1h", "1s", "2c", "1d", "13h"};
    int deck[12];

    int isThree = 0;
    int isTwo = 0;
    
    for (string x : array){
        deck[x[0]] += 1;
        if (deck[x[0]] == 3){
            isThree++;
            isTwo--;
        }else if (deck[x[0]] == 2){
            isTwo++;
        }
        
        if (isThree > 0 && isTwo > 0){
            cout << "yes.";
            return 0;
        }
    }
    
    cout << "no.";
}