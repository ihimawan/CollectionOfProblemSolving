#include <iostream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stack>

//implement min-stack

using namespace std;

class MinStack{
    
public:

    void push (int x){
        actualstack.push(x);
        if (minimum.empty() || x <= minimum.top()){
            minimum.push(x);
        }
    }
    
    void pop(){
        
        if (!actualstack.empty()){
            int x = minimum.top();
            int y = actualstack.top();
            
            if (actualstack.top() == minimum.top()){
                minimum.pop();
            }
            actualstack.pop();
            return;
        }else{
            return;
        }
    }
    
    int getMin(){
        if (minimum.empty()){
            return pow(2,31);
        }else{
            return minimum.top();
        }
        
    }
    
    stack<int> minimum;
    stack<int> actualstack;

};



int main(){
    MinStack *newstack = new MinStack();
    newstack->push(5);
    newstack->push(4);
    newstack->push(3);
    newstack->push(10);
    
    cout << newstack->getMin();
    
    newstack->pop();
    newstack->pop();
    
    cout << newstack->getMin();
}