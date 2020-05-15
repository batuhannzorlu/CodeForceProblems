

#include <iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

string LongestPalSub(string);
int main()
{	
	string input, wait;
	cout << "ENTER A PALINDROMIK STRING: " << endl;
	cin >> input;
	string PalindromSubString = LongestPalSub(input);
	cout << PalindromSubString << endl;
	cin >> wait;
}
//THIS SOLUTÝON ONLY FOR ODD NUMBER OF ELEMENTS.
string LongestPalSub(string s) {
	string result;
	vector<char>longestSubstring;
	int size = s.size();

	if (size == 1)
		return s;
	if (size == 2 && s[0] == s[1])
		return s;

	char CurrentChar;
	vector<char> LeadChar;
	vector<char> BackChar;
	int currentpalindromsize = 0;
	int maxpolindromsize = 0;
	if (s.size() >= 3)
	{
		for (int i = 2; i < s.size(); ++i)
		{
			int half = floor(((s.size() - 1) + i) / 2);
			CurrentChar = s[i];
			int shortside = bool(i) >= ((s.size() - 1) - i) ? ((s.size() - 1) - i) : (i);
			for (int j = 1; j <= shortside; j++)
			{
				if (s[i + j] != s[i - j]) {
					currentpalindromsize = 0;
					BackChar.clear();
					LeadChar.clear();
				}
				else
				{
					++currentpalindromsize;
					BackChar.insert(BackChar.begin(), s[i - j]);
					LeadChar.insert(LeadChar.end(), s[i + j]);
					if (currentpalindromsize > maxpolindromsize)
					{
						longestSubstring.clear();
						maxpolindromsize = currentpalindromsize;
						longestSubstring.insert(longestSubstring.begin(), BackChar.begin(), BackChar.end());
						longestSubstring.push_back(CurrentChar);
						longestSubstring.insert(longestSubstring.end(), LeadChar.begin(), LeadChar.end());
					}
				}
			}
		}
	}
	for (vector<char>::iterator it = longestSubstring.begin(); it != longestSubstring.end(); ++it)
		result += *it;

	return result;
}

