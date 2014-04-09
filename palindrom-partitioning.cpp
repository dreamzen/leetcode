#include <iostream>
#include <vector>
using namespace std;

/**
 * DP is OK.
 * NOTE:When cal a&&b, if a is FALSE, then it will not cal b.
 */
class Solution
{
private:
    vector<vector<int> > A;
    vector<vector<string> > result;
    vector<string> one_result;
public:
    vector<vector<string> > partition(string s)
    {
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            vector<int> tmp(len, -1);
            A.push_back(tmp);
        }
        //after two pass, every A[i][j] is avalible
        for(int i = 0; i < len; i++)
        {
            A[0][i] = isPalindrom(s, 0, i);
            A[i][len - 1] = isPalindrom(s, i, len - 1);
        }
        
        getResult(s, 0);
        return result;
    }
    
    bool isPalindrom(string s, int lhs, int rhs)
    {
        if(A[lhs][rhs] != -1)
        {
            return A[lhs][rhs];
        }
        else if(lhs == rhs)
        {
            A[lhs][rhs] = 1;
        }
        else if(lhs + 1 == rhs)
        {
            A[lhs][rhs] = (s[lhs] == s[rhs]);
        }
        else
        {
            A[lhs + 1][rhs - 1] = isPalindrom(s, lhs + 1, rhs - 1);
            A[lhs][rhs] = ((s[lhs] == s[rhs]) && A[lhs + 1][rhs - 1]);
        }
        return A[lhs][rhs];
    }
    
    void getResult(string s, int index)
    {
        int len = s.length();
        for(int i = index; i < len; i++)
        {
            if(A[index][i] == 1)
            {
                one_result.push_back(s.substr(index, i - index + 1));
                if(i == len - 1)
                {
                    result.push_back(one_result);
                }
                else
                {
                    getResult(s, i + 1);
                }
                one_result.pop_back();
            }
        }
    }
};

int main()
{
    string s = "aabb";
    Solution s1;
    s1.partition(s);
    return true;
}
