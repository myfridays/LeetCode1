/*
* 第一遍从左到右，计算左低右高的情况；第二遍从右到左，计算右低左高的情况，取至少能取到的雨水；
* 两边一定接不到雨水
* 时间复杂度：O(n), 空间复杂度O(n)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); //数组长度
        vector<int> trapVec(n, 0); // 雨水数组
        int h = height[0]; 
        for(int i = 1; i < n; i++){ // 第一遍，计算左低右高的情况
            if(h > height[i]){
                trapVec[i] = h - height[i]; 
            }else{
                h = height[i];
            } 
        }
        h = height[n-1]; 
        trapVec[n-1] = 0;   // 两边的雨水为0
        for(int i = n-2; i >= 0; i--){ //第二遍从右到左，计算右低左高的情况
            if(h > height[i]){
                trapVec[i] = min(trapVec[i], h-height[i]);
            }else{
                trapVec[i] = 0;
                h = height[i];
            }
        }
        int trapC = 0;  // 雨水总数
        for(int i = 0; i < n; i++){
            trapC += trapVec[i];
        }
        return trapC;
    }
};