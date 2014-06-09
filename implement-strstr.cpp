#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> p;
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
        p.resize(len2);
        getNextVal(needle);
        int i = 0;
        int j = -1;
        while(i < len1 && j < len2)
        {
            if(haystack[i] == needle[j + 1])
            {
                i++;
                j++;
                if(j == len2 - 1)
                {
                    return &haystack[i - len2];
                }
            }
            else
            {
                if(j == -1)
                {
                    i++;
                }
                else
                {
                    j = p[j];
                }
            }
        }
        return NULL;
    }
    void getNextVal(char *str)
    {
        int len = strlen(str);
        int j = 1;
        int k = -1;
        p[0] = -1;
        while(j < len)
        {
            if(str[j] == str[k + 1])
            {
                p[j] = k + 1;
                j++;
                k++;
            }
            else
            {
                if(k == -1)
                {
                    p[j] = -1;
                    j++;
                }
                else
                {
                    k = p[k];
                }
            }
        }
    }
};

int main()
{
	return 0;
}
