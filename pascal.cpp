class Solution {
public:

    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        
        vector<vector<int>> result (numRows); 
        
        for (int line = 0; line < n; line++){
            result[line].push_back(1);
            for (int x = 1; x < line; x++){
                result[line].push_back(result[line-1][x-1] + result[line-1][x]);
            }
            result[line].push_back(1);
        }
        
        return result;
    }
};