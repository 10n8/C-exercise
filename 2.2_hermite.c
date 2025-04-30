#include <stdio.h>
#include <math.h>
#define EPSA 1.e-70
int n;
double f( double y );
double df( double y );
double legendre(int n, double x);
double newton( double (*func)( double x ), double (*dfunc)( double x ),
double x0, double dx );

int main(){
    int k,cnt;
    double kd, sol;
    int kmax = 100;
    double eps=1.e-8;
    printf("Legendre polynomial n ==> ");
    scanf("%d", &n);
    cnt = 0;
    for (k=0; k<kmax; k++){
        kd = (double) k;
        if (f(kd/kmax)*f((kd+1.)/kmax) < 0){
            sol = newton(f, df, (kd/kmax+(kd+1.)/kmax)/2., eps);
            if (!(sol==-1.0)){
                printf("sol = %10.8e\n", sol);
                cnt++;
            }
        }
    }
    printf("the number of solutions : %d\n", cnt);
    return 0;
}

double f( double x ){
    return legendre(n, x);
}

double df( double x ){
    return n*(legendre(n-1,x)-x*legendre(n,x))/(1-x*x);
}

double legendre(int n, double x){
    int k;
    double y0, y1, y2;
    y0=1;
    if (n==0)
    return y0;
    y1=x;
    for (k=2; k<=n; k++){
        double l = (double)k;
        y2=((2.*l-1)*x*y1-(l-1)*y0)/l;
        y0=y1;
        y1=y2;
    }
    return y1;
}

double newton( double (*func)( double x ), double (*dfunc)( double x ),
double x0, double dx ){
    int n;
    double x1;
    n=0; 
    while( n++ < 20 ){
    x1 = x0 - func(x0)/dfunc(x0);
    if( fabs(x1-x0)<EPSA+dx*fabs(x1) )
        return x1;
    x0=x1;
    }
    return -1.0; //error: No solution can be found.
}