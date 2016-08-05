#include <stdio.h>
#include <iostream>

using namespace std;

const char* strStr(const char* source, const char* target){
    
    char* current;
    current = (char*) source;
    
    while (*current){ //while source still exists
        if (*current == *target){ //if source and target is the same,
            int i = 0;
            const char* save; //keep the address of the source
            save = current;
            
            while (*(current+i) == *(target+i)){ //while source and target is the same
                i++; //keep going
                if (!*(target+i)){ // if the target is empty
                    return save; //you've found it!
                }
            }
        }
        
        current++; //otherwise, keep going in the source
    }
    
    return NULL;
    
}

int main (){
    const char *ch = "helloworld";
    
    if (strStr(ch, "low") != NULL){
        cout << "foudn it!";
    }else{
        cout << "nope";
    }

    
}