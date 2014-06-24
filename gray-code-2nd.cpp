#include <iostream>
#include <vector>
using namespace std;

/**
 * symmetry
 */
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        result.push_back(0);
        for(int i = 0; i < n; i++)
        {
            for(int j = result.size() - 1; j >= 0; j--)
            {
                result.push_back(result[j] | (1 << i));
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
