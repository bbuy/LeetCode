#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str = "aaa bbb cdd dse";
	vector<string> splitStr;
	int i = 0;
	while(i<str.length())
        {
            cout<<i<<endl;
            int end = str.find(' ', i);
            if (end != str.npos)
            {
            	splitStr.push_back(str.substr(i,end-i));
            	i = end + 1;
            }
        	else
        	{
        	splitStr.push_back(str.substr(i,str.length() - i));
            i = str.length()+1;
        	}
        }

        for(auto s:splitStr)
        	cout<<s<<" ";
        cout<<endl;
    return 0;
}