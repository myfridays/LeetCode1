/*法一
* 思路：贪心算法
* 时间复杂度：O(n) 空间复杂度：O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int min = prices[0]; // 当前买入的最小值
       int max = 0; //当前获利最大值
       for(int i = 1; i < prices.size(); i++){
            max = std::max(max, prices[i]-min); // 当前获利最大
            min = std::min(min, prices[i]); // 当前买入最小
       }
       return max;
    }
};
