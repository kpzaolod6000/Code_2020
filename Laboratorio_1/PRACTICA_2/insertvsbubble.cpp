#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>



void Insertion_sort(int*,int,int,unsigned long long int,int);
void Bubble_sort(int*,int,int,unsigned long long int,int);
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
        
        return chrono::duration_cast<chrono::milliseconds>(endTime - m_StartTime).count();
    }
    
    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }

private:
    chrono::time_point<chrono::system_clock> m_StartTime;
    chrono::time_point<chrono::system_clock> m_EndTime;
    bool                                               m_bRunning = false;
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

int* generadorcreciente(int tam){
    int* arreglo = generadors(tam);
    Insertion_sort(arreglo,tam,0,0,0);
    return arreglo;
}
int* generadordecreciente(int tam,int* newarr){

    int* arreglo = new int[tam];
    for(int i=tam-1,j=0;i>=0;j++,i--){
        arreglo[j] = newarr[i]; 
    }
    return arreglo;
}


void Insertion_sort(int* arreglo,int tam,int memory1,unsigned long long int asignaciones1,int comparaciones1){
    //INSERT_SORT
    Timer timer;
    timer.start();
    
    int j,clave;
    memory1+=sizeof(int);
    memory1+=sizeof(int);
    memory1+=sizeof(int);;// for i++
    for(int i=1;i<tam;i++){
 
        ++asignaciones1;// for i++
        ++comparaciones1;// i<tam

        clave = arreglo[i];
        j=i-1;
        asignaciones1+=2;// dos asignaciones

        while(j>=0 && arreglo[j]>clave){
            
            comparaciones1+=2; // j>=0 && arreglo[j]>clave
            
            arreglo[j+1]=arreglo[j];
            j=j-1;
            asignaciones1+=2;   
        }
        arreglo[j+1]=clave;
        ++asignaciones1;

    }

    timer.stop();


    cout<<"\nINSERT_SORT\n";
    cout<<"Numero de asignaciones: "<<8*asignaciones1<<endl;
    cout<<"Numero de comparaciones: "<<2*comparaciones1<<endl;
    cout<<"Numero de asignacion de memoria: "<<memory1<<" en byte"<<endl;
    cout << "Seconds: " << timer.elapsedSeconds() <<endl;
    cout << "Milliseconds: " << timer.elapsedMilliseconds() <<endl;
    cout<<"\n";


}

void Bubble_sort(int* arreglo2,int tam,int memory2,unsigned long long int asignaciones2,int comparaciones2){
//BUBBLE_SORT
    Timer timer2;
    timer2.start();
    

    bool swapped;
    int temp;
    
    
    memory2+=sizeof(bool);
    memory2+=sizeof(int);
    memory2+=sizeof(int);;// for i++
    memory2+=sizeof(int);// for  anidado i++
    for(int i=0;i<tam-1;i++){


        ++asignaciones2;//i=0
        ++comparaciones2;//i<tam-1

        for(int j=0;j<tam-i-1;j++){

            ++asignaciones2;//j=0
            ++comparaciones2;//j<tam-i-1

            if(arreglo2[j] > arreglo2[j+1]){

                ++comparaciones2;//arreglo2[j] > arreglo2[j+1]

                temp = arreglo2[j];
                arreglo2[j]=arreglo2[j+1];
                arreglo2[j+1]=temp;
                swapped = true;
                
                asignaciones2+=4;// 3 para un swap y 1 bool = 4 asignaciones
            }
        }
        if (swapped == false){ 
            ++comparaciones2;
            break;
        }

    }

    timer2.stop();

    cout<<"\nBUBBLE_SORT\n";
    cout<<"Numero de asignaciones: "<<8*asignaciones2<<endl;
    cout<<"Numero de comparaciones: "<<2*comparaciones2<<endl;
    cout<<"Numero de asignacion de memoria: "<<memory2<<" en byte"<<endl;
    cout << "Seconds: " << timer2.elapsedSeconds() <<endl;
    cout << "Milliseconds: " << timer2.elapsedMilliseconds() <<endl;


}

int main(){

    int tam;
    unsigned long long asignaciones1=0;
    unsigned long long comparaciones1=0;
    unsigned long long int asignaciones2=0;
    unsigned long long int comparaciones2=0;
    int memory1 = 0,memory2=0;

    cout<<"Longitud: ";cin>>tam;

    int* arreglo;
    arreglo = generadors(tam);

    //creando el mismo arreglo
    int* arreglo2 = new int[tam];
    
    for(int i=0;i<tam;i++){
        arreglo2[i] = arreglo[i];
    }

//comprobador XD
/*
    for(int i=0;i<tam;i++){
       cout<<arreglo[i]<<" ";
    }
*/


//ARREGLO ALEATORIOS
    //Insertion_sort(arreglo,tam,memory1,asignaciones1,comparaciones1);

    //cout<<endl<<"HOLAAAAA:"<<endl;
    //Bubble_sort(arreglo2,tam,memory2,asignaciones2,comparaciones2);

//ARREGLOS CRECIENTES

    //int* newarr = generadorcreciente(tam); // ojo es necesario que este arreglo funcione con el decreciente
/*
    Insertion_sort(newarr,tam,memory1,asignaciones1,comparaciones1);
    cout<<endl<<"HOLAAAAA:"<<endl;
    Bubble_sort(newarr,tam,memory2,asignaciones2,comparaciones2);
  */  
        
 //ARREGLOS DECRECIENTES
 /*
    int* drecarr = generadordecreciente(tam,newarr);
    int* drecarr2 = new int[tam];
    /*for(int i=0;i<tam;i++){
       cout<<drecarr[i]<<" ";
    }
    
    for(int i=0;i<tam;i++){ // creando otro arreglo para bubble
       drecarr2[i] = drecarr[i];
    }
    cout<<"COMPROBADORES XDXDXDXXDXDXD:\n";
    Insertion_sort(drecarr,tam,memory1,asignaciones1,comparaciones1);
    cout<<endl<<"HOLAAAAA:"<<endl;
    Bubble_sort(drecarr2,tam,memory2,asignaciones2,comparaciones2);
*/
    cout<<endl;
    delete []arreglo2;
    delete []arreglo;
    //delete []newarr;
    //delete []drecarr;
    //delete []drecarr2;
    return 0;


}