//
// Created by utec on 19/09/19.
//

#include "Sort.h"
#include "auxFunctions.h"


template<typename T>
void Sort<T> :: mergeSort( int p, int r){
    if(p<r){
    int q= floor((p+r)/2);
    mergeSort(p, q);
    mergeSort(q+1, r);
    merge(p, q, r);
    }
}


template <typename T>
void Sort <T> :: merge( int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<T> left(n1 + 1), right(n2 + 1);
    for (int i = 0; i < n1; i++)
        left[i] = values[p + i];
    for (int j = 0; j < n2; j++)
        right[j] = values[q + j + 1];

    left[n1] = INT8_MAX;
    right[n2] = INT8_MAX;

    int i = 0,j = 0;

    for (int k = p; k <= r; k++){
        if (left[i] <= right[j]){
            values[k] = left[i];
            i++;
        }
        else {
            values[k] = right[j];
            j++;
        }

    }
}

template <typename T>
void Sort <T> :: quickSort( int p, int r){

    if (p < r){
        int q = partition( p, r);
        quickSort( p, q-1);
        quickSort( q, r);

    }
}

template <typename  T>
int Sort <T> :: partition( int p, int r){
    T x = values[r];
    int i = p -1;

    for(int j = p; j<=r-1; j++){

        if(values[j]<=x){
            i++;
            swap(values[i], values[j]);
        }
    }
    swap(values[i + 1], values[r]);
    return i+1;
}



template <typename  T>
void Sort<T> ::heapify(int n, int i) {
    int maxVal = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if ( r < n && values[r] > values[maxVal])
        maxVal = l;

    if (r < n && values[r] > values(maxVal))
        maxVal = r;

    if (maxVal != i){
        swap(values[i],values[maxVal]);
    }
}

template <typename T>
void Sort<T> :: HeapSort( ){
    int n = values.size();

    for(int i = values.size()/2; i >= 0; i--) {
        heapify(n,i);
    }
    for(int j = values.size()-1; j >=0; --j){
        swap(values[0], values[j]);
        heapify(j,0);
    }
    }

    template <typename T>
    void Sort<T> :: ShellSort(){
        int n = values.size();


        for (int gap = n/2; gap > 0; gap = gap / 2)
        {

            for (int i = gap; i < n; i += 1) {

                T temp = values[i];

                int j;


                for ( j = i; j >= gap && values[j - gap] > temp; j = j - gap)
                    values[j] = values[j - gap];

                values[j] = temp;
            }
        }



    }






