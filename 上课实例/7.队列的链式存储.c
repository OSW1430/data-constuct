#include <stdio.h>
#include <stdlib.h>

typedef int ElmentaryType;
struct Node{
    ElmentaryType Data;
    struct Node *Next;
};
struct QNode{
    struct Node *front;
    struct Node *rear;
};
typedef struct QNode *Quene;
//初始化队列
Quene CreatQuene(){
    Quene Q = (Quene)malloc(sizeof(struct QNode));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}
//判断队列是否为空
int isEmpty(Quene PtrQ){
    return (PtrQ->front == NULL);//front不指向任何结点说明为空
}
//入队
void AddQuene(Quene PtrQ, ElmentaryType item){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->Data = item;
    node->Next = NULL;
    if(PtrQ->front == NULL){
        PtrQ->front = node;
        PtrQ->rear = node;
    }
    else {
        PtrQ->rear->Next = node;//连接结点
        PtrQ->rear = node;//移动rear指针指向最后一个结点
    }
}
//出队
ElmentaryType DeleteQuene(Quene PtrQ){
    struct Node *FrontNode;
    ElmentaryType FrontVal;
    if(isEmpty(PtrQ)){
        printf("队列为空\n");
        return 0;
    }
    FrontNode = PtrQ->front;
    if(PtrQ->front == PtrQ->rear){//如果队列只有一结点
        PtrQ->front = NULL;
        PtrQ->rear = NULL;
    }
    else {
        PtrQ->front = PtrQ->front->Next;//否则将front指针移向后一位
    }
    FrontVal = FrontNode->Data;
    free(FrontNode);
    return FrontVal;
}
int main(){
    Quene Q = CreatQuene();
    printf("1入队\n");
	AddQuene(Q,1);
	printf("3入队\n");
	AddQuene(Q,3);
	printf("5入队\n");
	AddQuene(Q,5);
	printf("%d出队\n",DeleteQuene(Q));
	printf("%d出队\n",DeleteQuene(Q));
	return 0;
}
