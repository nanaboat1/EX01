#include <iostream> // the standard input and output library
#include <vector> // the standard template vector library
#include <string> // the standard string library
#include <cstdlib> // for the random function. 


/** 
 *  Checks whether length is less than or equals 0.
 * 
 *  @param length input length of triangle
 *  @return whether length is less than or equals zero.
*/
bool check_length( int length ) {

    if ( length <= 0 ) {
        return true; 
    }
    return false;
}


/**
 *  Checks Triangle using it's length's.
 *
 * Evaluates based on triangle's length
 * 
 * @param a length of one side of triangle
 * @param b length of the second side of the triangle
 * @param c length of the third side of the triangle 
 * @return either the sides make-up a triangle or not
 * 
 */
bool isTriangle( int a, int b, int c ) { 

    // Two Requirements for a triangle.

    // a. Checks whether each length's magnitude 
    // of the triangle is not less than 0.

    int collection[3] = { a, b, c}; // bag's length of triangle


    for ( int i=0; i < 3; i++ ) {

        // 
        if ( check_length(collection[i])) {
            return false;
        }
    }

    // b. checks whether length of two sides is less than or greater than both sides.
    if ( (a + b) <= c ) {
        return false; 
    }
    return true; 
}




int main( ) {

    srand(time(NULL)); // seed random library with time

    std::vector <int> triangle_sides; // to hold the sides of the triangle.

    // Loop Check's whether it is a triangle.
    for ( int i=0; i< 100; i++ ) {


        int _a = rand() % ( i+50);
        int _b = rand() % (2 + i);
        int _c = rand() % (34);

        // The function evaluates the length whether is a triangle.
        if ( isTriangle(_a, _b, _c) ){
            std::cout << "It is a triangle " << std::endl << std::endl; 
        } else { 
            std::cout << "It is not a triangle " << std::endl << std::endl ;
        }

    }

    return 0; // return's upon completion
}

