#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int left, right, up, down;
    int total;
    enum direction{L, R, U, D};
    vector<int> result;
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        if(matrix.empty())
        {
            return result;
        }
        left = -1;
        up = -1;
        down = matrix.size();
        right = matrix[0].size();
        total = right * down;
        visitMatrix(0, 0, R, 0, matrix);
        return result;
    }
    void visitMatrix(int i, int j, direction d, int num, vector<vector<int> > &matrix)
    {
        if(num == total)
        {
            return;
        }
        result.push_back(matrix[i][j]);
        switch(d)
        {
            case R:
                if(j + 1 < right)
                {
                    visitMatrix(i, j + 1, R, num + 1, matrix);
                }
                else
                {
                    up = i;
                    visitMatrix(i + 1, j, D, num + 1, matrix);
                }
                break;
            case D:
                if(i + 1 < down)
                {
                    visitMatrix(i + 1, j, D, num + 1, matrix);
                }
                else
                {
                    right = j;
                    visitMatrix(i, j - 1, L, num + 1, matrix);
                }
                break;
            case L:
                if(j - 1 > left)
                {
                    visitMatrix(i, j - 1, L, num + 1, matrix);
                }
                else
                {
                    down = i;
                    visitMatrix(i - 1, j, U, num + 1, matrix);
                }
                break;
            case U:
                if(i - 1 > up)
                {
                    visitMatrix(i - 1, j, U, num + 1, matrix);
                }
                else
                {
                    left = j;
                    visitMatrix(i, j + 1, R, num + 1, matrix);
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
