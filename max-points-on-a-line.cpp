#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
public:
    int maxPoints(vector<Point> &points)
    {
        if(points.size() < 3)
        {
            return points.size();
        }
        sort(points.begin(), points.end(), cmp);
        int maxNum = 0;
        for(int i = 0; i < points.size(); i++)
        {
            int samePoints = 1;
            for(int j = i + 1; j < points.size(); j++)
            {
                int num = 0;
                int a = points[j].y - points[i].y;
                int b = points[j].x - points[i].x;
                if(a == 0 && b == 0)
                {
                    samePoints++;//but if all the points are same, we will use this.
                    continue;//skip same point, we will count them in 'k' loop
                }
                for(int k = 0; k < points.size(); k++)
                {
                    int c = points[k].x - points[i].x;
                    int d = points[k].y - points[i].y;
                    if(a * c == b * d)
                    {
                        num++;
                    }
                }
                maxNum = max(maxNum, num);
            }
            maxNum = max(maxNum, samePoints);
        }
        return maxNum;
    }
    static bool cmp(const Point &p1, const Point &p2)
    {
        return (p1.x < p2.x);
    }
};

int main()
{
	return 0;
}
