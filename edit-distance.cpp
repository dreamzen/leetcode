#include <iostream>
#include <vector>
using namespace std;

/**
 * str1a str2b
 * f(i,j) = f(i-1, j-1)     word1[i] == word2[j]
 *        = min of  f(i-1, j-1) + 1     a-->b
 *                  f(i-1, j) + 1       delete a
 *                  f(i, j-1) + 1       insert 'b' after a
 **/
class Solution
{
private:
    vector<vector<int> > f;
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        for(int i = 0; i <= m; i++)
        {
            vector<int> tmp(n + 1);
            f.push_back(tmp);
        }
        for(int i = 0; i <= m; i++)
        {
            f[i][0] = i;
        }
        for(int j = 0; j <= n; j++)
        {
            f[0][j] = j;
        }
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    f[i][j] = f[i - 1][j - 1];
                }
                else
                {
                    int min = (f[i - 1][j - 1] < f[i - 1][j]) ? f[i - 1][j - 1] : f[i - 1][j];
                    min = (min < f[i][j - 1]) ? min : f[i][j - 1];
                    f[i][j] = min + 1;
                }
            }
        }
        return f[m][n];
    }
};

int main()
{
	return 0;
}
