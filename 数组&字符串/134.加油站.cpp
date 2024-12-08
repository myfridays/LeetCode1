/**法一
* 暴力算法:超时
* 时间复杂度：O(n^2) / 空间复杂度O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 遍历所有加油站点
        int num = 0; // 油量
        int n = gas.size();
        for(int i = 0; i < n; i++){
            num = gas[i]; //初始油量
            int j = 0;
            while(num >= cost[(j+i)%n]){
                num = num - cost[(j+i)%n] + gas[(j+i+1)%n];
                j++;
                cout << num << "\t";
                if(j == n && num >= 0){
                    return i;
                }
            }
        }
        return -1; //不存在解
    }
};

/**法二
* 我们首先检查第 0 个加油站，并试图判断能否环绕一周；如果不能，就从第一个无法到达的加油站开始继续检查。
* 时间复杂度：O(n) / 空间复杂度O(1)
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0; 
        int n = gas.size();
        while(i < n){
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while(cnt < n){
                    int j = (i + cnt) % n;
                    sumOfGas += gas[j];
                    sumOfCost += cost[j];
                    if(sumOfGas < sumOfCost){
                        break;
                    }
                    cnt++;
            }
            if(cnt == n){
                return i;
            }
            i = cnt + i + 1;
        }
        return -1; 
    }
};