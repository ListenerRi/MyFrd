#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "FrdSearcher.h"

using namespace std;

// 获取文件中的行数
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

// 将文件中的每一行转化为一个Friend对象
void  FrdSearcher::file2array(Friend * friends, int linec) {
    ifstream ifs;
    ifs.open("friends.dat", ios::in);
    // 用于暂存每一行的数据, 以便生成Friend对象
    char temp[50];
    linec = 0;
    // 依次读取文件中的每一行
    while (ifs.getline(temp, 50)) {
        // 将每一行分割为适当的字符串
        // 并赋值给数组中的Friend对象
        char * token = strtok(temp, " ");
        // 切记!!c/c++中的c风格字符串不能直接使用'='赋值
        strcpy(friends[linec].name, token);
        token = strtok(NULL, " ");
        friends[linec].age = atoi(token);
        token = strtok(NULL, " ");
        strcpy(friends[linec].phone, token);
        // cout << "DEBUG: " << friends[index].name << " " << friends[index].age << " " << friends[index].phone << endl;
        linec++;
    }
    // cout << "DEBUG: 向friends数组中添加了:" << index << "个元素" << endl;
}

// 获取搜索关键字
void FrdSearcher::setKey(char * keyword) {
    cout << "请输入要查找的朋友姓名关键字: ";
    cin >> keyword;
}

// 输出朋友信息
void FrdSearcher::printFrds(Friend * friends, int linec) {
    cout << "##########################" << endl;
    cout << "姓名" << "\t" << "年龄" << "\t" << "电话" << endl;
    for (int i = 0; i < linec; ++i) {
        cout << friends[i].name << "\t";
        cout << friends[i].age << "\t";
        cout << friends[i].phone << endl;
    }
}

// 如果flag为1则打印所有
// 否则如果flag为0通过关键字搜索
int FrdSearcher::searchFrd(int flag) {
    int linec = getLineCount();
    // cout << "DEBUG: linec is: " << linec << endl;

    // 用于存放代表每行数据的数组
    Friend * friends = new Friend[linec];
    file2array(friends, linec);

    // 打印所有朋友
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
            cout << "找到如下朋友:" << endl;
            printFrds(frdsMatched, indexOfMatched);
        }
        else {
            cout << "没有找到符合条件的朋友.." << endl;
        }
        delete [] frdsMatched;
    }
    delete [] friends;
    return 0;
}
