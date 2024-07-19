#include"BinarySearchTree.h"


void TestBSTree3()
{
	// 输入单词，查找单词对应的中文翻译
	keyValue::BSTree<string, string> dict;
	dict.Insert("string", "字符串");
	dict.Insert("tree", "树");
	dict.Insert("left", "左边、剩余");
	dict.Insert("right", "右边");
	dict.Insert("sort", "排序");
	
	// 插入词库中所有单词
	string str;
	while (cin >> str)
	{
		keyValue::BSTNode<string, string>* ret = dict.Find(str);
		if (ret == nullptr)
		{
			cout << "单词拼写错误，词库中没有这个单词:" << str << endl;
		}
		else
		{
			cout << str << "中文翻译:" << ret->_value << endl;
		}
	}
}

void TestBSTree4()
{
	// 统计水果出现的次数
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
   "苹果", "香蕉", "苹果", "香蕉" };
	keyValue::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// 先查找水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		// 2、在，则查找到的节点中水果对应的次数++
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}


//int main()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//
//
//	/*keyValue::BSTree<string,string> b1;
//	b1.Insert("苹果", "apple");
//	b1.Insert("香蕉", "banana");
//	b1.Insert("树", "tree");
//	b1.Insert("左边", "left");
//	b1.Insert("右边", "right");
//	b1.InOrder();*/
//	/*for (size_t i = 0; i < sizeof(a)/sizeof(a[0]); i++)
//	{
//		b1.Insert(a[i]);
//	}
//	b1.InOrder();
//	b1.Erase(14);
//	b1.InOrder();*/
//
//	return 0;
//}

int main()
{

	//TestBSTree4();
	TestBSTree3();
	return 0;
}