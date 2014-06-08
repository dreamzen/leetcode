#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    enum direction{Down = 0, Up};
public:
    string convert(string s, int nRows)
    {
        if(nRows <= 1)
        {
            return s;
        }
        vector<string> vStr(nRows, "");
        direction d = Down;
        int x = 0;
        int y = 0;
        while(y < s.length())
        {
            vStr[x] += s[y];
            y++;
            switch(d)
            {
                case Down:
                    if(x == vStr.size() - 1)
                    {
                        d = Up;
                        x -= 1;
                    }   
                    else
                    {
                        x++;
                    }
                    break;
                case Up:
                    if(x == 0)
                    {
                        d = Down;
                        x = 1;
                    }
                    else
                    {
                        x--;
                    }
                    break;
                default:
                    break;
            }
        }
        for(int i = 1; i < nRows; i++)
        {
            vStr[0] += vStr[i];
        }
        return vStr[0];
    }
};

int main()
{
	return 0;
}
