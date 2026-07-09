#include<iostream>
using namespace std;
#include<stack>

// valid parenthesis TC-O(n) SC- O(n)

bool isValidParenthesis(string s)
{
    stack <char> stk;
    for(int i = 0; i< s.length();i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            stk.push(ch);
        }
        else
        {
            // closing bracket
                if(!stk.empty())
                { char top = stk.top();
                        if( (ch == ')' && top == '(') || (ch == '}' && top == '{')    || (ch == ']' && top == '[')  )  
                        {
                             stk.pop();
                        } 
                        else 
                        {
                            return false;
                        }
         
                }
                else // stk empty and got closing bracket 
                       return false;

        }

    }
    if(stk.empty())
       return true;
    else 
       return false;   
}

int main()
{
    return 0;
}