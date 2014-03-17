#include <iostream>
using namespace std;

/* only 0-->s.zise() - 1, so O(n)?  how about substr()? */
class Solution
{
public:
	void reverseWords(string &s)
	{
		int i;
		int tail, head;
		bool has_tail = false; //whether the word is begin

		//erase leading space
		while(s[0] == ' ')
			s.erase(0, 1);
		string reverse_s;
		tail = s.size() - 1;
		
		//parse whole string from  tail to head
		for(i = tail; i >= 0; i--)
		{
			if(s[i] == ' ')
			{
				if(has_tail)//here comes a complete word
				{
					head = i + 1;
					reverse_s += s.substr(head, tail - head + 1);
					reverse_s += " ";
					has_tail = false; //the whole word has been selected, so false again.
				}
				else//continue to find the 'tail'
				{
					continue;
				}
			}
			else if(has_tail)//in the middle of the word
			{
				continue;
					
			}
			else//reach the tail of a new word
			{
				tail = i;
				has_tail = true;
			}
		}

		//the 'last' word, or there is no words!
		if(has_tail)
		{
			reverse_s += s.substr(0, tail + 1);
		
		}
		else
		{
			reverse_s = "";//empty, NOT ' '!
		
		}
		s = reverse_s;
	}
};

int main()
{
	Solution my;

	char str[1024];
	cin.getline(str, 1024);
	string s = str;
	my.reverseWords(s);
	
	cout << s << endl;
	return 0;
}
