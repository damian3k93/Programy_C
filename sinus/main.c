#include <stdio.h>
#include <stdlib.h>

int silnia(int a);
int main()
{
    int n;
    int lp;
    float wynik;
    int x=1;
    printf("Program liczacy wartosc funkcji sin(x) korzystajac z rozwiniecia w szereg.\n\n");
    printf("Podaj dokladnosc dla obliczenia wartosci szeregu: ");
    scanf("%d",&lp);
    for(n=1;n<=lp;n++)
    {
        wynik+=(float)((-1)^(n-1))*(float)(x^(2*n-1)/silnia(2*n-1));
    }

    printf("Wynik: %f    %d",wynik, silnia(2*n-1));

    return 0;
}

int silnia(int a)
{
    if(a>0)
    {
        a=a*silnia(a-1);
    }
    else
        a=1;

    return a;
}
