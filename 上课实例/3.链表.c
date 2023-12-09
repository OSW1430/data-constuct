#include <stdio.h>
#include <stdlib.h>
typedef struct LNode *List;
typedef int ElementaryType;

struct LNode{
    ElementaryType Data;
    List Next;
};
//初始化链表
List MakeEmpty(){
    List Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl = NULL;
    return Ptrl;
}
//求表长
int Length(List Ptrl){
    int j = 0;
    List p = Ptrl;
    while(p != NULL){
        p = p->Next;
        j++;
    }
    return j;
}
//查找(按序号)
List FindKth(int K, List Ptrl){
    List p = Ptrl;
    int j = 1;
    while(p != NULL && j < K){
        p = p->Next;
        j++;
    }
    if(K == j) return p;
    else return NULL;
}
//按值查找
List Find(ElementaryType X, List Ptrl){
    List p = Ptrl;
    while(p != NULL && X != p->Data){
        p = p->Next;
    }
    // 找到了 返回p
	// 未找到 返回NULL 此时p就等于NULL 
    return p;
}
//插入(在i-1个结点后插入)
List Insert(ElementaryType X, int i, List Ptrl){
    List p,s;
    if(i == 1){
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = Ptrl;
        return s;
    }
    p = FindKth(i-1, Ptrl);//查找第i-1个结点
    if(p == NULL){
        printf("i参数错误");
        return NULL;
    }
    else {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return Ptrl;
    }
}
//删除(第i个结点)
List Delete(int i, List Ptrl){
    List p,s;
    if(i == 1){//删除的是头结点
        s = Ptrl;
        if(Ptrl != NULL) Ptrl = Ptrl->Next;
        else return NULL;
        free(s);
        return Ptrl;
    }
    p = FindKth(i-1, Ptrl);//p指向被删除的前一结点
    if(p == NULL) {
        printf("第%d个结点不存在",i-1);
        return NULL;
    }
    else if(p->Next == NULL){
        printf("第%d个结点不存在",i);
        return NULL;
    }
    else{
        s = p->Next;//s指向被删除结点
        p->Next = s->Next;//删除结点
        free(s);
        return Ptrl;
    }
}
//打印链表
void Print(List Ptrl){
    List p = Ptrl;
    for(int i = 0; i < Length(Ptrl); i++){
        printf("%d ",p->Data);
        p = p->Next;
    }
}
int main(){
    List list = MakeEmpty();
    list = Insert(10,1,list);
    list = Insert(11,2,list);
    list = Insert(12,3,list);
    Print(list);
    list = Delete(2,list);
    Print(list);
    printf("\n查找11是否在链表中\n");
    if(Find(11,list)){
        printf("是\n");
    }
    else printf("否");
    printf("\n查找第二个元素是否在链表中\n");
    if(FindKth(2,list)){
        printf("是\n");
    }
    else printf("否");
}
