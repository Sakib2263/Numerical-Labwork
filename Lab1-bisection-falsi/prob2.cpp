#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double error_tolerance = 0.00001;

double func(double x) {
    return ((x +4)/( (42 - 2*x)*(42 - 2*x)*(28 -x) ) ) - 0.016;
}


double false_position(double xl, double xu) {
    int iter = 1;
    double xr;
    double xr_prev = INT_MAX, approxError = INT_MAX;

    if(func(xl) * func(xu) > 0) {
        printf("Wrong guess of xl xu\n");
        return 0;
    }

    do {
        if(iter != 1)
            xr_prev = xr;

        xr = xu-func(xu)*(xl-xu)/( func(xl)-func(xu) );
        approxError = fabs((xr - xr_prev) / xr) * 100;

        printf("%8d\t%0.8lf\t%0.8lf\t%0.8lf\t%0.8lf\t%0.8lf\n", iter, xl, xu, xr, func(xr), (iter==1) ? 0 : approxError);
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

    for(double i=0; i<=20;i++){
        printf("%lf\t%lf\r\n",i, func(i) );
    }

    double xl,xu;
    printf("Enter lower and upper bound\n");
    scanf("%lf %lf", &xl, &xu);
    printf("\nEnter relative errror tolerance\n");
    scanf("%lf", &error_tolerance);
    false_position(xl,xu);

    return 0;
}
