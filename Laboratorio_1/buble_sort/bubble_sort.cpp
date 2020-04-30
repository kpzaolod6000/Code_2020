#include <iostream>
using namespace std;

int main(){

    int arr[] = {20,25,35,40,44,55,38,99,10,65,50};
    
    int tam = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<tam-1;i++){
        int temp;    
        for(int j=0;j<tam-i-1;j++){
            
            if(arr[j] > arr[j+1]){
                //cout<<"entro";
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }

    for(int i=0;i<tam;i++){
        cout<<arr[i]<<" ";
    }


}