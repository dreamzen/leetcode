#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int result;
    vector<bool> A;
    vector<bool> B;//x+y = 0,1,2,...,2n-1
    vector<bool> C;//y-x+(n-1) = 0,1,2,...,2n-1
public:
    int totalNQueens(int n)
    {
        result = 0;
        for(int i = 0; i < n; i++)
        {
            A.push_back(0);
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
                A[i] = 1;
                B[k + i] = 1;
                C[i - k + n - 1] = 1;
                if(k == n - 1)
                {
                    //get the solution
                    result++;
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
        cout << s.totalNQueens(n) << endl;
    }
    return 0;
}
