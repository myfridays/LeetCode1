class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        bool tag1 = true;
        bool tag2 = true;
        // s2t
        s2t[s[0]] = t[0];
        for(int i = 1; i < s.size(); i++){
            if(s2t.find(s[i]) != s2t.end()){
                if(t[i] != s2t[s[i]]){
                    tag1 = false;
                    break;
                }
            }else{
                s2t[s[i]] = t[i];
            }
        }

        // t2s
        t2s[t[0]] = s[0];
        for(int i = 1; i < s.size(); i++){
            if(t2s.find(t[i]) != t2s.end()){
                if(s[i] != t2s[t[i]]){
                    tag2 = false;
                    break;
                }
            }else{
                t2s[t[i]] = s[i];
            }
        }
        
        return tag1 && tag2;
    }
};