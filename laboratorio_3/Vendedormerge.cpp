#include<iostream>

using namespace std;
static int index1 = 0;
static int index2 = 0;

int maxtres(int maxizq, int maxcruz, int maxder)
{
	int valormax = max(maxizq,maxcruz);
	return max(valormax, maxder);
}


int seg_max_divide_venceras(int* array, int p, int r)
{
	if ( p == r) 
        return max(0, array[p]);
	
	int q= (p+r)/2;
	int maxizq, maxder, max2izq, suma = 0;

	maxizq = seg_max_divide_venceras(array, p, q);
	maxder =  seg_max_divide_venceras(array, q+1, r);

	max2izq =suma = array[q];
    
    for (int i = q-1; i >= p ; i--)
	{
		suma = suma + array[i];
        max2izq = max(max2izq, suma);
        if( max2izq <= suma){
            index1 = i;
        }
		
    }
    int max2der = suma = array[q+1];

	for (int j = q+2; j <= r; ++j)
	{
		suma = suma + array[j];
		max2der = max(max2der, suma);
        //cout<< j << " / ";
        if( max2der <= suma){
            index2 = j;
        }
		
	}
	int maxcruz = max2izq + max2der;
    return maxtres(maxizq,maxcruz,maxder);
}

int main(){  
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
        int valor_max = seg_max_divide_venceras(ARpedidos,0,nCalles-1);
        cout<<endl<<valor_max<<endl;  
        
        if( valor_max> 0)
            cout << "La mejor parte de la ruta: "<<i+1<<" es entre las calles: "<< index1+1 <<" y "<< index2+2 <<endl;
        else
            cout << "La ruta: "<< i+1 << " no tiene calles interesantes\n";
    }
        
}