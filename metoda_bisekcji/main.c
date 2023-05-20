#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double wielomian(double x, double A, double B, double C, double D);

int main()
{
    double a, b, fa, fb, x0, f0;
    double A, B, C, D;
    double eps;


    printf("METODA BISEKCJI\n\n");

    printf("Podaj wspolczynniki wielomianu stopnia 3:\n");
    printf("\nWspolczynnik dla x^3: ");
    scanf("%lf",&A);
    printf("\nWspolczynnik dla x^2: ");
    scanf("%lf",&B);
    printf("\nWspolczynnik dla x: ");
    scanf("%lf",&C);
    printf("\nWyraz wolny: ");
    scanf("%lf",&D);

    printf("\nPodaj przedzial [a,b] UWAGA: a<b:\n");
    printf("\nWartosc a:");
    scanf("%lf",&a);
    printf("\nWartosc b:");
    scanf("%lf",&b);

    printf("\nPodaj wartosc bledu obliczen \nUWAGA przecinek oznaczamy znakiem \".\" :");
    scanf("%lf",&eps);


    fa=wielomian(a,A,B,C,D);
    fb=wielomian(b,A,B,C,D);

    printf("\n");
    printf("f(%f)=%f\n",a,fa);
    printf("f(%f)=%f\n",b,fb);

    if(fa*fb>0)
        printf("Funkcja nie spelnia kryteriow.\n");
    else
    {
        while(fabs(a-b)>eps)
        {
            x0=(a+b)/2;
            f0=wielomian(x0,A,B,C,D);
            printf("\nf(%.10f)=%.10f\n",x0,f0);
            if(fabs(f0)<eps)
            {
                break;
            }
            if(fa*f0<0)
            {
                b=x0;
                fb=f0;
            }
            else
            {
                a=x0;
                fa=f0;
            }
        }
        printf("\nf(%.10f)=%.10f\n",x0,f0);
        printf("\n\nRozwiazanie to x0=%.10f \n\n",x0);
    }

    return 0;
}

double wielomian(double x, double A, double B, double C, double D)
{
    return A*x*x*x+B*x*x+C*x+D;
}
