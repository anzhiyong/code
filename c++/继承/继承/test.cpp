#include<iostream>
using namespace std;
#include<string>

class Person
{
public:

	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	void print()
	{
		cout << "name:" << name << endl;
		cout << "age:" << age << endl;
	}

protected:
	string name;
	int age;
};

class Student : public Person
{
public:
	Student(string name,int age,int id)
		:Person(name,age)
		,id(id)
	{

	}
protected:
	int id;//Ñ§ºÅ
};

class Teacher : public Person
{
protected:
	int id;//¹¤ºÅ
};

int main()
{
	Student s("an",20,1234);
	s.print();

	/*Teacher t;
	t.print();*/

	return 0;
}