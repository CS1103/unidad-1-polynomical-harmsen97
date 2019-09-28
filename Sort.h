//
// Created by utec on 19/09/19.
//

#ifndef ORDENAR_SORT_H
#define ORDENAR_SORT_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>





template <typename T>

class Sort{
private:
    std::vector<T> values;



    void mergeSort( int p, int r);

    void merge( int p, int q, int r);

    void quickSort( int p, int r);

    int partition( int p, int r);

    void heapify( int n, int i);

    void HeapSort();

    void ShellSort();

public:
//interfaces
    Sort(std::vector<T> values){
        this->values = values;
    }

    void MergeSort(){
        mergeSort(0,values.size()-1);
    }

    void QuickSort(){
        quickSort(0, values.size()-1);
    }


    void print(){
        for (auto & i:values)
            std::cout<<i<<" ";
        std::cout<<std::endl;
    }
};

//libreria artesanal para que funcionen los templates

template class Sort<int>;
template class Sort<unsigned int>;
template class Sort<long int>;
template class Sort<long long int>;
template class Sort<unsigned long int>;
template class Sort<unsigned long long int>;
template class Sort<char>;
template class Sort<std::string>;
template class Sort<double>;
template class Sort<float>;


#endif //ORDENAR_SORT_H
