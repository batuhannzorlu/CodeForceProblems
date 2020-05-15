/*

When Serezha was three years old, he was given a set of cards with letters for his birthday. They were arranged into words in the way which formed the boy's mother favorite number in binary notation.
Serezha started playing with them immediately and shuffled them because he wasn't yet able to read.
His father decided to rearrange them. Help him restore the original number, on condition that it was the maximum possible one.

Input
The first line contains a single integer n (1⩽n⩽105) — the length of the string.
The second line contains a string consisting of English lowercase letters: 'z', 'e', 'r', 'o' and 'n'.

It is guaranteed that it is possible to rearrange the letters in such a way that they form a sequence of words, each being either "zero" which corresponds to the digit 0 or "one" which corresponds to the digit 1.

Output
Print the maximum possible number in binary notation. Print binary digits separated by a space. The leading zeroes are allowed.
----------------------
EXP1:
INPUT:
4
ezor

OUTPUT:
0
-----------------------
EXP2:
INPUT:
10
nznooeeoer

OUTPUT:
1 1 0

*/

#include <iostream>
#include<list>
#include<string>
using namespace std;

void SortAndDivide(list<char>);

int main()
{

	int count;
	string UserInput;
	list<char> listedInput;
	cin >> count;	
	cin >> UserInput;
	for (int i = 0; i < count; i++)
		listedInput.push_front(UserInput[i]);

	SortAndDivide(listedInput);

}
void SortAndDivide(list<char>Input) {
	list<char>z;
	list<char>e;
	list<char>r;
	list<char>o;
	list<char>n;
	int MinOneCount=0;
	int MinZeroCount = 0;
	for (list<char>::iterator it = Input.begin(); it != Input.end(); it++)
	{
		if (*it == 'o')
			o.push_back(*it);
		if (*it == 'n')
			n.push_back(*it);
		if (*it == 'e')
			e.push_back(*it);
		if (*it == 'r')
			r.push_back(*it);
		if (*it == 'z')
			z.push_back(*it);
	}
	MinOneCount = _Min_value(_Min_value(o.size(), n.size()), e.size());
	for (int i = 0; i < MinOneCount; i++)
	{
		o.pop_front();
		n.pop_front();
		e.pop_front();
	}
	MinZeroCount =_Min_value(_Min_value(_Min_value(z.size(), e.size()), r.size()), o.size());
	for (int i = 1; i <= MinOneCount+MinZeroCount; i++)
	{
		if (i<=MinOneCount)
			cout << " 1 ";

		else
			cout << " 0 ";
	}


}





