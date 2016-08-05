//write a function that takes in an int and returns a string that would be how one would say that number (ex: 123 -&gt; one hundred twenty three; 50019 -&gt; five thousand nineteen).

#include <iostream>
using namespace std;


string removeDuplicate(string s);

int main(int argc, const char * argv[]) {
    
    cout << removeDuplicate("lolllhelloo");
    
}

string removeDuplicate (string s){
    bool seen [256];
    
    string newString="";
    
    for (int x = 0; x<s.length(); x++){
        
        if (!seen[s[x]]){
            newString += s[x];
            seen[s[x]]=true;
        }
    }
    
    return newString;
}

