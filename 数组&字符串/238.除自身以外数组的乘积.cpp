/*法一
*先将数组所有非零的相乘总数mul，并且计有多少个0数；如果没有0,直接mul/nums[i];如果有一个0，
*nums[i]就是0，则mul,否则为0；如果有至少两个零，则为0
*时间复杂度：O(n); 空间复杂度O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroC = 0; // 数组0的个数
        int mul = 1; // 数组所有项相乘的总数
        for(auto x : nums){
            if(x != 0){
                mul *= x;
            }else{
                zeroC++;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(zeroC == 0){
                nums[i] = mul / nums[i];
            }else if(zeroC > 1 || (zeroC == 1 && nums[i] != 0)){
                nums[i] = 0;
            }else if(zeroC == 1 && nums[i] == 0){
                nums[i] = mul;
            }
        }
        return nums;
    }
};


/*法二
*求前缀和后缀数组，最后乘积为前缀乘以后缀
*时间复杂度：O(n); 空间复杂度O(n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n, 0), R(n, 0); // 前后缀数组
        vector<int> ans(n, 0); // 结果
        L[0] = 1;
        for(int i = 1; i < n; i++){
            L[i] = L[i-1] * nums[i-1]; // 前缀数组
        }

        R[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            R[i] = R[i+1] * nums[i+1]; // 后缀数组
        }

        for(int i = 0; i < n; i++){
            ans[i] = L[i] * R[i];
        }
        return ans;
    }
};