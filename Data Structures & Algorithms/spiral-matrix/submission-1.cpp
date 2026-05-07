class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }
        
        int left = 0;
        int right = matrix[0].size();
        int top = 0;
        int bottom = matrix.size();

        while (left < right && top < bottom) {
            // Traverse from left to right
            for (int i = left; i < right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // Traverse downwards
            for (int i = top; i < bottom; i++) {
                res.push_back(matrix[i][right - 1]);
            }
            right--;

            if (!(left < right && top < bottom)) {
                break;
            }

            // Traverse from right to left
            for (int i = right - 1; i >= left; i--) {
                res.push_back(matrix[bottom - 1][i]);
            }
            bottom--;

            // Traverse upwards
            for (int i = bottom - 1; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};


