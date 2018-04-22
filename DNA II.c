#include<stdio.h>
#include<string.h>

int main(void)
{
    int testy, licznik, dlugosc, i;
    unsigned long long int wagi[32];
    unsigned long long int liczba;
    char napis[50];

    wagi[0]=1;
    for(i=1; i<32; i++){
        wagi[i]=wagi[i-1]*4;
    }

    licznik=1;

    scanf("%d\n", &testy);

    while(testy--){
        liczba=0;
        fgets(napis, 50, stdin);
        dlugosc=strlen(napis);
        for(i=0; i<dlugosc; i++){
            if(napis[i]=='C') liczba+=wagi[dlugosc-i-2];
            if(napis[i]=='G') liczba+=2*wagi[dlugosc-i-2];
            if(napis[i]=='T') liczba+=3*wagi[dlugosc-i-2];
        }
        printf("Case %d: (%d:%llu)\n", licznik, dlugosc-1, liczba);
        licznik++;
    }

    return 0;
}
