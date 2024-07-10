#include<iostream>
using namespace std;
#include<string>

//class Person
//{
//public:
//
//	Person(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//
//	void print()
//	{
//		cout << "name:" << name << endl;
//		cout << "age:" << age << endl;
//	}
//
//protected:
//	string name;
//	int age;
//};
//
//class Student : public Person
//{
//public:
//	Student(string name,int age,int id)
//		:Person(name,age)
//		,id(id)
//	{
//
//	}
//protected:
//	int id;//学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int id;//工号
//};
//
//int main()
//{
//	Student s("an",20,1234);
//	s.print();
//
//	/*Teacher t;
//	t.print();*/
//
//	return 0;
//}



//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex;  // 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void Test()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	//2.基类对象不能赋值给派生类对象
//	//sobj = pobj;
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	//pp = &sobj;
//	//Student * ps1 = (Student*)pp; // 这种情况转换时可以的。
//	//ps1->_No = 10;
//
//	//pp = &pobj;
//	//Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	//ps2->_No = 10;
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}


class Person
{
public:
    Person(const char* name = "peter")
        : _name(name)
    {
        cout << "Person()" << endl;
    }

    Person(const Person& p)
        : _name(p._name)
    {
            cout << "Person(const Person& p)" << endl;
    }

    Person& operator=(const Person& p)
    {
        cout << "Person operator=(const Person& p)" << endl;
        if (this != &p)
            _name = p._name;

        return *this;
    }

    ~Person()
    {
        cout << "~Person()" << endl;
    }
protected:
    string _name; // 姓名
};
class Student : public Person
{
public:
    Student(const char* name, int num)
        : Person(name)
        , _num(num)
    {
        cout << "Student()" << endl;
    }

    Student(const Student& s)
        : Person(s)
        , _num(s._num)
    {
        cout << "Student(const Student& s)" << endl;
    }

    Student& operator = (const Student& s)
    {
        cout << "Student& operator= (const Student& s)" << endl;
        if (this != &s)
        {
            Person::operator =(s);
            _num = s._num;
        }
        return *this;
    }

    ~Student()
    {
        cout << "~Student()" << endl;
    }
protected:
    int _num; //学号
};
void Test()
{
    Student s1("jack", 18);
    Student s2(s1);
    Student s3("rose", 17);
    s1 = s3;
}

int main()
{
    Test();

    return 0;
}

//友元关系不能继承，也就是说基类友元不能访问子类私有和保护成员

//基类定义了static静态成员，则整个继承体系里面只有一个这样的成员。无论派生出多少个子
//类，都只有一个static成员实例 。


// Car和BMW Car和Benz构成is-a的关系
//class Car {
//protected:
//    string _colour = "白色"; // 颜色
//    string _num = "陕ABIT00"; // 车牌号
//};
//
//class BMW : public Car {
//public:
//    void Drive() { cout << "好开-操控" << endl; }
//};
//
//class Benz : public Car {
//public:
//    void Drive() { cout << "好坐-舒适" << endl; }
//};

// Tire和Car构成has-a的关系

class Tire {
protected:
    string _brand = "Michelin";  // 品牌
    size_t _size = 17;         // 尺寸

};

class Car {
protected:
    string _colour = "白色"; // 颜色
    string _num = "陕ABIT00"; // 车牌号
    Tire _t; // 轮胎
};
