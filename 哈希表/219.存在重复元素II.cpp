/* 法一 哈希表
* 1、创建哈希表(键为元素，值为索引)，遍历整个数组，当这个元素存在哈希表中，则将两个索引进行比较是否绝对值小于等于k
* 时间复杂度：O(n), 空间复杂度：O(n)
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(mp.count(x) && (abs(i - mp[x]) <= k)){
                return true;
            }
            mp[x] = i;
        }

        return false;
    }
};


/* 法二 滑动窗口
* 时间复杂度：O(n), 空间复杂度：O(k)
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            if (i > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.count(nums[i])) {
                return true;
            }
            s.emplace(nums[i]);
        }
        return false;
    }
};
