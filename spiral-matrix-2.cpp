#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    enum direct{R = 0, D, L, U};
    int m;
    vector<vector<int> > result;
public:
    vector<vector<int> > generateMatrix(int n) 
    {
        m = n;
        for(int i = 0; i < n; i++)
        {
            vector<int> tmp(n, 0);
            result.push_back(tmp);
        }
        fillMatrix(0, 0, 1, R);
        return result;
    }
    void fillMatrix(int i, int j, int val, direct d)
    {
        if(val > m * m)
        {
            return;
        }
        result[i][j] = val;
        switch (d)
        {
            case R:
                if(j + 1 < m && result[i][j + 1] == 0)
                {
                    fillMatrix(i, j + 1, val + 1, R);
                }
                else
                {
                    fillMatrix(i + 1, j, val + 1, D);
                }
                break;
            case D:
                if(i + 1 < m && result[i + 1][j] == 0)
                {
                    fillMatrix(i + 1, j, val + 1, D);
                }
                else
                {
                    fillMatrix(i, j - 1, val + 1, L);
                }
                break;
            case L:
                if(j - 1 >= 0 && result[i][j - 1] == 0)
                {
                    fillMatrix(i, j - 1, val + 1, L);
                }
                else
                {
                    fillMatrix(i - 1, j, val + 1, U);
                }
                break;
            case U:
                if(i - 1 >= 0 && result[i - 1][j] == 0)
                {
                    fillMatrix(i - 1, j, val + 1, U);
                }
                else
                {
                    fillMatrix(i, j + 1, val + 1, R);
                }
                break;
            default:
                break;
        }
    }
};

int main()
{
	return 0;
}
