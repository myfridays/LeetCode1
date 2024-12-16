/*法一：暴力
*时间复杂度：O(n^2), 空间复杂度：O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] == target){
                    ans.emplace_back(i);
                    ans.emplace_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

/*法二：哈希表
*键：x,值：位置
*时间复杂度：O(N), 空间复杂度：O(N)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            int x = target - nums[i]; // 剩余的数
            if(mp.count(x)){
                ans.emplace_back(i);
                ans.emplace_back(mp[x]);
            }else{
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};