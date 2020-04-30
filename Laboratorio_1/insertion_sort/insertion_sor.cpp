#include <iostream>
using namespace std;

int main(){

    int arr[] = {20,25,35,40,44,55,38,99,10,65,50};
    
    int tam = sizeof(arr)/sizeof(arr[0]);

    int j;
    for(int i=1;i<tam;i++){
        int clave = arr[i];
        j=i-1;

        while(j>=0 && arr[j]>clave){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=clave;

    }

    for(int i=0;i<tam;i++){
        cout<<arr[i]<<" ";
    }


}