#include <iostream>
#include <vector>
using namespace std;

/**
 * DP:From bottom to top
 * result[i][j] = result[i-1][j-1], S[i-1] != T[j-1]
 *              = result[i-1][j-1] + result[i-1][j], S[i-1] == T[j-1]
 * result[i][j] means: the num of distinct subsequences of T[0,1,...,j] in S[0,1,...,i]
 * 
 * If we could use iterative, DO NOT use recursive algorithm!
 */
class Solution
{
public:
    int numDistinct(string S, string T)
    {
        int s_len = S.length();
        int t_len = T.length();
        vector<vector<int> > result;
        
        if(s_len < t_len)
        {
            return 0;
        }
        //init result[][] with 0,result[][] is larger than S x T
        for(int i = 0; i < s_len + 1; i++)
        {
            vector<int> tmp;
            for(int j = 0; j < t_len + 1; j++)
            {
                tmp.push_back(0);
            }
            result.push_back(tmp);
        }
        //Regard the subsequences of "" in S is 1
        for(int i = 0; i <= s_len; i ++)
        {
            result[i][0] = 1;
        }
        for(int j = 1; j <= t_len; j++)
        {
            for(int i = j; i <= s_len; i++)
            {
                if(S[i - 1] != T[j - 1])
                {
                    result[i][j] = result[i - 1][j];
                }
                else
                {
                    result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
                }
            }
        }
        return result[s_len][t_len];
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
