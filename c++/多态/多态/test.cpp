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
//		cout << "����" << endl;
//	}
//};
//
//class dog :public animals
//{
//	void sound() const
//	{
//		cout << "����" << endl;
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


//�麯����д����������
//1.Э��

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
////2������������д(�������������������������ֲ�ͬ)
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


//1. final�������麯������ʾ���麯�������ٱ���д
//class car
//{
//	virtual void dirve() final;
//	
//};
//
//class benz :public car
//{
//	virtual void dirve() //���ڸ����е��麯��dirve��final���Σ������޷����̳�
//	{
//		cout << "����" << endl;
//	}
//};


//�����ࣺ�麯����� =0����ʾΪ���麯�����������麯��������������࣬Ҳ�нӿ�
//�����಻�ܱ�ʵ����Ϊ����
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
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
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