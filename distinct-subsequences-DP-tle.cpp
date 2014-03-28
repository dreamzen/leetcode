#include <iostream>
#include <vector>
using namespace std;

/**
 * DP:From top to bottom
 * Time Limit Exceeded
 */
class Solution
{
public:
    int s_len, t_len;
    vector<vector<int> > result;
    int numDistinct(string S, string T)
    {
        s_len = S.length();
        t_len = T.length();
        if(s_len < t_len)
        {
            return 0;
        }
        //init result[][] with -1, result[][] is larger than s x t
        for(int i = 0; i < s_len + 1; i++)
        {
            vector<int> tmp;
            for(int j = 0; j < t_len + 1; j++)
            {
                tmp.push_back(-1);
            }
            result.push_back(tmp);
        }
        //find all positions of T[0] in S
        vector<int> v;
        for(int i = 0; i < s_len; i++)
        {
            if(S[i] == T[0])
            {
                v.push_back(i);
            }
        }
        //no match
        if(v.empty())
        {
            return 0;
        }
        else//match sub-string
        {
            return findDistinct(S, T, 0, 0);
        }
    }

    //find distinct S[m, m+1, ...] T[n, n+1, ...] 
    int findDistinct(string S, string T, int m, int n)
    {
        if(result[m][n] != -1)
        {
            return result[m][n];
        }
        if(n >= t_len)//find till the end of T
        {
            result[m][n] = 1;
            return 1;
        }
        if(s_len - m < t_len - n)//S' is shorter than T'
        {
            result[m][n] = 0;
            return 0;
        }
        else//S' is longer than T', then find T'[0] in S' and recursivly call findDistinct()
        {
            vector<int> v;
            for(int i = m; i < s_len; i++)
            {
                if(S[i] == T[n])
                {
                    v.push_back(i);
                }
            }
            if(v.empty())
            {
                result[m][n] = 0;
                return 0;
            }
            else
            {
                int sum = 0;
                bool notFound = false;
                for(vector<int>::iterator ite = v.begin(); ite != v.end(); ite++)
                {
                    if(result[(*ite)][n] == 0)
                    {
                        notFound = true;
                    }
                    if(notFound)
                    {
                        result[(*ite)][n] = 0;
                    }
                    else
                    {
                        result[(*ite)][n]= findDistinct(S, T, (*ite) + 1, n + 1);
                        sum += result[(*ite)][n];
                    }
                }
                return sum;
            }
        }
    }
};


int main()
{
    while(1)
    {
        Solution s;
        string s1, s2;
        cin >> s1 >> s2;
        cout << s.numDistinct(s1, s2) << endl;
    }
    return 0;
}
