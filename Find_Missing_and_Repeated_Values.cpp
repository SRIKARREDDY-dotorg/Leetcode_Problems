class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // check for the repeating integer and missing one.
        int n = grid.size();
        int m = n * n;
        int sumOfNSquare = m*(m+1)/2;
        int totalSum = 0;
        unordered_set<int> s;
        int duplicate = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(s.find(grid[i][j]) != s.end()) {
                    duplicate = grid[i][j];
                } else {
                    totalSum += grid[i][j]; 
                }
                s.insert(grid[i][j]);
            }
        }
        return {duplicate, sumOfNSquare-totalSum};
    }
};
