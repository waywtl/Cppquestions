#define _CRT_SECURE_NO_WARNINGS 1


//表达式求值
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        for (const auto& str : tokens)
        {
            if (str == "+" || str == "-" || str == "*" || str == "/")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                switch (str[0])
                {
                case '+':
                {
                    st.push(left + right);
                    break;
                }
                case '-':
                {
                    st.push(left - right);
                    break;
                }
                case '*':
                {
                    st.push(left * right);
                    break;
                }
                case '/':
                {
                    st.push(left / right);
                    break;
                }
                default:
                    break;
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};