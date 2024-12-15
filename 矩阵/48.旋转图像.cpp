// 先转置，然后再列反转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // 从对角进行互换
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > j){
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;
                }
            }
        }

        // 按列进行逆序
        for(int i = 0; i < m; i++){
            int left = 0, right = n-1;
            while(left < right){        // 数组逆序：双指针 
                int tmp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = tmp;
                left++;
                right--;
            }
        }
        return ;
    }
};