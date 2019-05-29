#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Osoba {
private:
	string name;
	double money;
public:
	Osoba(string n, double m);
	string GetName();
	double GetMoney();
	double lose(double x);


};

double Osoba::lose(double x) {
	this->money -= x;
	return money;
}

Osoba::Osoba(string n, double m) {
	this->name = n;
	this->money = 0;
	this->money = m;
}

string Osoba::GetName() {
	return this->name;
}

double Osoba::GetMoney() {
	return this->money;
}




class Faktura {
private:
	Osoba **persons;
	int count;
public:
	Faktura(int n);
	~Faktura();
	Osoba *CreatePerson(string n, double m);
	Osoba *SearchPerson(string n);
	int Count(int count);
};

Faktura::Faktura(int n) {
	this->persons = new Osoba*[n];
	this->count = 0;
}

Faktura::~Faktura() {
	for (int i = 0; i < this->count; i++) {
		delete this->persons[i];
	}
}

Osoba* Faktura::CreatePerson(string n, double m) {
	Osoba *newPerson = new Osoba(n, m);
	this->persons[this->count] = newPerson;
	this->count += 1;
	return newPerson;
}

Osoba* Faktura::SearchPerson(string n) {
	for (int i = 0; i < this->count; i++) {
		if (this->persons[i]->GetName() == n) {
			return this->persons[i];
		}
		delete[]persons;
	}
	return nullptr;
}

int Faktura::Count(int count) {
	return this->count;
}





int main() {
	int N = 3;
	Faktura *faktury = new Faktura(N);
	string a;
	double b;
	string a2;
	/**
	vector <string> a1;

	for (int i = 0; i < N; i++) {
		cout << "Zadajte meno" << endl;
		getline(cin, a2);
		a1.push_back(a2);
		faktury->CreatePerson(a1[i], 500);
	}
	*/
	
	faktury->CreatePerson("Janko", 500);
	faktury->CreatePerson("Ferko", 500);
	faktury->CreatePerson("Miso", 500);



	cout << "Zadajte meno pozadovanej osoby:" << endl;
	getline(cin, a);
	cout << "Penazny vklad do faktury:" << endl;
	cin >> b;
	
	faktury->SearchPerson(a)->lose(b);

	cout << "Aktualny dlh na fakture: " << faktury->SearchPerson(a)->GetMoney() << endl;


	system("pause");
	return 0;
}