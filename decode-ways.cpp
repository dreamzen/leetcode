#include <iostream>
using namespace std;

class Solution
{
public:
    bool noway;
    int *value;
    int numDecodings(string s)
    {
        noway = false;
        int rhs = s.length();
        value = new int[rhs];
        //init value[]
        for(int i = 0; i < rhs; i++)
        {
            value[i] = -1;
        }
        int result = decoding(s, 0, rhs - 1);
        if(noway)
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

    int decoding(string s, int lhs, int rhs)
    {
        if(lhs == rhs)
        {
            if(s[lhs] >= '1' && s[lhs] <= '9')
            {
                return 1;
            }
            else
            {
                noway = true;
                return 0;
            }
        }
        else
        {
            if(s[lhs] == '1')
            {
                if(lhs + 2 <= rhs)//120, 103, 123
                {
                    if(s[lhs + 1] == '0')//10x, next turn, 'x' will be detected
                    {
                        if(value[lhs + 2] == -1)
                        {
                            value[lhs + 2] = decoding(s, lhs + 2, rhs);
                        }
                        return value[lhs + 2];
                    }
                    else if(s[lhs + 2] == '0')//1x0
                    {
                        if(value[lhs + 1] == -1)
                        {
                            value[lhs + 1] = decoding(s, lhs + 1, rhs);
                        }
                        return value[lhs + 1];
                    }
                    else
                    {
                        if(s[lhs + 1] >= '1' && s[lhs + 1] <= '9')//123, 193
                        {
                            if(value[lhs + 1] == -1)
                            {
                                value[lhs + 1] = decoding(s, lhs + 1, rhs);
                            }
                            if(value[lhs + 2] == -1)
                            {
                                value[lhs + 2] = decoding(s, lhs + 2, rhs);
                            }
                            return value[lhs + 1] + value[lhs + 2];
                        }
                        else//1a3
                        {
                            noway = true;
                            return 0;
                        }
                    }
                }
                else//12, 10,
                {
                    if(s[lhs + 1] == '0')//10
                    {
                        return 1;
                    }
                    else if(s[lhs + 1] >= '1' && s[lhs + 1] <= '9')//12
                    {
                        return 2;
                    }
                    else//1a
                    {
                        noway = true;
                        return 0;
                    }
                }
            }
            else if(s[lhs] == '2')
            {
                if(lhs + 2 <= rhs)//220, 203, 223
                {
                    if(s[lhs + 1] == '0')//20x, next turn, 'x' will be detected
                    {
                        if(value[lhs + 2] == -1)
                        {
                            value[lhs + 2] = decoding(s, lhs + 2, rhs);
                        }
                        return value[lhs + 2];
                    }
                    else if(s[lhs + 2] == '0')//2x0
                    {
                        if(value[lhs + 1] == -1)
                        {
                            value[lhs + 1] = decoding(s, lhs + 1, rhs);
                        }
                        return value[lhs + 1];
                    }
                    else
                    {
                        if(s[lhs + 1] >= '1' && s[lhs + 1] <= '6')//223, 213, 264
                        {
                            if(value[lhs + 1] == -1)
                            {
                                value[lhs + 1] = decoding(s, lhs + 1, rhs);
                            }
                            if(value[lhs + 2] == -1)
                            {
                                value[lhs + 2] = decoding(s, lhs + 2, rhs);
                            }
                            return value[lhs + 1] + value[lhs + 2];
                        }
                        else if(s[lhs + 1] >= '7' && s[lhs + 1] <= '9')//283
                        {
                            if(value[lhs + 2] == -1)
                            {
                                value[lhs + 2] = decoding(s, lhs + 2, rhs);
                            }
                            return value[lhs + 2];
                        }
                        else//2a3
                        {
                            noway = true;
                            return 0;
                        }
                    }
                }
                else//22, 20,
                {
                    if(s[lhs + 1] == '0')//20
                    {
                        return 1;
                    }
                    else if(s[lhs + 1] >= '1' && s[lhs + 1] <= '6')//24
                    {
                        return 2;
                    }
                    else if(s[lhs + 1] >= '7' && s[lhs + 1] <= '9')//27 28 29
                    {
                        return 1;
                    }
                    else//2m
                    {
                        noway = true;
                        return 0;
                    }
                }
            }
            else if(s[lhs] >= '3' && s[lhs] <= '9')//333991
            {
                if(value[lhs + 1] == -1)
                {
                    value[lhs + 1] = decoding(s, lhs + 1, rhs);
                }
                return value[lhs + 1];
            }
            else
            {
                noway = true;
                return 0;
            }
        }
    }
};

int main()
{
    string str;
    Solution s;
    while(cin >> str)
    {
        if(str[0] == 'e')
            break;
        cout << s.numDecodings(str) << endl;
    }
    return 0;
}
