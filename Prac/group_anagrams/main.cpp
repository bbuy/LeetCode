// Given an array of strings, group anagrams together.

// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Return:

// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]

/*
My thoughts:
The simple way is to sort the word and use it as key and add the word to the Dictionary.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> anagrams(vector<string> list)
{
	unordered_map<string, vector<string>> m;
	vector< vector<string> > rtn;
	for(auto s:list)
	{
		string tmp = s;
		sort(tmp.begin(), tmp.end());
		if(m.find(tmp)==m.end())
		{
			vector<string> newList;
			newList.push_back(s);
			m.insert(pair<string,vector<string>>{tmp,newList});
		}
		else
		{
			m[tmp].push_back(s);
		}
	}

	for(auto i=m.begin();i!=m.end();i++)
	{
		rtn.push_back(i->second);
	}

	return rtn;
}

void test1()
{
	vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> rtn = anagrams(input);

	cout<<"List size: "<<rtn.size()<<endl;
	for(auto l:rtn)
	{
		for(auto s:l)
			cout<<s<<" , ";
			cout<<endl;
	}
}

void test2()
{
	vector<string> input = {};
	vector<vector<string>> rtn = anagrams(input);

	cout<<"List size: "<<rtn.size()<<endl;
	for(auto l:rtn)
	{
		for(auto s:l)
			cout<<s<<" , ";
			cout<<endl;
	}
}

int main()
{
	test1();
	test2();

	return 0;
}

