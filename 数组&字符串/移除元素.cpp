/*法一
* 思路：直接判断是否为val，如果是计数1，如果不是，则将该元素保存
* 时间复杂度：O(n)  空间复杂度：O(n)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); // nums数组的长度
        int temp[100];  // 临时数组的长度
        int j = 0; // 临时数组的索引
        int k = 0; // 等于val的个数
        for(int i = 0; i < n; i++){
            // 去判断是否为val
            if(nums[i] == val){
                k++;
            }else {
                temp[j] = nums[i];
                j++;
            }
        }
        for(int i = 0; i < j; i++){
            // 将temp元素移动到nums
            nums[i] = temp[i];
        }
        return n-k;
    }
};