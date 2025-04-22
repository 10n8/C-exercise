#include <stdio.h>
#include <math.h>
#define EPSA 1.e-70
#define PI 3.141592653589793
double f( double y );
double g( double z );
double secant( double (*func)( double x ), double x0, double dx);
double v0;
int main()
{   
double y0, y2, z0, z2, eps;
eps=1.e-8;  
v0=10000;
printf("\n fのときの初期値 ==> ");
scanf("%lf", &y0);
printf("\n gのときの初期値 ==> ");
scanf("%lf", &z0);
y2 = secant( f, y0, eps );
printf("\n fのときの結果：%15.8e %15.8e\n", (y2-0.5*PI)/PI, f(y2) );
z2 = secant( g, z0, eps );
printf("\n gのときの結果：%15.8e %15.8e\n", z2/PI, g(z2) );
return 0;
}
double f( double x )
{
    return x*x-v0*v0*cos(x)*cos(x);
}
double g( double x )
{
    return x*x-v0*v0*sin(x)*sin(x);
}
double secant( double (*func)( double x ), double x0, double dx)
{
int n;
double x1;
double x2;
double dfunc;
n=0;
x1=x0+dx;
while( n++ < 20 ){
    dfunc = (func(x1)-func(x0))/(x1-x0);
    x2 = x1 - func(x1)/dfunc;
    if( fabs(x2-x1)<EPSA+dx*fabs(x2) )
	return x2;
    x0=x1;
    x1=x2;
}
printf(" 解が見つかりません !!\n");
return x2;
}
