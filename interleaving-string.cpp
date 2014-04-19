#include <iostream>
#include <vector>
using namespace std;
/**
 * DP
 * A[i][j] = 1, i=0 && j=0 (i,j is the length)
 *         = A[i-1][j] && (s1[i-1] == s3[i+j-1]) 
             || A[i][j-1] && (s2[j-1] == s3[i+j-1])
 */
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<vector<bool> > A;//A[i][j] means s1[0],...,s1[i-1](len=i) and s2[0],...,s2[j-1](len=j) ==> s3[0],...,s3[i+j-1]
        if(s3.length() != (s1.length() + s2.length()))
        {
            return false;
        }
        for(int i = 0; i < s1.length() + 1; i++)
        {
            vector<bool> tmp(s2.length() + 1);
            A.push_back(tmp);
        }
        A[0][0] = true;
        for(int i = 1; i <= s1.length(); i++)
        {
            A[i][0] = A[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for(int j = 1; j <= s2.length(); j++)
        {
            A[0][j] = A[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        
        for(int i = 1; i <= s1.length(); i++)
        {
            for(int j = 1; j <= s2.length(); j++)
            {
                A[i][j] = (A[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) || (A[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
            }
        }
        return A[s1.length()][s2.length()];
    }
};

int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	Solution s;
	cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}
