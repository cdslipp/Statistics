#include <iostream>
#include <stdlib.h>

using namespace std;

int tenTo(int a){
    int ten = 1;
    for(int i = 0; i < a; i++){
        ten = ten * 10;
    }
    return ten;
}

int convertToIntArray(int argc, char* argv[], int array[]) {
    for(int i = 1; i < argc; i++) {
        int z = 0;
        int c = 0;
        bool negative = false;
        array[i-1] = 0;

        while(argv[i][c]!='\0'){  //this loop calculates the size of the char array
            c++;
        }
        if(c > 9){
            cerr << "Error: Argument " << i << " is too large.";
            exit(-i);
        }
        else if(c > 1) {                 //if the number is multiple digits, this loop converts to int
            int temp[c];
            while (argv[i][z] != '\0') {
                temp[z] = argv[i][z] - '0';
                if(temp[z] == -3){              //checking if the value is negative (hyphen - char 0 = -3)
                    temp[z] = 0;
                    negative = true;
                }
                else if(temp[z] < 0 || temp[z] > 9){
                    cerr << "Error: Argument " << i << " is not an integer.";
                    exit(-i);
                }

                z++;
            }
            for (int x = 0; x < z; x++) {
                array[i-1] = array[i-1] + (temp[x] * tenTo(c-1));
                c--;
            }
            if(negative){
                array[i-1] = array[i-1] * -1;
            }
        }
        else{                       //this is for numbers < 10
            while (argv[i][z] != '\0') {
                array[i-1] = argv[i][z] - '0';
                if(array[i-1] < 0 || array[i-1] > 9){
                    cerr << "Error: Argument " << i << " is not an integer.";
                    exit(-i);
                }
                z++;
            }
        }
    }

    return argc - 1;
}


int findMax (int array[], int numElements){
    int max = array[0];
    for(int i = 1; i < (numElements); i++){
        max = (array[i] > max) ? array[i]:max;
    }
    return max;
}

int findMin (int array[], int numElements){
    int min = array[0];
    for(int i = 1; i < (numElements); i++) {
        min = (array[i] < min) ? array[i] : min;
    }
    return min;
}

float average (int array[], int numElements){
    int ave = array[0];
    for(int i = 1; i < numElements; i++){
        ave = ave + array[i];
    }
    float aveF = (float) ave;
    float numF = (float) numElements;
    return (aveF/numF);

}


int main(int argc, char *argv[]) {
    const int size = argc - 1;
    if(argc <= 1){
        cerr << "Error. No arguments.";
        return -1;
    }
    else if(argc > 21){
        cerr << "Error: Exceeded value limit." ;
        return -21;
    }
    int array[size];
    int *ptr = array;

    int numElements = convertToIntArray(argc, argv, ptr);
    cout << "Maximum: " << findMax(array, numElements) << endl << "Minimum: " << findMin(array, numElements) << endl;
    cout << "Average: " << average(array, numElements) << endl;


    return 0;
}