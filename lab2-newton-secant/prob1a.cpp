#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double error_tolerance;

double func(double m) {
    double v=35, g=9.8,c=15,t=9;
    return (v - ( ((g*m)/c) * (1 - exp((-1*c/m)*t)) ));
}

double get_error(double xl, double xu) {
    return (fabs((xu - xl) / (xu + xl)) * 100.0);
}

void bisection(double xl, double xu) {

    if(func(xl) * func(xu) >= 0) {
        printf("Wrong guess of xl and/or xu\n");
        return;
    }

    printf("\titer\tupper\t\tlower\t\txr\t\tf(xr)\t\tREA\n\n");

    double xr = 0.0;
    int iteration = 0;

    while(get_error(xl, xu) > error_tolerance) {

        xr = (xl + xu) / 2;

        if(func(xr) == 0.0) {
            break;
        } else {
            printf("%8d\t%.8lf\t%0.8lf\t%0.8lf\t%0.8lf\t%0.8lf\n", ++iteration, xl, xu, xr, func(xr), get_error(xl, xu));
            //printf("%d,%.4lf,%0.4lf,%0.4lf,%0.4lf,%0.4lf\n", ++iteration, xl, xu, xr, func(xr,0), get_error(xl, xu));
        }

        if(func(xl) * func(xr) < 0.0) {
            xu = xr;
        } else {
            xl = xr;
        }
    }

    printf("\nX (approx.) = %0.5lf\n", xr);
}

int main() {
    //freopen("prob1_0.csv", "w", stdout);
    double xl,xu;
    printf("\nEnter lower and upper bound\n");
    scanf("%lf %lf", &xl, &xu);
    printf("\nEnter relative errror tolerance\n");
    scanf("%lf", &error_tolerance);
    printf("\n\n");
    for(double i =xl; i<=xu; i+=0.1){
        printf("%0.6lf\t%0.6lf\n",i,func(i));
    }
    printf("\n\n");
    bisection(xl, xu);

    return 0;
}

