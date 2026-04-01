class Solution {
public:
    bool isValid(string s) {

       stack <char> my_stack;

       for (char ch : s)
       {
        if (ch == '(' || ch == '{' || ch =='[')
        {
            my_stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch ==']')
        {
            if (my_stack.empty())
            {
                return false;
            }
           switch (ch)
           {
            case ')':
                if (my_stack.top() == '(')
                {
                    my_stack.pop();
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if (my_stack.top() == '{')
                {
                    my_stack.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (my_stack.top() == '[')
                {
                    my_stack.pop();
                }
                else
                {
                    return false;
                }
                break;
           } 
        }
       }
       return my_stack.empty();;
    }
};
