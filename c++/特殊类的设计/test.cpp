#include<iostream>
#include<string>


////���һ�������࣬���ܱ�����
//class Student
//{
//public:
//	Student(std::string name, int age)
//	{
//		_name = name;
//		_age = age;
//	}
//
//	
//	void Print()
//	{
//		std::cout << "name:" << _name << std::endl;
//		std::cout << "age:" << _age << std::endl;
//	}
//private:
//	Student(const Student& s) = default;
//	Student& operator=(const Student&) = default;
//
//	std::string _name;
//	int _age;
//};
//
//
//
//int main()
//{
//	Student s1("anzhiyong", 21);
//	Student s2(s1);
//	Student s3 = s2;
//	s3.Print();
//
//	return 0;
//}

//����һ���ֻ࣬���ڶ��ϴ�������

//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly;
//	}
//private:
//	//�ѹ��캯��˽�л�
//	HeapOnly() {};
//
//	//���ÿ�������
//	HeapOnly(const HeapOnly&) = delete;
//
//};


//�����һ���ֻ࣬����ջ�ϴ�������
//����һ��ͬ�Ͻ����캯��˽�л���Ȼ����ƾ�̬�����������󷵻ؼ��ɡ�
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//	// ����operator new���԰�������new ���ÿ�������������������
//	// StackOnly obj = StackOnly::CreateObj();
//	// StackOnly* ptr3 = new StackOnly(obj);
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//private:
//	StackOnly()
//		:_a(0)
//	{}
//private:
//	int _a;
//};



//�����һ���࣬���ܱ��̳�
//C++11����
//final�ؼ��֣�final�����࣬��ʾ���಻�ܱ��̳С�

//class A final
//{
//	// ....
//};