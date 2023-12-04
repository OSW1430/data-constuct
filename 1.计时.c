#include <stdio.h>
#include <time.h>
#include <math.h>
clock_t start,stop;
double duration;
#define MAXN 10
#define MAXK 1e7//循环次数，解决运行单次速度过快导致无法计数
//∑i~10 i*x^i
/*秦九韶多项式*/
double f1( int n, double a[], double x ){
	int i;
	double p = a[n];
	for( i = n; i > 0; i--){
		p = a[i-1] + x*p;
	}
	return p;
}
/*一般求法*/
double f2( int n, double a[], double x ){
	int i;
	double p = a[0];
	for( i = 1; i < n; i++){
		p += a[i]*pow(x,i);
	}
	return p;
}
void interval(double (*f)(int n, double a[], double x)){
	double a[MAXN];
	for(int i = 0; i < MAXN; i++) a[i] = (double)i;

	start = clock();
	for(int i = 0; i < MAXK; i++) f(MAXN-1, a, 1.1);
	stop = clock();

	duration = ((double)(stop - start))/CLK_TCK/MAXK;
	printf("ticks = %f\n",(double)(stop - start));
	printf("duration = %6.2e\n",duration);
}
int main(){
	interval(f1);
	interval(f2);
	return 0;
}
