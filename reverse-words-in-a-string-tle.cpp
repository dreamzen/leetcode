#include <iostream>
using namespace std;

class Solution
{
public:
    void reverseWords(string &s)
{


        int last = s.size() - 1;
        size_t tail;
        size_t head = last;
        string word = "";
    
        while(true)
        {//find() is easy to undersand but it's not optimal! 
                //find 'tail' and 'head', and then form a 'word'
                tail = s.find_last_not_of(" ", head);
                head = s.find_last_of(" ", tail);
                
                if(head == string::npos && tail == string::npos)
                {   
                        break;
                }   

                if(head == string::npos)
                {   
                        word += s.substr(0, tail + 1); 
                        break;
                }   

                if(tail != string::npos && head != string::npos)
                {   
                        word += s.substr(head + 1, tail - head);
                        if(s.find_last_not_of(" ", head) == string::npos)
                        {   
                                break;
                        }   
                        else
                        {   
                                word += " ";
                        }   
                }   
        }   
        s = word;
    }
};

int main()
{
	Solution s;
	char cc[1024];
	while(true)
	{
		cin.getline(cc, 1024);
		string str = cc;
		if(str == "e")
		{
			break;
		}
		s.reverseWords(str);
		cout << str << endl;
	}
	return 0;
}
