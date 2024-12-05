/*法一
* 思路： 1、找到每个索引能到达的最大位置，2、判断当前到达的最大位置能不能到达这个索引
* 时间复杂度：O(n), 空间复杂度：O(1)
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); // 长度
        int reach = 0; // 到达的最大位置
        for(int i = 0; i < n; i++){
            if(reach < i){
                return false;
            }
            reach = max(reach, i+nums[i]);
        }
        return true;
    }
};