#include<iostream>
using namespace std;


//class animals
//{
//public:
//	virtual void sound() const = 0;
//	
//private:
//	const string name;
//};
//
//class cat :public animals
//{
//	void sound() const
//	{
//		cout << "喵喵" << endl;
//	}
//};
//
//class dog :public animals
//{
//	void sound() const
//	{
//		cout << "汪汪" << endl;
//	}
//};
//
//void sound(animals& a)
//{
//	a.sound();
//}
//
//int main()
//{
//	cat c;
//	dog d;
//	sound(c);
//	sound(d);
//	return 0;
//}


//虚函数重写的两个例外
//1.协变

//class A {};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() { return new A; }
//};
//class Student : public Person {
//public:
//	virtual B* f() { return new B; }
//};
//
//
////2析构函数的重写(基类与派生类析构函数的名字不同)
//
//
//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}


//1. final：修饰虚函数，表示该虚函数不能再被重写
//class car
//{
//	virtual void dirve() final;
//	
//};
//
//class benz :public car
//{
//	virtual void dirve() //由于父类中的虚函数dirve被final修饰，所以无法被继承
//	{
//		cout << "奔驰" << endl;
//	}
//};


//抽象类：虚函数后加 =0，表示为纯虚函数，包含纯虚函数的类叫做抽象类，也叫接口
//抽象类不能被实例化为对象
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}

//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	return 0;
//}


//class A
//
//{
//
//public:
//
//	virtual void f()
//
//	{
//
//		cout << "A::f()" << endl;
//
//	}
//
//};
//
//
//
//class B : public A
//
//{
//
//private:
//
//	virtual void f()
//
//	{
//
//		cout << "B::f()" << endl;
//
//	}
//
//};
//
//int main()
//{
//	A* pa = (A*)new B;
//
//	pa->f();
//	return 0;
//}


class A
{
public:
  A() 
  :m_iVal(0) 
  { 
      test(); 
  }
  virtual void func() { std::cout << m_iVal << ' '; }

  void test() { func(); }

public:

  int m_iVal;

};



class B : public A
{
public:
    B() { test(); }
    virtual void func()
    {
        ++m_iVal;
        std::cout << m_iVal << ' ';
    }
};



int main(int argc, char* argv[])

{

    A* p = new B;

    p->test();

    return 0;

}