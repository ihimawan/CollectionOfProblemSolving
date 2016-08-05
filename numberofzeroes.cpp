#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int numberofzeroes(int number){
    string x = to_string(number);
    int count = 0;
    
    for (int j = 0; j < x.length(); j++){
        if (x[j] == '0'){
            count ++;
        }
    }
    
    cout << count;
    return count;
}

int main (){
    numberofzeroes(2000);
}