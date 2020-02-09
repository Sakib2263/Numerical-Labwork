#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

double error_tolerance = 0.00001;
long long int fact[15];

void calculate_factorial(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i<14; i++){
        fact[i] = fact[i-1] * i;
    }
}

double func(double x, int n){

    double temp1 = pow((x/2), n);
    double temp2 = 0.0;
    for(int k= 1; k<=10; k++){
        temp2 = temp2 + ( (pow(-1, k) * pow((x*x/4), k))/(fact[k]* fact[k+n]));
    }
	return temp2*temp1;
}

double get_error(double xl, double xu){
    return (fabs((xu - xl) / (xu + xl)) * 100.0);
}

void bisection(double xl, double xu){

	if(func(xl,0) * func(xu,0) >= 0){
		printf("Wrong guess of xl and/or xu\n");
		return;
	}

	double xr = 0.0;
	int iteration = 0;

	while(get_error(xl, xu) > error_tolerance){

		xr = (xl + xu) / 2;

		if(func(xr,0) == 0.0){
			break;
		}else{
            printf("%d\t%.4lf\t%0.4lf\t%0.4lf\t%0.4lf\t%0.4lf\n", ++iteration, xl, xu, xr, func(xr,0), get_error(xl, xu));
            //printf("%d,%.4lf,%0.4lf,%0.4lf,%0.4lf,%0.4lf\n", ++iteration, xl, xu, xr, func(xr,0), get_error(xl, xu));
		}

		if(func(xl,0) * func(xr,0) < 0.0){
			xu = xr;
		}else{
			xl = xr;
		}
	}

	printf("\nX (approx.) = %0.5lf\n", xr);
}

int main(){
	freopen("prob1_0.csv", "w", stdout);
	calculate_factorial();

	for(double i=0; i<10.1;i+= 0.1){
        printf("%lf,%lf\n",i, func(i, 0) );
    }
    /*

	double xl,xu;
    printf("\nEnter lower and upper bound\n");
    scanf("%lf %lf", &xl, &xu);
    printf("\nEnter relative errror tolerance\n");
    scanf("%lf", &error_tolerance);

	bisection(xl, xu);*/

	return 0;
}

