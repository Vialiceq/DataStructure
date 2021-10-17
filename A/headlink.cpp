#include <iostream>
using namespace std;

typedef int ElemType;
typedef struct Node{

    ElemType data;
    struct Node *next;
}LNode, *Linklist;



bool initList(Linklist& L){

L=(LNode *)malloc(sizeof(LNode)); //申请空间

if(L==NULL) return 0;  //判空，并置空

L->next=NULL;
return true;
}
void test(){

Linklist L;
initList(L);

}


//WITH HEAD
//1.Tail insert  can also be used for GetElem  (WITH HEAD)
bool Linklist_Insert(Linklist &L, int i, ElemType e){

    if(i<1) return false;

    Linklist p,s,r;
    int j=1;
     p=L;
     s=(LNode*)malloc(sizeof(LNode)); //insert elem
     s->data=e;

    //FIND i-1 node
    while(p&&j<i){     
         p=p->next;
         ++j;
    }
    
        s->next=p->next;
        p->next=s;  
        return true;
    
    /*
    while(){

        s=(LNode*)malloc(sizeof(LNode));
        s->data=e;

    }
    */
}

//2. GETElem
LNode* GetElem(Linklist L,int i){

    int j=1;
    Linklist p;

    if(i==0) return L ;
    if(i<1) return NULL;
    p=L->next;

    while(p&&j<i){

        p=p->next;
        j++;

    }
    
    return p;

}

LNode* LocateElem(Linklist L, ElemType e){

LNode *p =L->next;
while(p&&p->data!=e){

    p=p->next;

}

return p;

}
// 3.FROUNT INSERT
Linklist Front_Insert(Linklist &L){

    LNode* s; int x;
    //build linklist
    L=(LNode*)malloc(sizeof(LNode)); 
    L->next=NULL;

    cin>>x;
   
    while(x!=999){
        //build linklist
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        cout<<"wahat is your list:";
        cin>>x;
    }

    return L;

}
Linklist Tail_Insert(Linklist &L){

    LNode* s; int x,len=1;
    LNode* r;
    //build linklist
    L=(LNode*)malloc(sizeof(LNode)); 
    L->next=NULL;
    r=L;

    cin>>x;
   
    while(x!=999){
        //build linklist
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=NULL;
        r->next=s;
        r=r->next;
        cout<<"wahat is your list:";
        cin>>x;
        len++;
    }
    cout<<"all node is:"<<len<<endl;

    return L;

}

//double linklist
//delete
Linklist Delete_Node(Linklist &L,int i){

    LNode *q,*p;
    p=GetElem(L,i);
    q=p->next;
    p->next=q->next;
    free(q);

    return L;

}

int main(){

    //initial linklist
    Linklist L,q;
    initList(L);
    cout<<"Initial over"<<L->next<<endl;
    //Tail_Insert(L);
    Front_Insert(L);

       while(L->next){
        L=L->next;
        cout<<"Tailvalue:"<<L->data<<endl;

    }

    cout<<L->next<<endl;
    L->next=NULL;
    //Front_Insert(L);

    cout<<"input n numbers:"<<endl;
    int a;
    //cin>>n;
    for(a=1;a<5;a++){
        
        Linklist_Insert(L,a,a); //在第a个位置插入a
        cout<<a<<"ok"<<endl;

    }
    cout<<"over"<<endl;

  
    Linklist_Insert(L,3,80);  //insert 80 in No.3 Node
    cout<<L->data<<endl;
    //getEKEM
    if(q=GetElem(L,3))
        cout<<"the beldjs:"<<q->data<<endl;
    else cout<<"sorry notElem"<<endl;   
    //print L 
    while(L->next){
        L=L->next;
        cout<<"value:"<<L->data<<endl;

    }

    cout<<L->next<<endl;
    return 0;

}


