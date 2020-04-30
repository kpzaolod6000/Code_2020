#include <iostream>

using namespace std;

template<typename T>
class Bubble
{
private:
    T *list;
    T tam;

public:
    Bubble(T*,T);
    void order();
    void print();
    ~Bubble();
};
template<typename T>
Bubble<T>::Bubble(T arr[],T longi)
{
    list = arr;
    tam = longi;

}

template<typename T>
void Bubble<T>::order(){


    for(T i=0;i<tam-1;i++){
        T temp;    
        for(T j=0;j<tam-i-1;j++){
            
            if(list[j] > list[j+1]){
                cout<<"entro";
                temp = list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }

    }
}
template<typename T>
void Bubble<T>::print(){

    cout<<"tamaño"<<tam<<endl;

    for(int i=0;i<tam;i++){
        cout<<list[i]<<" ";
    }
   
}

template<typename T>
Bubble<T>::~Bubble()
{
    //delete list;
}
