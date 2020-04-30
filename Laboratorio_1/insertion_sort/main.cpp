#include "insertion_sort111.h"

int main(){

    int arr[] = {20,25,35,40,44,55,38,99,10,65,50};
    
    int tam = sizeof(arr)/sizeof(arr[0]);
    //cout<< tam;

    Insertions<int> obj(&arr[0],tam);

    cout<<"linea "<<arr;
    obj.print();
    obj.order();
    obj.print();
    
    return 0;
}