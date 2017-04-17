#include "MyFrd.h"
#include "FrdAdder.h"
#include "FrdSearcher.h"

int main(void)
{
	welcome();

	while(true) {
	    char choice = '?';
	    choice = getChoice();
	    //cout << "DEBUG: choice is: " << choice << endl;
	    switch (choice) {
	        case '1':
	            // add
                cout << "\n1: 增加一个朋友" << endl;
	            FrdAdder adder;
	            adder.addFrd();
	            break;
	        case '2':
	            // search
                cout << "\n2: 查找一个朋友" << endl;
                FrdSearcher searcher;
                searcher.searchFrd(0);
	            break;
	        case '3':
	            // print all
                cout << "\n3: 查看所有朋友" << endl;
                FrdSearcher printer;
                printer.searchFrd(1);
	            break;
	        case '?':
	        	welcome();
	        	break;
	        case 'q':
	        	cout << "退出程序..." << endl;
	        	return 0;
	        default:
	        	cout << "只有 '1/2/3/?/q' 选项可用, 请重新输入选项." << endl;
	            break;
	    }
	}
    return 0;
}

void welcome() {
    cout << "\n\n==============================" << endl;
    cout << "欢迎 :)" << endl;
    cout << "\n------------------------------" << endl;
    cout << "1: 增加一个朋友" << endl;
    cout << "2: 查找一个朋友" << endl;
    cout << "3: 查看所有朋友" << endl;
    cout << "------------------------------\n" << endl;
    cout << "输入 '1/2/3' 来选择上面的选项." << endl;
    cout << "输入 '?' 查看这个帮助信息." << endl;
    cout << "输入 'q' 退出本程序'." << endl;
    cout << "==============================" << endl;
}

char getChoice() {
    cout << "\n你的选择是: ";
    char choice = '?';
    cin >> choice;
    return choice;
}
