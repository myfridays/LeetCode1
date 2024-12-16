/* 法一：哈希表
* 首先剔除重复元素，然后在该表中找到最小连续数，循环加1
* 时间复杂度：O(n), 空间复杂度：O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for(const int & num : nums){
            numSet.insert(num);
        }

        int ans = 0;
        for(auto & num : numSet){
            if(!numSet.count(num - 1)){
                int cur = num; // 当前的连续初始数
                int curLen = 1; // 初始长度；

                while(numSet.count(cur + 1)){
                    cur += 1;
                    curLen += 1;
                } 

                ans = max(curLen, ans);
            }
        }
        return ans;
    }
};