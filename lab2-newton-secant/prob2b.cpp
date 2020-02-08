#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double error_tolerance = 0.00001;

double f(double x){
    return (4-x)*exp(-0.5*x) - 2;
}

double f_d(double x){
	return ((x -6)*exp(-0.5*x))/2;
}

double get_error(double current, double prev){
    return fabs((current - prev) / current) * 100;
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

int main(){
	//freopen("prob1_0.csv", "w", stdout);
/*

	for(double i=0; i<10.1;i+= 0.1){
        printf("%lf,%lf\n",i, f_d(i) );
    }
    */
	double x;
    printf("\nEnter guess\n");
    scanf("%lf", &x);
    printf("\nEnter relative error tolerance\n");
    scanf("%lf", &error_tolerance);

	newton_raphson(x, error_tolerance);

	return 0;
}


