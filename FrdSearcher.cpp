#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "FrdSearcher.h"

using namespace std;

// ��ȡ�ļ��е�����
int FrdSearcher::getLineCount() {
    ifstream ifs;
    ifs.open("friends.dat", ios::in);
    char temp[50];
    int line = 0;
    while (ifs.getline(temp, 50)) {
        line++;
    }
    ifs.close();
    return line;
}

// ���ļ��е�ÿһ��ת��Ϊһ��Friend����
void  FrdSearcher::file2array(Friend * friends, int linec) {
    ifstream ifs;
    ifs.open("friends.dat", ios::in);
    // �����ݴ�ÿһ�е�����, �Ա�����Friend����
    char temp[50];
    linec = 0;
    // ���ζ�ȡ�ļ��е�ÿһ��
    while (ifs.getline(temp, 50)) {
        // ��ÿһ�зָ�Ϊ�ʵ����ַ���
        // ����ֵ�������е�Friend����
        char * token = strtok(temp, " ");
        // �м�!!c/c++�е�c����ַ�������ֱ��ʹ��'='��ֵ
        strcpy(friends[linec].name, token);
        token = strtok(NULL, " ");
        friends[linec].age = atoi(token);
        token = strtok(NULL, " ");
        strcpy(friends[linec].phone, token);
        // cout << "DEBUG: " << friends[index].name << " " << friends[index].age << " " << friends[index].phone << endl;
        linec++;
    }
    // cout << "DEBUG: ��friends�����������:" << index << "��Ԫ��" << endl;
}

// ��ȡ�����ؼ���
void FrdSearcher::setKey(char * keyword) {
    cout << "������Ҫ���ҵ����������ؼ���: ";
    cin >> keyword;
}

// ���������Ϣ
void FrdSearcher::printFrds(Friend * friends, int linec) {
    cout << "##########################" << endl;
    cout << "����" << "\t" << "����" << "\t" << "�绰" << endl;
    for (int i = 0; i < linec; ++i) {
        cout << friends[i].name << "\t";
        cout << friends[i].age << "\t";
        cout << friends[i].phone << endl;
    }
}

// ���flagΪ1���ӡ����
// �������flagΪ0ͨ���ؼ�������
int FrdSearcher::searchFrd(int flag) {
    int linec = getLineCount();
    // cout << "DEBUG: linec is: " << linec << endl;

    // ���ڴ�Ŵ���ÿ�����ݵ�����
    Friend * friends = new Friend[linec];
    file2array(friends, linec);

    // ��ӡ��������
    if (flag == 1) {
        printFrds(friends, linec);
    }
    else if (flag == 0) {
        char keyword[10];
        setKey(keyword);
        //cout << "DEBUG: keyword is: " << keyword << endl;
        Friend * frdsMatched = new Friend[linec];
        int indexOfMatched = 0;
        for (int i = 0; i < linec; ++i) {
            if(strcasestr(friends[i].name, keyword) != NULL) {
                frdsMatched[indexOfMatched] = friends[i];
                indexOfMatched++;
            }
        }
        if (indexOfMatched != 0) {
            cout << "�ҵ���������:" << endl;
            printFrds(frdsMatched, indexOfMatched);
        }
        else {
            cout << "û���ҵ���������������.." << endl;
        }
        delete [] frdsMatched;
    }
    delete [] friends;
    return 0;
}
