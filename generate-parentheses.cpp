#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<string> result;
    string one_result;
public:
    vector<string> generateParenthesis(int n)
    {
        one_result.resize(2*n);
        generate(0, n, n);
        return result;
    }
    
    void generate(int index, int left, int right)
    {
        if(left < 0 || right < 0)
        {
            return;
        }
        if(left == 0 && right == 0)
        {
            result.push_back(one_result);
        }
        if(left == right)
        {
            one_result[index] = '(';
            generate(index + 1, left - 1, right);
        }
        else//left < right
        {
            one_result[index] = '(';
            generate(index + 1, left - 1, right);
            one_result[index] = ')';
            generate(index + 1, left, right - 1);
        }
    }
};

int main()
{
	return 0;
}
