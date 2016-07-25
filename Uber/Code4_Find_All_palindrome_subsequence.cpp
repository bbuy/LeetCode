#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

void findFromPivit(string& s, int& left, int& right, unordered_set<string>& rtn)
{
	while(left>=0&&right<s.length()&&(s[left]==s[right]))
	{
		string newWord = s.substr(left,right-left+1);
		if(rtn.find(newWord) == rtn.end())
		{
			rtn.insert(newWord);
		}

		left--;
		right++;
	}
}

unordered_set<string> FindUniquePalindrome(string& s)
{
	unordered_set<string> rtn;
	for(int i=0;i<s.length();i++)
	{
		int left = i;
		int right = i;
		findFromPivit(s,left,right,rtn);
		

		if(i<s.length() && s[i]==s[i-1])
		{
			left = i-1;
			right = i;
			findFromPivit(s,left,right,rtn);
		}
	}

	return rtn;
}

int main()
{
	string test = "abcbcbefg";
	auto rtn = FindUniquePalindrome(test);

	for(auto i=rtn.begin();i!=rtn.end();i++)
	{
		cout<<*i<<endl;
	}
	return 0;
}