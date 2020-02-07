#include<bits/stdc++.h>
using namespace std;
double f(double x)
{
    return x*x-4*x-10;
}
void _print(double x0,double x1,double x2)
{
    double error = abs(x2-x1)/x2;
    printf("%lf   %lf   %lf   %lf\n",x0,x1,x2,error);
}
int main()
{

    freopen("false_position.txt","w",stdout);
    double x0=4,x1=9;
    int l=10;
    cout<<"x0       x1           x2         error\n";
    while(l--)
    {

        double x2 = x0-((f(x0)*(x1-x0))/(f(x1)-f(x0)));

        _print(x0,x1,x2);

        if(f(x2)*f(x0)<0) x1=x2;
        else x0=x2;
    }

}
