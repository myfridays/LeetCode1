/*
* 一次遍历，判断最小连续区间，然后保存
* 时间复杂度：O(N) 空间复杂度：O(1)
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        string start = "", end = "";
        int i = 0;
        while(i < n){
            start = std::to_string(nums[i]);
            while(i+1 < n && nums[i] + 1 == nums[i+1]){
                end = std::to_string(nums[i+1]);
                i++;
            }

            if(end == ""){
                ans.emplace_back(start);
                
            }else{
                string a = start + "->" + end;
                ans.emplace_back(a);
                end = "";
            }
            i++;
        }
        return ans;
    }
};