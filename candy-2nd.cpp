#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        if(ratings.size() <= 1)
        {
            return ratings.size();
        }
        vector<int> candys(ratings.size(), 1);
        //from left to right, make sure every child has more candy than his left
        for(int i = 1; i < ratings.size(); i++)
        {
            if(ratings[i] > ratings[i - 1])
            {
                candys[i] = candys[i - 1] + 1;
            }
        }
        //from right to left
        for(int i = ratings.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
            {
                candys[i] = max(candys[i], (candys[i + 1] + 1));
            }
        }
        int num = 0;
        for(int i = 0; i < candys.size(); i++)
        {
            num += candys[i];
        }
        return num;
    }
};

int main()
{
	return 0;
}
