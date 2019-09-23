//
// Created by rudri on 9/17/2019.
//

#ifndef SORT_METHODS_SORT_H
#define SORT_METHODS_SORT_H


template <typename T>
class Sort {
private:
    T nueva_clase;

public:
    Sort(T nuevaClase);

    void Merge();
    void Quick();
    void Heap();
    void Shell();
};


#endif //SORT_METHODS_SORT_H
