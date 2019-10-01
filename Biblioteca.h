//
// Created by ALONSO on 26/09/2019.
//

#ifndef UNIDAD2_PROYECTO_BIBLIOTECA_H
#define UNIDAD2_PROYECTO_BIBLIOTECA_H

#include "Definiciones.h"

template <typename T>
class Biblioteca {
private:
    vector<T> valores;

public:
    Biblioteca(const vector<T> &valores) : valores(valores) {}

    //----------------------------- MERGE ------------------------------------------------
    void merge(vector<T> &v, itr init, itr mid, itr last){

        vector<T> v_izquierda((mid-init)+1);
        vector<T> v_derecha(last-mid);

        auto inic = init;
        auto mit = mid+1;

        for(auto it = v_izquierda.begin(); it != v_izquierda.end(); it++){
            *it = *inic;
            inic++;
        }
        for(auto it = v_derecha.begin(); it != v_derecha.end(); it++){
            *it = *mit;
            mit++;
        }

        auto i = v_izquierda.begin();
        auto j = v_derecha.begin();
        auto k = init;

        while(i != v_izquierda.end() && j != v_derecha.end()){
            if(*i < *j){
                *k = *i;
                i++;
            }
            else {
                *k = *j;
                j++;
            }
            k++;
        }

        while(i != v_izquierda.end()){
            *k = *i;
            i++;
            k++;
        }
        while(j != v_derecha.end()){
            *k = *j;
            j++;
            k++;
        }
    }

    void mergesort(vector<T> &v,itr init,itr last){
        if(init != last){
            auto mid = init + (last-init)/2;
            mergesort(v,init,mid);
            mergesort(v,mid+1,last);
            merge(v,init,mid,last);
        }
    }

    void Merge(){
        mergesort(valores, valores.begin(), valores.end());
    }
    //----------------------------- QUICK ------------------------------------------------

    itr partition(itr left,itr right){
        itr i=left-1;
        itr it=left;
        while(it<right)
        {
            if(*it<=*right){
                ++i;
                std::swap(*i,*it);}
            ++it;
        }
        swap(*(i+1),*right);
        return ++i;
    }

    void quicksort(vector<T>& v,itr left, itr right)
    {
        if(distance(left,right)>=1)
        {
            auto mid=partition(left,right);
            quicksort(v,left,mid-1);
            quicksort(v,mid+1,right);
        }
    }
    void Quick(){
        quicksort(valores, valores.begin(), valores.end());
    }

    //----------------------------- HEAP ------------------------------------------------

    void heapify(vector<T>& v, int n, int i){
        int largo = i;
        int izquierda = 2*i+1;
        int derecha = 2*i+2;

        if ((izquierda < n) and (v[izquierda] > v[largo])){
            largo = izquierda;
        }

        if ((derecha < n) and (v[derecha] > v[largo])){
            largo = derecha;
        }

        if (largo != i) {
            swap(v[i], v[largo]);

            heapify(v, n, largo);
        }
    }

    void heapSort(vector<T>& v){
        int n = v.size();
        for (int i = n/2-1; i >= 0 ; --i) {
            heapify(v, n, i);
        }

        for (int j = n-1; j >=0 ; --j) {
            swap(v[0], v[j]);
            heapify(v, j, 0);
        }
    }

    void Heap(){
        heapSort(valores);
    }

    //----------------------------- SHELL ------------------------------------------------

    void Shell(){
     int n = valores.size();
        for (int gap = n/2; gap > 0; gap /= 2)
            for (int j = gap; j < n; ++j)
                for (int k = j - gap; k >= 0; k -= gap) {
                    if (valores[k+gap] >= valores[k])
                        break;
                    else
                        swap(valores[k+gap], valores[k]);
                }
    }

    //----------------------------- PRINT ------------------------------------------------

    void print(){
        cout << "Valores:\n";
        for(auto i = valores.begin(); i != valores.end(); i++)
            cout << *i << " ";
        cout << endl;
    }

    T operator[](int index){
        auto i = valores.begin();
        return *i;
    }
};


#endif //UNIDAD2_PROYECTO_BIBLIOTECA_H
