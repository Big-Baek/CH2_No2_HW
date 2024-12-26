#include<iostream>
#include<string>
#include<vector>
#include"animal.h"

using namespace std;

//자식클래스 3개 생성 (Cat, Dog, Cow)
class Cat : public Animal 
{
public:
	void makeSound() {
		cout << "미야아아옹" << endl;
	}
	void moving() {
		cout << "사뿐사뿐" << endl;
	}
};

class Dog : public Animal
{

public:

	void makeSound() {
		cout << "왈왈왈" << endl;
	}
	void moving() {
		cout << "탁탁탁" << endl;
	}
};

class Cow : public Animal
{

public:

	void makeSound() {
		cout << "음메에에" << endl;
	}
	void moving() {
		cout << "쿵쿵" << endl;
	}
};

//랜덤으로 Cat, Dog, Cow중 하나를 동적할당 한뒤 Animal 타입으로 반환 (다형성 구현)
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
	Animal** Home;			//가상함수 클래스는 동적할당이 안되서 이중포인터 사용.
							//Animal*Home은 Animal타입들을 관리하는 Home 배열이지만
							//Animal**Home 은 Animal*타입을 관리하는 배열
	int count = 0;
	int home_num;
public:
	Zoo(int N) {			//생성자. 동적할당된 주소값을 받아 동물추가 함수 실행
		home_num = N;		//N번 반복할 예정
		Home = new Animal*[N]; //포인터를 할당.

		for (int i = 0; i < home_num; i++) {
			addAnimal(createRandomAnimal());
			
		}
		performActions();	// 동물 10마리 다 받고 모든 동물들의 기능 실행.
	}

	void addAnimal(Animal* animal) { //받는 타입은 Animal이지만 실제는 Cat, Dog, Cow 중 하나. Animal에서 구현한 가상함수로 구분
		if (count >= home_num) cout << "Over Flow" << endl; //N마리가 다찼다면 오버플로우 발생.
		else {				//사육장 비어있으면 동물 추가.
			this->Home[count] = animal;
			count++;
		}
	};

	void performActions() { //동물들 행동 모두 실행
		for (int j = 0; j < count; j++) {
			Home[j]->makeSound();
			Home[j]->moving();
		}
	};

	~Zoo() {				//프로그램 종료되면 동적할당된 사육장속 동물들 모두 반환.
		for (int j = 0; j < count; j++) {
			delete Home[j]; //j번의 Home이지만 내용은 동물
		}
		delete[] Home;
	};
};







int main() {
	srand(time(NULL)); //무슨뜻인지 모름. 그냥 흔히 쓰는중.
	int N;

	cout << "몇마리 받을건지 쓰세요" << endl;
	cin >> N;
	Zoo seoul(N);
	return 0;
}