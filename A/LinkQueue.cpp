#include <iostream>
using namespace std;
#define Maxsize 50

typedef int ElemType;

//linkQueue
typedef struct LinkNode{

    ElemType data;
    struct LinkNode* next; 
} LinkNode;

typedef struct LinkQueue{
    LinkNode *front,*rear;
}LinkQueue;

//Head
void Init_LQueue(LinkQueue &Q){

Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
Q.front->next=NULL;

}

void testlq(){
    LinkQueue Q;
    Init_LQueue(Q);
    cout<<"initial finished"<<endl;

}

bool isEmpty(LinkQueue Q){

    if(Q.front==Q.rear) 
        return true;
    else 
        return false;
}

void EnQueue(LinkQueue &Q, ElemType x){

    LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}

bool DeQueue(LinkQueue &Q, ElemType &x){

    if(Q.front==Q.rear) return false;
    LinkNode *p=Q.front->next;
    
    x=p->data;
    Q.front->next=p->next;
    if(p==Q.rear) Q.rear=Q.front;
   
    free(p);
    return true;
} 
//without heda

void Init_lqNoHead(LinkQueue &Q){
    //all point NULL to initial
    Q.front=NULL;
    Q.rear=NULL; 
}

bool EnQueueNH(LinkQueue &Q,ElemType x){

    LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=x;
        s->next=NULL;
    if(Q.rear==NULL) {
        
        Q.front=s;
        Q.rear=s;
        return true;
    }
 
    Q.rear->next=s;
    Q.rear=s;
    return true;

}

bool DeQueueNH(LinkQueue &Q, ElemType &x){

    if(Q.front==NULL) return false;
    LinkNode*p=Q.front;
    x=Q.front->data;
        
    if(Q.front==Q.rear) {
        
        Q.front=Q.rear=NULL;
      
    }
    else    Q.front=p->next;

    free(p);
    return true;


}

int main(){

    //testlq();

    
    LinkQueue q1,q2;
    ElemType x,y,z;
    //Head
    /*Init_LQueue(q1);
    cout<<isEmpty(q1)<<endl;

    for(int i=1;i<6;++i){

        EnQueue(q1,i);
        cout<<"Queue rear value:"<<q1.rear->data<<" in order of "<<i<<endl;


    }
    cout<<"enQueue finished"<<endl;

    while(q1.front!=q1.rear){

        DeQueue(q1,y);
        cout<<"Out Queue Value is:"<<y<<endl;
        cout<<isEmpty(q1)<<endl;
    }
    cout<<"Congratulations! LinkQueue q1 operation is achieved~"<<endl;
    */
    Init_lqNoHead(q2);
    for(int i=1;i<6;++i){

        EnQueueNH(q2,i);
        cout<<"EnQueue rear value:"<<q2.rear->data<<" in order of "<<i<<endl;


    }
    cout<<"enQueue q2 finished"<<endl;

    while(q2.front!=NULL){

        DeQueueNH(q2,z);
        cout<<"Out Queue Value is:"<<z<<endl;
        cout<<"q2 front: "<<q2.front->data<<endl;
    }
    cout<<"Congratulations! LinkQueue q2 operation is achieved~"<<endl;

    return 0;

}