#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    char wiersz[60], slowo[60];
    int dlugosc_wiersza, i, dlugosc_slowa, j, myslnik;

    fgets(wiersz, 60, stdin);
    dlugosc_wiersza=strlen(wiersz);
    dlugosc_slowa=0;
    myslnik=0;
    while(!(dlugosc_wiersza==2 && wiersz[0]=='#')){
        for(i=0; i<dlugosc_wiersza; i++){
            if(isalpha(wiersz[i])){
                slowo[dlugosc_slowa]=wiersz[i];
                dlugosc_slowa++;
            }
            else{
                if(wiersz[i]=='-'){
                    myslnik=1;
                    break;
                }
                else{
                    if(isspace(wiersz[i])){
                        for(j=0; j<dlugosc_slowa; j++){
                            printf("%c", slowo[j]);
                        }
                        if(myslnik){
                            printf("\n");
                            myslnik=0;
                        }
                        dlugosc_slowa=0;
                        printf("%c", wiersz[i]);
                    }
                }
            }
        }
        fgets(wiersz, 60, stdin);
        dlugosc_wiersza=strlen(wiersz);
    }

    return 0;
}
