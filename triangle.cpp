#include <iostream>
#include <vector>
using namespace std;

/*
cal from bottom to top
*/
class Solution
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        int row = triangle.size();
        if(row == 0)
        {
            return 0;
        }
        if(row == 1)
        {
            return triangle[0][0];
        }
        //init vector sum with the bottom row
        vector<int> sum;
        for(int i = 0; i < row; i++)
        {
            sum.push_back(triangle[row - 1][i]);
        }
        for(int i = row - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                if(sum[j] < sum[j + 1])
                {
                    sum[j] += triangle[i][j];
                }
                else
                {
                    sum[j] = sum[j + 1] + triangle[i][j];
                }
            }
        }
        return sum[0];
    }
};

int main()
{
    Solution s;
    vector<int> v1;
    vector<vector<int> > v2;

    v1.push_back(2);
    v2.push_back(v1);
    
    v1.clear();
    v1.push_back(3);
    v1.push_back(4);
    v2.push_back(v1);

    v1.clear();
    v1.push_back(6);
    v1.push_back(5);
    v1.push_back(7);
    v2.push_back(v1);

    v1.clear();
    v1.push_back(4);
    v1.push_back(1);
    v1.push_back(8);
    v1.push_back(3);
    v2.push_back(v1);

    cout << s.minimumTotal(v2) << endl;
    return 0;
}
