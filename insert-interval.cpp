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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        vector<Interval> result;
        if(intervals.empty())
        {
            result.push_back(newInterval);
            return result;
        }
        //before all
        if(newInterval.end < intervals[0].start)
        {
            result.push_back(newInterval);
            for(int i = 0; i < intervals.size(); i++)
            {
                result.push_back(intervals[i]);
            }
            return result;
        }
        //after all
        if(newInterval.start > intervals[intervals.size() - 1].end)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        //other
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i].end < newInterval.start)
            {
                result.push_back(intervals[i]);
            }
            else if(intervals[i].start > newInterval.end)
            {
                result.push_back(newInterval);
                for(int j = i; j < intervals.size(); j++)
                {
                    result.push_back(intervals[j]);
                }
                return result;
            }
            else
            {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
                if(i == intervals.size() - 1)//merge until the tail
                {
                    result.push_back(newInterval);
                }
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
