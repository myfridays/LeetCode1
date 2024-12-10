/*
*1、去除尾部多余空格；2、读取尾部第一个字符串并反转 3、依次反复 4、最后去除尾部多余空格
* 时间复杂度：O(N) 空间复杂度：O(N)
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = n-1;
        while(i >= 0){
            string str = ""; // 保存字符串
            while(i >= 0 && s[i] == ' '){ // 去除多余空格
                i--;
            }

            while(i >= 0 && s[i] != ' '){ // 读取字符串
                str += s[i];
                i--;
            }

            std::reverse(str.begin(), str.end()); //反转字符串
            ans += str;
            ans += " ";

        }
        i = ans.size()-1;
        while(i >= 0 && ans[i] == ' '){ // 去除多余空格
                ans.erase(ans.end()-1);
                i--;
        }
        return ans;
    }
};