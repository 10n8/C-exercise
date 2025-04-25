#include <stdio.h>
#include <math.h>
double hermite(int n, double x);
double legendre(int n, double x);

int main()
{
    int n, i;
    double hv, lv;
    printf("\n Hermite and Legendre polynomial n ==> ");
    scanf("%d", &n);
    //printf("\n variable x ==> ");
    //scanf("%lf", &x);
    for (i=0; i<=20; i++)
    {
        hv = hermite(n, 0.05*i);
        lv = legendre(n, 0.05*i);
        printf("\n x = %5.3f : hv = %15.8e, lv = %15.8e", 0.05*i, hv, lv);
    }
}

double hermite(int n, double x)
{
    int k;
    double y0, y1, y2;
    y0 = 1.;
    if (n == 0)
        return y0;
    y1 = 2. * x;
    for (k = 2; k <= n; k++)
    {
        y2 = 2. * (x * y1 - (k - 1) * y0);
        y0 = y1;
        y1 = y2;
    }
    return y1;
}

double legendre(int n, double x)
{
    int k;
    double y0, y1, y2;
    y0=1;
    if (n==0)
    return y0;
    y1=x;
    for (k=2; k<=n; k++);
    {
        double l = (double)k;
        y2=((2.*k-1)*x*y1-(k-1)*y0)/l;
        y0=y1;
        y1=y2;
    }
    return y1;
}