class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        int sum = 0;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    st.push(x+y);
                }
                if(tokens[i] == "-"){
                    st.push(x-y);
                }
                if(tokens[i] == "*"){
                    st.push(x*y);
                }
                if(tokens[i] == "/"){
                    st.push(x/y);
                }

            }else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};