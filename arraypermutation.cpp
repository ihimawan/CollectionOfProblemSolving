#include <iostream>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stack>
#include <string>

//implement min-stack

using namespace std;

void permutation (int array[], int starting, int ending){
    
    if (starting == ending){
        
        for (int x = 0 ; x <= ending; x++){
            cout << array[x] << " ";
        }
        cout << "\n";
    }else{
        for (int i = starting; i <= ending ;i++){
            int temp = array[starting];
            array[starting] = array[i];
            array[i] = temp;
            permutation(array, starting+1, ending);
        }
    }
    
}

int main(){

    int array[] = {1,2,3,4};
    permutation(array, 0, sizeof(array)/sizeof(int)-1);
    
    
}

//Here is a non-recursive algorithm in C++ from the Wikipedia entry for unordered generation of permutations. For the string s of length n, for any k from 0 to n! - 1 inclusive, the following modifies s to provide a unique permutation (that is, different from those generated for any other k value on that range). To generate all permutations, run it for all n! k values on the original value of s.


#include <algorithm>

void permutation(int k, string &s)
{
    for(int j = 1; j < s.size(); ++j)
    {
        std::swap(s[k % (j + 1)], s[j]);
        k = k / (j + 1);
    }
}