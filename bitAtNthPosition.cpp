#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool bitatnth(int number, int position){
    
    int k = 1;
    
    for (int i = 0 ; i<position; i++){
        k = k << 1;
    }
    
    if (number & k){
        cout << "yes";
        return true;
    }else{
        cout << "no";
        return false;
    }
    

}

int main (){
    bitatnth(3, 0);
}