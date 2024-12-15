class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(); // 长 宽
        std::unordered_set<int> row;
        std::unordered_set<int> col;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }

        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row.count(i) > 0 || col.count(j)){
                    matrix[i][j] = 0;
                }
            }

        }
    }
};