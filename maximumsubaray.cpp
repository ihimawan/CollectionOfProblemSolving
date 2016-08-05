#include <iostream>
#include <stdio.h>

#define INT_MIN -2000

using namespace std;

int Maximum_sub_array(int array[], int n){
    if (n==1){
        return array[0];
    }
    
    int m = n/2;
    
    int leftMSS = Maximum_sub_array(array, m);
    int rightMSS = Maximum_sub_array(array+m, n - m);
    int sum = 0;
    int rightSum = INT_MIN, leftSum = INT_MIN;
    
    for (int i = m+1; i < n ; i ++){ //right sum starts at m+1 up to n-1
        sum += array[i];
        rightSum = max(rightSum, sum);
    }
    
    sum = 0;
    
    for (int i = m; i>=0;i--){ //left sum starts at m up to 0
        sum += array[i];
        leftSum = max (leftSum, sum);
    }
    
    int ans = max (leftMSS, rightMSS); //see on the two halves
    return max(ans,leftSum + rightSum); //compare with the one that meets in the middle
}

int kadane (int array[], int n){
    int ans = 0, sum = 0;
    
    for (int i = 0 ; i < n; i++){
        if (sum + array[i]>0){
            sum+=array[i];
        }else{
            sum = 0;
        }
        
        ans = max(ans, sum);
    }
    return ans;
}

int main(){

}
