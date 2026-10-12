#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(const string &s)
{
    stack<int> st;
    st.push(-1);

    int best = 0;
    string maxValid = "";

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();

                if (len > best)
                {
                    best = len;
                    maxValid = s.substr(st.top() + 1, len);
                }
            }
        }
    }

    cout << "Max Valid Parentheses: " << maxValid << endl;

    return best;
}

int main()
{
    string s = "()(()()";

    int length = longestValidParentheses(s);

    cout << "Longest Valid Parentheses Length: "
         << length << endl;

    return 0;
}
