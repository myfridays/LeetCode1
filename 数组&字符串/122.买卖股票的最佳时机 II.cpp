/** 法一
*思路：有点离谱，简单
*时间复杂度：O(n), 空间复杂度：O(1)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 1; i < prices.size(); i++){
            if(prices[i]-prices[i-1] > 0){
                ans += prices[i] - prices[i-1]; 
            }
        }
        return ans;
    }
};