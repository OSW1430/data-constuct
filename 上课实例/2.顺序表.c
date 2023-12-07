#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct LNode *List;
typedef int ElmentaryType;//设置元素类型为int
struct LNode{
    ElmentaryType Data[MAXSIZE];
    int Last;//指向最后一个元素，范围[0,n-1]
};

//建立空表
List MakeEmpty(){
    List PtrL;//指向结构体的指针
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}
//查找
int Find(ElmentaryType X, List Ptrl){
    int i = 0;
    while(i < Ptrl->Last && X != Ptrl->Data[i]){
        i++;
    }
    if(X == Ptrl->Data[i]) return i;//找到则返回下标
    else return -1;
}
//插入 i代表要插入的位置 范围[1,n+1],n+1即在尾部添加一个元素
void Insert(ElmentaryType X, int i, List Ptrl){
    if(Ptrl->Last == MAXSIZE - 1){
        printf("表满了无法插入");
        return;
    }
    if(i < 1 || i > MAXSIZE){
        printf("位置不合法");
        return;
    }
    for(int j = Ptrl->Last; j > i; j--){
        Ptrl->Data[j+1] = Ptrl->Data[j];
    }
    Ptrl->Data[i-1] = X;
    Ptrl->Last++;
    return;
}
//删除
void Delete(int i, List Ptrl){
    if(Ptrl->Last == -1){
        printf("空表无可删除元素");
        return;
    }
    if(i < 1 || i > Ptrl->Last + 1){
        printf("位置不合法");
        return;
    }
    for(int j = i; j <= Ptrl->Last; j++){
        Ptrl->Data[j-1] = Ptrl->Data[j];
    }
    Ptrl->Last--;
    return;
}
//输出
void Print(List Ptrl){
    for(int i = 0; i <= Ptrl->Last; i++){
        printf("%d ",Ptrl->Data[i]);
    }
}
int main(){
    List list = MakeEmpty();
    Insert(3,1,list);
    Insert(4,2,list);
    Insert(5,3,list);
    Print(list);
    printf("%d ",Find(3,list));
    Delete(1,list);
    Print(list);
}
