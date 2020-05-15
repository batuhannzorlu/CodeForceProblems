/*

Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all n dragons that live on this level.
Kirito and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Kirito's strength equals s.

If Kirito starts duelling with the i-th (1 ≤ i ≤ n) dragon and Kirito's strength is not greater than the dragon's strength x i,
then Kirito loses the duel and dies. But if Kirito's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by y i.

Kirito can fight the dragons in any order.
Determine whether he can move on to the next level of the game, that is, defeat all dragons without a single loss.

Input
The first line contains two space-separated integers s and n (1 ≤ s ≤ 104, 1 ≤ n ≤ 103). 
Then n lines follow: the i-th line contains space-separated integers x i and y i (1 ≤ x i ≤ 104, 0 ≤ y i ≤ 104) — the i-th dragon's strength and the bonus for defeating it.

Output
On a single line print "YES" (without the quotes), if Kirito can move on to the next level and print "NO" (without the quotes), if he can't.
---------------------------------------
EXP1:
INPUT:
2 2
1 99
100 0

OUTPUT:
YES
----------------------------------------
EXP2:
INPUT:

10 1
100 100

OUTPUT:
NO

*/

#include <iostream>
#include<queue>

using namespace std;

int PlayerStr;
int NumOfDragons;
struct DragonInfo
{
	int DragonPoint;
	int DragonStrenght;
};
struct BatZNode
{
	DragonInfo data;
	BatZNode*right;
	BatZNode*left;
};

bool IsPlayerMoveToNextLevel(int&, const int);
BatZNode* insert(BatZNode*, DragonInfo);
void Inorder(BatZNode*root, queue<DragonInfo>&);
int main()
{
	cin >> PlayerStr >> NumOfDragons;
	IsPlayerMoveToNextLevel(PlayerStr, NumOfDragons) ? cout << "YES" : cout << "NO";
}
BatZNode* FindMin(BatZNode*root) {
	while (root->left != NULL) root = root->left;
	return root;
}
BatZNode* insert(BatZNode*root, DragonInfo data) {

	if (root == NULL)
	{
		BatZNode* newNode = new BatZNode;
		newNode->data = data;
		newNode->left = newNode->right = NULL;
		root = newNode;
	}
	else if (data.DragonStrenght <= root->data.DragonStrenght)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);

	return root;
}
void Inorder(BatZNode*root, queue<DragonInfo> &DragonInfoQ) {
	if (root == NULL) return;

	Inorder(root->left, DragonInfoQ);
	if (root->data.DragonPoint != -1)
		DragonInfoQ.push(root->data);
	Inorder(root->right, DragonInfoQ);
}
bool IsPlayerMoveToNextLevel(int& playerstr, const int numofdragons) {
	BatZNode* root = NULL;

	/*
	DEFINING PLAYER AS A ROOT OF THE DRAGONINFO TREE!
	*/
	DragonInfo info;
	info.DragonStrenght = playerstr;
	info.DragonPoint = -1;
	root = insert(root, info);

	int dragonstr = 0;
	int dragonpoint = 0;


	for (int i = 0; i < numofdragons; i++)
	{
		cin >> dragonstr >> dragonpoint;
		info.DragonPoint = dragonpoint;
		info.DragonStrenght = dragonstr;
		root = insert(root, info);
	}
	queue<DragonInfo>DragonInfoQ;
	Inorder(root, DragonInfoQ);

	for (int i = 0; i < numofdragons; i++)
	{
		DragonInfo Di = DragonInfoQ.front();
		if (playerstr > Di.DragonStrenght)
			playerstr += Di.DragonPoint;
		else
			return false;
		DragonInfoQ.pop();
	}
	return true;
}

