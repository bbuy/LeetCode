#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int>& list, int left, int right)
{
	int pivot = list[left];
	int j = left;
	for(int i=left+1;i<=right;i++)
	{
		if(list[i]<pivot)
		{
			j++;
			if(i!=j)
			{
				swap(list[i],list[j]);
			}
		}
	}

	swap(list[left],list[j]);

	return j;
}

void QuickSortRange(vector<int>& list, int left, int right)
{
	if(left>=right)
		return;
	else
	{
		int middle = Partition(list, left, right);
		QuickSortRange(list,left,middle-1);
		QuickSortRange(list,middle+1,right);
	}
}

void QuickSort(vector<int>& list)
{
	QuickSortRange(list,0,list.size()-1);
}

void test()
{
	vector<int> test;

	for(int i=0;i<10;i++)
	{
		test.push_back(rand()%100);
	}

	//test = {32, 17, 81, 34, 64, 20, 80, 78, 55, 1};

	//test = {71, 92, 81, 88, 47, 25, 73, 88, 63, 86 };
	cout<<"Old List: ";
	for(auto i:test)
		cout<<i<<" ";
	cout<<endl;

	QuickSort(test);

	cout<<"New List: ";
	for(auto i:test)
		cout<<i<<" ";
	cout<<endl;
}

int main()
{
	srand(time(NULL));
	for(int i=0;i<10;i++)
		test();

	return 0;
}