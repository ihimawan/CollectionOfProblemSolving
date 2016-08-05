#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> parseByThree(int i){
 
    stack <int> result;
    int insert;
    
    while (i>0){
        insert = i%1000;
        result.push(insert);
        i = i/1000;
    }
    
    return result;
}

string threeToString(int num){
    string ones[] = {"", "one", "two", "three", "four", "five" , "six" , "seven" , "eight", "nine" , "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy" , "eighty", "ninety"};
    
    int current;
    int temp;
    
    string result = "";
    
    if (current>0){
        
        current = num;
        
        if (current>=100){
            temp = current/100;
            result += ones[temp];
            result += " hundred ";
            current = current%100;
        }
        
        if (current > 19){
            temp = current / 10;
            result += tens[temp];
            result += " ";
        }else if(current > 9){
            result += ones[current];
            result += " ";
            return result;
        }
        
        current = current % 10;
        
        result += ones[current];
        
        result += " ";
    }
    
    return result;
    
}

string combine(stack<int> s){
    string units[] = {"billion", "million", "thousand", ""};
    
    int size = 4-(int)s.size();
    
    string result  = "";
    
    while (!s.empty()){
        
        int x = s.top();
    
        if (x==0){
            size++;
        }else{
            result += threeToString(x);
            result += units[size++];
        }
        result += " ";
        s.pop();
    }
    
    return result;
}

void intToText(int num){
    
    if (num == 0){
        cout << "zero";
        return;
    }
    
    cout << combine(parseByThree(num));
    
}

int main (){
    
    intToText(999000913);
}