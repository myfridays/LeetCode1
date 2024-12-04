/**法一
*思路：先进行快排，然后遍历每个数出现的个数cnt，如果cnt>(n/2),则返回这个数
*时间复杂度：O(n),空间复杂度O(1)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); // nums的长度
        int cnt = 0; // 计数：每个数出现的个数
        int cur = nums[0]; // 当前计数元素
        sort(nums.begin(), nums.end()); // 快排
        for(int i = 0; i < n; i++){
            if(cur == nums[i]){ 
                cnt++;
                if(cnt > n / 2){
                    break;
                }
            }else{
                cur = nums[i]; 
                cnt = 1; // 重新计数
            }
        }
        return cur;
    }
};