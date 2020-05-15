#include<iostream>
#include <chrono>
#include <ctime>

using namespace std;

class Timer
{
public:
    void start()
    {
        m_StartTime = chrono::system_clock::now();
        m_bRunning = true;
    }
    
    void stop()
    {
        
        m_EndTime = chrono::system_clock::now();
        m_bRunning = false;
    }
    
    double elapsedMilliseconds()
    {
        chrono::time_point<std::chrono::system_clock> endTime;
        
        if(m_bRunning)
        {
            endTime = chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }
        
        return chrono::duration_cast<chrono::nanoseconds>(endTime - m_StartTime).count();
    }
    
    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000000.0;
    }

private:
    chrono::time_point<chrono::system_clock> m_StartTime;
    chrono::time_point<chrono::system_clock> m_EndTime;
    bool m_bRunning = false;
};
int* generadors(int tam){
    int* arreglo = new int[tam];
    srand(static_cast<unsigned int>(time(0)));
    int ran;
    
    for(int i=0;i<tam;i++){
        ran=0+rand()%10000;
        arreglo[i] = ran;
    }

    return arreglo;
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0; 
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    { 
        int m = (r+l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 
  
void insert_sort(int* arreglo,int tam){
    int j;
    for(int i=1;i<tam;i++){
        int clave = arreglo[i];
        j=i-1;

        while(j>=0 && arreglo[j]>clave){
            arreglo[j+1]=arreglo[j];
            j=j-1;
        }
        arreglo[j+1]=clave;

    }
    cout<<endl;
}


int main(){


    //int tam;
    //cout<<"Coloque el tamaño:\n";
   // cin >> tam;

    int cont=0;
    int fin;
    int ini;
    cin>>ini;
    cin>>fin;
    for(int tam = ini;tam<=fin;tam++){

    cout<<"\nPara tamaño de "<<tam<<endl;
    int* arreglo = generadors(tam);
    //for(int i=0;i<tam;i++){
      //  cout<<arreglo[i]<<" ";
    //}

    int* arreglo2 = new int[tam];
    for(int i=0;i<tam;i++){
        arreglo2[i] = arreglo[i];
    }

    cout<<endl;

    //INSERT_SORT
    Timer timer;
    timer.start();
    insert_sort(arreglo,tam);
    /////////////////////////////////////////////////////////////////
    timer.stop();
    //for(int i=0;i<tam;i++){
      //  cout<<arreglo[i]<<" ";
    //}
    cout<<endl;
    cout << "Milliseconds: " << timer.elapsedSeconds() <<endl;
    cout << "Nanoseconds: " << timer.elapsedMilliseconds() <<endl;
    auto in = timer.elapsedMilliseconds();
    cout<<"\n";

    //MERSE_SORT
    //for(int i=0;i<tam;i++){
      //  cout<<arreglo2[i]<<" ";
    //}
    cout<<endl;


    Timer timer1;
    timer1.start();
    mergeSort(arreglo2, 0, tam - 1);
    timer1.stop();

    cout<<endl;
    
    //for(int i=0;i<tam;i++){
      //  cout<<arreglo2[i]<<" ";
    //}
    cout<<endl;

    cout << "Milliseconds: " << timer1.elapsedSeconds() <<endl;
    cout << "Nanosegundos: " << timer1.elapsedMilliseconds() <<endl;
    auto in2= timer1.elapsedMilliseconds();
    
    if(in < in2){
        cout<<timer.elapsedMilliseconds()<<" nanosegundos de insert es menor que el "<<timer1.elapsedMilliseconds()<<" nanosegundos del merge\n";
        cont++;
    }
    delete []arreglo;
    delete []arreglo2;
    
    }
    cout<<cont<<endl;
    

    return 0;
}