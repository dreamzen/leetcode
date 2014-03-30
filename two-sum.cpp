#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
 * NOTE: numbers={1,2,2,3}, target=4
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> m;
        int index1, index2;
        vector<int> result;
        int len = numbers.size();
        for(int i = 0; i < len; i++)
        {
            m.insert(make_pair(numbers[i], i));
        } 
        //search, n x lgn ==> O(nlgn)
        map<int, int>::iterator ite;
        for(int i = 0; i < len; i++)
        {
            if(numbers[i] <= target && (2 * numbers[i]) != target)
            {
                index1 = i + 1;
                ite = m.find(target - numbers[i]);
                if(ite != m.end())
                {
                    index2 = ite->second + 1;
                    result.push_back(index1);
                    result.push_back(index2);
                }
            }
        }
        //if no result, then it will be the situation of 'NOTE'
        target /= 2;
        for(int i = 0; i < len; i++)
        {
            if(numbers[i] == target)
            {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(2);
    numbers.push_back(15);
    int target = 4;
    Solution s;
    vector<int> v = s.twoSum(numbers, target);
    cout << v[0] << " " << v[1] << endl;
    return 0;
}
