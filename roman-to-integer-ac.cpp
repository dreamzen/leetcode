#include <iostream>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int len = s.length();
        int i = 0;
        int result = 0;
        int op1, op2;
        while(i < len)
        {
            if( i == len - 1) //the last Roman
            {
                op1 = toBasicInt(s[i]);
                result += op1;
                i = i + 1;
            }
            else
            {
                op1 = toBasicInt(s[i]);
                op2 = toBasicInt(s[i + 1]);
                //if left > right, then plus left. because if [left, right] forms an int, its value is left+right, so we just plus left and i-->i+1 will always be right. in case [MCM] --> 1000 + (1000 - 100) = 1900 NOT (1000 + 100) + 1000.
                if(op1 >= op2) 
                {
                    result += op1;
                    i = i + 1;//only plus left, so i-->i+1
                }
                else //if left < right, then[left, right] form an int --> right - left
                {
                    result += (op2 - op1);
                    i = i + 2;
                }
            }
        }
        return result;
    }

    int toBasicInt(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                break;
        }
    }
};

int main()
{
    while(true)
    {
        string str;
        cin >> str;
        if(str == "e")
        {
            break;
        }
        Solution s;
        cout << s.romanToInt(str) << endl;
    }
    return 0;
}
