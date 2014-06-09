#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> result;
        if(intervals.empty())
        {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        Interval curr = intervals[0];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i].start <= curr.end)
            {
                curr.end = max(intervals[i].end, curr.end);
            }
            else
            {
                result.push_back(curr);
                curr = intervals[i];
            }
        }
        result.push_back(curr);
        return result;
    }
    //must static, or compile error
    static bool cmp(const Interval &I1, const Interval &I2)
    {
        return I1.start < I2.start;
    }
};

int main()
{
	return 0;
}
