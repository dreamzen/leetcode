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
        if(*p == '\0')
        {
            return (*s == '\0');
        }
        if(*s == '\0')
        {
            while(*p == '*')
            {
                p++;
            }
            return (*p == '\0');
        }
        
        if(*s == *p || *p == '?')
        {
            return isMatch(s + 1, p + 1);
        }
        else if(*p == '*')
        {
            //skip continuous '*'
            while(*p == '*')
            {
                p++;
            }
            const char *pStart = p;
            //find next '*'
            while(*p != '*' && *p != '\0')
            {
                p++;
            }
            const char *pEnd = p;
            //no next '*'
            if(*pEnd == '\0')
            {
                if(strlen(s) >= (pEnd - pStart))
                {
                    return isMatch(s + strlen(s) - (pEnd - pStart), pStart);
                }
                else
                {
                    return false;
                }
            }
            else//have next '*', then match p[pstart, pEnd) with s
            {
                const char *sStart;
                for(sStart = s; strlen(sStart) >= pEnd - pStart; sStart++)
                {
                    bool found = true;
                    for(int i = 0; i < pEnd - pStart; i++)
                    {
                        if(*(sStart + i) != *(pStart + i) && *(pStart + i) != '?')
                        {
                            found = false;
                            break;
                        }
                    }
                    if(found)
                    {
                        return isMatch(sStart + (pEnd - pStart), pEnd);
                    }
                }
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

int main()
{
	return 0;
}
