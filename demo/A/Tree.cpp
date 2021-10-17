#include <iostream>
using namespace std;
#define Maxsize 100

 typedef int ElemType;
//Sq storeage
struct TreeNode{
    ElemType value;
    bool isEmpty; 
};





//link style storage
typedef struct BiTNode{

    ElemType data;
    struct BiTNode *lchild,*rchild;

}BiTNode,*BiTree;

//visit value
void visit(BiTree T){

     cout<<"->"<<T->data;
    

}
//preOrder visist
void PreOrder(BiTree T){

    if (T!=NULL) {
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
    }
}

//InOrder visit
void InOrder(BiTree T){

    if(T){
    
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);

    }
}

//post order visit
void PostOrder(BiTree T){

    if(T){
    
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);

    }
}





int main(){
    
    int i,j;
    /*
    //SqTree
    TreeNode t[Maxsize];

    for(int i=0;i<16;++i){

        if(i!=15) t[i+1].value=i+1;
        t[i].isEmpty=false;
        //cout<<"elem to tree:"<<t[i+1].value<<endl;
    }
    
    for(i=1;i<16;++i){
        cout<<"tree elem is:"<<t[i].value<<endl;
    }
    cout<<"SqTree is completed~"<<endl;
    */
    //linkTree
    
    BiTree root=NULL;
    root=(BiTNode*)malloc(sizeof(BiTNode));
    root->data=1;
    root->lchild=NULL;
    root->rchild=NULL;
  

    BiTNode* p2=(BiTNode*)malloc(sizeof(BiTNode)); //insert 2 in left
    p2->data=2;
    p2->lchild=NULL;
    p2->rchild=NULL;
    root->lchild=p2; //root lchild

    BiTNode* p3=(BiTNode*)malloc(sizeof(BiTNode)); //insert 3 in R
    p3->data=3;
    p3->lchild=NULL;
    p3->rchild=NULL;
    root->rchild=p3; //root rchild

    BiTNode* p4=(BiTNode*)malloc(sizeof(BiTNode)); //insert 4 in R of 2
    p4->data=4;
    p4->lchild=NULL;
    p4->rchild=NULL;
    p2->rchild=p4; //p2 rchild

    BiTNode* p6=(BiTNode*)malloc(sizeof(BiTNode)); //insert 6 in L of 3
    p6->data=6;
    p6->lchild=NULL;
    p6->rchild=NULL;
    p3->lchild=p6; //p3 lchild

    BiTNode* p7=(BiTNode*)malloc(sizeof(BiTNode)); //insert 7 in R of 3
    p7->data=7;
    p7->lchild=NULL;
    p7->rchild=NULL;
    p3->rchild=p7; //p3 rchild

    BiTNode* p11=(BiTNode*)malloc(sizeof(BiTNode)); //insert 11 in R of 4
    p11->data=11;
    p11->lchild=NULL;
    p11->rchild=NULL;
    p4->rchild=p11; //p4 rchild

    BiTNode* p12=(BiTNode*)malloc(sizeof(BiTNode)); //insert 12 in L of 6
    p12->data=12;
    p12->lchild=NULL;
    p12->rchild=NULL;
    p6->lchild=p12; //p6 lchild


    PreOrder(root);
    cout<<"  Congratulations~ PreOrder achieved!"<<endl;
    InOrder(root);
    cout<<"  Congratulations~ InOrder achieved!"<<endl;
    PostOrder(root);
    cout<<"  Congratulations~ PostOrder achieved!"<<endl;
 
    return 0;
}