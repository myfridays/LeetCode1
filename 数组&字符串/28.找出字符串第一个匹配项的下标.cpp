class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

// 会报错，改改
class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.length();
        int l2 = needle.length();
        int j = 0;
        int startIndex = 0;
        for(int i = 0; i < l1; i++) {
            if (haystack[i] != needle[i]) {
                j = 0;
                i = startIndex++;
            } else {
                if (j == l2 - 1) {
                    return i - j;
                } else {
                    if (j == 0) {
                        startIndex = i;
                    }
                    j++;
                }
            }
        }
        return -1;
    }
};