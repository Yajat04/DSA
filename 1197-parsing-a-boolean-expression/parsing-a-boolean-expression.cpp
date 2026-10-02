class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack <char> st;

        int n = expression.size();
        for(int i = 0; i < n; i++){
            if(expression[i] == ',') continue;
            else if(expression[i] == ')'){
                bool hasTrue = false;
                bool hasFalse = false;
                while(st.top() != '('){
                    char operand = st.top();
                    if(operand == 't') hasTrue = true;
                    else hasFalse = true;
                    st.pop();
                }
                st.pop();
                
                char optr = st.top();
                bool result;
                if(optr == '&'){
                    if(hasFalse) result = false;
                    else result = true; 
                }

                else if(optr == '|'){
                    if(hasTrue) result = true;
                    else result = false; 
                }

                else{ //!
                    if(hasTrue) result = false;
                    else result = true;
                }

                st.pop();

                if(result) st.push('t');
                else st.push('f');
            }

            else st.push(expression[i]);
        }

        if(st.top() == 't') return true;
        return false;
    }
};