#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int> > result;
    vector<int> one_result;
public:
    vector<vector<int> > combine(int n, int k)
    {
        getResult(1, n, k);
        return result;
    }
    
    void getResult(int lhs, int rhs, int num)
    {
        if(num > rhs - lhs + 1)
        {
            return;
        }
        //pick current number
        one_result.push_back(lhs);
        if(num == 1)
        {
            result.push_back(one_result);
        }
        else
        {
            getResult(lhs + 1, rhs, num - 1);
        }
        one_result.pop_back();
        //not pick
        getResult(lhs + 1, rhs, num);
    }
};

int main()
{
    return 0;
}
