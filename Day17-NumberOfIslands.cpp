/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        if(!h) return 0;
        int w = grid[0].size();
        
        int island = 0;
        
        for(int i = 0; i < w; i++)
            for(int j = 0; j < h; j++)
                if(grid[j][i] == '1'){
                    dfs(grid, j, i);
                    island++;
                }
        return island;    
    }
    
    void dfs(vector<vector<char>>& grid, int y, int x){
        if(y >= grid.size() || y < 0 
          || x >= grid[0].size() || x < 0 || grid[y][x] == '0')
            return;
        grid[y][x] = '0';
        dfs(grid, y-1, x);
        dfs(grid, y+1, x);
        dfs(grid, y, x-1);
        dfs(grid, y, x+1);
    }
};
