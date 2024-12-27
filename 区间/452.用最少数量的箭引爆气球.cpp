/*
*将相同的区域进行合并并保存在一个区间数组，然后这个合并的区间数组的大小就是引爆气球的最少箭数数量。
*时间复杂度：O(nlogn) , 空间复杂度：O(n)
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector <int>> tmp;
        for(int i = 0; i < points.size(); i++){
            int L = points[i][0], R = points[i][1];
            if(!tmp.size() || tmp.back()[1] < L){
                tmp.push_back({L, R});
            }else{
                tmp.back()[0] = max(tmp.back()[0], L);
                tmp.back()[1] = min(tmp.back()[1], R);
            }
        }
        return tmp.size();
    }
};