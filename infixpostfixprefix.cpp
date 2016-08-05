#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int postfix(char C[]){
    
    stack<int> S;
    char ch;
    int result;
    for (int i = 0 ; i < strlen(C); i++){
        ch = C[i];
        if (ch == '+' || ch == '/' || ch == '*' || ch == '-'){
            result = S.top();
            S.pop();
            
            switch (ch) {
                case '+':
                    result += S.top();
                    break;
                case '*':
                    result = result * S.top();
                    break;
                case '/':
                    result = S.top() / result;
                    break;
                case '-':
                    result = S.top() - result;
                    break;
                    
                default:
                    break;
            }
            
            S.pop();
            S.push(result);
        }else if(('1'<=ch && ch<='9')){
            ch = ch - '0';
            S.push(ch);
        }
    }

    return S.top();
}

bool mulopp(char ch){
    if (ch == '*' || ch == '/'){
        return true;
    }else{
        return false;
    }
}

bool addopp(char ch){
    if (ch == '+' || ch == '-'){
        return true;
    }else{
        return false;
    }
}

bool higher(char ch1, char ch2){
    if (mulopp(ch1) && addopp(ch2)){
        return true;
    }else{
        return false;
    }
}

void infixToPostfix(char C[]){
    stack<char> S;
    char ch;
    for (int i = 0 ; i<strlen(C); i++) {
        ch = C[i];
        if ('A' <= ch && ch<='Z'){
            cout << ch;
        }else if(mulopp(ch) || addopp(ch)){

            while(!S.empty() && S.top()!='(' && higher(S.top(), ch)){
                cout << S.top();
                S.pop();
            }

            S.push(ch);
        }else if (ch == ')'){
            while(S.top()!='(' && !S.empty()){
                cout << S.top();
                S.pop();
            }
            S.pop();
        }else if(ch == '('){
            S.push(ch);
        }
    }
    
    while(!S.empty()){
        cout << S.top();
        S.pop();
    }
    
    
}

string prefix (char C[]){
    
    //postfix but backwards.
    
    return "hi";
}


int main (){
    char C[100];
    cin >> C;
    
    infixToPostfix(C);
    


}