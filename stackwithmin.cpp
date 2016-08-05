#include <iostream>
#include <stdio.h>
#include <sstream>
#include <map>
#include <array>
#include <algorithm>
#include <string>
#include <stack>


using namespace std;

class stack2{
private:
    int array[10];
    int top;
    
public:
    
    stack2(){
        top = -1;
    }
    
    virtual void push(int x){
        if (!isFull()){
            array[++top] = x;
        }
    }
    
    virtual void pop(){
        if (!isEmpty()){
            top--;
        }
    }
    
    bool isEmpty(){
        return (top == -1);
    }
    
    int top1(){
        if (!isEmpty()){
            return array[top];
        }else{
            return -1;
        }
    }
    
    bool isFull(){
        return !(top+1<10);
    }
};

class stackWithMin: public stack2{
    
private:
    stack2 *minStack;
    
public:
    stackWithMin(){ //constructor
        minStack = new stack2();
    }

    void push(int x){
        if (!isFull()){
            if (minStack->isEmpty() || x < minStack->top1()){
                minStack->push(x);
            }
            stack2::push(x);
        }
    }
    
    void pop(){
        if (!isEmpty()){
            if (minStack->top1() == top1()){
                minStack->pop();
            }
            stack2::pop();
        }
    }
    
    int min(){
        if (!minStack->isEmpty()){
            return minStack->top1();
        }else{
            return 0;
        }
        
    }
    
};


int main(){

    
    
}