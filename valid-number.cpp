#include <iostream>
using namespace std;

class Solution
{
public:
    bool isNumber(const char *s)
    {
        //erase white spaces
        int start = 0;
        int end = strlen(s) - 1;
        char newS[strlen(s) + 1];
        while(start < end && s[start] == ' ')
        {
            start++;
        }
        while(start < end && s[end] == ' ')
        {
            end--;
        }
        if(start == end && s[start] == ' ')
        {
            return false;
        }
        else
        {
            strncpy(newS, s + start, end -start + 1);
            newS[end - start + 1] = '\0';
        }
        //have white space
        for(int i = 0; i < strlen(newS); i++)
        {
            if(newS[i] == ' ')
            {
                return false;
            }
        }
        //2e3
        if(isScientific(newS))
        {
            return true;
        }
        // 1/2
        if(isPartial(newS))
        {
            return true;
        }
        //0.2, 200
        bool outOfRange;
        if(isFloat(newS, outOfRange))
        {
            return true;
        }
        return false;
    }
    
    bool isPartial(const char *s)
    {
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == '/')
            {
                char left[strlen(s) + 1];
                strncpy(left, s, i);
                left[i] = '\0';
                char right[strlen(s) + 1];
                strncpy(right, s + i + 1, strlen(s) - i - 1);
                right[strlen(s) - i - 1] = '\0';
                // x/0
                if(strlen(right) == 1 && right[0] == '0')
                {
                    return false;
                }
                if(isNormalInteger(left) && isNormalInteger(right))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }
    
    bool isScientific(const char *s)
    {
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] == 'e' || s[i] == 'E')
            {
                char left[strlen(s) + 1];
                strncpy(left, s, i);
                left[i] = '\0';
                char right[strlen(s) + 1];
                if(s[i + 1] == '+' || s[i + 1] == '-')
                {
                    strncpy(right, s + i + 2, strlen(s) - i - 2);
                    right[strlen(s) - i - 2] = '\0';
                }
                else
                {
                    strncpy(right, s + i + 1, strlen(s) - i - 1);
                    right[strlen(s) - i - 1] = '\0';
                }
                bool outOfRange;
                //FIXME: +5e, 5e, +e9, e9 is false, outOfRange is OK....
                if(strlen(left) == 0 || strlen(right) == 0)
                {
                    return false;
                }
                if(strlen(left) == 1 && (left[0] == '+' || left[0] == '-'))
                {
                    return false;
                }
                if(isNormalInteger(right) && isFloat(left, outOfRange))// && !outOfRange)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }
    //2.33, 2.0, 4, ...
    bool isFloat(const char *s, bool &outOfRange)
    {
        int i;
        for(i = 0; i < strlen(s); i++)
        {
            if(s[i] == '.')
            {
                break;
            }
        }
        //no '.'
        if(i == strlen(s))
        {
            if(strlen(s) == 1 && s[0] >= '1' && s[0] <= '9')
            {
                outOfRange = false;
            }
            else
            {
                outOfRange = true;
            }
            return isNormalInteger(s);
        }
        else//have '.'
        {
            char left[strlen(s) + 1];
            strncpy(left, s, i);
            left[i] = '\0';
            char right[strlen(s) + 1];
            strncpy(right, s + i + 1, strlen(s) - i - 1);
            right[strlen(s) - i - 1] = '\0';
            if(strlen(left) == 1 && s[0] >= '1' && s[0] <= '9')
            {
                outOfRange = false;
            }
            else
            {
                outOfRange = true;
            }
            //3. is true  +. is false
            if(left[0] == '\0' && right[0] == '\0')
            {
                return false;// "."
            }
            if(strlen(left) == 1 && strlen(right) == 0)
            {
                if(left[0] == '+' || left[0] == '-')
                {
                    return false;
                }
            }
            return (isNormalInteger(left) && isSpecialInteger(right));
        }
    }
    //1230
    bool isNormalInteger(const char *s)
    {
        if(s == NULL || *s == '\0')
        {
            return true;//FIXME: .1 is true..
        }
        if(s[0] != '+' && s[0] != '-' && (s[0] < '0' || s[0] > '9'))
        {
            return false; //FIXME: 01 is true...
        }
        for(int i = 1; i < strlen(s); i++)
        {
            if(s[i] < '0' || s[i] > '9')
            {
                return false;
            }
        }
        return true;
    }
    
    //00001 ==> 2.00001
    bool isSpecialInteger(const char *s)
    {
        //0 is OK. eg: 2.0
        if(s == NULL || *s == '\0')
        {
            return true;//FIXME: 3. is true...
        }
        if(strlen(s) == 1 && s[0] == '0')
        {
            return true;
        }
        //all 0 
        bool allZero = true;
        for(int i = 0; i < strlen(s); i++)
        {
            if(s[i] != '0')
            {
                allZero = false;
            }
            if(s[i] < '0' || s[i] > '9')
            {
                return false;
            }
        }
        if(allZero)
        {
            return true;//FIXME: all 0 is true...
        }
        return true;
    }
};

int main()
{
	char str[1024];
	cin >> str;
	Solution s;
	cout << s.isNumber(str) << endl;
	return 0;
}
