/*
* 先插入，再合并
* 时间复杂度：O(nlogn) 空间复杂度：O(1)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for(int i = 0; i < intervals.size(); i++){
            int L = intervals[i][0], R = intervals[i][1];
            if(!ret.size() || ret.back()[1] < L){
                ret.push_back({L, R});
            }else{
                ret.back()[1] = max(ret.back()[1], R);
            }
        }
        return ret;

    }
};