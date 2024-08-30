#include<iostream>
#include<string>


////设计一个特殊类，不能被拷贝
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

//设置一个类，只能在堆上创建对象

//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly;
//	}
//private:
//	//把构造函数私有化
//	HeapOnly() {};
//
//	//禁用拷贝构造
//	HeapOnly(const HeapOnly&) = delete;
//
//};


//请设计一个类，只能在栈上创建对象
//方法一：同上将构造函数私有化，然后设计静态方法创建对象返回即可。
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//	// 禁掉operator new可以把下面用new 调用拷贝构造申请对象给禁掉
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



//请设计一个类，不能被继承
//C++11方法
//final关键字，final修饰类，表示该类不能被继承。

//class A final
//{
//	// ....
//};