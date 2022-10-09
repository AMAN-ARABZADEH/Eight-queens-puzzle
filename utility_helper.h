//
// Created by amana on 2022-10-09.
//

#ifndef TEMPLATES_UTILITY_HELPER_H
#define TEMPLATES_UTILITY_HELPER_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
int solution;


void printboard(char * board, int n){
    // int i, j ;
    puts("\nPress Enter for next solution.\n");
    getchar;
    printf("\nSolution # %d:\n\n", ++solution);
    for(int i = 0; i < n; i++){
        putchar('\t');
        for(int j = 0; j < n; j++){
            printf("%c", * (board +i*n + j));
        }
        std::cout << std::endl;
    }
}



int aboveOK(char * board, int i, int j , int n){
    for(i--; i >= 0; i--)
        if(*(board + i*n + j) == 'Q')
            return 0;
    return 1;

}



int upleftOK(char * board, int i, int j , int n){
    for(i--, j-- ; i >= 0 && j >= 0; i--, j--)
        if(*(board + i*n + j) == 'Q')
            return 0;
    return 1;
}

int uprightOK(char * board, int i, int j , int n){
    for(i--, j++; i >= 0 && j < n; i--, j++)
        if(*(board + i*n + j) == 'Q')
            return 0;
    return 1;
}


void putqueen(char * board, int row, int n) {
    int j;
    if (row == n) {
        printboard(board, n);
        return;
    }
    for (j = 0; j < n; j++) {
        if (upleftOK(board, row, j, n) && aboveOK(board, row, j, n) && uprightOK(board, row, j, n)) {
            *(board + row * n + j) = 'Q';
            putqueen(board, row + 1, n);
            *(board + row * n + j) = '-';
        }
    }
}

void initboard(char * board, int n){
    int i;
    for(i = 0; i < n*n; i++)
        *(board + i) = '-';
}


void print(){
    char * board;
    int n, c;
    do{
        solution = 0;
        puts("\nEnter size of board:");
        scanf("%d",&n);
        getchar();
        board = (char *)malloc(n*n*sizeof(char));
        initboard(board, n);
        putqueen(board, 0, n);
        free (board);
        printf("\n%d solutions total for %d queens problem.",
               solution, n);
        puts("\n\nContinue? (y/n):");
        while((c = getchar()) == '\n');
    }while(c == 'y' or c == 'Y');
}







////////////////////////////////////////////



struct person{
    std::string name;
    std::string login;

    friend std::ostream& operator << (std::ostream& out, const person& p){
        return out << "[\"" << p.name << "\", \"" << p.login << "\"]";
    }
    friend bool operator<(const person& lhs, const person& rhs);
};


bool person_by_name_func(const person& lhs, const person& rhs){
    return lhs.name < rhs.name;
}

//template<typename It, typename Compare = std::less<std::remove_reference_t<decltype(*It{})>>>
template<typename It, typename Compare>
void selection_sort(It first, It last, Compare comp){
    for(; first != last; first++){
        // mallinstansiering
        auto min = std::min_element(first, last, comp);
        std::iter_swap(min, first);
    }
}
template<typename It>
void selection_sort(It first, It last) {
    auto element = *first;
    using value_type = decltype(element);
    selection_sort(first, last, std::less<value_type>());
}



//// primes

#include <cstdlib>
// predicate, which returns whether an integer is a prime or not.
bool isPrime(int number){

    // ignoring negative sign
    number = abs(number);
    // 0 and 1 are not prime
    if(number == 1 or number == 0){
        return false;
    }
        // find devisor that devides with no reminder
    int divisor;
    for(divisor = number/2; number%divisor != 0; --divisor){;}
/*
    while(number % divisor != 0){
        divisor = number / 2;
        --divisor;
        ;
    }
*/
    // if no divisor greater 1 is found, it is a prime
    return divisor ==  1;



}
#endif //TEMPLATES_UTILITY_HELPER_H
