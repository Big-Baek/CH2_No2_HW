#include "animal.h"
#include<iostream>
#include <string>

using namespace std;

void Animal::set_name(string name)
{
	this->name = name;
}

void Animal::set_howl(string mhowl)
{
	this->howl = mhowl;
}

void Animal::moving()
{
	cout << "��ĩ ��ĩ" << endl;
}

void Animal::makeSound()
{
	cout << "������" << endl;
}



