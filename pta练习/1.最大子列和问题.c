#include<stdio.h>
//采用在线处理
int MaxSubseqSum(int a[], int n){
    int ThisSum,MaxSum;
    ThisSum = MaxSum = 0;
    for(int i = 0; i < n; i++){
        ThisSum += a[i];
        if( ThisSum > MaxSum ) 
            MaxSum = ThisSum;
        else if( ThisSum < 0 )
            ThisSum = 0;
    }
    return MaxSum;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    printf("%d",MaxSubseqSum(a,n));
}
