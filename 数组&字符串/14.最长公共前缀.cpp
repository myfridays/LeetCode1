/*找最小的字符串，将最小的字符串的字符，跟字符串数组的每个字符串的字符进行比较*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        int min = 200; // 找出最小的那个长度
        int index = 0; // 找出最小长度字符串的位置
        int n = strs.size(); //字符串数组长度
        for(int i = 0; i < n; i++){
            if(min >= strs[i].size()){
                min = strs[i].size();
                index = i;
            }
        }
        for(int i = 0; i < min; i++){
            char s = strs[index][i];
            bool flag = false;
            for(int j = 0; j < n; j++){
                if(s != strs[j][i]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                str += s;
            }else{
                break;
            }
        }
        return str;
    }
};