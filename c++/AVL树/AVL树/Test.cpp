#include "AVLTree.h"

int main()
{
	AVLTree<int,int> a1;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : a)
	{
		a1.Insert({ e,e });
	}

	a1.InOrder();
	cout << a1.IsBalanceTree() << endl;

	return 0;
}



