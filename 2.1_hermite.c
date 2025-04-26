#include <stdio.h>
#include <math.h>
double hermite(int n, double x);
double legendre(int n, double x);
double hermite_5(double x);
double legendre_5(double x);

int main()
{
    int n, i;
    double hv, lv, hv_5, lv_5;
    printf("\n Hermite and Legendre polynomial n ==> ");
    scanf("%d", &n);
    for (i=0; i<=20; i++)
    {
        hv = hermite(n, 0.05*i);
        lv = legendre(n, 0.05*i);
        hv_5 = hermite_5(0.05*i);
        lv_5 = legendre_5(0.05*i);
        printf("\n x = %5.3f : hv = %5.3e (%5.3e) lv = %5.3e (%5.3e)", 0.05*i, hv, hv_5, lv, lv_5);
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
    for (k=2; k<=n; k++)
    {
        double l = (double)k;
        y2=((2.*l-1)*x*y1-(l-1)*y0)/l;
        y0=y1;
        y1=y2;
    }
    return y1;
}

double hermite_5(double x)
{
    return 32. * x * x * x * x * x - 160.* x * x * x + 120.*x;
}

double legendre_5(double x)
{
    return (63. * x * x * x * x * x - 70. * x * x * x + 15. * x)/8.;
}