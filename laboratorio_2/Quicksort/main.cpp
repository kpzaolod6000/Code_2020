#include "quicksort.h"

int main(){

    int arr[]={12,11,13,5,6,7,'\0'};

    int size = sizeof(arr)/sizeof(arr[0]); 
    quick_sort<int,int> obj(arr,0,size-2);
    
    obj.print();
    
    cout<<"\n all fine \n";
    obj.call_quicksort();
    cout<<"\n all ordered \n";
    obj.print();

    cout<<"\n all fine \n";

    return 0;
}