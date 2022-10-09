#include <iostream>
#include <algorithm>
#include <list>
#include "utility_helper.h"

int main() {

    person arr[]= {{"baba", "Ali"},
                   {"Who", "amI"},
                   { "Lulu", "lala"}
    };
    auto by_name = [](const person& lhs, const person& rhs)->bool {
        return lhs.name < rhs.name;
    };

    // mallinstansiering selection_sort<double>
    selection_sort(arr, arr + 3, by_name);
    for(int i = 0; i < 3; i++){
        std::cout << arr[i] << "\n";
    }


    /// Testing the queeen problem
    print();

    std::cout << std::endl << std::endl;
    std::list<int> coll;

    // insert elements in the list
    for( int i = 14; i < 200;++i){
        coll.emplace_back(i);
    }



    auto pos = std::find_if(coll.begin(), coll.end(), isPrime);
    if(pos != coll.end()){
        std::cout <<*pos << " is first prime number found" << std::endl;
    }else{
        std::cout << "No prime number found!" << std::endl;
    }



}