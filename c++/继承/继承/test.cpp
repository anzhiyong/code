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
//	int id;//ѧ��
//};
//
//class Teacher : public Person
//{
//protected:
//	int id;//����
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
//	string _name; // ����
//	string _sex;  // �Ա�
//	int _age; // ����
//};
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//void Test()
//{
//	Student sobj;
//	// 1.���������Ը�ֵ���������/ָ��/����
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	//2.��������ܸ�ֵ�����������
//	//sobj = pobj;
//
//	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//	//pp = &sobj;
//	//Student * ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//	//ps1->_No = 10;
//
//	//pp = &pobj;
//	//Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
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
    string _name; // ����
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
    int _num; //ѧ��
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

//��Ԫ��ϵ���ܼ̳У�Ҳ����˵������Ԫ���ܷ�������˽�кͱ�����Ա

//���ඨ����static��̬��Ա���������̳���ϵ����ֻ��һ�������ĳ�Ա���������������ٸ���
//�࣬��ֻ��һ��static��Աʵ�� ��


// Car��BMW Car��Benz����is-a�Ĺ�ϵ
//class Car {
//protected:
//    string _colour = "��ɫ"; // ��ɫ
//    string _num = "��ABIT00"; // ���ƺ�
//};
//
//class BMW : public Car {
//public:
//    void Drive() { cout << "�ÿ�-�ٿ�" << endl; }
//};
//
//class Benz : public Car {
//public:
//    void Drive() { cout << "����-����" << endl; }
//};

// Tire��Car����has-a�Ĺ�ϵ

class Tire {
protected:
    string _brand = "Michelin";  // Ʒ��
    size_t _size = 17;         // �ߴ�

};

class Car {
protected:
    string _colour = "��ɫ"; // ��ɫ
    string _num = "��ABIT00"; // ���ƺ�
    Tire _t; // ��̥
};
