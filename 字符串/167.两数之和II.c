/*
* 前后双指针，取两边的值跟target比较，比target大，说明要取更小的值，右指针往前；比target小，说明取更大的值，左指针往后；
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int index1 = 0, index2 = n-1;
        vector<int> two;
        while(index1 < index2){
            int num = numbers[index1] + numbers[index2];
            if(num == target){
                two.push_back(index1+1);
                two.push_back(index2+1);
                return two;
            }else if(num > target){
                index2--;
            }else{
                index1++;
            }
        }
        return two;
    }
};