#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

string randomG(vector<pair<string,int>>& wordList)
{
	int v = rand()%100;
	int sum = 0;
	for(auto pair:wordList)
	{
		sum += pair.second;
		if(sum>=v)
			return pair.first;
	}
}

int main()
{
	vector<pair<string,int>> test;
	test.push_back(pair<string,int>{"string1",10});
	test.push_back(pair<string,int>{"string2",20});
	test.push_back(pair<string,int>{"string3",70});

	vector<int> check(3,0);
	srand(time(NULL));
	for(int i=0;i<1000;i++)
	{
		string result = randomG(test);
		if(result == "string1")
			check[0]++;
		if(result == "string2")
			check[1]++;
		if(result == "string3")
			check[2]++;
		
	}

	cout<<"string1:"<<check[0]<<endl;
	cout<<"string2:"<<check[1]<<endl;
	cout<<"string3:"<<check[2]<<endl;
	return 0;
}
