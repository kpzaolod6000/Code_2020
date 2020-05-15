#include "merge_sort.h"

int main(){

    int arr[]={12,11,13,5,6,7,'\0'};

    int size = sizeof(arr)/sizeof(arr[0]); 
    merge_sort<int,int> obj(arr,0,size-2);
    
    obj.print();
    
    cout<<"\n all fine \n";
    obj.call_break_array();
    cout<<"\n all ordered \n";
    obj.print();

    cout<<"\n all fine \n";

    return 0;
}