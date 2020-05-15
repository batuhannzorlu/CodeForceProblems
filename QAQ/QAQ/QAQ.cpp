/*
"QAQ" is a word to denote an expression of crying. Imagine "Q" as eyes with tears and "A" as a mouth.

Now Diamond has given Bort a string consisting of only uppercase English letters of length n. There is a great number of "QAQ" in the string (Diamond is so cute!).

Bort wants to know how many subsequences "QAQ" are in the string Diamond has given. Note that the letters "QAQ" don't have to be consecutive, but the order of letters should be exact.

Input
The only line contains a string of length n (1 ≤ n ≤ 100). It's guaranteed that the string only contains uppercase English letters.

Output
Print a single integer — the number of subsequences "QAQ" in the string.

EXP:

INPUT:

QAQAQYSYIOIWIN

OUTPUT:

4


*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string UserInput;
vector<char>UserInputLst;
int FrontQCount = 0;
int BackQCount = 0;
int MidACount = 0;
int CurrentACount = 0;
int QAQcount = 0;

int index = 0;
int main()
{
	cin >> UserInput;
	for (int i = 0; i < UserInput.size(); i++) {
		UserInputLst.push_back(UserInput[i]);
		if (UserInput[i]=='A')
			++MidACount;
	}
	int i = 0;
	for (i; i < UserInputLst.size(); ++i)
	{
		if (UserInputLst[i] == 'Q')
			++BackQCount;

		if (UserInputLst[i] == 'A') {
			++CurrentACount;			
			for (int j =i ; j < UserInputLst.size(); j++)
			{
				if (UserInputLst[j] == 'Q')
					++FrontQCount;
			}
			if (CurrentACount <= MidACount) {

				QAQcount += BackQCount * FrontQCount;
				UserInputLst.erase(UserInputLst.begin() + i);
				i = -1;
				BackQCount = 0;
				FrontQCount = 0;
			}
		}
	}

	cout << QAQcount;
}
