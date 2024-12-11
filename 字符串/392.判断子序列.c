/*
* 双指针，一个指针指向s，一个指向t，当s结束则说明存在，则结束
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0, tp = 0;
        int sn = s.size(), tn = t.size();
        while(sp < sn && tp < tn){
            if(s[sp] == t[tp]){
                sp++;
            }
            tp++;
        }
        if(sp == sn){
            return true;
        }
        return false;
    }
};