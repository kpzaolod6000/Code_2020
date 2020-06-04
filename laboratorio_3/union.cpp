
//KELVIN PAUL PUCHO ZEVALLOS        CUI:20180694
//LABORATORIO GRUPO A

#include<iostream>

using namespace std;

static int index1 = 0;
static int index2 = 0;

 //SEGMENTO MAXIMO CON DIVIDE Y VENCERAS
	
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


//SEGMENTO-MAXIMO CON CODIGO LINEAL

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
    
    if(sumamax > 0)
        cout << "La mejor parte de la ruta: "<<ruta+1<<" es entre las calles: "<< e+1 <<" y "<< d+2 <<endl;
    else
        cout << "La ruta: "<< ruta+1 << " no tiene calles interesantes\n";
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
        //SEGMENTO-MAXIMO CON CODIGO LINEAL
        cout<<"SEGMENTO-MAXIMO CON CODIGO LINEAL\n";
        seg_max(i,ARpedidos,nCalles-1);

        //SEGMENTO MAXIMO CON DIVIDE Y VENCERAS
        
        cout << "SEGMENTO MAXIMO CON DIVIDE Y VENCERAS\n";
        int valor_max = seg_max_divide_venceras(ARpedidos,0,nCalles-1);
        cout<<endl<<valor_max<<endl;  
        
        if( valor_max> 0)
            cout << "La mejor parte de la ruta: "<<i+1<<" es entre las calles: "<< index1+1 <<" y "<< index2+2 <<endl;
        else
            cout << "La ruta: "<< i+1 << " no tiene calles interesantes\n";

        
    }
    return 0;
}   
