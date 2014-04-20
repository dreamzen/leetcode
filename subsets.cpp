#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int> > result;
    vector<int> one_result;
public:
    vector<vector<int> > subsets(vector<int> &S)
    {
        sort(S.begin(), S.end());
        dealWith(S, 0);
        return result;
    }
    void dealWith(vector<int> &S, int index)
    {
        if(index >= S.size())
        {
            result.push_back(one_result);
            return;
        }
        //select S[index]
        one_result.push_back(S[index]);
        dealWith(S, index + 1);
        one_result.pop_back();
        //not select S[index]
        dealWith(S, index + 1);
    }
};

int main()
{
	return 0;
}
