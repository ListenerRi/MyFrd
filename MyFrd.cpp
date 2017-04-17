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
                cout << "\n1: ����һ������" << endl;
	            FrdAdder adder;
	            adder.addFrd();
	            break;
	        case '2':
	            // search
                cout << "\n2: ����һ������" << endl;
                FrdSearcher searcher;
                searcher.searchFrd(0);
	            break;
	        case '3':
	            // print all
                cout << "\n3: �鿴��������" << endl;
                FrdSearcher printer;
                printer.searchFrd(1);
	            break;
	        case '?':
	        	welcome();
	        	break;
	        case 'q':
	        	cout << "�˳�����..." << endl;
	        	return 0;
	        default:
	        	cout << "ֻ�� '1/2/3/?/q' ѡ�����, ����������ѡ��." << endl;
	            break;
	    }
	}
    return 0;
}

void welcome() {
    cout << "\n\n==============================" << endl;
    cout << "��ӭ :)" << endl;
    cout << "\n------------------------------" << endl;
    cout << "1: ����һ������" << endl;
    cout << "2: ����һ������" << endl;
    cout << "3: �鿴��������" << endl;
    cout << "------------------------------\n" << endl;
    cout << "���� '1/2/3' ��ѡ�������ѡ��." << endl;
    cout << "���� '?' �鿴���������Ϣ." << endl;
    cout << "���� 'q' �˳�������'." << endl;
    cout << "==============================" << endl;
}

char getChoice() {
    cout << "\n���ѡ����: ";
    char choice = '?';
    cin >> choice;
    return choice;
}
