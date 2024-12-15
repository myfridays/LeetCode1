/*法一
*1、首先复制一份数组，来保存当前细胞的一个状态
*2、然后通过比较周围八个细胞存活数，然判断该细胞是死是活
*3、然后在原数组进行更新
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {0, 1, -1}; // 左右的节点

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int>> copyBoard(rows, vector<int>(cols, 0));
        
        for(int row = 0; row < rows; row++){   // 复制一份数组
            for(int col = 0; col < cols; col++){
                copyBoard[row][col] = board[row][col];
            }
        }

        for(int row = 0; row < rows; row++){   
            for(int col = 0; col < cols; col++){
                int live = 0; // 细胞存活数

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(!(neighbors[i] == 0 && neighbors[j] == 0)){
                            int r = row + neighbors[i];
                            int c = col + neighbors[j];
                            //判断相邻细胞是否是活细胞
                            if((r >= 0 && r < rows) && (c >= 0 && c < cols) && copyBoard[r][c]){
                                live += 1;
                            }
                        }
                    }
                }

                if(!copyBoard[row][col] && live == 3){
                    board[row][col] = 1;
                }

                if(copyBoard[row][col] && (live < 2 || live > 3)){
                    board[row][col] = 0;
                }
            }
        }

    }
};