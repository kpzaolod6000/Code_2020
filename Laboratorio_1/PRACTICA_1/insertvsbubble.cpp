#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

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
        ran=0+rand()%1000;
        arreglo[i] = ran;
    }

    return arreglo;
}


int main(){

    int tam;
    unsigned long int asignaciones1=0;
    unsigned long int comparaciones1=0;
    unsigned long int asignaciones2=0;
    unsigned long int comparaciones2=0;
    int memory1 = 0,memory2=0;

    cout<<"Longitud: ";cin>>tam;

    int* arreglo;
    arreglo = generadors(tam);

    //creando el mismo arreglo
    int* arreglo2 = new int[tam];
    
    for(int i=0;i<tam;i++){
        arreglo2[i] = arreglo[i];
    }



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


    
    delete []arreglo2;
    delete []arreglo;
    return 0;


}


//Verificaciones

//        INSERTION_SORT                                                    BUBBLE_SORT
// EN UN ARREGLO DE TAMAÑO 10                                       EN UN ARREGLO DE TAMAÑO 10  
// Numero_de_asignaciones : 752                                     Numero_de_asignaciones : 1360
// Numero_de_comparaciones : 134                                    Numero_de_comparaciones : 166
// Numero de asignacion de memoria: 12 byte                         Numero de asignacion de memoria: 13 byte
// Segundos:0                                                       Segundos:0
// Milisegundos:0                                                   Milisegundos:0
// NO tengo instancias de una clase dentro de los algoritmos de ordenacion
////////////////////////////////////////////////////////////////////////////////////////////////////
// EN UN ARREGLO DE TAMAÑO 1000                                       EN UN ARREGLO DE TAMAÑO 1000  
// Numero_de_asignaciones : 3945504                                  Numero_de_asignaciones : 11831064
// Numero_de_comparaciones : 980382                                  Numero_de_comparaciones : 1490190
// Numero de asignacion de memoria: 12 byte                          Numero de asignacion de memoria: 13 byte
// Segundos:0.003                                                    Segundos:0.003
// Milisegundos: 3                                                   Milisegundos:3
////////////////////////////////////////////////////////////////////////////////////////////////////
// EN UN ARREGLO DE TAMAÑO 100mil                                    EN UN ARREGLO DE TAMAÑO 100mil
// Numero_de_asignaciones : 39926073792                              Numero_de_asignaciones : 119846147640
// Numero_de_comparaciones : 9980918454                              Numero_de_comparaciones : 14990459226   
// Numero de asignacion de memoria: 12 byte                          Numero de asignacion de memoria:13 byte
// Segundos: 5.908                                                   Segundos:29.647
// Milisegundos: 5908                                                Milisegundos:29647
////////////////////////////////////////////////////////////////////////////////////////////////////
// EN UN ARREGLO DE TAMAÑO 1 millón                                 EN UN ARREGLO DE TAMAÑO 1 millón
// Numero_de_asignaciones : 3990402139296                            Numero_de_asignaciones : 11980744278648
// Numero_de_comparaciones : 997594534830                            Numero_de_comparaciones :1498797267414
// Numero de asignacion de memoria: 12 byte                          Numero de asignacion de memoria:13 byte
// Segundos: 612.923                                                 Segundos:3305.66
// Milisegundos:612923                                               Milisegundos:3.30566e+06





////////////////////////////////////////////////////////////
