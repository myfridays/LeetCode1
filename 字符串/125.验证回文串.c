/*
 *1.先处理字符串，获取字母字符和数字字符，字母要变大小写
 *2.尾部字符串和首部字符串一一对比
 */
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) { // 使用 isalnum 函数判断 ch 是否是字母或数字字符。
                sgood += tolower(ch); // 如果 ch 是字母或数字，就将其转换为小写（
            }
        } 
        string sgood_rev(sgood.rbegin(), sgood.rend()); // sgood.rbegin() 和 sgood.rend()
        return sgood == sgood_rev; //  返回指向 sgood 逆向遍历的迭代器
    }
};

