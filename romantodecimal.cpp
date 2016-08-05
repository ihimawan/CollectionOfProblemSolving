#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int romanToDecimal(const char *roman){
    char* ch;
    ch = (char*) roman;
    int valid = 1000;
    bool error = false;
    int sum =0;
    vector<char> past;
    
    while (*ch && !error){
        
        switch (*ch) {
            case 'M':
                if (valid >= 1000){
                    sum+=1000;
                    valid = 1000;
                }else{
                    error = true;
                }
                break;
                
            case 'D':
                if (valid >= 500 && past.size()==0){
                    sum+=500;
                    valid = 500;
                    past.push_back('D');
                }else{
                    error = true;
                }
                break;
                
            case 'C':
                if (valid >= 100){
                    if (*(ch+1) == 'M' && valid>=1000 && past.size()<=4){
                        sum = sum + 1000 - 100;
                        ch++;
                        valid = 50;
 
                    }else{
                        sum+=100;
                        valid = 100;
                        
                        if (past.empty() || past[0]!='C'){
                            past.clear();
                        }
                        past.push_back('C');
                    }
                    
                }else{
                    error = true;
                }
                break;
                
                
            case 'L':
                if (valid >= 50 && past.size()==0){
                    sum+=50;
                    valid = 50;
                    
                    if (past.empty() || past[0]!='L'){
                        past.clear();
                    }

                    past.push_back('L');
                    
                }else{
                    error=true;
                }
                break;
                
                
            case 'X':
                if (valid >= 10){
                    if (*(ch+1) == 'L' && valid >= 50 && past.size()<=4){
                        sum = sum + 50 -10;
                        ch++;
                        valid = 1;
                        
                    }else{
                        sum += 10;
                        valid = 10;
                        
                        if (past.empty() ||past[0]!='X'){
                            past.clear();
                        }
                        
                        past.push_back('X');
                        
                    }
                }else{
                    error=true;
                }
                break;
                
            case 'I':
                if (valid >= 1){
                    
                    if (*(ch+1) == 'X' && valid>=10 && past.size()<=4){
                        sum = sum + 9;
                        ch++;
                        valid = 0;
                    }else{
                        sum += 1;
                        valid = 1;
                        
                        if (past.empty() ||past[0]!='I'){
                            past.clear();
                        }
                        
                        past.push_back('I');
                    }
                    
                }else{
                    error=true;
                }
                
                
                break;
                
            default:
                error = true;
                break;
                
        }
        ch++;
    }
    
    if (error){
        cout << "invalid expression.";
        return 0;
    }
    
    return sum;
}

int main (){
    cout << romanToDecimal("LL");
}