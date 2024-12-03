/**法一
* 思路：直接判断是否为val，如果是计数加1，如果不是，则将该元素保存到temp;最后保存到nums
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

/**法二:
 * 思路：双指针
 * 时间复杂度：O(n)  空间复杂度：O(1)
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); // n是nums的长度
        if (n == 0) {
            return 0;
        }
        int left = 0, right = n - 1; // 左右指针
        while (left < right) {
            // 当left == right就退出
            if (nums[left] != val && nums[right] != val) {
                left++;
            } else if (nums[left] != val && nums[right] == val) {
                left++;
                right--;
            } else if (nums[left] == val && nums[right] == val) {
                right--;
            } else if (nums[left] == val && nums[right] != val) {
                // 右边是val,左边不是val,相互替换，并更新指针
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                right--;
                left++;
            }
        }
        if (nums[left] == val) {
            return left;
        } else {
            return left + 1;
        }
    }
};

/*法二
 * 思路：双指针（起始位置都是0）,将不是val的元素覆盖到起始位置
 * 时间复杂度：O(n)  空间复杂度：O(1)
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); // n是nums的长度
        int left = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};


/*法三
 * 思路：双指针优化,左边就是一直判断是否相等的，如果不是就一直找
        ，右边就是左边有相等的就一直替换左边，然后减一
 * 时间复杂度：O(n)  空间复杂度：O(1)
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
};