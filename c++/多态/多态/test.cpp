#include<iostream>
using namespace std;


class animals
{
public:
	virtual void sound() const = 0;
	
private:
	const string name;
};

class cat :public animals
{
	void sound() const
	{
		cout << "����" << endl;
	}
};

class dog :public animals
{
	void sound() const
	{
		cout << "����" << endl;
	}
};

void sound(animals& a)
{
	a.sound();
}

int main()
{
	cat c;
	dog d;
	sound(c);
	sound(d);
	return 0;
}