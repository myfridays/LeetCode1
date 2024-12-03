/**法一
* 思路：双指针：一个指针进行重新赋值，另一个指针去寻找满足条件的元素
* 时间复杂度：O(n), 空间复杂度：O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); // nums数组的长度
        int left = 0;
        for(int right = 0; right < n; right++){
            if(nums[left] != nums[right]){
                nums[++left] = nums[right];
            }
        }
        return left+1;
    }
};