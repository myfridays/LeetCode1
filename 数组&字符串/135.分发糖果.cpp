/*
*要理解明白相邻的孩子中，评分高的孩子获得更多的糖果。这个句话的含义。
*时间复杂度O(n), 空间复杂度O(n)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
       int n = ratings.size();
       vector<int>  candyVec(n, 1);
       for(int i = 1; i < n; i++){ // 从左到右遍历，右边评分大的糖果数要更多
            if(ratings[i] > ratings[i-1]) candyVec[i] = candyVec[i-1]+1;
       }
       int candyNum = 0; //糖果总数
       for(int i = n-2; i >= 0; i--){ // 从右向左遍历，左边评分大的糖果数要更多
            if(ratings[i] > ratings[i+1]) candyVec[i] = max(candyVec[i+1] + 1, candyVec[i]);
            candyNum += candyVec[i+1];
       }
       
       return candyNum+candyVec[0];
    }
};