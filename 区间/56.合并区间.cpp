/*
*首先第一个区间加入到结果数组中去，然后判断当前的区间一个元素跟结果数组的最后一个区间进行比较，如果区间第一个元素
* 较大，说明没有重叠，直接将当前区间加入到结果中去；否则重叠，更新结果数组最后一个区间的第二个元素
* 时间复杂度：O(nlogn), 空间复杂度：O(1)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end());

        for(int i = 0; i < intervals.size(); i++){
            int L = intervals[i][0], R = intervals[i][1];
            if(!ret.size() || ret.back()[1] < L){
                ret.push_back({L, R});
            }else {
                ret.back()[1] = max(ret.back()[1], R);
            }
        }

        return ret;
        

        return ret;
    }
};