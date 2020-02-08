#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double error_tolerance;

double func(double m) {
    double v=35, g=9.8,c=15,t=9;
    return (v - ( ((g*m)/c) * (1 - exp((-1*c/m)*t)) ));
}


double false_position(double xl, double xu) {
    int iter = 1;
    double xr;
    double xr_prev = INT_MAX, approxError = INT_MAX;

    if(func(xl) * func(xu) > 0) {
        printf("Wrong guess of xl xu\n");
        return 0;
    }

    printf("\titer\tupper\t\tlower\t\txr\t\tf(xr)\t\tREA\n\n");

    do {
        if(iter != 1)
            xr_prev = xr;

        xr = xu-func(xu)*(xl-xu)/( func(xl)-func(xu) );
        approxError = fabs((xr - xr_prev) / xr) * 100;
        printf("%8d\t%0.8lf\t%0.8lf\t%0.8lf\t%0.8lf\t%0.8lf\n", iter, xu, xl, xr, func(xr), (iter==1) ? 0 : approxError);
        //printf("%8d,%0.8lf,%0.8lf,%0.8lf,%0.8lf,%0.8lf\n", iter, xl, xu, xr, func(xr), (iter==1) ? 0 : approxError);

        if(func(xr) == 0.0) {
            break;
        }

        if(func(xl) * func(xr) < 0) {
            xu = xr;
        } else {
            xl = xr;
        }
        iter++;
    } while(approxError >= error_tolerance);

    printf("x = %lf\n", xr);

}

int main() {
    //freopen("prob2.csv", "w", stdout);
    double xl,xu;
    printf("Enter lower and upper bound\n");
    scanf("%lf %lf", &xl, &xu);
    printf("\nEnter relative errror tolerance\n");
    scanf("%lf", &error_tolerance);
    for(double i =xl; i<=xu; i+=0.1){
        printf("%0.6lf\t%0.6lf\n",i,func(i));
    }

    false_position(xl,xu);
    return 0;
}
