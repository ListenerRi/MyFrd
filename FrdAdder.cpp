#include <iostream>
#include <fstream>
#include "FrdAdder.h"

using namespace std;

Friend FrdAdder::createFrd() {
    Friend frd;

	cout << "姓名: ";
	cin >> frd.name;
	cout << "年龄: ";
	cin >> frd.age;
	cout << "电话: ";
	cin >> frd.phone;
    return frd;
}

int FrdAdder::addFrd() {
	Friend frd = createFrd();
	//cout << "DEBUG: " << frd.name << " " << frd.age << " " << frd.phone << endl;
    ofstream of;
    of.open("friends.dat", ios::out | ios::app);
	of << frd.name << " " << frd.age << " " << frd.phone << endl;
    cout << "添加成功!" << endl;
    of.close();
    return 0;
}
