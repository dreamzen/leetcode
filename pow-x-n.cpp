#include <iostream>
using namespace std;

class Solution
{
public:
    double pow(double x, int n)
    {
        if(x == 0)
        {
            return 0.0;
        }
        if(n == 0)
        {
            return 1.0;
        }
        else if(n > 0)
        {
            return my_pow(x, n);
        }
        else
        {
            if(n == (1 << 31))//MIN_INT ==> -MIN_INT is invalid.
            {
                double tmp = my_pow(x, (-1) * (n + 1));
                tmp *= x;
                return 1 / tmp;
            }
            else
            {
                return 1 / my_pow(x, (-1) * n);
            }
        }
    }
    
	//divide and conquer
    double my_pow(double x, int n)
    {
        if(n == 1)
        {
            return x;
        }
        else if(n % 2 == 0)
        {
            double tmp = my_pow(x, n / 2);
            return tmp * tmp;
        }
        else
        {
            double tmp = my_pow(x, n / 2);
            return tmp * tmp * x;
        }
    }
};

int main()
{
	double x;
	int n;
	Solution s;
	cin >> x >> n;
	cout << s.pow(x, n) << endl;
	return 0;
}
