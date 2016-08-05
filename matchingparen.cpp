#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

bool check(char C[]){
    
    stack<char> S;
    char ch;
    for (int i = 0 ; i < strlen(C); i++){
        ch = C[i];
        if (ch == '(' || ch == '[' || ch == '{'){
            S.push(ch);
        }else{
            if (ch == ')'){
                if (S.top()!='('){
                    return false;
                }else{
                    S.pop();
                }
            }else if (ch == ']'){
                if (S.top()!='['){
                    return false;
                }else{
                    S.pop();
                }
            }else if (ch == '}'){
                if (S.top()!='{'){
                    return false;
                }else{
                    S.pop();
                }
            }
        }
    }
    
    if (!S.empty())
    {return false;}
    
    return true;
}


int main (){
    char C[100];
    cin >> C;
    
    cout << strlen(C);
    
    if (check(C)){
        cout << "ok";
    }else{
        cout << "nope";
    }

}