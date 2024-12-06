/*法一
*思路：找到当前能到达的最远位置作为边界，当索引到达边界，重新更新边界，直到到最后
*时间复杂度：O(n), 空间复杂度：O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0; // 这是当前到达的最大索引
        int end = 0; //边界
        int n = nums.size(); // 数组长度
        int step = 0; //最小步数
        for(int i = 0; i < n-1; i++){
            if(maxPos >= i){
                maxPos = max(maxPos, i+nums[i]);
                if(i == end){
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};