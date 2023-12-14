#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6
typedef int ElmentaryType;
typedef struct QNode *Quene;
struct QNode{
    ElmentaryType Data[MAXSIZE];
    int front;//指向队头的前一位
    int rear;//指向队尾
};
Quene CreatQuene(){
    Quene Q = (Quene)malloc(sizeof(struct QNode));
    Q->front = 0;//循环队列 初始化front和rear为数组第一个元素的下标
    Q->rear = 0;
    return Q;
}
//判断队列是否已满
int isFull(Quene PtrQ){
    return ((PtrQ->rear + 1) % MAXSIZE == PtrQ->front);//这里加1是配合取余空出数组中的一个位置
}
//判断队列是否为空
int isEmpty(Quene PtrQ){
    return (PtrQ->front == PtrQ->rear);
}
//入队
void AddQuene(Quene PtrQ, ElmentaryType item){
    if(isFull(PtrQ)){
        printf("队列已满\n");
        return;
    }
    else {
        PtrQ->rear = (PtrQ->rear + 1) % MAXSIZE;//这里加1代表rear往后移一位
        PtrQ->Data[PtrQ->rear] = item;
    }
}
ElmentaryType DeleteQuene(Quene PtrQ){
    if(isEmpty(PtrQ)){
        printf("队列为空\n");
        return 0;
    }
    else {
        PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
        return PtrQ->Data[PtrQ->front];
    }
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
