#include<stdio.h>
//在线处理 复杂度O(n)
int MaxSubseqSum1(int a[], int n){
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
//分而治之 复杂度O(nlogn)
int findMax(int a, int b, int c){
    return (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
}
int MaxSubseqSum2(int a[], int left, int right){
    if(left == right){
        if(a[left] > 0){
            return a[left];
        }
        else return 0;
    }
//计算左右子列最大和
    int mid = (left + right) / 2;
    int MaxLeftSum = MaxSubseqSum2(a,left,mid);
    int MaxRightSum = MaxSubseqSum2(a,mid+1,right);

//计算跨界最大和
    int MaxLeftBoderSum = 0;
    int LeftBoderSum = 0;
    for(int i = mid; i >= left; i--){
        LeftBoderSum += a[i];
        if(LeftBoderSum > MaxLeftBoderSum)
            MaxLeftBoderSum = LeftBoderSum;
    }

    int MaxRightBoderSum = 0;
    int RightBoderSum = 0;
    for(int i = mid+1; i < right; i++){
        RightBoderSum += a[i];
        if(RightBoderSum > MaxRightBoderSum)
            MaxRightBoderSum = RightBoderSum;
    }
    return findMax(MaxLeftSum,MaxRightSum,MaxLeftBoderSum + MaxRightBoderSum);
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    printf("%d",MaxSubseqSum1(a,n));
}
