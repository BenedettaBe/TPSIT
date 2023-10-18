#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 5

void scambio(int *v1,int *v2){
int v;
v=*v1;
*v1= *v2;
*v2=v;
}

void bubbleSort3(int vett[], int n) { 
int k,sup,sca;
  sup= n-1 ;
  while ( sup>0 )  {
    sca=0 ;
    for (k = 0; k < sup ; k++) {
      if (*(vett+k)> *(vett+k+1)){
        scambio(*(vett+k) , *(vett+k+1));
        sca=k ;

       } }
sup=sca ; }
}

void StampaVett(int vett[], int n){
for(int k=0; k<DIM;k++){
printf("%d   ",*(vett+k));
}}


int main(){
int vett[DIM]={3,2,5,6,1};

bubbleSort3(vett, DIM);
stampaVett(vett, DIM);
return 0;
}