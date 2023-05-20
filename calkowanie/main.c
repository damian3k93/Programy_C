#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);

double met_prost(double a, double b, double n); //definicja ca³ki Riemanna
double met_trap(double a, double b, double n);
double met_parab(double a, double b, double n); //metoda Simpsona

int main()
{
    printf("# CALKOWANIE NUMERYCZNE #\n\n");

    double w = 0.8414709848;
    double xp, xk, n;
    double wynik;
    printf("Wprowadz przedzial [a,b]:\n");
    printf("\nPoczatek przedzialu to: ");
    scanf("%lf",&xp);
    printf("\nKoniec przedzialu to: ");
    scanf("%lf",&xk);
    printf("\nNa ile podzielic przedzial: ");
    scanf("%lf",&n);

    printf("\n\nWprowadzony przedzial to: [%.0lf;%.0lf] i podzielono na %.0lf ",xp,xk,n);

    printf("\n\nPoprawny wynik dla funkcji f(x)=cos(x)do 10 miejsc po przecinku:\n");
    printf("\n                      \t WYNIK\t\t BLAD BEZWZGLEDNY   BLAD WZGLEDNY");
    printf("\n Wynik poprawny:    \t %.10lf",w);
    wynik = met_prost(xp, xk, n);
    printf("\n Wynik metody prost:\t %.10lf\t %.10lf\t    %.10lf%%",wynik,fabs(w-wynik),fabs(w-wynik)/w*100);
    wynik = met_trap(xp, xk, n);
    printf("\n Wynik metody trap: \t %.10lf\t %.10lf\t    %.10lf%%",wynik,fabs(w-wynik),fabs(w-wynik)/w*100);
    wynik = met_parab(xp, xk, n);
    printf("\n Wynik metody parab:\t %.10lf\t %.10lf\t    %.10lf%%\n",wynik,fabs(w-wynik),fabs(w-wynik)/w*100);
    return 0;
}

double f(double x){
    return (cos(x));
}

double met_prost(double a, double b, double n){
    double s = 0;
    double d;
    int i;

    d = (b-a)/n;
    for(i=1;i<=n;i++)
        s+=f(a+i*d);
    s *= d;

    return s;
}

double met_trap(double a, double b, double n){
    double h;
    double s = 0;
    double podst1;
    double podst2;
    int i;

    h = (b-a)/n;
    podst1 = f(a);

    for(i=1;i<=n;i++)
    {
        podst2 = f(a+h*i);
        s += (podst1+podst2);
        podst1 = podst2;
    }

    return s*0.5*h;
}

double met_parab(double a, double b, double n){
    double s = 0;
    double st = 0;
    double d;
    int i;
    double x = 0;

    d = (b-a)/n;

    for(i=1;i<=n;i++)
    {
        x = a+d*i;
        st += f(x-d/2);
        if(i<n) s+=f(x);
    }

    return (d/6*(f(a)+f(b)+2*s+4*st));
}
