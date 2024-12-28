class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0, n = path.size(); 

        // 将所有文件或者目录入栈
        while(i < n){
            while(i < n && path[i] == '/'){i++;} //把斜杆清完
            string str = "";
            while(i < n && path[i] != '/'){
                str += path[i];
                i++;
            }
            if(str == "") continue;
            if(st.empty()){
                if(str != ".." && str != "."){
                    st.push(str);
                }
            }else{
                if(str == ".."){
                    st.pop();
                }else if(str == "."){
                    continue;
                }else{
                    st.push(str);
                }       
            }
        }
        stack<string> ts;
        while(!st.empty()){
            ts.push(st.top());
            st.pop();
        }
        string ans = "";
        while(!ts.empty()){
            ans = ans + "/" + ts.top();
            ts.pop();
        }

        return ans.size() ? ans : "/";
    }
};