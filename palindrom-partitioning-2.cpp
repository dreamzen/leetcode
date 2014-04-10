#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<bool> > A;//A[i][j] = 1 means s[i],...,s[j] is palindrom
    vector<int> B;//B[i] means the min cuts of s[0],...,s[i]
public:
    int minCut(string s)
    {
        int len = s.length();
        B.resize(len);
        for(int i = 0; i < len; i++)
        {
            vector<bool> tmp(len);
            A.push_back(tmp);
        }
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j + i < len; j++)
            {
                A[j][j + i] = isPalindrom(s, j, j + i);
            }
        }
        B[0] = 0;
        for(int i = 1; i < len; i++)
        {
            int min = i;//every single char
            for(int j = 0; j <= i; j++)
            {
                if(A[j][i] == 1)
                {
                    if(j == 0)
                    {
                        min = 0;
                        break;
                    }
                    else
                    {
                        int tmp = B[j - 1] + 1;
                        if(tmp < min)
                        {
                            min = tmp;
                        }
                    }
                }
            }
            B[i] = min;
        }
        return B[len - 1];
    }
    
    bool isPalindrom(string s, int lhs, int rhs)
    {
        if(lhs == rhs)
        {
            return true;
        }
        else if(lhs + 1 == rhs)
        {
            return (s[lhs] == s[rhs]);
        }
        else
        {   //NOTE: CAN NOT swap the order!!
            //A[lhs + 1][rhs - 1] is O(1), but (s[lhs]==s[rhs]) is not!
            return (A[lhs + 1][rhs - 1] && s[lhs] == s[rhs]);
        }
    }
};
int main()
{
//    string s = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    Solution s1;
    cout << s.length() << " " << s1.minCut(s) << endl;
    return 0;
}
