// https://leetcode.com/problems/convert-1d-array-into-2d-array/?envType=daily-question&envId=2024-09-01
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int originalSize = original.size();
        if(m*n != originalSize) {
            return {};
        }
        int originalIndex = 0;
        vector<vector<int>> matrix(m, vector<int>(n));
        for(int i = 0; i < m; i ++) {
            for(int j = 0; j < n; j ++) {
                matrix[i][j] = original[originalIndex++];
            }
        }
        return matrix;
    }
};
