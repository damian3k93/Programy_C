#include <stdio.h>
#include <stdlib.h>

#define MAX 32
#define MAX2 256

void utworzWiad(FILE *ftp,int lp);
void szyfruj(FILE *ftp, FILE *ftp2,FILE *ftp3, int plotek, int lp, char tab[MAX2][MAX]);
void odszyfruj(FILE *ftp, FILE *ftp2, int plotek, int lp, char tab[MAX2][MAX]);

int main()
{
    int zad=1;
    int lp;
    FILE *plik, *plik2, *plik3;
    int plotek;
    char tab[MAX2][MAX]={0};
    printf("PROGRAM SZYFRUJACY - 'PLOTEK'");
    while((zad=1)||(zad=0))
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
                printf("\nPodaj wysokosc plotka:");
                scanf("%d",&plotek);
                printf("\nPodaj liczbe plikow do szyfrowania: ");
                scanf("%d",&lp);
                szyfruj(plik, plik2, plik3, plotek, lp, tab);
                break;
            }
        case 3:
            {
                printf("Podaj wysokosc plotka: ");
                scanf("%d",&plotek);
                printf("Podaj liczbe plikow do odszyfrowania: ");
                scanf("%d",&lp);
                odszyfruj(plik, plik2, plotek, lp, tab);
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
            printf("\nWskazowka! Znak # i [ENTER] konczy wprowadzanie tekstu.\n");
            ftp = fopen(nazwapliku,"w+");
            if(ftp == NULL)
            {
                printf("\n-->Blad przy probie otwarcia pliku.\n");
                exit(1);
            }

            while((ch=getchar())!='#')
            {
                fputc(ch,ftp);
            }
            fclose(ftp);
        }
        printf("\n-->Tworzenie plikow zakonczone.\n\n");
}

void szyfruj(FILE *ftp, FILE *ftp2,FILE *ftp3, int plotek, int lp, char tab[MAX2][MAX])
{
    int i;
    int j = 0;
    int k = 0;
    char nazwapliku[MAX];
    char nazwapliku2[MAX];
    char ch;
    int rozm=0;
    int z=0;
    char tab2[MAX2]={0};
    int tabP[MAX2]={0};

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
                    while((ch=fgetc(ftp))!=EOF)
                    {
                        tab2[z]=ch;
                        rozm++;
                        z++;
                    }
                        for(k=0;k<plotek;k++)
                        {
                            for(j=0;j<rozm;j++)
                            {
                                tab[j][k]='*';
                            }
                        }
                        printf("\n\nTEST: \n");
                        for(k=0;k<plotek;k++)
                        {
                            for(j=0;j<rozm;j++)
                            {
                                printf("%c ",tab[j][k]);
                            }
                            printf("\n");
                        }
                        printf("\n\nTEST 2:\n");
                        for(z=0;z<rozm;z++)
                        {
                            printf("%c ",tab2[z]);
                        }
                        int s=-1;
                        k=0;
                        for(j=0;j<rozm;j++)
                        {
                            if(j%(plotek-1)==0)
                            {
                                s=-1*s;
                                tabP[j]=0;
                            }
                            if(s==1)
                            {
                                tabP[j]=k;
                                k++;
                            }
                            if(s==-1)
                            {
                                tabP[j]=k;
                                k--;
                            }
                        }
                        printf("\n\nTEST 3:\n");
                            for(j=0;j<rozm;j++)
                            {
                                printf("%d ",tabP[j]);
                            }

                        for(j=0;j<rozm;j++)
                        {
                            tab[j][tabP[j]]=tab2[j];
                        }
                        printf("\n\nTEST 4: \n");
                        for(k=0;k<plotek;k++)
                        {
                            for(j=0;j<rozm;j++)
                            {
                                printf("%c ",tab[j][k]);
                            }
                        }

                        for(k=0;k<plotek;k++)
                        {
                            for(j=0;j<rozm;j++)
                            {
                                if(tab[j][k]!='*')
                                {
                                    putc(tab[j][k],ftp2);
                                }
                            }
                            printf("\n");
                        }


                        fclose(ftp2);
                }
                fclose(ftp);
            }
    }
    printf("\n-->Szyfrowanie zostalo zakonczone.\n\n");
}
void odszyfruj(FILE *ftp, FILE *ftp2, int plotek, int lp, char tab[MAX2][MAX])
{
    int i;
    int j;
    char nazwapliku[MAX];
    char nazwapliku2[MAX];
    char ch;
    int rozm=0;
    char tab2[MAX2]={0};
    int tabP[MAX2]={0};
    int z=0;
    int k=0;

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
                        tab2[z]=ch;
                        rozm++;
                        z++;
                    }

                    printf("\n\nTEST: \n");
                    for(k=0;k<plotek;k++)
                    {
                        for(j=0;j<rozm;j++)
                        {
                            printf("%c ",tab[j][k]);
                        }
                        printf("\n");
                    }
                    for(j=0;j<rozm;j++)
                        {
                            for(k=0;k<plotek;k++)
                            {
                                if(tab[j][k]!='*')
                                {
                                    putc(tab[j][k],ftp2);
                                }
                            }
                        }
                fclose(ftp2);
                }
                fclose(ftp);
            }
    }
    printf("\n--> Odszyfrowanie zostalo zakonczone.\n\n");
}

