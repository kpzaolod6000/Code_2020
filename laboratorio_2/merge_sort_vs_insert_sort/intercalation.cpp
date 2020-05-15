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
void insert_sort(int* arreglo,int ini,int tam){
    int j;
    for(int i=ini;i<=tam;i++){
        int clave = arreglo[i];
        j=i-1;

        while(j>=ini && arreglo[j]>clave){
            arreglo[j+1]=arreglo[j];
            j=j-1;
        }
        arreglo[j+1]=clave;

    }
    cout<<endl;
}

void intercalar(int* arreglo,int p,int q,int r){
    int* aux = new int[r+1];
    for(int i=p;i<=q;i++){
        aux[i] = arreglo[i]; 
    }
    for(int j=q+1;j<=r;j++){
        aux[r+q+1-j] = arreglo[j];
    }
    cout<<endl;
    
    int i = p;
    int j = r;
    for(int k=p ;k<=r;k++){
        if(aux[i]<=aux[j]){
            arreglo[k] = aux[i];
            i=i+1;
        }else{
            arreglo[k] = aux[j];
            j=j-1;
        }
    }
}
void intercalar2(int* arreglo,int p,int q,int r){
    int aux[q+1],aux2[r+1];
    q=q+1;
    int tam1 = q;//3
    int tam2 = r-q; //3   

    for (int i = 0; i < q; i++) 
        aux[i] = arreglo[i]; 
    for (int j = 0; j <= r-q ; j++) //q=3 y r=6
        aux2[j] = arreglo[q+j];
/*
    for(int i = 0; i < q; i++)
        cout<< aux[i]<<" ";
    cout <<endl;
    for(int j = 0; j <=r-q ; j++)
        cout<< aux2[j]<<" ";
*/
    int i=0;
    int j=0;
    int k=0;
    while (i < tam1 && j <= tam2) 
    { 
        if (aux[i] <= aux2[j]) 
        { 
            arreglo[k] = aux[i]; 
            i++; 
        } 
        else
        { 
            arreglo[k] = aux2[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < tam1) 
    { 
        arreglo[k] = aux[i]; 
        i++; 
        k++; 
    } 
  
    while (j <= tam2) 
    { 
        arreglo[k] = aux2[j]; 
        j++; 
        k++; 
    } 

    cout<<endl;
}


int main(){

    int tam;
    int ini =0;
    
    cout<<"coloque tamaño: \n";
    cin>>tam;
    int* arreglo = generadors(tam);

    //antes
    //for (int i=0;i<tam;i++){
      //  cout<<arreglo[i]<<" ";
    ////}

    insert_sort(arreglo,ini,(tam/2)-1);
    insert_sort(arreglo,(tam/2),tam-1);
    //////////////////////////////

    //despues
    //for (int i=0;i<tam;i++){
      //  cout<<arreglo[i]<<" ";
    //}
    int* arreglo2 = new int[tam];

    for (int i=0;i<tam;i++){
        arreglo2[i] = arreglo[i];
    }

    cout<<endl;

    //INTERCALAR
    int r=tam-1;
    int q = (tam/2)-1; 
    int p = 0;

    Timer timer;
    timer.start();

    intercalar(arreglo,p,q,r);
    timer.stop();
    //for (int i=0;i<tam;i++){
     //   cout<<arreglo[i]<<" ";
   // }

    cout<<endl;

    cout << "Milliseconds: " << timer.elapsedSeconds() <<endl;
    cout << "Nanosegundos: " << timer.elapsedMilliseconds() <<endl;

    //
    cout<<endl;
    //INTERCALAR SIN INVERTIR

    Timer timer1;
    timer1.start();
    intercalar2(arreglo2,p,q,r);
    timer1.stop();
    cout << endl;
    //for (int i=0;i<tam;i++){
      //  cout<<arreglo2[i]<<" ";
    //}

    cout << endl;
    cout << "Milliseconds: " << timer1.elapsedSeconds() <<endl;
    cout << "Nanosegundos: " << timer1.elapsedMilliseconds() <<endl;
    cout<<endl;
    return 0;
}