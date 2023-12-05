#include<stdio.h>
int MaxSubseqSum1(int res[], int a[], int n){
    int ThisSum,MaxSum;
    ThisSum = 0;
    MaxSum = -1;
    res[0] = a[0];//左区间
    res[1] = a[n-1];//右区间
    int temp = res[0];
    for(int i = 0; i < n; i++){
        ThisSum += a[i];
        if( ThisSum > MaxSum ){
            MaxSum = ThisSum;
            res[0] = temp;
            res[1] = a[i];//更新最大和时，当前数字即此时最大和的右区间
        }
        else if( ThisSum < 0 ){
            ThisSum = 0;
            temp = a[i+1];//和小于0 即当前数字以及前面所有数字都不会构成序列，所以让temp指向下一个数字
        }
    }
    if(MaxSum < 0) MaxSum = 0;//若最大和为负数，输出0
    return MaxSum;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int res[2];
    printf("%d",MaxSubseqSum1(res,a,n));
    for(int i = 0; i < 2; i++){
        printf(" %d",res[i]);
    }
}
