#include <stdio.h>
#include <stdlib.h>
typedef int ElementaryType;
typedef struct SNode *Stack;

struct SNode{
    ElementaryType Data;
    struct SNode *Next;
};
//初始化堆栈
Stack CreatStack(){
    Stack S = (Stack)malloc(sizeof(struct SNode));//S为一个不存储值的结点，永远指向栈顶top
    S->Next = NULL;
    return S;
}
//判断堆栈是否为空
int isEmpty(Stack S){
    return (S->Next == NULL);
}
//入栈
void Push(ElementaryType item, Stack S){
    Stack temp = (Stack)malloc(sizeof(struct SNode));
    temp->Data = item;
    temp->Next = S->Next;
    S->Next = temp;//让入栈元素接在S后面
}
//出栈
ElementaryType Pop(Stack S){
    Stack TopNode;
    ElementaryType TopVal;
    if(isEmpty(S)){
        printf("栈为空");
        return; 
    }
    else {
        TopNode = S->Next;//出栈结点为S后的第一个结点
        S->Next = TopNode->Next;//断开出栈结点
        TopVal = TopNode->Data;//存储出栈结点的值,因为后面需要释放空间
        free(TopNode);
        return TopVal;
    }
}
int main(){
    Stack S = CreatStack();
    printf("1入栈\n");
	Push(1,S);
	printf("5入栈\n");
	Push(5,S);
	printf("10入栈\n");
	Push(10,S);
	printf("%d出栈\n",Pop(S));
	printf("%d出栈\n",Pop(S));
	return 0;
}
