class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int > ans;
        int m = matrix.size(), n = matrix[0].size(); // 长， 宽
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while(left <= right && top <= bottom){
            // 从左到右
            for(int i = left; i <= right; i++){
                ans.emplace_back(matrix[top][i]);
            }
            top++;

            // 从上到下
            for(int i = top; i <= bottom; i++){
                ans.emplace_back(matrix[i][right]);
            }
            right--;

            // 从右到左
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.emplace_back(matrix[bottom][i]);
                }
            }
            
            bottom--;

            // 从下到上
            if (left <= right) {
                for(int i = bottom; i >= top; i--){
                    ans.emplace_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};