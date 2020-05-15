
#include <iostream>
#include <string>
#include <fstream>
#include<vector>
#include<list>
#include<Map>
#include<forward_list>

using namespace std;
struct HighestOddPosition
{
	int max;
	int MaxCount;
};
string longestPalindrome(string s);
vector<vector<int>> bubbleSortFleft(vector<vector<int>>);
HighestOddPosition HighestOddRight(vector<vector<int>>);
vector<vector<int>> bubblEqual(vector<vector<int>> matrix);
vector<vector<int>>EvenNumbers(vector<vector<int>> matrix);
string UserInput;
string wait;
int main()
{
	cout << "LUTFEN EN UZUN POLINDROMU BULUNACAK DIZIYI GIRINIZ: " << endl;
	cin >> UserInput;
	cout << longestPalindrome(UserInput) << endl;
	cin >> wait;
}
string longestPalindrome(string s) {

	string LongestPalindrome;
	int no_of_cols = 2;
	int count = 0;
	vector<vector<int>> matrix;
	matrix.resize(s.size(), std::vector<int>(no_of_cols, 1));

	for (string::iterator it = s.begin(); it != s.end(); it++)
	{
		matrix[count][0] = (int)(*it);;
		count++;
	}
	vector<vector<int>> Smatrix = bubbleSortFleft(matrix);
	vector<vector<int>>Cmatrix = bubblEqual(Smatrix);
	vector<vector<int>>Ematrix = EvenNumbers(Cmatrix);
	HighestOddPosition position = HighestOddRight(Cmatrix);

	for (int i = 0; i < Ematrix.size(); i++)
	{
		if (i == 0) {
			for (int i = 0; i < (position.MaxCount - 1) / 2; i++)
			{
				LongestPalindrome.push_back(static_cast<char>(position.max));
			}
		}
		for (int j = 0; j < Ematrix[i][1] / 2; j++)
		{
			LongestPalindrome.push_back(static_cast<char>(Ematrix[i][0]));
		}
		if (i == Ematrix.size() - 1) {
			LongestPalindrome.push_back(static_cast<char>(position.max));
		}
	}
	for (int i = Ematrix.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < (Ematrix[i][1]) / 2; j++)
		{
			LongestPalindrome.push_back(static_cast<char>(Ematrix[i][0]));
		}
		if (i == 0) {
			for (int i = 0; i < (position.MaxCount - 1) / 2; i++)
			{
				LongestPalindrome.push_back(static_cast<char>(position.max));
			}
		}
	}
	return LongestPalindrome;
}
vector<vector<int>>EvenNumbers(vector<vector<int>>matrix) {

	int row = matrix.size();
	int column = matrix[0].size();
	vector<vector<int>> evenmatrix;
	evenmatrix.resize(row, std::vector<int>(column));
	int evencount = 0;
	for (int k = 0; k < matrix.size(); k++)
	{
		if (((matrix[k][1]) % 2) == 0)
		{
			evenmatrix[evencount][0] = matrix[k][0];
			evenmatrix[evencount][1] = matrix[k][1];
			evencount++;
		}
	}
	evenmatrix.erase(evenmatrix.begin() + evencount, evenmatrix.end());
	return evenmatrix;
}
vector<vector<int>> bubbleSortFleft(vector<vector<int>> matrix) {

	int i, j, temp;

	for (i = 0; i < matrix.size(); i++) {
		for (j = i + 1; j < matrix.size(); j++)
		{
			if (matrix[j][0] < matrix[i][0]) {
				temp = matrix[i][0];
				matrix[i][0] = matrix[j][0];
				matrix[j][0] = temp;
			}
		}
	}
	return matrix;
}
vector<vector<int>> bubblEqual(vector<vector<int>> matrix) {

	int i, j, temp;

	for (i = 0; i < matrix.size(); i++) {
		for (j = i + 1; j < matrix.size(); j++)
		{
			if (matrix[j][0] == matrix[i][0])
			{
				matrix.erase(matrix.begin() + j);
				matrix.shrink_to_fit();
				++matrix[i][1];
				--j;
			}
		}
	}
	return matrix;
}
HighestOddPosition HighestOddRight(vector<vector<int>>matrix) {
	int  max, maxCount = 0;
	max = matrix[0][1];
	for (int k = 0; k < matrix.size(); k++)
	{
		if (matrix[k][1] > max && matrix[k][1] % 2 != 0)
		{
			max = matrix[k][0];
			maxCount = matrix[k][1];
		}
	}
	HighestOddPosition position = { max,maxCount };
	return position;
}





