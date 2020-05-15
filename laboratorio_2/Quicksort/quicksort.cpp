#include"quicksort.h"
template<class MEGUMIN,class KAZUMA>
quick_sort<MEGUMIN,KAZUMA>::quick_sort(MEGUMIN* arr,KAZUMA first,KAZUMA size)
{
    this->first = first;
    array = arr;
    this->size = size;
}


template<class MEGUMIN,class KAZUMA>
void quick_sort<MEGUMIN,KAZUMA>::swap(KAZUMA* a,KAZUMA* b){

    MEGUMIN temp;
    temp = *a;
    *a=*b;
    *b
    

}
template<class MEGUMIN,class KAZUMA>
KAZUMA quick_sort<MEGUMIN,KAZUMA>::particion_array(MEGUMIN* array,KAZUMA first,KAZUMA size){

    MEGUMIN pivot = array[size];

    KAZUMA i = first;

    for(KAZUMA j=first;j<=size-1;j++){
        if(array[j] < pivot){
            swap(&array[i],&array[j]);
            i++;
        }
    }
    swap(&array[i],&array[size]);
    return i;
} 

template<class MEGUMIN,class KAZUMA>
void quick_sort<MEGUMIN,KAZUMA>::quicksort(MEGUMIN* array,KAZUMA first,KAZUMA size){
    //aca llamo a particion
    if(first < size){
        KAZUMA indexpi = particion_array(array,first,size);

        //indexpi = idice del pivote
        quicksort(array,first,indexpi-1);
        quicksort(array,indexpi+1,size);
    }

}

template<class MEGUMIN,class KAZUMA>
void quick_sort<MEGUMIN,KAZUMA>::print(){
    MEGUMIN* g = array;

    while(*g != NULL){
        cout<<*g<<" ";
        g++;
    }
} 

template<class MEGUMIN,class KAZUMA>
quick_sort<MEGUMIN,KAZUMA>::~quick_sort()
{
}