/*反向遍历：把最后面的空格都跳过给，然后遇到非空字符开始统计长度，遇到第一个空格则退出*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag = false; // 用于记录已经接收到了字符串
        int length = 0; // 最后字符串的长度
        for(int i = s.size()-1; i >= 0; i--){
            if(flag && s[i] == ' '){
                return length;
            }else if(s[i] == ' '){
                continue;
            }else if(s[i] != ' '){
                length++;
                flag = true;
            }
        }
        return length;
    }
};