#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Adress {
public:
	Adress(string city, string street, int number_house, int number_apartament)
		: city(city), street(street), number_house(number_house), number_apartament(number_apartament) {}

	string get_output() {
		return city + ", " + street + ", " + to_string(number_house) + ", " + to_string(number_apartament);
	}

private:
	string city;
	string street;
	int number_house;
	int number_apartament;
};

int main() {
	setlocale(LC_ALL, "rus");
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int n;
	fin >> n;

	vector<Adress> addresses;
	for (int i = 0; i < n; ++i) {
		string city, street;
		int number_house, number_apartament;

		fin >> city;
		fin >> street;
		fin >> number_house;
		fin >> number_apartament;
		addresses.emplace_back(city, street, number_house, number_apartament);
	}
	fout << n << endl;
	for (int i = n - 1; i >= 0; --i) {
		fout << addresses[i].get_output() << endl;
	}

	fin.close();
	fout.close();
}