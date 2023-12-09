#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
typedef int ElementaryType;
typedef struct SNode *Stack;
struct SNode{
    ElementaryType Data[MAXSIZE];
    int Top;
};
//初始化栈
Stack CreatStack(){
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Top = -1;
    return S;
}
//栈是否已满
int isFull(Stack PtrS){
    return (PtrS->Top == MAXSIZE - 1);
}
//栈是否为空
int isEmpty(Stack PtrS){
    return (PtrS->Top == -1);
}
//入栈
void Push(Stack PtrS, ElementaryType item){
    if(isFull(PtrS)){
        printf("栈已满");
        return;
    }
    else {
        PtrS->Data[++PtrS->Top] = item;//相当于 PtrS->Top++;
        return;                        //      PtrS->Data[PtrS->Top] = item;
    }
}
//出栈
ElementaryType Pop(Stack PtrS){
    if(isEmpty(PtrS)){
        printf("栈为空");
        return;
    }
    else {
        return PtrS->Data[(PtrS->Top)--];//返回出栈的元素 
    }
}
int main(){
    Stack S = CreatStack();
    printf("1入栈\n");
	Push(S,1);
	printf("5入栈\n");
	Push(S,5);
	printf("10入栈\n");
	Push(S,10);
	printf("%d出栈\n",Pop(S));
	printf("%d出栈\n",Pop(S));
	return 0;
}
