#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        //use stack:if it's num, then push, else pop the top two ops and cal.
        //we also push the intermediate result, so an 'int' stack is needed.
        stack<int> my_stack;
        vector<string>::iterator s;

        for(s = tokens.begin(); s != tokens.end(); s++) 
        {
            if(*s == "+")
            {
                int op1 = my_stack.top();
                my_stack.pop();
                int op2 = my_stack.top();
                my_stack.pop();
                //cal result
                int result = op2 + op1;
                //push
                my_stack.push(result); 
            }
            else if(*s == "-")
            {
                int op1 = my_stack.top();
                my_stack.pop();
                int op2 = my_stack.top();
                my_stack.pop();
                //cal result
                int result = op2 - op1;
                //push
                my_stack.push(result); 
            }
            else if(*s == "*")
            {
                int op1 = my_stack.top();
                my_stack.pop();
                int op2 = my_stack.top();
                my_stack.pop();
                //cal result
                int result = op2 * op1;
                //push
                my_stack.push(result); 
            }
            else if(*s == "/")
            {
                int op1 = my_stack.top();
                my_stack.pop();
                int op2 = my_stack.top();
                my_stack.pop();
                //cal result
                int result = op2 / op1;
                //push
                my_stack.push(result); 
            }
            else
            {
                //string --> int
                int op = str_int(*s);
                //push
                my_stack.push(op);
            }
        }
        return my_stack.top();
    }

    //ATTENTION: in case s is "-1", "-2", ...
    int str_int(string s) {
        int result = 0;
        int length = s.length();
        if(s[0] != '-')
        {
            for(int i = 0; i < length; i ++)
            {
                result *= 10;
                result += (s[i] - '0');
            }
        }
        else
        {
            for(int i = 1; i < length; i ++)
            {
                result *= 10;
                result -= (s[i] - '0');
            }
        }
        return result;
    }
};


int main()
{
    vector<string> strs;
	string str[105] = {"-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-","16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+","120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70","-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31","156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93","*","196","-","-59","+","187","-","143","/","-79","-89","+","-"};
    for(int i = 0; i < 105; i ++)
        strs.push_back(str[i]);
	Solution s;
	int result = s.evalRPN(strs);
	cout << result << endl;

	return 0;
}
