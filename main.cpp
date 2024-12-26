#include<iostream>
#include<string>
#include<vector>
#include"animal.h"

using namespace std;

//�ڽ�Ŭ���� 3�� ���� (Cat, Dog, Cow)
class Cat : public Animal 
{
public:
	void makeSound() {
		cout << "�̾߾ƾƿ�" << endl;
	}
	void moving() {
		cout << "��ӻ��" << endl;
	}
};

class Dog : public Animal
{

public:

	void makeSound() {
		cout << "�пп�" << endl;
	}
	void moving() {
		cout << "ŹŹŹ" << endl;
	}
};

class Cow : public Animal
{

public:

	void makeSound() {
		cout << "���޿���" << endl;
	}
	void moving() {
		cout << "����" << endl;
	}
};

//�������� Cat, Dog, Cow�� �ϳ��� �����Ҵ� �ѵ� Animal Ÿ������ ��ȯ (������ ����)
Animal* createRandomAnimal() {
	int R_n;

	R_n = rand() % 3; 

	switch (R_n) {
	case 0: return new Cat;
	case 1: return new Dog;
	case 2: return new Cow;
	}
}



class Zoo {
private:
	Animal** Home;			//�����Լ� Ŭ������ �����Ҵ��� �ȵǼ� ���������� ���.
							//Animal*Home�� AnimalŸ�Ե��� �����ϴ� Home �迭������
							//Animal**Home �� Animal*Ÿ���� �����ϴ� �迭
	int count = 0;
	int home_num;
public:
	Zoo(int N) {			//������. �����Ҵ�� �ּҰ��� �޾� �����߰� �Լ� ����
		home_num = N;		//N�� �ݺ��� ����
		Home = new Animal*[N]; //�����͸� �Ҵ�.

		for (int i = 0; i < home_num; i++) {
			addAnimal(createRandomAnimal());
			
		}
		performActions();	// ���� 10���� �� �ް� ��� �������� ��� ����.
	}

	void addAnimal(Animal* animal) { //�޴� Ÿ���� Animal������ ������ Cat, Dog, Cow �� �ϳ�. Animal���� ������ �����Լ��� ����
		if (count >= home_num) cout << "Over Flow" << endl; //N������ ��á�ٸ� �����÷ο� �߻�.
		else {				//������ ��������� ���� �߰�.
			this->Home[count] = animal;
			count++;
		}
	};

	void performActions() { //������ �ൿ ��� ����
		for (int j = 0; j < count; j++) {
			Home[j]->makeSound();
			Home[j]->moving();
		}
	};

	~Zoo() {				//���α׷� ����Ǹ� �����Ҵ�� ������� ������ ��� ��ȯ.
		for (int j = 0; j < count; j++) {
			delete Home[j]; //j���� Home������ ������ ����
		}
		delete[] Home;
	};
};







int main() {
	srand(time(NULL)); //���������� ��. �׳� ���� ������.
	int N;

	cout << "��� �������� ������" << endl;
	cin >> N;
	Zoo seoul(N);
	return 0;
}