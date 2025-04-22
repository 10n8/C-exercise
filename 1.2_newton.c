#include <stdio.h>
#include <math.h>
#define EPSA 1.e-70
double f( double y );
double df( double y );
double g( double z );
double dg( double z);
double newton( double (*func)( double x ), double (*dfunc)( double x ),
double x0, double dx );
int main()
{
    double y0, y1, z0, z1,  eps;
eps=1.e-8;
printf("\n fのときの初期値 ==> ");
scanf("%lf",&y0);
printf("\n gのときの初期値 ==> ");
scanf("%lf",&z0);
y1 = newton( f, df, y0, eps );
z1 = newton( g, dg, z0, eps );
printf("fのときの結果：%15.8e %15.8e\n", y1, f(y1) );
printf("gのときの結果：%15.8e %15.8e\n", z1/M_PI, g(z1) );
return 0;
}
double f( double x )
{
    return sin(x)-x/2;
}
double df( double x )
{
    return cos(x)-1./2;
}
double g( double x )
{
    return tan(x)-1./x;
}
double dg( double x )
{
    return 1./(cos(x)*cos(x))+1./(x*x);
}
    
double newton( double (*func)( double x ), double (*dfunc)( double x ),
double x0, double dx )
{
int n;
double x1;
n=0;
while( n++ < 20 ){
x1 = x0 - func(x0)/dfunc(x0);
if( fabs(x1-x0)<EPSA+dx*fabs(x1) )
return x1;
x0=x1;
}
printf(" 解が見つかりません !!\n");
return x1;
}
