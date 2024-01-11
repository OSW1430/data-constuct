#include <stdio.h>
#include <stdlib.h>

struct PolyNode{
    int coef;
    int expo;
    struct PolyNode *next;
};
typedef struct PolyNode *Polynomial;
int Compare(int a, int b){
    if(a > b) return 1;
    else if(a < b) return -1;
    else return 0;
}
void Attach(Polynomial *pRear, int coefficient, int exponential){
    Polynomial temp = (Polynomial)malloc(sizeof(struct PolyNode));
    temp->coef = coefficient;
    temp->expo = exponential;
    temp->next = NULL;
    (*pRear)->next = temp;//连接temp结点
    *pRear = temp;//尾指针后移
}
Polynomial Read(){
    int n,coefficient,exponential;
    Polynomial P,temp,rear;
    P = (Polynomial)malloc(sizeof(struct PolyNode));//空结点p
    rear = P;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&coefficient,&exponential);
        Attach(&rear, coefficient, exponential);
    }
    //释放空结点
    temp = P;
    P = P->next;
    free(temp);
    return P;
}
void Print(Polynomial P){
    while(P != NULL){
        printf("%d %d",P->coef,P->expo);
        if(P->next) printf(" ");
        P = P->next;
    }
}
Polynomial Add(Polynomial p1, Polynomial p2){
    Polynomial front,rear,temp;
    int sum;
    front = (Polynomial)malloc(sizeof(struct PolyNode));
    rear = front;
    while(p1 && p2){
        switch (Compare(p1->expo, p2->expo))
        {
        case 1:
            Attach(&rear, p1->coef, p1->expo);
            p1 = p1->next;
            break;
        case -1:
            Attach(&rear, p2->coef, p2->expo);
            p2 = p2->next;
            break;
        case 0:
            sum = p1->coef + p2->coef;
            Attach(&rear, sum, p1->expo);
            p1 = p1->next;
            p2 = p2->next;
            break;
        }
    }
    for(;p1;p1 = p1->next) Attach(&rear, p1->coef, p1->expo);
    for(;p2;p2 = p2->next) Attach(&rear, p2->coef, p2->expo);
    rear->next = NULL;
    temp = front;
    front = front->next;
    free(temp);
    return front;
}
Polynomial Multiply(Polynomial p1, Polynomial p2){
    Polynomial P,rear,t1,t2,temp;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->next = NULL;
    rear = P;
    t1 = p1;t2 = p2;
    //将p1的第一项与p2每一项相乘构造结果多项式
    while(t2){
        Attach(&rear,t1->coef * t2->coef,t1->expo + t2->expo);
        t2 = t2->next;
    }
    t1 = t1->next;//后面从p1的第二项开始操作
    //释放空节点
    rear = P;
    P = P->next;
    free(rear);
    //从p1的第二项开始遍历 所得项利用加法与结果多项式相加
    for(;t1;t1 = t1->next){
        t2 = p2;
        for(;t2;t2 = t2->next){
            temp = (Polynomial)malloc(sizeof(struct PolyNode));
            temp->coef = t1->coef * t2->coef;
            temp->expo = t1->expo + t2->expo;
            temp->next = NULL;
            P = Add(temp,P);
        }
    }
    return P;
}
int main(){
    Polynomial p1 = Read();
    Polynomial p2 = Read();
    Polynomial Poly2mul = Multiply(p1,p2);
    Print(Poly2mul);
    printf("\n");
    Polynomial Poly2add = Add(p1,p2);
    Print(Poly2add);
    return 0;
}
