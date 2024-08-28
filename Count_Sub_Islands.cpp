// https://leetcode.com/problems/count-sub-islands/?envType=daily-question&envId=2024-08-28

typedef vector<vector<int>> vvi;

class Solution {
public:
    vector<int> xDir{0, 1, 0, -1};
    vector<int> yDir{1, 0, -1, 0};
    
    bool isSubIsland(int x, int y, vvi& grid1, vvi& grid2) {
        bool subIsland = true;
        queue<pair<int, int>> q;
        q.push({x, y});
        grid2[x][y] = 0;
        while(!q.empty()) {
            int currX = q.front().first;
            int currY = q.front().second;
            q.pop();

            if(grid1[currX][currY] == 0) {
                subIsland = false;
            }

            for(int k = 0; k < 4; k ++) {
                int nextX = currX + xDir[k];
                int nextY = currY + yDir[k];
                if(isValid(nextX, nextY, grid2)) {
                    grid2[nextX][nextY] = 0;
                    q.push({nextX, nextY});
                }
            }
        }
        return subIsland;
    }

    bool isValid(int x, int y, vvi& grid) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y];
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        vector<pair<int,int>> cords;
        for(int i = 0; i < grid2.size(); i ++) {
            for(int j = 0; j < grid2[0].size(); j ++) {
                if(grid2[i][j] == 1 && isSubIsland(i, j, grid1, grid2)) {
                    count++;
                }
            }
        }
        return count;
    }
};
