#include <iostream>

using namespace std;

template<typename T>
class Insertions
{
private:
    T *list;
    T tam;

public:
    Insertions(T*,T);
    void order();
    void print();
    ~Insertions();
};
template<typename T>
Insertions<T>::Insertions(T arr[],T longi)
{
    list = arr;
    tam = longi;

}

template<typename T>
void Insertions<T>::order(){

    int j;
    for(int i=1;i<tam;i++){
        int clave = list[i];
        j=i-1;

        while(j>=0 && list[j]>clave){
            list[j+1]=list[j];
            j=j-1;
        }
        list[j+1]=clave;

    }
}
template<typename T>
void Insertions<T>::print(){

    cout<<"tamaño"<<tam<<endl;

    for(int i=0;i<tam;i++){
        cout<<list[i]<<" ";
    }
   
}

template<typename T>
Insertions<T>::~Insertions()
{
    //delete list;
}
