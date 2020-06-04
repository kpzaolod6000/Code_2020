#include<iostream>

using namespace std;

void seg_max(int ruta,int* array , int tam){
    int sumamax = 0;
    int e = 0;
    int d = -1;
    int suma = 0;
    int i = 0;
    int j = -1;

    while(j < tam-1){
        j = j+1;
        suma = suma + array[j];
        if(suma < 0 )
        {
            suma = 0;
            i=j+1;
        }
        else if (suma >= sumamax)
        {
            sumamax = suma;
            e=i;
            d=j;
        }
        
    }
    
    /*
    for(int i = 0; i< tam ; i++){
        int suma = 0;
        for(int j = i ; j<tam; j++){
            suma = suma + array[j];
            if(suma >= sumamax){
                sumamax = suma;
                e=i;
                d=j;
            }
        }
    }*/
    if(sumamax > 0)
        cout << "La mejor parte de la ruta: "<<ruta+1<<" es entre las calles: "<< e+1 <<" y "<< d+2 <<endl;
    else
        cout << "La ruta: "<< ruta+1 << " no tiene calles interesantes\n";
}

int main(){
    //int nRC[100000][20000];
    
    int nCalles;
    int nRutas;

    int array[100000];
    int ARpedidos[20000] = {};

    int npedidos;
    cin >> nRutas;
    for(int i = 0;i < nRutas ; i++){
        cin>>nCalles;
        for(int j = 0 ; j < nCalles ; j++){
            array[j]= j+1;
        }
        for(int k = 0 ; k < nCalles-1 ; k++){
            cin >> npedidos;
            ARpedidos[k] = npedidos;
        }

        //for(int h = 0; h<nCalles - 1 ; h++)
          //  cout << ARpedidos[h] << " ";
        //cout << endl;
        seg_max(i,ARpedidos,nCalles-1);

        
}

/*
    cin >> nRutas;
    for(int i = 0; i < 3 ; i++){
        cin >> nCalles;
        if(nRutas != i){
            for(int j = 0; j < 4 ; j++){
                if(nCalles != j)
                    nRC[i][j] = 0;
                
            }
        }
        for(int i = 0; i < nRutas ; i++){
            for(int j = 0; j < nCalles ; j++){
                cout << nRC[i][j]<<  " ";
            }
            cout << endl;
        }
    
    }
    
    
    **/
    return 0;

}