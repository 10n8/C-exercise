#include <stdio.h>
#include <math.h>

int n;
double psi(int n, double x);
double Pcl(int n, double x);
double hermite(int n, double x);
double factional(int n);

int main(){
    // plot for x in the interval [-1,3]
    int m = 100;
    double a = -1., b = 3.;
    double x;
    double step = (b-a)/m;
    printf("quantum number n ==> ");
    scanf("%d", &n);
    printf("x          psi(x)       Pcl(x)\n");
    printf("====================================\n");

    for (int i = 0; i <= m; i++){
        x = a + i*step;
        printf("%10.8e %10.8e %10.8e\n", x, psi(n, x), Pcl(n, x));
    }

    printf("====================================\n");
    return 0;
}

double psi(int n, double x){
    double h, f;
    h=hermite(n, x);
    f=factional(n);
    return ( h*h * exp(-1.*x*x))/(M_PI * pow(2, n+1) * f*f);
}

double Pcl(int n, double x){
    return 1./(M_PI * sqrt(2*n+1-x*x));
}

double hermite(int n, double x){
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

double factional(int n){
    double f = 1.;
    for (int i = 1; i <= n; i++){
        f *= i;
    }
    return f;
}