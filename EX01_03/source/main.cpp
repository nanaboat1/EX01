#include <iostream> // the standard input and output library
#include <vector> // the standard template library for a vector
#include <cstdlib> // for the random library.

/** 
 *  Generic function to find elements in a vector.
 * 
 * @tparam search_vector vector to search element from
 * @return true if elements exist else, false.
*/
template <typename Type>
bool element_find(std::vector<Type> & search_vector, Type search_element ) { 


    // Case : Iterate through vector to locate element
    for ( int i=0; i < search_vector.size(); i++ ) {

        if ( search_element == search_vector[i]) {
            return true;
        }
    }
    return false;
}

/**
 * To unionize two vectors
 * 
 * @param a first vector
 * @param b second vector
 * @return the union of the two vectors.
*/
std::vector<int>& unionVectors(std::vector<int>& a, std::vector<int>& b ) {

    // hold the union of the two vectors.
    std::vector<int> union_vector; 
    int max_iterate = 0; // max_iterate for the union.

    // Get the size of both vectors
    int a_size =  a.size(); 
    int b_size = b.size(); 

    // Assign iterator the max vector size.
    if ( a_size > b_size ) {
        max_iterate = a_size;
    } else {
        max_iterate = b_size;
    }


    /** Constraints  
     * 
     *   No same elements are union from both vectors.
     *   elements from both vector a and b must not be in union_vector.        
    */      
    for ( int i=0; i < max_iterate; i++ ) {

        /** 
         *  Obtain element from a, then element_find() if
         * it exists in either union_vector or b.
         * If true, don't add else add. 
        */
        if ( !((element_find(b, a[i])) && (element_find(union_vector, a[i])))) {
            union_vector.push_back(a[i]);
        }

        /** 
         *  Obtain element from b, then element_find() if
         * it exists in either union_vector or a.
         * If true, don't add else add. 
        */
        if ( !((element_find(a, b[i])) && (element_find(union_vector, b[i])))) {
            union_vector.push_back(b[i]);
        }
        // Check if max_iterate is not being exceeded by union.
       // if ( max_iterate < union_vector.size()) {
            //max_iterate += 20;
        //}


        
    }
    
    // Testing
    return union_vector;
}


int main( ) {


    std::vector <int> a_testVector; 
    std::vector <int> b_testVector;

    // Case : Fill the vector with ints from 0 to 100 
    // send ints to vector. 
    int a_send;
    int b_send; 


    srand(time(NULL)); // seed random library

    for ( int i=0; i<5; i++) {

        a_send = rand() % 200;
        b_send = rand() % 200;


        a_testVector.push_back(a_send);
        b_testVector.push_back(b_send);

    }

   // for ( int i=0; i< 100; i++ ) {
       // std::cout << a_testVector[i]  << std::endl << b_testVector[i] << std::endl;
    //}
    
    std::vector <int> unionized_vector;

    // Error Here --> Discuss in Class.
    unionized_vector = unionVectors(a_testVector, b_testVector) ;
    // Error Here --> Discuss in Class. 

    for ( int i=0; i< unionized_vector.size(); i++) {
        std::cout << unionized_vector[i] << std::endl;
    }


    return 0;
}