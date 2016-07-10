// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// my thoughts: maintain state for each row, each col and each block of 9, if the same number show more than once in the same row or same col or same block of 9, return false, otherwise return true.

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


// bool validSudu(vector<vector<char>>& gameBoard)
// {
// 	vector<unordered_set<char>> rowState(9, unordered_set<char>{});
// 	vector<unordered_set<char>> colState(9, unordered_set<char>{});
// 	vector<unordered_set<char>> sqrState(9, unordered_set<char>{});

// 	for(int i=0;i<9;i++)
// 	{
// 		for(int j=0;j<9;j++)
// 		{
// 			//cout<<"Debug:"<<gameBoard[i][j]<<endl;
// 			if(gameBoard[i][j]!='.')
// 			{
// 				if(rowState[i].find(gameBoard[i][j])==rowState[i].end())
// 				{
// 					rowState[i].insert(gameBoard[i][j]);
// 				}
// 				else
// 				{
// 					return false;
// 				}

// 				if(colState[j].find(gameBoard[i][j])==colState[j].end())
// 				{
// 					colState[j].insert(gameBoard[i][j]);
// 				}
// 				else
// 				{
// 					return false;
// 				}

// 				int sqrIdx = i/3*3 + j/3;
// 				//cout<<"sqrIdx = " <<sqrIdx<<endl; 
// 				if(sqrState[sqrIdx].find(gameBoard[i][j])==sqrState[sqrIdx].end())
// 				{
// 					sqrState[sqrIdx].insert(gameBoard[i][j]);
// 				}
// 				else
// 				{
// 					return false;
// 				}
// 			}
// 		}
// 	}

// 	return true;
// }

// Why would I use unordered_set, so expensive. just use array of 9
bool validSudu(vector<vector<char>>& gameBoard)
{
	vector<vector<char>> rowState(9, vector<char>(9,'.'));
	vector<vector<char>> colState(9, vector<char>(9,'.'));
	vector<vector<char>> sqrState(9, vector<char>(9,'.'));

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			//cout<<"Debug:"<<gameBoard[i][j]<<endl;
			if(gameBoard[i][j]!='.')
			{
				int idV = gameBoard[i][j]-'1';
				if(rowState[i][idV]=='.')
				{
					rowState[i][idV] = 'c';
				}
				else
				{
					cout<<"Row"<<endl;
					return false;
				}

				if(colState[j][idV]=='.')
				{
					colState[j][idV] = 'c';
				}
				else
				{
					cout<<"Col"<<endl;
					return false;
				}

				int sqrIdx = i/3*3 + j/3;
				//cout<<"sqrIdx = " <<sqrIdx<<endl; 
				if(sqrState[sqrIdx][idV] == '.')
				{
					sqrState[sqrIdx][idV] = 'c';
				}
				else
				{
					return false;
				}
			}
		}
	}

	return true;
}

int main()
{
	vector<vector<char>> input = 
	{
		{'.','8','7','6','5','4','3','2','1'},
		{'2','.','.','.','.','.','.','.','.'},
		{'3','.','.','.','.','.','.','.','.'},
		{'4','.','.','.','.','.','.','.','.'},
		{'5','.','.','.','.','.','.','.','.'},
		{'6','.','.','.','.','.','.','.','.'},
		{'7','.','.','.','.','.','.','.','.'},
		{'8','.','.','.','.','.','.','.','.'},
		{'9','.','.','.','.','.','.','.','.'}
	};


	cout<<validSudu(input)<<endl;
}