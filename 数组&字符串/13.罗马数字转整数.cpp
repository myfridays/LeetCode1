/**法一
*用一个哈希表去存所有罗马数字和整数的对应，然后将s从左向右遍历，如果是特殊字符则判断
*时间复杂度：O(N), 空间复杂度O(N)
*/
class Solution {
    std::unordered_map<string, int> roman = {{"M", 1000}, {"CM", 900}, {"D", 500},
                                             {"CD", 400}, {"C", 100}, {"XC", 90},
                                             {"L", 50}, {"XL", 40}, {"X", 10},
                                             {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
public:
    int romanToInt(string s) {
        string str = "";
        int Int = 0; // 整数
        int n = s.size();
        for(int i = 0; i < n; i++){
            str = s[i];
            if(i != n-1 && (s[i] == 'I' || s[i] == 'X' || s[i] == 'C')){
                if(roman.find(str+s[i+1]) != roman.end()){
                    Int += roman[str+s[i+1]];
                    i++;
                    continue;
                }
            }
            Int += roman[str];
        }
        return Int;
    }
};