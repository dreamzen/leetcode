#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * DP can not reduce the complexity for the worst case.
 * For the test case, we traversal from tail to head is OK.
 * But, if s = "baaa....", it will run forever!
 */
class Solution
{
private:
    vector<vector<bool> > A;
    vector<string> result;
    string one_result;
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            vector<bool> tmp(len);
            for(int j = i; j < len; j++)
            {
                tmp[j] = inDict(s.substr(i, j - i + 1), dict);
            }
            A.push_back(tmp);
        }

        getResult(s, len - 1);
        return result;
    }

    bool inDict(string s, unordered_set<string> &dict)
    {
        unordered_set<string>::iterator ite;
        ite = dict.find(s);
        if(ite == dict.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    //from tail to head
    void getResult(string s, int index)
    {
        for(int i = 0; i <= index; i++)
        {
            if(A[i][index])
            {
                one_result = s.substr(i, index - i + 1) + one_result;
                if(i == 0)
                {
                    result.push_back(one_result);
                }
                else
                {
                    one_result = " " + one_result;
                    getResult(s, i - 1);
                    one_result = one_result.substr(1, one_result.length() - 1);//erase " "
                }
                one_result = one_result.substr(index - i + 1, one_result.length() - (index - i + 1));//erase the firt word
            }
        }
    }
};

int main()
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    unordered_set<string> dict;
    dict.insert("aaaaaaaaaa");
    dict.insert("aaaaaaaaa");
    dict.insert("aaaaaaaa");
    dict.insert("aaaaaaa");
    dict.insert("aaaaaa");
    dict.insert("aaaaa");
    dict.insert("aaaa");
    dict.insert("aaa");
    dict.insert("aa");
    dict.insert("a");
    Solution s1;
    s1.wordBreak(s, dict);
    return 0;
}
