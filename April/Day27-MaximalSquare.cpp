/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        
        int ans = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int lookup[row][col];
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                lookup[i][j] = matrix[i][j] - '0';
                if(i && j && matrix[i][j] == '1')
                    lookup[i][j] = 1 + min(lookup[i-1][j-1] , min(lookup[i][j-1], lookup[i-1][j]));
                ans = max(ans, lookup[i][j]);   
            }
        }
       return ans*ans;
    }
};
