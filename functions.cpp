/*
 * the supporting demo functions implementations
 */

#include "functions.h"

// pass in a pointer to a Data
bool change_data(Data *data_struct){
    // change the values stored
    data_struct->id = 2;
    data_struct->data = "Good Bye Cruel World";
    
    // return true to indicate success
    return true;
}

// pass in an array of type Data and the size of the array
//bool fill_data_array(Data *array, int size){
//    for(int i=0; i<size; i++){
//        // fill with ids 10,20,etc. and a generic string
//        array[i].id = (i+1)*10;
//        array[i].data =  "some string " + std::to_string(i+1);
//    }
//    return true;
//}
//
// pass in an array of type Data and the size of the array
//void display_data_array(Data *array, int size){
//    for(int i=0; i<size; i++){
//        cout << array[i].id << ": " << array[i].data << endl;
//    }
//    cout << endl;
//}

void rand_string(std::string *str){
    // create size 0 to MAXSTRSIZE-1
    int rnum = rand() % MAXSTRSIZE;

    // make buffer to hold rand string
    char *buffer = new char[rnum+1];

    // fill buffer with random characters A to Z
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';

    // transfer buffer to passed in string
    *str = buffer;

    // clean up
    delete[] buffer;
    return;
}


// 2d array version
// pass in an array of type Data and rows and cols
bool fill_data_array(Data **array, int rows, int cols){
    for(int i=0; i<rows; i++){
        // fill with ids 10,20,etc. and a generic string
        for (int j = 0; j<cols; j++) {
            array[i]->id = (i+1)*10;
//            array[i]->data =  "some string " + std::to_string(i+1);
            //array[i][j].id = rand();
            //rand_string(&array[i]->data);  // trying out just using i
            rand_string(&array[i][j].data);  // have to use . to access member here
        }
    }
    return true;
}

//print the 2d array
void display_data_array(Data **array, int rows, int cols){
    for(int i=0; i<rows; i++){
        for (int j = 0; j < cols; j++) {
            //std::cout << array[i]->id << ": " << array[i]->data << std::endl;
            std::cout << array[i]->id << ": "  << array[i][j].data << std::endl;
        }
    }
    cout << endl;
}
