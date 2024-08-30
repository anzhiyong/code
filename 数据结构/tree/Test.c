#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"

//int main()
//{
//	int a[] = { 60,70,65,50,32,100 };
//	//堆排序
//	HeapSort(a, 6);
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", a[i]);
//	}
//
//
//	/*Heap hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
//	{
//		HeapPush(&hp, a[i]);
//	}*/
//	//printf("%d\n", HeapTop(&hp));
//	//printf("%d\n", HeapSize(&hp));
//	/*int i;
//	while(!HeapEmpty(&hp))
//	{
//		HeapPop(&hp);
//		printf("%d\n", HeapTop(&hp));
//
//	}*/
//	
//	//HeapDestory(&hp);
//
//	return 0;
//}


void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "D:\\Code\\legend\\tree\\data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}



//int main()
//{
//	
//	PrintTopK();
//	//TopK();
//	return 0;
//}


//二叉树的实现————链式结构
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc:fail");
		return -1;
	}
	node->val = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;

}


// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return 0;
	}
	printf("%d ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return 0;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->val);
	BinaryTreeInOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return 0;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->val);
}


// 二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->val == x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

// 二叉树第k层节点个数
int TreeKLevel(BTNode* root, int k)
{
	assert(k > 0);

	if (NULL == root)
		return 0;

	if (k == 1)
		return 1;

	// 不等于空，且k > 1说明第k层的节点在子树里面，转换成子问题求解
	return TreeKLevel(root->left, k - 1)
		+ TreeKLevel(root->right, k - 1);
}

// 二叉树节点个数
int size = 0;
int TreeSize(BTNode* root)
{
	/*if (root == NULL)
		return 0;
	else
		size++;

	TreeSize(root->left);
	TreeSize(root->right);
	return size;*/

	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}

//二叉树高度
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int h1 = TreeHeight(root->left);
	int h2 = TreeHeight(root->right);
	return h1 > h2 ? h1 + 1 : h2 + 1;
}
int main()
{
	BTNode* tree = BinaryTreeCreate();
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	printf("二叉树节点个数：%d\n", TreeSize(tree));
	printf("二叉树高度：%d\n", TreeHeight(tree));
	return 0;
}