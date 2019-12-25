/*bubble sort algorithm using function pointers, can input ascending or descending order*/
#include <stdio.h>

/*bubble sort algorithm*/
int bs(int *x,int size,int (*compare)(int x,int y)) {
   int swap=1;
   int i;
   int temp=0;
   /*keep sorting if swapped the iteration before*/
   while (swap==1){
      swap=0;
      /*go through all element in list and swap adjacent values if necessary*/
      for (i=1;i<size;i++){
         /*calling pointer function depending if ascending or descending order is wanted*/
         if (((*compare)(x[i-1],x[i]))==1){
            /*swapping of elements*/
            temp=x[i-1];
            x[i-1]=x[i];
            x[i]=temp;
            swap=1;
         }
      }
   }
   return 1;
}

/*less than function--for descending order*/
int lt(int x, int y) {
   if (x<y){
      return 1;
   }
   return 0;
}

/*greater than function--for ascending order*/
int gt(int x,int y) {
   if (x>y){
      return 1;
   }
   return 0;
}

/*Testing code*/
int main(void) {
   int i=0;
   int vals[10];
   for (i=0;i<10;i=i+1){
      vals[i]=100+i;
   }
   for (i=0;i<10;i++){
      printf("in[%d]=%d\n",i,vals[i]);
   }
   bs(vals, 10, lt);
   for (i=0;i<10;i++){
      printf("out[%d]=%d\n",i,vals[i]);
   }
   return 0;
}