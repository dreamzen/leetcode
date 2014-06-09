#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        if(s == NULL || p == NULL)
        {
            return false;
        }
        int len1 = strlen(s);
        int len2 = strlen(p);
        if(len1 == 0 && len2 == 0)
        {
            return true;
        }
        return match(s, p, 0, 0, ' ');
    }
    
    bool match(const char *s, const char *p, int x, int y, char pre)
    {
        int len1 = strlen(s);
        int len2 = strlen(p);
        if(x == len1 || y == len2)
        {
            if(x == len1 && y == len2)
            {
                return true;
            }
            else if(x == len1)
            {
                if(p[y] == '*')//a, a*
                {
                    return match(s, p, x, y + 1, ' ');
                }
                else if(y + 1 < len2 && p[y + 1] == '*')//a, ab*
                {
                    return match(s, p, x, y + 2, ' ');
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        bool special = false;
        if(y + 1 < len2 && p[y + 1] == '*')
        {
            special = match(s, p, x, y + 2, ' ');
            if(special)
            {
                return true;
            }
        }
        
        if(s[x] == p[y])
        {
            return match(s, p, x + 1, y + 1, p[y]);
        }
        else
        {
            switch (p[y])
            {
                case '.':
                    return match(s, p, x + 1, y + 1, '.');
                    break;
                case '*':
                    switch (pre)
                    {
                        case '.':
                            return match(s, p, x + 1, y, '.') || match(s, p, x, y + 1, ' ');
                            break;
                        case ' ':
                            return match(s, p, x, y + 1, ' ');
                            break;
                        default:
                            return ((s[x] == pre) && match(s, p, x + 1, y, pre)) || match(s, p, x, y + 1, ' ');
                            break;
                    }
                    break;
                default:
                    return false;
                    break;
            }
        }
    }
};

int main()
{
	return 0;
}
