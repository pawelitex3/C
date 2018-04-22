#include<stdio.h>
#include<string.h>

int liczby[] = {
                -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000
                };

char slowa[32][10] = {"negative", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                    "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"
                    };

int ktoraLiczba(char * liczba)
{
    char *wskaznik;
    int i;
    for(i=0; i<32; i++){
        wskaznik = slowa[i];
        if(!strncmp(liczba, wskaznik, 6)) return i;
    }
    return 0;
}

int main(void)
{
    char wiersz[200];
    char *next;
    long int liczba, przetwarzana, ktora, negacja;
    while(fgets(wiersz, 200, stdin) != NULL){
        liczba=0;
        przetwarzana=0;
        negacja=0;
        next = (char*) strtok(wiersz, " \t\n");
        while(next!=NULL){

            ktora = ktoraLiczba(next);
            if(ktora==0) negacja=1;
            else{
                if(ktora>29){
                    przetwarzana*=liczby[ktora];
                    liczba+=przetwarzana;
                    przetwarzana=0;
                }
                else{
                    if(ktora==29){
                        przetwarzana*=liczby[ktora];
                    }
                    else przetwarzana+=liczby[ktora];
                }
            }



            next = (char*) strtok(NULL, " \t\n");
        }
        liczba+=przetwarzana;
        if(negacja) printf("-%ld\n", liczba);
        else printf("%ld\n", liczba);
    }




    return 0;
}
