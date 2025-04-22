#include <stdio.h>
#include <math.h>
#define EPSA 1.e-70
double f( double x );
double df( double x );
int main()
{
    double x0, x1, eps;
    int n, nmax;
    eps=1.e-8;
    nmax=20;
    printf(" 初期値 x0 = ");
    scanf("%lf",&x0);
/* l は一ではなくエル */
    for( n=1; n<=nmax; n++ ){
	x1 = x0 - f(x0)/df(x0);
	if( fabs(x1-x0) < EPSA + eps*fabs(x1) ){
	    printf("--------------------------------------\n");
	    printf("%2d %15.8e %15.8e\n", n, x1, f(x1) );
	    return 0;
	}
	x0=x1;
	printf("%2d %15.8e %15.8e\n", n, x1, f(x1) ); /* 途中経過を表示 */
    }
    printf(" 解が見つかりません !!\n");
    return 0;
}

double f( double y )
{
    return sin(y)-y/2;
}
double df( double y )
{
    return cos(y)-1./2;
}
