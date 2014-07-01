#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> next;
public:
    char *strStr(char *haystack, char *needle)
    {
        if(haystack == NULL || needle == NULL)
        {
            return NULL;
        }
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        if(len2 == 0)
        {
            return haystack;
        }
        if(len1 < len2)
        {
            return NULL;
        }
        next.resize(len2);
        getNext(needle);
        int j = 0;
        int k = -1;
        while(j < len1)
        {
            if(haystack[j] == needle[k + 1])
            {
                j++;
                k++;
                if(k == len2 - 1)
                {
                    return haystack + j - (k + 1);
                }
            }
            else
            {
                if(k == -1)
                {
                    j++;
                }
                else
                {
                    k = next[k];
                }
            }
        }
        return NULL;
    }
    
    void getNext(char *s)
    {
        int len = strlen(s);
        next[0] = -1;
        int j = 1;
        int k = -1;
        while(j < len)
        {
            if(s[j] == s[k + 1])
            {
                next[j] = k + 1;
                j++;
                k++;
            }
            else
            {
                if(k == -1)
                {
                    next[j] = -1;
                    j++;
                }
                else
                {
                    k = next[k];
                }
            }
        }
    }
};

int main()
{
	return 0;
}
