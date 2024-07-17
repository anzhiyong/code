#include"BinarySearchTree.h"

int main()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };


	BSTree<int> b1;
	for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); i++)
	{
		b1.Insert(a[i]);
	}
	b1.InOrder();
	b1.Erase(14);
	b1.InOrder();

	return 0;
}