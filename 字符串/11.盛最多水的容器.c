/*
* 双指针，前后各求出最大的面积
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1; // 左右指针
        int area = 0; //最大面积
        int w = 0, h = 0; //宽和高
        while(i < j){
            w = j - i;
            h = min(height[i], height[j]);
            area = max(area, w*h);
            if(height[i] >= height[j]){
                j--;
            }else{
                i++;
            }
        }
        return area;
    }
};