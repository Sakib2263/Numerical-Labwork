
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double error_tolerance = 0.00001;

double f(double x){
    return sin(x) + cos(1 +(x*x)) -1;
}

double f_d(double x){
	return 2*x*exp(-x) - x*x*exp(-x);
}

double get_error(double current, double prev){
    return fabs((current - prev) / current) * 1000;
}

void newton_raphson(double x, double error_tolerance)
{
    double prev_x, error = 0;
    int i = 1;
    while (i ==1 || error >= error_tolerance)
    {
        printf("%5d %5.5lf %5.5lf %5.5lf %5.5lf\n", i++, x, f(x), f_d(x), error);
        //printf("%5d,%5.5lf,%5.5lf,%5.5lf,%5.5lf\n", i++, x, f(x), f_d(x), error*100);
        if(f(x) == 0) break;
        prev_x = x;
        x = x - f(x)/f_d(x);
        error = get_error(x, prev_x);
    }

    printf("The approx value of the root is : %lf", x);
}

void secant(double x_prev, double x_cur, double error_tolerance)
{
    if(f(x_prev) * f(x_cur) > 0){
        printf("Wrong guess");
        return;
    }
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
	//freopen("prob1_0.csv", "w", stdout);

	/*
	for(double i=0; i<10.1;i+= 0.1){
        printf("%lf,%lf\n",i, func(i, 0) );
    }
    */
	double x1,x2;
    printf("\nEnter guesses\n");
    scanf("%lf %lf", &x1, &x2);
    printf("\nEnter relative error tolerance\n");
    scanf("%lf", &error_tolerance);

	secant(x1,x2, error_tolerance);

	return 0;
}


