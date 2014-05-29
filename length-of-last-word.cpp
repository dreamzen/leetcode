#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(const char *s)
    {
        if(s == NULL)
        {
            return 0;
        }
        int len = strlen(s);
        int pos_word = -1;
        int pos_space = -1;
        for(int i = len - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                pos_word = i;
                break;
            }
        }
        
        for(int i = pos_word - 1; i >= 0; i--)
        {
            if(s[i] == ' ')
            {
                pos_space = i;
                break;
            }
        }
        
        return pos_word - pos_space;
    }
};

int main()
{
	const char *p = "hello world";
	Solution s;
	cout << s.lengthOfLastWord(p) << endl;
	return 0;
}
