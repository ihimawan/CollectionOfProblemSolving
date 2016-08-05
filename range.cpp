//Given a sorted integer array without duplicates, return the summary of its ranges.

//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

//NOTE! YOU CANNOT DO += ON VECTOR STRING.

#include <string>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    bool isStart = true;
    string hi = "";
    vector<string> result;
    for (int current = 0; current<nums.size(); current++){
        if (nums[current]+1 != nums[current+1]|| current+1==nums.size()){
            hi+=to_string(nums[current]);
            result.push_back(hi);
            isStart = true;
            hi = "";
        }else {
            if (isStart){
                hi += to_string(nums[current]);
                hi += "->";
                isStart = false;
            }
        }
    }
    
    for (string x: result){
        cout << x;
    }
    return result;
    }
};