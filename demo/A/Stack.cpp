#include <iostream>
using namespace std;
#define Maxsize 50

typedef int ElemType;

// LinkStack data struct
typedef struct Linknode{

    ElemType data;
    struct Linknode *next;
} *LiStack;

//SqStack
typedef struct Sqstack{
    ElemType data[Maxsize];
    int top;
    /* data */
} Sqstack;

void Initial_Stack(Sqstack &S){

    S.top=-1;
}

bool Stack_Empty(Sqstack S){
    if(S.top==-1) return true;
    return false;
}

bool Push(Sqstack &S,ElemType e){
    if(S.top==Maxsize-1) return false;
    S.data[++S.top]=e ; return true;
}

bool Pop(Sqstack &S, ElemType &x){
    if(S.top==-1) return false;
    
    x=S.data[S.top--]; return true;
}

bool GetTop(Sqstack S, ElemType &x){
    if(S.top==-1) return false;
    x=S.data[S.top]; return true;
}

int main(){

        ElemType x,t;

        Sqstack s1;
        bool q;
        Initial_Stack(s1); //initial stack
       
        Stack_Empty(s1);
        //cout<<"is the stack empty ?"<<q<<endl; //can be used for test

        for(int i=1;i<6;++i){    //into stack
        
        
        Push(s1,i+5);
        cout<<"The stack value:"<<s1.data[s1.top]<<"  is ranking:"<<i<<endl;
        }
        cout<<"Elem transfer to Stack over"<<endl;

       

        GetTop(s1,t);   //get top elem
        cout<<"the top value is:"<<t<<endl;

        while(s1.top!=-1){    //out stack

            Pop(s1,x);
            cout<<"the value:"<<x<<endl;
        }
        cout<<"Congratulations ! The values, which is LIFO, end "<<endl;   //over

    return 0;

    
}