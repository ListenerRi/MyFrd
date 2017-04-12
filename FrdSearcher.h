#include "Friend.h"

class FrdSearcher {
    public:
        int getLineCount();
        void file2array(Friend * friends, int linec);
        void setKey(char * keyword);
    	int searchFrd(int flag);
        void printFrds(Friend * friends, int linec);
};
