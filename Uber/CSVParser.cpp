#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

vector<vector <string>> CSVParser(string filename)
{
	vector<vector<string>> list;

	fstream file(filename);
	string line;
	while(getline(file,line))
	{
		cout<<"line:"<<line<<endl;
		vector<string> tokenLine;
		int wordStart = 0;
		int wordEnd = 0;

		while(wordStart<line.length())
		{
			if(line[wordEnd] == '"')
			{
				int tmp = wordEnd + 1;
				wordEnd++;
				while(line[tmp]!='"' && tmp<line.length()){tmp++;}
				if(tmp < line.length())
				{
					tokenLine.push_back(line.substr(wordStart,tmp-wordStart));
					wordStart = tmp+1;
					wordEnd = tmp+1;
				}
			}

			while(line[wordEnd] != ',' && wordEnd<line.length())
			{
				wordEnd++;
			}
			cout<<"WordEnd:"<<wordEnd<<endl;
			tokenLine.push_back(line.substr(wordStart,wordEnd-wordStart));
			wordStart = wordEnd +1;
			wordEnd = wordStart;
		}

		list.push_back(tokenLine);
	}

	return list;
} 

int main()
{
	auto rtn = CSVParser("test.txt");

	for(auto l:rtn)
	{
		cout<<"Line: ";
		for(auto str:l)
			cout<<str<<"|";
		cout<<endl;
	}
	return 0;
}