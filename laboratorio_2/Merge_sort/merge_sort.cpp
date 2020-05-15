#include "merge_sort.h"

template<class MEGUMIN,class KAZUMA>
merge_sort<MEGUMIN,KAZUMA>::merge_sort(MEGUMIN* arr,KAZUMA first,KAZUMA size)
{
    this->first = first;
    array = arr;
    this->size = size;
}


template<class MEGUMIN,class KAZUMA>
void merge_sort<MEGUMIN,KAZUMA>::break_array(MEGUMIN* array,KAZUMA first,KAZUMA size){
    
    if(first < size){
        
        KAZUMA middle = (first+size)/2;

        break_array(array,first,middle);
        break_array(array,middle+1,size);
        //merge(array,first,middle,size); 
    }

}

template<class MEGUMIN,class KAZUMA>
void merge_sort<MEGUMIN,KAZUMA>::merge(MEGUMIN* array,KAZUMA first,KAZUMA middle,KAZUMA size){

    KAZUMA i,j,k;
    //i = block left
    //j = block right
    //k = put a data in the main array

    KAZUMA index1 = middle - first + 1;  
    KAZUMA index2 = size - middle;

    MEGUMIN Left[index1],Right[index2];

    for(KAZUMA i=0;i<index1;i++){
        Left[i] = array[first+i];
    }
    for(KAZUMA j=0;j<index2;j++){
        Right[j] = array[middle+j+1];
    }
    i=0;
    j=0;
    k=first;

    while(i<index1 && j<index2){
        if(Left[i] <= Right[j]){
            array[k] = Left[i];
            i++;
        }else
        {
            array[k] = Right[j];
            j++;
        }
        k++;
    }

    while(i<index1){
        array[k] = Left[i];
        i++;
        k++;
    }

    while(j<index2){
        array[k] = Right[j];
        j++;
        k++;
    }

}

template<class MEGUMIN,class KAZUMA>
void merge_sort<MEGUMIN,KAZUMA>::print(){
    MEGUMIN* g = array;

    //cout<<"h: "<<size<<endl;
    KAZUMA i=0;
    while(*g != NULL){
        cout<<i<<" : "<<*g<<"\n";
        g++;
        i++;

    }
} 

template<class MEGUMIN,class KAZUMA>
merge_sort<MEGUMIN,KAZUMA>::~merge_sort()
{
}
