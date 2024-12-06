/**法一
*暴力法
*时间复杂度：O(n^2) 空间复杂度：O(1)
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n = citations.size(); 
       int h = n; // h指数
       while(h > 0){
            int cnt = 0; // 记录有多少篇满足引用量
            for(int i = 0; i < n; i++){
                if(citations[i] >= h)
                    cnt++;
            }
            if(cnt >= h){
                break;
            }
            h--;
       }
       return h;
    }
};

/**法二
*先排序
*时间复杂度：O(nlogn) 空间复杂度：O(1)
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
       int n = citations.size(); // 数组长度
       int h = 0; // h指数
       sort(citations.begin(), citations.end()); // 快排
       for(int i = n-1; i >= 0; i--){
            if(citations[i] > h){
                h++;
            }else{
                break;
            }
       }
       return h;
    }
};