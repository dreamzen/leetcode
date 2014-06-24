#include <iostream>
using namespace std;

class Solution {
private:
    string result;
public:
    string getPermutation(int n, int k)
    {
        string str;
        for(int i = 1; i <= n; i++)
        {
            str += (i + '0');
        }
        getKthPermutation(str, k);
        return result;
    }
    void getKthPermutation(string str, int k)
    {
        if(k == 1)
        {
            result += str;
            return;
        }
        int len = str.length();
        int elementsPerPart = 1;
        for(int i = 1; i < len; i++)
        {
            elementsPerPart *= i;
        }
        int group = (k - 1) / elementsPerPart;
        //Add the element to result
        result += str[group];
        //Get new string, new k
        string newStr;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] != str[group])
            {
                newStr += str[i];
            }
        }
        int newK;
        newK = k - elementsPerPart * group;
        //Get next element
        getKthPermutation(newStr, newK);
    }
};

int main()
{
	return 0;
}
