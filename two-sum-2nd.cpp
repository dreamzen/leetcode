#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> result;
        if(numbers.size() < 2)
        {
            return result;
        }
        unordered_map<int, int> mapping;
        for(int i = 0; i < numbers.size(); i++)
        {
            mapping[numbers[i]] = i + 1;
        }
        bool found = false;
        //normal situation
        for(int i = 0; i < numbers.size(); i++)
        {
            if((2 * numbers[i] != target) && mapping.find(target - numbers[i]) != mapping.end())
            {
                found = true;
                int index1 = mapping[numbers[i]];
                int index2 = mapping[target - numbers[i]];
                result.push_back(min(index1, index2));
                result.push_back(max(index1, index2));
                break;
            }
        }
        //special situation [1, 2, 2, 6] target = 4 or 5
        if(!found)
        {
            int index1, index2;
            for(index1 = 0; index1 < numbers.size(); index1++)
            {
                if(2 * numbers[index1] == target)
                {
                    break;
                }
            }
            for(index2 = numbers.size() - 1; index2 >= 0; index2--)
            {
                if(2 * numbers[index2] == target)
                {
                    break;
                }
            }
            if(index1 < index2)
            {
                result.push_back(index1 + 1);
                result.push_back(index2 + 1);
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
