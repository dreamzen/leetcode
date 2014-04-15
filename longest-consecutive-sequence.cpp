#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Hash map.
 * 
 */

class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        unordered_map<int, bool> used;
        int max_length = 0;
        for(int i = 0; i < num.size(); i++)
        {
            used[num[i]] = false;//used<> has key num[i] means num[i] is in the array.
        }
        for(int i = 0; i < num.size(); i++)
        {
            if(used[num[i]])//used[num[i]] == true means we have checked the length of num[i]-1,num[i],num[i]+1,.....
            {
                continue;
            }
            else
            {
                int length = 1;
                used[num[i]] = true;
                for(int j = num[i] - 1; used.find(j) != used.end(); j--)
                {
                    used[j] = true;
                    length++;
                }
                for(int j = num[i] + 1; used.find(j) != used.end(); j++)
                {
                    used[j] = true;
                    length++;
                }
                max_length = (max_length > length) ? max_length : length;
            }
        }
        return max_length;
    }
};

int main()
{
    return 0;
}
