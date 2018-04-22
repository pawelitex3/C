#include<stdio.h>

int main(void)
{
    double odlegloscA, odlegloscB, odlegloscC, odlegloscD, x, y, pole;
    long ilosc_puntkow, i, punkty_nalezace, a;

    scanf("%ld %ld", &ilosc_puntkow, &a);
    while(ilosc_puntkow!=0){

        punkty_nalezace=0;
        for(i=0; i<ilosc_puntkow; i++){
            scanf("%lf %lf", &x, &y);
            odlegloscA=x*x+y*y;
            odlegloscB=(x-a)*(x-a)+y*y;
            odlegloscC=(x-a)*(x-a)+(y-a)*(y-a);
            odlegloscD=x*x+(y-a)*(y-a);
            if(odlegloscA<=a*a && odlegloscB<=a*a && odlegloscC<=a*a && odlegloscD<=a*a) punkty_nalezace++;
        }

        pole=punkty_nalezace*a*a;
        pole = pole/ilosc_puntkow;
        printf("%.05lf\n", pole);
        scanf("%ld %ld", &ilosc_puntkow, &a);

    }





    return 0;

}
