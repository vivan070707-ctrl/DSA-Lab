#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";
    string num = "";

    for (char c : infix)
    {
        if (isspace(static_cast<unsigned char>(c)))
            continue;

        if (isdigit(static_cast<unsigned char>(c)))
        {
            num += c;
        }
        else
        {
            if (!num.empty())
            {
                postfix += num + " ";
                num = "";
            }

            if (c == '(')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                while (!s.empty() && s.top() != '(')
                {
                    postfix += s.top();
                    postfix += " ";
                    s.pop();
                }

                if (!s.empty())
                    s.pop();
            }
            else
            {
                while (!s.empty() && s.top() != '(' &&
                       (precedence(s.top()) > precedence(c) ||
                       (precedence(s.top()) == precedence(c) && c != '^')))
                {
                    postfix += s.top();
                    postfix += " ";
                    s.pop();
                }

                s.push(c);
            }
        }
    }

    if (!num.empty())
        postfix += num + " ";

    while (!s.empty())
    {
        if (s.top() != '(')
        {
            postfix += s.top();
            postfix += " ";
        }

        s.pop();
    }

    if (!postfix.empty() && postfix.back() == ' ')
        postfix.pop_back();

    return postfix;
}

int main()
{
    string infix = "1*(2+3/4)-5";

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;

    return 0;
}
