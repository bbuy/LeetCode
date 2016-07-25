// http://www.fgdsb.com/2015/01/25/group-contacts/

// input is a list of contacts, each contacts has {name, email, phone} any two contacts that share the same name or email or phone will be the same contact. Return the list of unique contact group.

// Use union find. and 3 dictionaries, one for each property. For each contact, find the contacts that it is identical to and union all of them. 


#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct contact
{
public:
	string name;
	string email;
	int phone;
	contact(string name, string email, int phone):name(name),phone(phone),email(email){}
};

void Union(int i, int j, vector<int>& groupId)
{
	if(groupId[i] == groupId[j])
		return;

	int p = groupId[i];
	int q = groupId[j];

	for(int i=0;i<groupId.size();i++)
	{
		if(groupId[i] == q)
			groupId[i] = p;
	}
}

vector<vector<contact>> FindGroup(vector<contact> contacts)
{
	vector<int> groupId(contacts.size());
	for(int i=0;i<contacts.size();i++)
		groupId[i] = i;

	unordered_map<string,vector<int>> nameMap;
	unordered_map<string,vector<int>> emailMap;
	unordered_map<int,vector<int>> phoneMap;

	for(int i=0;i<contacts.size();i++)
	{
		if(nameMap.find(contacts[i].name) == nameMap.end())
		{
			nameMap.insert(pair<string,vector<int>>{contacts[i].name,vector<int>{i}});	
		}
		else
		{
			nameMap[contacts[i].name].push_back(i);
			vector<int> identicalList = nameMap[contacts[i].name];
			for(auto id:identicalList)
			{
				Union(i,id,groupId);
			}
		}

		if(emailMap.find(contacts[i].email) == emailMap.end())
		{
			emailMap.insert(pair<string,vector<int>>{contacts[i].email,vector<int>{i}});	
		}
		else
		{
			emailMap[contacts[i].email].push_back(i);
			vector<int> identicalList = emailMap[contacts[i].email];
			for(auto id:identicalList)
			{
				Union(i,id,groupId);
			}
		}

		if(phoneMap.find(contacts[i].phone) == phoneMap.end())
		{
			phoneMap.insert(pair<int,vector<int>>{contacts[i].phone,vector<int>{i}});	
		}
		else
		{
			phoneMap[contacts[i].phone].push_back(i);
			vector<int> identicalList = phoneMap[contacts[i].phone];
			for(auto id:identicalList)
			{
				Union(i,id,groupId);
			}
		}
	}
	cout<<"GroupId:";
	for(auto i:groupId)
		cout<<i<<" ";
	cout<<endl;
	unordered_map<int,vector<contact>> rtnMap;
	for(int i=0;i<groupId.size();i++)
	{
		if(rtnMap.find(groupId[i]) == rtnMap.end())
		{
			rtnMap.insert(pair<int,vector<contact>>{groupId[i],vector<contact>{contacts[i]}});
		}
		else
		{
			rtnMap[groupId[i]].push_back(contacts[i]);
		}
	}

	vector<vector<contact>> rtn;

	for(auto l=rtnMap.begin();l!=rtnMap.end();l++)
	{
		rtn.push_back(l->second);
	}

	return rtn;
}

int main()
{
	vector<contact> testList;
	testList.push_back(contact("Tian","tiang513@gmail.com",123));
	testList.push_back(contact("Tian","tiang513@gmail.com1",1234));
	testList.push_back(contact("Tian2","tiang513@gmail.com2",123));

	auto result = FindGroup(testList);

	for(auto l:result)
	{
		cout<<"Group: ";
		for(auto contact:l)
		{
			cout<<"Name:" << contact.name <<" ";
			cout<<"email:" << contact.email <<" ";
			cout<<"phone:" << contact.phone <<"  /// ";
		}
		cout<<endl;
	}
	return 0;
}