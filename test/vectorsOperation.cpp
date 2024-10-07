// Created by Boris on 07/10/2024.
//
#include <iomanip>
#include <iostream>
#include <vector>
#include <bits/ranges_algo.h>

int  main() {
    std::vector<int> results { 1, 2, 3, 4, 5, 6 } ;
    for( int v : results ) std::cout << std::setw(4) << v ;
    std::cout << '\n' ;

    // modify elements with a range based loop
    for( int& v : results ) v *=100 ;
    for( int v : results ) std::cout << std::setw(4) << v ;
    std::cout << '\n' ;

    // modify elements with std::for_each
    std::ranges::for_each(results, [] ( int& v ) { v /= 5 ; } ) ;
    for( int v : results ) std::cout << std::setw(4) << v ;
    std::cout << '\n' ;

    // modify elements with std::transform
    std::ranges::transform(results, results.begin(),
                           [] (const int& v ) { return v / 5 ; } ) ;
    for( int v : results ) std::cout << std::setw(4) << v ;
}

