
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double error_tolerance = 0.00001;

double f(double x){
    return (8*sin(x)*exp(-x))-1;
}

double get_error(double current, double prev){
    return fabs((current - prev) / current) * 100;
}

void secant(double x_prev, double x_cur, double error_tolerance)
{

    double x_next,error;
    int i =0;
    while(get_error(x_cur,x_prev) >= error_tolerance){
        x_next = x_cur - (f(x_cur)*(x_cur-x_prev))/(f(x_cur) - f(x_prev));
        printf("%5d %5.5lf %5.5lf %5.5lf %5.5lf %5.5lf\n", i++, x_prev, x_cur, x_next, f(x_cur), get_error(x_next, x_cur));
        x_prev = x_cur;
        x_cur = x_next;
        if(f(x_cur) == 0) break;
    }
    printf("apprx root = %lf", x_cur);
}

int main(){
	double x1,x2;
    printf("\nEnter guesses\n");
    scanf("%lf %lf", &x1, &x2);
    printf("\nEnter relative error tolerance\n");
    scanf("%lf", &error_tolerance);

	secant(x1,x2, error_tolerance);

	return 0;
}


