#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<string> result;
    string one_result;
public:
    vector<string> letterCombinations(string digits)
    {
        one_result.resize(digits.length());
        getLetter(digits, 0);
        return result;
    }
    
    void getLetter(string digits, int index)
    {
        if(index == digits.length())
        {
            result.push_back(one_result);
        }
        else
        {
            char c = digits[index];
            switch (c)
            {
                case '0':
                    one_result[index] = ' ';
                    getLetter(digits, index + 1);
                    break;
                case '1':
                    getLetter(digits, index + 1);
                    break;
                case '2':
                    for(char i = 'a'; i <= 'c'; i++)
                    {
                        one_result[index] = i;
                        getLetter(digits, index + 1);
                    }
                    break;
                case '3':
                    for(char i = 'd'; i <= 'f'; i++)
                    {
                        one_result[index] = i;
                        getLetter(digits, index + 1);
                    }
                    break;
                case '4':
                    for(char i = 'g'; i <= 'i'; i++)
                    {
                        one_result[index] = i;
                        getLetter(digits, index + 1);
                    }
                    break;
                case '5':
                    for(char i = 'j'; i <= 'l'; i++)
                    {
                        one_result[index] = i;
                        getLetter(digits, index + 1);
                    }
                    break;
                case '6':
                    for(char i = 'm'; i <= 'o'; i++)
                    {
                        one_result[index] = i;
                        getLetter(digits, index + 1);
                    }
                    break;
                case '7':
                    for(char i = 'p'; i <= 's'; i++)
                    {
                        one_result[index] = i;
                        getLetter(digits, index + 1);
                    }
                    break;
                case '8':
                    for(char i = 't'; i <= 'v'; i++)
                    {
                        one_result[index] = i;
                        getLetter(digits, index + 1);
                    }
                    break;
                case '9':
                    for(char i = 'w'; i <= 'z'; i++)
                    {
                        one_result[index] = i;
                        getLetter(digits, index + 1);
                    }
                    break;
                default:
                    getLetter(digits, index + 1);
                    break;
            }
        }
    }
};

int main()
{
	return 0;
}
