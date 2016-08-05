#include <stdio.h>
#include <iostream>
#include <utility>
#include <map>
#include <vector>

#define RANGE 100

using namespace std;

int main(){
    int array[]={1,3,2,2,3,2,2,2,3,2,1};
    int k = 3;
    cout << "hi\n";
    pair<int,int> newArray[RANGE];
//    vector<pair<int,int>> v;
    
    for (int x : array){ //O(n)
        if (newArray[x].first == 0 && newArray[x].second == 0){
            newArray[x] = make_pair(x, 1);
        }else{
            newArray[x].second+=1;
        }
        
    }
    
    //just printing the array
    for (int i = 0 ; i<sizeof(newArray)/sizeof(newArray[1]); i++){
        if (newArray[i].first != 0 && newArray[i].second != 0){
//            v.push_back(newArray[i]);
            cout << newArray[i].first << "=>" << newArray[i].second << "\n";
        }
    }
    
    for (int i = 0; i<k; i++){ //O(nk)
        int biggestIndex = i;
        int biggest = newArray[biggestIndex].second;
        for (int j = i+1; j<sizeof(newArray)/sizeof(newArray[0]); j++){
            if (newArray[biggestIndex].second < newArray[j].second){
                biggestIndex = j;
                biggest = newArray[biggestIndex].second;
            }
        }
        
        pair<int, int> temp = newArray[biggestIndex];
        newArray[biggestIndex] = newArray[i];
        newArray[i] = temp;
        
    }
    
    cout << newArray[k-1].first << " " << newArray[k-1].second;
    
    //space complexity O(RANGE)

    
}