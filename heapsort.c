/*heap sort: lt() will result in a descending sort and a max heap; gt() will result in an ascending sort and a min heap.*/
#include <stdio.h>
#include <stdlib.h>

/*defining struct that will be used for heap*/
typedef struct {
   int *store;
   unsigned int size;
   unsigned int end;
   int (*compare)(int x,int y);
} intHeap_T;


/*heapify: max heap if lt() is used and min heap if gt() is used*/
int store (intHeap_T* heap, int value){
        /*initializing variables*/
        int cnt=0;
        int limit=0;
        int parent,sibling=0;
        int temp=0;
        int i;
        /*error checking*/
        if (heap==NULL){
                return -1;
        }
        if ((*heap).end>(*heap).size){
                return -1;
        }
        heap->store[heap->end]=value;
        heap->end++;
        /*defining the limit variable. the limit variable is the number of levels in the heap/tree structure*/
        if ((*heap).end%2==0){
                limit=((*heap).end)/2;
        }else if ((*heap).end%2==1){
                limit=(((*heap).end)+1)/2;
        }
        /*beginning of sorting/heapifying*/
        while (cnt<(limit)){
                for (i=((*heap).end)-1; i>=2; i=i-2){
                        /*defining parent and sibling value in the heap structure of array values (depends on odd or even number of values in array)*/
                        if (i%2==0){
                                parent=(i-2)/2;
                                sibling=i-1;
                        }else if (i%2==1){
                                parent=(i-1)/2;
                                if (i==(*heap).end-1){
                                        sibling=i;
                                }else{
                                        sibling=i+1;
                                }
                        }
                        /*if parent node is smaller than one of it's children, then swapping of value needs to be done*/
                        if ((heap->compare(heap->store[parent],heap->store[i])==1) || (heap->compare(heap->store[parent],heap->store[sibling])==1)){
                                if (heap->compare(heap->store[sibling],heap->store[i])==1){
                                        temp=heap->store[parent];
                                        heap->store[parent]=heap->store[i];
                                        heap->store[i]=temp;
                                }else{
                                        temp=heap->store[parent];
                                        heap->store[parent]=heap->store[sibling];
                                        heap->store[sibling]=temp;
                                }
                        }
                }
                cnt=cnt+1;
        }
        return 0;
}


/*reheapify (function that will restore the max heap structure (ex: needed when an item is removed from the heap, etc)): swap, take off, put it in rvalue array and then bubble down top node*/
int retrieve(intHeap_T* heap,int *rvalue) {
        /*initializing variables*/
        int idx=0;
        int right_idx=2;
        int left_idx=1;
        int temp_1=0;
        /*error checking*/
        if (heap==NULL){
                return -1;
        }
        if (rvalue==NULL){
                return -1;
        }
        /*changing the values in heap*/
        *rvalue=heap->store[0];
        heap->store[0]=heap->store[(heap->end)-1];
        heap->end=(heap->end)-1;
        /*bubble down*/
        while (((heap->compare(heap->store[idx],heap->store[right_idx])==1) || (heap->compare(heap->store[idx],heap->store[left_idx])==1)) && ((right_idx<=(heap->end)) && (left_idx<=(heap->end)))){
                /*comparing (depending on using lt() or gt() function) to either swap parent node with left or right child node*/
                /*swapping with left child*/
                if (heap->compare(heap->store[left_idx],heap->store[right_idx])==1){
                        /*swapping values*/
                        temp_1=heap->store[idx];
                        heap->store[idx]=heap->store[right_idx];
                        heap->store[right_idx]=temp_1;
                        idx=right_idx;
                        right_idx=(2*idx)+2;
                        left_idx=(2*idx)+1;
                }
                /*swapping with right child*/
                else if (heap->compare(heap->store[right_idx],heap->store[left_idx])==1){
                        /*swapping values*/
                        temp_1=heap->store[idx];
                        heap->store[idx]=heap->store[left_idx];
                        heap->store[left_idx]=temp_1;
                        idx=left_idx;
                        right_idx=(2*idx)+2;
                        left_idx=(2*idx)+1;
                }
        }
        return 0;
}

/*lt() will result in a descending sort and a max heap*/
int lt(int x, int y) {
   if (x<y){
      return 1;
   }
   return 0;
}

/*gt() will result in an ascending sort and a min heap*/
int gt(int x,int y) {
   if (x>y){
      return 1;
   }
   return 0;
}


/*heap sort*/
int hs(int *x,int size,int (*compare)(int x,int y)){
        int i,j,k;
        int rval;
        /*initializing heap struct*/
        intHeap_T heap;
        heap.store=(int*)malloc(size*sizeof(int));
        heap.size=size;
        heap.compare=compare;
        heap.end=0;
        /*loop to put every item in the array in the heap*/
        for (i=0;i<size;i++){
                store(&heap, x[i]);
        }
        /*loop to retrieve item*/
        for (j=0;j<size;j++){
                retrieve(&heap, &rval);
                x[j]=rval;
        }
        return 0;
}


/*testing*/
int main(void){
        intHeap_T heap;
        int x[9]={10,2000,33,24,5,76,7111,98,90};
        int z[9]={10,2000,33,24,5,76,7111,98,90};
        int i=0;
        int j=0;
        int rval=0;
        hs(x,9,gt);
        hs(z,9,lt);
        /*ascending order testing*/
        for (i=0;i<9;i++){
                printf("%dth position: %d \n",i, x[i]);}
        printf("----------------------------- \n");
        /*descending order testing*/
        for (j=0;j<9;j++){
                printf("%dth position: %d \n",j, z[j]);}
        }

