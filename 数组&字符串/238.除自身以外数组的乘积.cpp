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