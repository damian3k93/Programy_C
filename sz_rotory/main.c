#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 2
#define MAX2 128

void uWiad(FILE *ftp);
int rWiad(FILE *ftp);
void ustR1(FILE *ftp);
int rKodR1(FILE *ftp);
void odczR1(FILE *ftp, char tR1[MAX][MAX2]);
void szR1(FILE *ftp, char tR1[MAX][MAX2]);
void szR2(FILE *ftp, FILE *ftp2, int k);
void odszR2(FILE *ftp, FILE *ftp2, int k);
void odszR1(FILE *ftp, char tR1[MAX][MAX2]);

int main()
{
    FILE *plik, *plik2;
    int zad = 1;
    int rozm;
    char tR1[MAX][MAX2];
    int j;
    int n;

    printf("MASZYNA SZYFRUJACA - ROTORY!\n");

    while((zad=1)||(zad=2)||(zad=3)||(zad=0))
    {

        printf("\n# \tMENU: \t#\n");
        printf("-------------------------\n");
        printf("||  1.Utworz wiadomosc. \n");
        printf("||  2.Ustawienie rotora(1). \n");
        printf("||  3.Odczytaj ustawienie rotora(1). \n");
        printf("||  4.Szyfruj (Rotor1). \n");
        printf("||  5.Szyfruj (Rotor2). \n");
        printf("||  6.Odszyfruj. \n");
        printf("||  0.Zakoncz. \n");
        printf("\n\nWykonaj zadanie nr:");
        scanf("%d",&zad);

        switch(zad)
        {
        case 1:
            {
                uWiad(plik);
                break;
            }
        case 2:
            {
                ustR1(plik);
                break;
            }
        case 3:
            {
                odczR1(plik, tR1);
                rozm = rKodR1(plik);
                printf("\n");
                for(j=0;j<rozm;j++)
                {
                    printf("%c ",tR1[0][j]);
                }
                printf("\n");
                for(j=0;j<rozm;j++)
                {
                printf("%c ",tR1[1][j]);
                }
                printf("\n\n");
                break;
            }
        case 4:
            {
                szR1(plik,tR1);
                break;
            }
        case 5:
            {
                printf("\nO ile przesunac: ");
                scanf("%d",&n);
                szR2(plik,plik2,n);
                break;
            }
        case 6:
            {
                printf("\nO ile bylo przesuniete: ");
                scanf("%d",&n);
                odszR2(plik,plik2,n);
                odszR1(plik,tR1);
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

void uWiad(FILE *ftp){
    char ch={0};
            printf("\nUtworz wiadomosc (Znak # konczy wprowadzanie danych):\n");
            ftp = fopen("wiadomosc.txt","w+");
            if(ftp == NULL)
            {
                printf("\n-->Blad przy probie otwarcia pliku  |wiadmosc|.\n");
                exit(1);
            }
            if(isspace(ch=getchar()));
            while((ch=getchar())!='#')
            {
                fputc(ch,ftp);
            }
            fclose(ftp);
        printf("\n-->Tworzenie pliku |wiadomosc| zakonczone.\n\n");
}

int rWiad(FILE *ftp){
    char ch;
    int roz = 0;
            ftp = fopen("wiadomosc.txt","r");
            if(ftp == NULL)
            {
                printf("\n-->Blad przy probie otwarcia pliku  |wiadmosc|.\n");
                exit(1);
            }
            while((ch=getc(ftp))!=EOF)
            {
                roz++;
            }
            fclose(ftp);
    return roz;
}

void ustR1(FILE *ftp){
char ch;

    printf("\nUtworz ustawienia rotora1 (Znak # konczy wprowadzanie danych):\n");
            ftp = fopen("ustR1.txt","w+");
            if(ftp == NULL)
            {
                printf("\n-->Blad przy probie otwarcia pliku > ustR1 <.");
                exit(1);
            }

            if(isspace(ch=getchar()));
            while((ch=getchar())!='#')
            {
                fputc(ch,ftp);
            }
            fclose(ftp);
        printf("\n-->Tworzenie pliku > ustR1 < zakonczone.\n\n");
}

int rKodR1(FILE *ftp){
    char ch;
    int roz = 0;

            ftp = fopen("ustR1.txt","r");
            if(ftp == NULL)
            {
                printf("\n-->Blad przy probie otwarcia pliku  |wiadmosc|.\n");
                exit(1);
            }
            while((ch=getc(ftp))!=EOF)
            {
                roz++;
            }
            fclose(ftp);
    return (roz-1)/2;
}

void odczR1(FILE *ftp, char tR1[MAX][MAX2]){

    int i = 0;
    int j = 0;
    char ch;
    ftp = fopen("ustR1.txt","r");
        if(ftp == NULL)
        {
            printf("\n-->Blad przy probie otwarcia pliku >ustR1< w funkcji odczR1.\n");
            exit(1);
        }
        while((ch=fgetc(ftp))!=EOF)
        {
            if(ch!='/')
            {
               tR1[i][j]=ch;
                j++;
            }
            if(ch=='/')
            {
                i++;
                j=0;
            }
        }
        fclose(ftp);
        printf("\n-->Odczyt pliku > ustR1 < zakonczone.\n\n");
}

void szR1(FILE *ftp, char tR1[MAX][MAX2]){
    int r;
    FILE *ftp2;
    char ch;
    int j;
    r=rKodR1(ftp);
    printf("Rozmiar: %d",r);
    odczR1(ftp, tR1);
    if((ftp=fopen("wiadomosc.txt","r"))!=NULL)
    {
        if((ftp2=fopen("szR1.txt","w"))!=NULL)
        {
            while((ch=fgetc(ftp))!=EOF)
            {
                if(ch>=65 && ch<=122)
                for(j=0;j<r;j++)
                {
                    if(ch==tR1[0][j])
                    {
                        putc(tR1[1][j],ftp2);
                    }
                }
                else putc(ch,ftp2);
            }
        }
        fclose(ftp2);
    }
    fclose(ftp);
}

void szR2(FILE *ftp, FILE *ftp2, int k){
    char ch;
            if((ftp=fopen("szR1.txt","r"))!=NULL)
            {
                if((ftp2=fopen("plikZASZYFROWANY.txt","w"))!=NULL)
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
    printf("\nSzyfrowanie zostalo zakonczone.\n\n");
}

void odszR2(FILE *ftp,FILE *ftp2, int k){
    char ch;
    if((ftp=fopen("plikZASZYFROWANY.txt","r"))!=NULL)
    {
        if((ftp2=fopen("odszR2.txt","w"))!=NULL)
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
    printf("\nOdszyfrowanie zostalo zakonczone.\n\n");
}

void odszR1(FILE *ftp, char tR1[MAX][MAX2]){
    int r;
    FILE *ftp2;
    char ch;
    int j;
    r=rKodR1(ftp);
    printf("Rozmiar: %d",r);
    odczR1(ftp, tR1);
    if((ftp=fopen("odszR2.txt","r"))!=NULL)
    {
        if((ftp2=fopen("plikODSZYFROWANY.txt","w"))!=NULL)
        {
            while((ch=fgetc(ftp))!=EOF)
            {
                for(j=0;j<r;j++)
                {
                    if(ch==tR1[1][j])
                    {
                        putc(tR1[0][j],ftp2);
                    }
                }
                if ((ch<65)||(ch>125)||(ch=='\0'))
                    {
                        putc(ch,ftp2);
                    }
            }
        }
        fclose(ftp2);
    }
    fclose(ftp);
}
