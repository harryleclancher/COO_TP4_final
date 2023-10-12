// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "dms.h"

int main()
{

    dms d1(12, 1, 4);
    dms d2(2, 45, 15);

    d1.affiche();
    d2.affiche();

    dms d3 = d1;
    std::cout << "operateur = " << std::endl;
    d3.affiche();

    dms sum = d1 + d2;
    std::cout << "Operateur + " << std::endl;
    sum.affiche();

    dms diff = d1 - d2;
    std::cout << "\nOperateur -" << std::endl;
    diff.affiche();

    dms fois = d1 * 3;
    std::cout << "\nOperateur *" << std::endl;
    fois.affiche();

    float my_float = d1 ^ d2; 
    std::cout << "\nTransformation en flaot" << std::endl;
    std::cout << "Result: " << my_float << std::endl;

    std::cout << "\nComparisons " << std::endl;
    std::cout << "d1 <= d2: " << (d1 <= d2) << std::endl;
    std::cout << "d1 >= d2: " << (d1 >= d2) << std::endl;
    std::cout << "d1 < d2: " << (d1 < d2) << std::endl;
    std::cout << "d1 > d2: " << (d1 > d2) << std::endl;
    std::cout << "d1 == d2: " << (d1 == d2) << std::endl;
    std::cout << "d1 != d2: " << (d1 != d2) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
