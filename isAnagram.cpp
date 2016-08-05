#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {

    if (s.length() != t.length()){

        return false;

    }
    
    vector<char> s1;
    vector<char> t1;
    
    for (int i = 0; i < s.length(); i++){
        s1.push_back(s[i]);
        t1.push_back(t[i]);
    }
    
    sort(s1.begin(), s1.end());
    sort(t1.begin(), t1.end());

    

    for (int i = 0; i<s.length(); i++){

        if (s1[i]!=t1[i]){

            return false;

        }

    }


    return true;

}

int main (){
    
    if (isAnagram("cat", "cta")){
        cout << "ok";
    }else{
        cout << "nope";
    }
}