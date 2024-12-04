/*法一
 * 思路：快慢指针
 * 时间复杂度：O(n),空间复杂度O(1)
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); // nums的长度
        if (n <= 2) {
            return n;
        }
        int fast = 2, slow = 2; // 初始值为2
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                // 将上上个元素和当前元素比较
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};