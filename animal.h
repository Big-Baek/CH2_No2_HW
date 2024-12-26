#pragma once
#include<iostream>
#include<string>

using namespace std;

class Animal
{
protected:
	string name;
	string howl;
	
	
public:
	void set_name(string n);
	void set_howl(string mhowl);
	virtual void moving();
	virtual void makeSound();
	 ~Animal() {
		cout << "¼Ò¸êÇÑ´Ù." << endl;
	 }
};

