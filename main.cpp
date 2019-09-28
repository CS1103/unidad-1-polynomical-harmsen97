#include <iostream>
#include <vector>
#include <deque>
#include <list>


#include "Sort.h"
#include "auxFunctions.h"

int main(){
//con quicksort
    std::vector<int> vec1 = {9,8,7,6,5,4,3,2,1,0,10,20,44,12};
    Sort <int> A(vec1);
    A.print();
    std::cout<<std::fixed<<std::setprecision(6)<<stopWatchQuick(A)<<std::endl;
    A.print();





    std::cout<<std::endl;




    //con mergesort
    std::vector<int> vec2 = {9,8,7,6,5,4,3,2,1,0,10,20,44,12};
    Sort <int> B(vec2);
    B.print();
    std::cout<<std::fixed<<std::setprecision(6)<<stopWatchMerge(B)<<std::endl;
    B.print();



    std::cout<<std::endl;




    std::vector<int> vec3 = {9,8,7,6,5,4,3,2,1,0,10,20,44,12};
    Sort <int> C(vec3);
    C.print();
    std::cout<<std::fixed<<std::setprecision(6)<<stopWatchMerge(C)<<std::endl;
    C.print();



    std::cout<<std::endl;




    std::vector<int> vec4 = {9,8,7,6,5,4,3,2,1,0,10,20,44,12};
    Sort <int> D(vec4);
    D.print();
    std::cout<<std::fixed<<std::setprecision(6)<<stopWatchMerge(D)<<std::endl;
    D.print();
//utilizar iteradores
//necesita recibir archivos



    return 0;
}