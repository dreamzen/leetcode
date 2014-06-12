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
        if(*s == '\0' || *p == '\0')
        {
            while(*p == '*')
            {
                p++;
            }
            return (*s == *p);
        }
        if(*s == *p || *p == '?')
        {
            return isMatch(s + 1, p + 1);
        }
        else
        {
            if(*p == '*')
            {
                while(*p == '*')
                {
                    p++;
                }
                if(*p == '\0')
                {
                    return true;
                }
                else
                {
                    while(*s != '\0')
                    {
                        const char *ptr_s = s;
                        const char *ptr_p = p;
                        while(*ptr_s != '\0' && (*ptr_s == *ptr_p || *ptr_p == '?'))
                        {
                            ptr_s++;
                            ptr_p++;
                        }
                        if(*ptr_p == '\0')
                        {
                            if(*ptr_s == '\0')//"aaaab" and "*ab"
                            {
                                return true;
                            }
                            else//"aaaabaaaab" and "*ab"
                            {
                                s++;
                            }
                        }
                        else if(*ptr_p == '*')//"aaaabaaaab" and "*ab*"
                        {
                            return isMatch(ptr_s, ptr_p);
                        }
                        else
                        {
                            if(*ptr_s == '\0')//p is longer than s, eg: "aa" and "aa?"
                            {
                                return false;
                            }
                            s++;
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
        
    }
};

int main()
{
	char s[1024];
	char p[1024];
	Solution solu;
	cin >> s >> p;
	cout << solu.isMatch(s, p) << endl;
	return 0;
}
