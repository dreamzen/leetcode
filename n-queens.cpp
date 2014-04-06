#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    string str;
    vector<vector<string> > result;
    vector<bool> A;
    vector<bool> B;//x+y = 0,1,2,...,2n-1
    vector<bool> C;//y-x+(n-1) = 0,1,2,...,2n-1
    vector<int> col;//the col of each row
public:
    vector<vector<string> > solveNQueens(int n)
    {
        for(int i = 0; i < n; i++)
        {
            str += ".";
            A.push_back(0);
            col.push_back(0);
        }
        for(int i = 0; i < 2 * n - 1; i++)
        {
            B.push_back(0);
            C.push_back(0);
        }
        queen(n, 0);
        return result;
    }
    
    //n x n, put row k (from 0 to n-1)
    void queen(int n, int k)
    {
        for(int i = 0; i < n; i++)
        {
            if(place(n, k, i))
            {
                col[k] = i;
                A[i] = 1;
                B[k + i] = 1;
                C[i - k + n - 1] = 1;
                if(k == n - 1)
                {
                    //get the solution
                    vector<string> solution;
                    for(int j = 0; j < n; j++)
                    {
                        string tmp(str);
                        tmp[col[j]] = 'Q';
                        solution.push_back(tmp);
                        cout << tmp << endl;
                    }
                    cout << endl;
                    result.push_back(solution);
                }
                else
                {
                    queen(n, k + 1);
                }
                erase(n, k, i);
            }
        }
    }
    
    bool place(int n, int x, int y)
    {
        if(A[y] == 0 && B[x + y] == 0 && C[y - x + n - 1] == 0)
        {
            return true;
        }
        return false;
    }
    
    void erase(int n, int x, int y)
    {
        A[y] = 0;
        B[x + y] = 0;
        C[y - x + n - 1] = 0;
    }
};

int main()
{
    int n;
    while(cin >> n)
    {
        Solution s;
        s.solveNQueens(n);
    }
    return 0;
}
