#include<iostream>
#include<random>
#include<ctime>


using namespace std;


// Generador de Arreglos 
int* generadors(int tam){
    int* arreglo = new int[tam];
    srand(static_cast<unsigned int>(time(0)));
    int ran;
    
    for(int i=0;i<tam;i++){
        ran=0+rand()%1001; // rango de 0 a 1000
        arreglo[i] = ran;
    }

    return arreglo;
}

    

int main(){
    
    int tam;
    cout<<"tamanho: ";cin>>tam;
    

    int* arreglo;
    arreglo = generadors(tam);
    

    //print 
    cout <<"\n";
    for(int i=0;i<tam;i++){
        cout<<arreglo[i]<<" ";
    }
    //

    cout <<"\n";
    delete []arreglo;
    cout<<"eliminado\n";
    return 0;
}