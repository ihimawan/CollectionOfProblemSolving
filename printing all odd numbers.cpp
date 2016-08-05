//Printing all odd numbers

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 100
int stackIndex=0;

bool myfunction (int i, int j){
    return i<j;
}

void push(int value, int stack[]){
    stack[stackIndex++] = value;
}

int pop(int stack[]){
    return stack[--stackIndex];
}

int main(int argc, const char * argv[]) {
    int array[]={1,1,2,2,9,3,2,5,7};
    vector<int> v(array, array + sizeof(array)/sizeof(int));
    
    int stack[N];
    
    sort(v.begin(), v.end(), myfunction);
    
    for (vector<int>::iterator it=v.begin(); it!=v.end(); it++)
        if (*it != stack[stackIndex-1]){
            push (*it, stack);
        }else{
            pop(stack);
        }
    
    for (int i=0; i<stackIndex; i++){
        cout << stack[i];
    }
    
    
    
    
    
    
}
