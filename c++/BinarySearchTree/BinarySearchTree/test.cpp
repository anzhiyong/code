#include"BinarySearchTree.h"


void TestBSTree3()
{
	// ���뵥�ʣ����ҵ��ʶ�Ӧ�����ķ���
	keyValue::BSTree<string, string> dict;
	dict.Insert("string", "�ַ���");
	dict.Insert("tree", "��");
	dict.Insert("left", "��ߡ�ʣ��");
	dict.Insert("right", "�ұ�");
	dict.Insert("sort", "����");
	
	// ����ʿ������е���
	string str;
	while (cin >> str)
	{
		keyValue::BSTNode<string, string>* ret = dict.Find(str);
		if (ret == nullptr)
		{
			cout << "����ƴд���󣬴ʿ���û���������:" << str << endl;
		}
		else
		{
			cout << str << "���ķ���:" << ret->_value << endl;
		}
	}
}

void TestBSTree4()
{
	// ͳ��ˮ�����ֵĴ���
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
   "ƻ��", "�㽶", "ƻ��", "�㽶" };
	keyValue::BSTree<string, int> countTree;
	for (const auto& str : arr)
	{
		// �Ȳ���ˮ���ڲ�����������
		// 1�����ڣ�˵��ˮ����һ�γ��֣������<ˮ��, 1>
		// 2���ڣ�����ҵ��Ľڵ���ˮ����Ӧ�Ĵ���++
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
//	b1.Insert("ƻ��", "apple");
//	b1.Insert("�㽶", "banana");
//	b1.Insert("��", "tree");
//	b1.Insert("���", "left");
//	b1.Insert("�ұ�", "right");
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