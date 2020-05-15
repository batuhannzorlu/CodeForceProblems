
/*
QUESTION:
Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all n dragons that live on this level.
Kirito and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Kirito's strength equals s.

If Kirito starts duelling with the i-th (1 ≤ i ≤ n) dragon and Kirito's strength is not greater than the dragon's strength x i,
then Kirito loses the duel and dies. But if Kirito's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by y i.

Kirito can fight the dragons in any order. Determine whether he can move on to the next level of the game,
that is, defeat all dragons without a single loss.

Input
The first line contains two space-separated integers s and n (1 ≤ s ≤ 104, 1 ≤ n ≤ 103). 
Then n lines follow: the i-th line contains space-separated integers x i and y i (1 ≤ x i ≤ 104, 0 ≤ y i ≤ 104) — the i-th dragon's strength and the bonus for defeating it.

Output
On a single line print "YES" (without the quotes),
if Kirito can move on to the next level and print "NO" (without the quotes), if he can't.

EXP:             
İNPUT: 
2 2
1 99
100 0

OUTPUT:
YES
EXP2:

İNPUT:
10 1
100 100

OUTPUT:
NO


*/
#include <iostream>

using namespace std;

int partition(int[], int, int);
void swap(int*, int*);
void quickSort(int[], int, int);
void printArray(int[], int);
void findTotalDif(int[], int);
int StudentCount;
int TotalDif=0;

int main()
{
	cin >> StudentCount;

	int *arr = new int[StudentCount];
	for (int i = 0; i < StudentCount; i++)
		cin >> (arr[i]);

	quickSort(arr, 0, StudentCount - 1);
	findTotalDif(arr, StudentCount);
	
	cout << TotalDif;
	delete arr;
	return 0;
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i];
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];     
	int i = (low - 1);   

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void findTotalDif(int arr[],int size) {
	for (int i = 0; i < size - 1; i++) {
		TotalDif += arr[i + 1] - arr[i];
		i++;
	}
		
}