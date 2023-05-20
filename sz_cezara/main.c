#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 32

void utworzWiad(FILE *ftp, int lp);
void szyfruj(FILE *ftp, FILE *ftp2, int k, int lp);
void odszyfruj(FILE *ftp, FILE *ftp2, int k, int lp);

int main()
{
    int zad=1;
    int lp;
    FILE *plik, *plik2;
    int klucz;

    printf("PROGRAM SZYFRUJACY/ODSZYFROWUJACY - SZYFR CEZAR'A\n\n");

    while((zad=1)||(zad=2)||(zad=3)||(zad=0))
    {
        printf("   --------------------\n");
        printf("   | 1. Utworz plik.  |\n");
        printf("   | 2. Szyfruj.      |\n");
        printf("   | 3. Odszyfruj.    |\n");
        printf("   | 0. Zakoncz.      |\n");
        printf("   --------------------\n");
        printf("\n Wykonaj zadanie nr: ");
        scanf("%d",&zad);

        switch(zad)
        {
        case 1:
            {
                printf("\nPodaj liczbe plikow do utworzenia: ");
                scanf("%d",&lp);
                utworzWiad(plik,lp);
                break;
            }
        case 2:
            {
                printf("Podaj klucz szyfrowania: ");
                scanf("%d",&klucz);
                printf("Podaj liczbe plikow do szyfrowania: ");
                scanf("%d",&lp);
                szyfruj(plik, plik2, klucz, lp);
                break;
            }
        case 3:
            {
                printf("Podaj klucz odszyfrowania: ");
                scanf("%d",&klucz);
                printf("Podaj liczbe plikow do odszyfrowania: ");
                scanf("%d",&lp);
                odszyfruj(plik, plik2, klucz, lp);
                break;
            }
        case 0:
            {
                printf("Zakonczono dzialanie programu.\n");
                exit(0);
            }
        }
    }
    return 0;
}

void utworzWiad(FILE *ftp,int lp)
{
    int i;
    char nazwapliku[MAX];
    char ch;

    for(i=0;i<lp;i++)
        {
            printf("\nPodaj nazwe pliku: ");
            scanf("%s", nazwapliku);
            printf("\nWprowadz tekst: \n");
            printf("\nWskazowka! Znak ^ i [ENTER] konczy wprowadzanie tekstu.\n");
            ftp = fopen(nazwapliku,"w+");
            if(ftp == NULL)
            {
                printf("\nBlad przy probie otwarcia pliku.\n");
                exit(1);
            }

            while((ch=getchar())!='^')
            {
                putc(ch,ftp);
            }
            fclose(ftp);
        }
        printf("\nTworzenie plikow zakonczone.\n\n");
}

void szyfruj(FILE *ftp, FILE *ftp2, int k, int lp)
{
    int i;
    char nazwapliku[MAX];
    char nazwapliku2[MAX];
    char ch;

    for(i=0;i<lp;i++)
    {
        printf("\nPodaj nazwe pliku, ktory przechowuje tekst do zaszyfrowania:  ");
            scanf("%s", nazwapliku);
        printf("\nPodaj nazwe przechowujaca plik zaszyfrowany: ");
            scanf("%s", nazwapliku2);
            if((ftp=fopen(nazwapliku,"r"))!=NULL)
            {
                if((ftp2=fopen(nazwapliku2,"w"))!=NULL)
                {
                    while((ch=getc(ftp))!=EOF)
                    {
                        if ((ch>=32)&&(ch<=125))
                        {
                            ch-=32;
                            ch+=k;
                            ch%=94;
                            ch+=32;
                            putc(ch,ftp2);
                        }
                        else if ((ch<32)||(ch>125)||(ch=='\0'))
                        {
                         putc(ch,ftp2);
                        }
                    }
                    fclose(ftp2);
                }
                fclose(ftp);
            }
    }
    printf("\nSzyfrowanie zostalo zakonczone.\n\n");
}

void odszyfruj(FILE *ftp,FILE *ftp2, int k, int lp)
{
    int i;
    char nazwapliku[MAX]={0};
    char nazwapliku2[MAX]={0};
    char ch;

    for(i=0;i<lp;i++)
    {
        printf("\nPodaj nazwe pliku, ktory przechowuje tekst do odszyfrowania:  ");
            scanf("%s", nazwapliku);
        printf("\nPodaj nazwe przechowujaca plik odszyfrowany: ");
            scanf("%s", nazwapliku2);
            if((ftp=fopen(nazwapliku,"r"))!=NULL)
            {
                if((ftp2=fopen(nazwapliku2,"w"))!=NULL)
                {
                    while((ch=getc(ftp))!=EOF)
                    {
                        if ((ch>=32)&&(ch<=125))
                        {
                            ch-=32;
                            ch-=k;
                            if(ch<0)
                                ch=94-fabs(ch);
                            ch+=32;
                            putc(ch,ftp2);
                        }
                        else if ((ch<32)||(ch>125)||(ch=='\0'))
                        {
                         putc(ch,ftp2);
                        }
                    }
                    fclose(ftp2);
                }
                fclose(ftp);
            }
    }
    printf("\nOdszyfrowanie zostalo zakonczone.\n\n");

}
