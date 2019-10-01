//
// Created by ALONSO on 1/10/2019.
//

#ifndef SORTMETHODS_BIBLIOTECA_H
#define SORTMETHODS_BIBLIOTECA_H

#include "Definiciones.h"

template <typename T>
class Biblioteca {
private:
    vector<T> valores;

public:
    Biblioteca(const vector<T> &valores) : valores(valores) {}

    //----------------------------- MERGE ------------------------------------------------
    void mergeSort (vector<T>& v, int izquierda, int medio, int derecha){
        int size_izquierda = medio - izquierda + 1;
        int size_derecha = derecha - medio;
        vector<T> v_izquierda(size_izquierda);
        vector<T> v_derecha(size_derecha);

        for (int i = 0; i < size_izquierda; ++i)
            v_izquierda[i] = v[izquierda + 1];

        for (int j = 0; j < size_derecha; ++j)
            v_derecha[j] = v[medio + 1 + j];

        int index_izquierda = 0;
        int index_derecha = 0;
        int size_v = izquierda;
        while ((index_izquierda < size_izquierda) and (index_derecha < size_derecha)){
            if (v_izquierda[index_izquierda] <= v_derecha[index_derecha]){
                v[size_v] = v_izquierda[index_izquierda];
                index_izquierda++;
            }
            else {
                v[size_v] = v_derecha[index_derecha];
                index_derecha++;
            }
            size_v++;
        }

        while (index_izquierda < size_izquierda){
            v.push_back(v_izquierda[izquierda]);
            v[size_v] = v_izquierda[index_izquierda];
            index_izquierda++;
            size_v++;
        }
        while (index_derecha < size_derecha){
            v[size_v] = v_derecha[index_derecha];
            index_derecha++;
            size_v++;
        }
    }

    void Unir(vector<T>& v, int izquierda, int derecha){
        if (izquierda < derecha){
            int medio = (derecha+izquierda)/2;

            Unir(v, izquierda, medio);
            Unir(v, medio+1, derecha);
            mergeSort(v, izquierda, medio, derecha);
        }


    }

    void Merge(){
        Unir(valores, 0, valores.size()-1);
    }
    //----------------------------- QUICK ------------------------------------------------

    itr partition(itr left,itr right)
    {
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

    void quicksort(std::vector<int>& v,itr left, itr right)
    {
        if(distance(left,right)>=1)
        {
            auto mid=partition(left,right);
            quicksort(v,left,mid-1);
            quicksort(v,mid+1,right);
        }
    }
    void Quick(){
        quicksort(valores,begin(valores),end(valores)-1);
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

        /*auto last = valores.end();
        auto init = valores.begin();
        auto gap = next(init, valores.size()/2);

           for (; gap != init ; gap /= 2) {
               for (auto j = gap; j != last; ++j) {
                   for (auto k = j - gap; k > init ; k -= gap) {
                       if (*(k+gap) >= *k)
                           break;
                       else
                           swap(*(k+gap), *k);
                   }
               }
           }*/
    }

    //----------------------------- PRINT ------------------------------------------------

    void print(){
        cout << "\nValores:\n";
        for(auto i = valores.begin(); i != valores.end(); i++)
            cout << *i << " ";
    }
};

#endif //SORTMETHODS_BIBLIOTECA_H
