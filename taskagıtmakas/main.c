#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int tas_kagit_makas (int oyuncu,int bilgisayar){
    if(oyuncu==1 && bilgisayar==1)
        return(2);
    else if (oyuncu==1 && bilgisayar==2)
        return(1);
    else if (oyuncu==1 && bilgisayar==3)
        return(0);
    else if (oyuncu==2 && bilgisayar==1)
        return(0);
    else if (oyuncu==2 && bilgisayar==2)
        return(2);
    else if (oyuncu==2 && bilgisayar==3)
        return(1);
    else if (oyuncu==3 && bilgisayar==1)
        return(1);
    else if (oyuncu==3 && bilgisayar==2)
        return(0);
    else if (oyuncu==3 && bilgisayar==3)
        return(2);
}


int main()
{
    int oyuncu_secim[100],bilgisayar_secim[100],i=0,oyuncu_skor=0,bilgisayar_skor=0;
    srand(time(0));
    while(1){
            Baslama:
            printf("1-)Tas\n2-)Kagit\n3-)Makas    Seciminizi yapiniz: \n");
            scanf("%d",&oyuncu_secim[i]);
            if(oyuncu_secim[i]<1 || oyuncu_secim[i]>3){
                printf("Lutfen 1 ve 3 arasinda secim yapiniz.\n");
                goto Baslama;
            }
            bilgisayar_secim[i]=(rand()%3)+1;

            if(tas_kagit_makas (oyuncu_secim[i],bilgisayar_secim[i])==0){

                oyuncu_skor+=1;
                printf("Bu Turu Oyuncu Kazandi Durum Oyuncu=%d-Bilgisayar=%d\n",oyuncu_skor,bilgisayar_skor);
            }
            else if (tas_kagit_makas (oyuncu_secim[i],bilgisayar_secim[i])==1){

                bilgisayar_skor+=1;
                printf("Bu Turu Bilgisayar Kazandi Durum Bilgisayar=%d-Oyuncu=%d\n",bilgisayar_skor,oyuncu_skor);
            }
            else
                printf("Bu Tur Berabere Bitti.\n");
            if(oyuncu_skor==5 || bilgisayar_skor==5)
                break;

    }

    if(oyuncu_skor==5)
        printf("Oyuncu Kazandi Skor:%d-%d",oyuncu_skor,bilgisayar_skor);
    else
        printf("Bilgisayar Kazandi Skor:%d-%d",bilgisayar_skor,oyuncu_skor);

    return 0;
}
