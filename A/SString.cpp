#include <iostream>
using namespace std;
#define MAXSIZE 25

//
typedef struct SString{

    char ch[MAXSIZE];
    int length;

}SString;




typedef struct HString{

    char *ch;
    int leng;
}HString;

int main(){

    HString s;
    s.ch=(char*)malloc(MAXSIZE*sizeof(char));
 
    return 0;
}

