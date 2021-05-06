#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x,f,a,b;
float durmaKosul,deger,kontrol,g,temp, temp2,i;
int sayac = 0;
float iterasyon(float a, float b,float temp ,float temp2);
float aralik_hesapla(float a, float b);
float fonk(float x);

int main()
{
    printf("A degerini giriniz > ");
    scanf("%d", &a);

    printf("B degerini giriniz > ");
    scanf("%d", &b);

    if(b<a){
        printf("Alt sinir, ust sinirden buyuk olamaz!!!!!");
    }else{
    aralik_hesapla(a,b);
    }
}

float fonk(float x){

    g = (2*pow(x,3) - (3*pow(x,2)) - (4*x) + 5);
    return g;
}

float aralik_hesapla(float a, float b){

    fonk(a);
    printf("A = %.4f icin fonksiyon =>  %.4f\n",a, g);
    temp = g;

    fonk(b);
    printf("B = %.4f icin fonksiyon =>  %.4f\n",b, g);
    temp2 = g;

    kontrol = temp * temp2;

    if(kontrol < 0){
        printf("[%.4f,%.4f] Bu aralikta kok vardir\n",a,b);
        printf("----------------------------------------------------------\n");
        iterasyon(a,b,temp,temp2);
    }else{
        printf("[%.4f,%.4f] Bu girilen aralikta kok yoktur!!!!\n",a,b);
    }
}

float iterasyon(float a, float b, float temp, float temp2){

    sayac++;
    deger = (a+b)/ (float) 2;
    fonk(deger);
    durmaKosul = ((b-a)/pow(2,sayac));
    if(durmaKosul < 0.001 ){
        printf("degeri buldunuz ->>> %f  \n\n\n", deger);
    }else if(g * temp2 < 0){
        aralik_hesapla(deger,b);

    }else {
        aralik_hesapla(a,deger);
    }
}
