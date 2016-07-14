// To implement a multiply function that takes two big int and return a big int repersented as string.

#include <iostream>
#include <vector>
#include <string>

using namespace std;


string Plus(string& str1, string& str2)
{
	string rtn = "";
	int carryOn = 0;
	int i = str1.length()-1;
	int j = str2.length()-1;
	while(carryOn || i>=0 || j>=0)
	{
		int tmp = carryOn;
		if(i>=0)
		{
			tmp += str1[i] - '0';
			i--;
		}

		if(j>=0)
		{
			tmp += str2[j] - '0';
			j--;
		}

		carryOn = tmp / 10;
		rtn.insert(rtn.begin(),(tmp%10) + '0');
	}

	return rtn;
}

string Multiply(string& str1, string& str2)
{
	//cout<<str1<<endl;
	//cout<<str2<<endl;
	//cout<<"....."<<endl;
	if(str1.length()<str2.length())
	{
		return Multiply(str2,str1);
	}

	if(str2.length()==0)
		return str1;

	int plusTimes = str2[str2.length()-1] - '0';

	if(plusTimes != 0)
	{
		string tmp = "";
		for(int i = 0;i<plusTimes;i++)
			tmp = Plus(tmp,str1);

		str2[str2.length()-1] = '0';
		string rest = Multiply(str1,str2);
		return Plus(rest ,tmp);
	}
	else
	{
		if(str2.length()>1)
		{
		//cout<<"length:"<<str2.length()<<endl;
		str1.push_back('0');
		str2.pop_back();
		return Multiply(str1,str2);
		}
		else
		{
			return "0";
		}
	}
}

int main()
{
	string a = "127";
	string b = "4563";
	//<<Plus(a,b)<<endl;;
	cout<<Multiply(a,b)<<endl;
	return 0;
} 