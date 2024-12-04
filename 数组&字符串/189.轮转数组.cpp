/**法一
*思路：使用一个额外的数组
*时间复杂度：O(n) 空间复杂度O(n)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // nums的长度
        int nums1[n];
        int j = 0;
        k = k % n;
        for(int i = n-k; i < n; i++){
            nums1[j] = nums[i];
            j++;
        }
        for(int i = 0; i < n-k; i++){
            nums1[j] = nums[i];
            j++;
        }
        for(int i = 0; i < n; i++){
            nums[i] = nums1[i];
        }
    }
};


/*法一
*思路：使用一个额外的数组
*时间复杂度：O(n) 空间复杂度O(n)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // nums的长度
        vector<int> newArr(n);
        for(int i = 0; i < n; ++i){
            newArr[(i+k)%n] = nums[i];
        }
        nums.assign(newArr.begin(), newArr.end());
    }
};