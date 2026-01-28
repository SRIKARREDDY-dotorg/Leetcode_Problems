// https://leetcode.com/problems/range-sum-query-2d-immutable/?envType=problem-list-v2&envId=prefix-sum

class NumMatrix {
public:
    int row, col;
    vector<vector<int>> newMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        // last row sum
        row = matrix.size();
        col = matrix[0].size();
        for(int j = col-2; j >= 0; j --) {
            matrix[row-1][j] += matrix[row-1][j+1];
        }

        for(int i = row-2; i >= 0; i --) {
            matrix[i][col-1] += matrix[i+1][col-1];
        }

        for(int i = row-2; i >= 0; i --) {
            for(int j = col-2; j >= 0; j --) {
                matrix[i][j] += (matrix[i+1][j] + matrix[i][j+1] - matrix[i+1][j+1]);
            }
        }
        newMatrix = matrix;
        // print(newMatrix);
        // copy(matrix.begin(), matrix.end(), back_inserter(newMatrix));
    }

    void print(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i ++) {
            for(int j = 0; j < matrix[0].size(); j ++) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int rightSide = (col2+1) < col ? newMatrix[row1][col2+1] : 0;
        int bottomSide = (row2+1) < row ? newMatrix[row2+1][col1] : 0;
        int bottomCorner = ((col2+1) < col && (row2+1) < row) ? newMatrix[row2+1][col2+1] : 0;
        return newMatrix[row1][col1] - rightSide - bottomSide + bottomCorner;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
