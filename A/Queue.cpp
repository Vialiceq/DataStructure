#include <iostream>
using namespace std;
#define Maxsize 50

typedef int ElemType;
typedef struct Queue{
    ElemType data[Maxsize];
    int front,rear;
     

} SqQueue;


//round Queue

void Init_Queue(SqQueue &Q){
    Q.front=Q.rear=0;
}
//sacrafice a part of memory 
//(other two method is : 1. add 'Q.size' ?= Maxsize; 2: inQ then tag=1,while outQ tag=0)
bool isEmpty(SqQueue Q){

 if(Q.front==Q.rear) return false;

 else return true;
}

bool EnQueue(SqQueue &Q,ElemType x){

    if((Q.rear+1)%Maxsize==Q.front) return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%Maxsize;
}

bool DeQueue(SqQueue &Q,ElemType &x){

    if(Q.front==Q.rear) return false;
    x=Q.data[Q.front]; 
    Q.front=(Q.front+1)%Maxsize;
    return true;
}

int main(){

    bool y=0;
    SqQueue Q;
    int x;
    ElemType e=999;
    //initial Queue
    Init_Queue(Q);
    isEmpty(Q);
    //cout<<"is empty:??"<<y<<endl;   //used for test
    //build Queue
    for(int i=1;i<6;++i){

        EnQueue(Q,i);
        //test
        cout<<"data is:"<<i<<" Queue front is:"<<Q.front<<"   rear is:"<<Q.rear<<endl;
    }
    cout<<"enqueue successful!"<<endl;
   
    //Out Queue
    while(Q.front!=Q.rear){

        DeQueue(Q,e);
        cout<<"The OutQueue value:"<<e<<"  is in the order of:"<<Q.front<<endl;

    }

    cout<<"Congratulations! Queue operation is achieved~"<<endl;



    return 0;

}