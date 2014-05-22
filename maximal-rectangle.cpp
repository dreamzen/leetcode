#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char> > &matrix)
    {
        if(matrix.empty())
        {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> height(col, 0);
        
        int maxRec = 0;
        for(int i = 0; i < row; i++)
        {
            //update height[]
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == '1')
                {
                    height[j] += 1;
                }
                else    
                {
                    height[j] = 0;
                }
            }
            //refer to largest rectangle in histogram, O(n)
            int area = maxRectangleArea(height);
            maxRec = (area > maxRec) ? area : maxRec;
        }
        return maxRec;
    }
    
    int maxRectangleArea(vector<int> &height )
    {
        height.push_back(0);
        int len = height.size();
        stack<int> s;
        int i = 0;
        int maxArea = 0;
        while(i < len)
        {
            if(s.empty() || height[i] > height[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int h = height[s.top()];
                s.pop();
                int left = s.empty() ? -1 : s.top();
                int wide = i - left - 1;
                int area = h * wide;
                maxArea = (area > maxArea) ? area : maxArea;
            }
        }
        return maxArea;
    }
};

int main()
{
	return 0;
}
