/*
*1、a保存magazine字符串中字母的出现次数 2、将ransomNote字符串的字母进行抵消 3，判断a中的字母个数是否足够抵消
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {0};
        for(int i = 0; i < magazine.size(); i++){
            int index = magazine[i] - 'a';
            a[index] += 1;
        }

        for(int i = 0; i < ransomNote.size(); i++){
            int index = ransomNote[i] - 'a';
            a[index] -= 1;
        }

        for(int i = 0; i < 26; i++){
            if(a[i] < 0){
                return false;
            }
        }
        return true;
    }
};