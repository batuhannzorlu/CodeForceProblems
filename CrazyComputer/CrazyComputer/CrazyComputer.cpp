/*
ZS the Coder is coding on a crazy computer. If you don't type in a word for a c consecutive seconds, everything you typed disappear!

More formally, if you typed a word at second a and then the next word at second b, then if b - a ≤ c, just the new word is appended to other words on the screen. If b - a > c,
then everything on the screen disappears and after that the word you have typed appears on the screen.

For example, if c = 5 and you typed words at seconds 1, 3, 8, 14, 19, 20 then at the second 8 there will be 3 words on the screen.
After that, everything disappears at the second 13 because nothing was typed.
At the seconds 14 and 19 another two words are typed, and finally, at the second 20, one more word is typed, and a total of 3 words remain on the screen.

You're given the times when ZS the Coder typed the words.
Determine how many words remain on the screen after he finished typing everything.

Input
The first line contains two integers n and c (1 ≤ n ≤ 100 000, 1 ≤ c ≤ 109) — the number of words ZS the Coder typed and the crazy computer delay respectively.

The next line contains n integers t 1, t 2, ..., t n (1 ≤ t 1 < t 2 < ... < t n ≤ 109), where t i denotes the second when ZS the Coder typed the i-th word.

Output
Print a single positive integer, the number of words that remain on the screen after all n words was typed, in other words, at the second t n.

INPUT:

6 5
1 3 8 14 19 20

OUTPUT:

3


INPUT:

6 1
1 3 5 7 9 10

OUTPUT:

2

-------------------------------------------------------------------------
NOTE:
The first sample is already explained in the problem statement.
For the second sample, after typing the first word at the second 1, 
it disappears because the next word is typed at the second 3 and 3 - 1 > 1. Similarly, only 1 word will remain at the second 9.
Then, a word is typed at the second 10, so there will be two words on the screen, as the old word won't disappear because 10 - 9 ≤ 1.
*/
#include <iostream>
#include<math.h>
#include<vector>
#include <cstdlib>

using namespace std;

int CharCount;
int RemainTime;
int TimeDif = 0;
int index = 0;
struct MaxPos
{
	int MaxIndex = 0;
	int MaxValue = 0;
};

int main()
{
	MaxPos pos;

	cin >> CharCount;
	cin >> RemainTime;

	vector<int>Cinput;
	int x;
	for (int i = 0; i < CharCount; i++)
	{
		cin >> x;
		Cinput.insert(Cinput.end(), x);
	}
	for (int i = 0; i < CharCount - 1; i++)
	{
		TimeDif = Cinput[i+1] - Cinput[i];
		if (TimeDif > RemainTime) {
			pos.MaxIndex = i;
			pos.MaxValue = TimeDif;
		}
		else if (TimeDif == RemainTime) {
			for (i; i < CharCount - 2; i++)
			{

				TimeDif = Cinput[i + 2] - Cinput[i + 1];
				if (TimeDif > RemainTime)
				{
					pos.MaxIndex = i;
					pos.MaxValue = TimeDif;
					break;
				}
				else if (TimeDif == RemainTime)
					continue;
				else
					break;
			}							
		}													
	}	
	if (pos.MaxValue > RemainTime)
		cout << CharCount - (pos.MaxIndex + 1) << endl;
	else if (pos.MaxValue == RemainTime)
		cout << CharCount - (pos.MaxIndex) << endl;
	else
		cout << CharCount - (pos.MaxIndex) << endl;
}






