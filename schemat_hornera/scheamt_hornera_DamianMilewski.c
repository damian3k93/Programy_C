#include <stdio.h>
#include <stdlib.h>

#define N 20

int main()
{
    int st;
    int tab[N];
    int i;
    int x;
    int wynik=0;

    printf("PROGRAM: SCHEMAT HORNERA\n\n");

    printf("Podaj stopien wielomianu: ");
    scanf("%d",&st);

    printf("\nWprowadz wspolczynniki wielomianu i wyraz wolny: \n\n");
    for(i=st;i>0;i--)
    {
        printf("Wspolczynnik dla x^%d: ",i);
        scanf("%d",&tab[i]);
    }
    printf("\nWyraz wolny: ");
    scanf("%d",&tab[0]);


    printf("\n\n[TEST]: Sprawdzenie zawartosci tablicy wspolczynnikow: ");
    for(i=st;i>=0;i--)
        printf("%d ",tab[i]);

    printf("\n\n");
    printf("Oblicz wartosc wielomianu dla x=: ");
    scanf("%d",&x);
    wynik = tab[st];
    printf("\n\n[TEST]: Sprawdzenie obliczen: %d\n",wynik);
    for(i=(st-1);i>=0;i--)
    {
        printf("[TEST] Sprawdzenie obliczen: (%d*%d)+%d=",wynik,x,tab[i]);
        wynik=wynik*x+tab[i];
        printf("%d ",wynik);
        printf("\n");
    }
    printf("\n\nWYNIK:\nWartosc wielomianu dla x=%d wynosi %d",x,wynik);
    printf("\n");
    return 0;
}
