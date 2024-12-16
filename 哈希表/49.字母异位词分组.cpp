/*法一：哈希表
*键：同一类异位词标志，值：将同一类异位词
*时间复杂度：O(nklogk), 空间复杂度：O(nk)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        // 哈希表
        for(string& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); ++it){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};