/*法一
* 得出每一行得字符串
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2){
            return s;
        }
        string str = "";
        int i = 0, flag = -1;
        vector<string> rows(numRows);
        for(char c : s){
            rows[i].push_back(c);
            if(i == 0 || i == numRows-1){
                flag = -flag;
            }
            i += flag;
        }
        for(const string & row : rows){
            str += row;
        }
        return str;
    }
};