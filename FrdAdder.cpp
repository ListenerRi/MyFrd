#include <iostream>
#include <fstream>
#include "FrdAdder.h"

using namespace std;

Friend FrdAdder::createFrd() {
    Friend frd;

	cout << "����: ";
	cin >> frd.name;
	cout << "����: ";
	cin >> frd.age;
	cout << "�绰: ";
	cin >> frd.phone;
    return frd;
}

int FrdAdder::addFrd() {
	Friend frd = createFrd();
	//cout << "DEBUG: " << frd.name << " " << frd.age << " " << frd.phone << endl;
    ofstream of;
    of.open("friends.dat", ios::out | ios::app);
	of << frd.name << " " << frd.age << " " << frd.phone << endl;
    cout << "��ӳɹ�!" << endl;
    of.close();
    return 0;
}
