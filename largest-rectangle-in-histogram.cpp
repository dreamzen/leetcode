#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
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
	vector<int> h;
 	h.push_back(4);
 	h.push_back(2);
	Solution s;
	cout << s.largestRectangleArea(h) << endl;
	return 0;
}
