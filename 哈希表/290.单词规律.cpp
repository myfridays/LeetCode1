class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> p2ss;
        unordered_map<string, char> ss2p;

        vector<string> ss;
        string str = "";
        for(int i = 0; i < s.size(); i++){  // 将字符串进行存储
            if(s[i] == ' '){
                ss.emplace_back(str);
                str = "";
                continue;
            }
            str += s[i];
            if(i == s.size()-1){
                ss.emplace_back(str);
            }
        }
        // 两个字符长度不一样，直接退出
        if(pattern.size() != ss.size()){
            return false;
        }
        // 两两映射
        for(int i = 0; i < pattern.size(); i++){
            char ch = pattern[i];
            string st = ss[i];
            if((p2ss.count(ch) && p2ss[ch] != st) || (ss2p.count(st) && ss2p[st] != ch)){
                return false;
            }else{
                p2ss[ch] = st;
                ss2p[st] = ch;
            }
        } 
        return true;
    }
};