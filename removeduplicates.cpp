

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

