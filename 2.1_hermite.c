#include <stdio.h>
#include <math.h>
double hermite( int n, double x);

int main()
{
    int n;
    double x, hv;
    printf("\n Hermite polynomial n ==> ");
    scanf("%d", &n);
    printf("\n variable x ==> ");
    scanf("%lf", &x);
    hv = hermite(n, x);
    printf("\n value = %15.8e\n", hv);
}

double hermite( int n, double x )
{
int k;
double y0, y1, y2;
y0=1.;
if( n==0 )
return y0;
y1=2.*x;
for( k = 2; k<=n; k++ ){
y2 = 2.*( x*y1 - (k-1)*y0 );
y1 = y2;
y0 = y1;
}
return y1;
}