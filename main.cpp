#include <iostream>
#include <time.h>
using namespace std;

void Quicksort_midpoint(int numbers[], int i, int k);
void Quicksort_medianOfThree(int numbers[], int i, int k);
void InsertionSort(int numbers[], int numbersSize);

int main() {
    //generates 3 arrays of integers between 0 and NUMBERS_SIZE
    const int NUMBERS_SIZE = 50000;
    int arr1[NUMBERS_SIZE], arr2[NUMBERS_SIZE], arr3[NUMBERS_SIZE];

        for(int i = 0; i < NUMBERS_SIZE; ++i){
           arr1[i] = 0 + rand() % (NUMBERS_SIZE - 0 + 1);
           arr2[i] = arr1[i];
           arr3[i] = arr1[i];
    }

    const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds
    clock_t Start = clock();
//call sort function here
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE);
    clock_t End = clock();
    int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    cout << "Elapsed runtime: " << elapsedTime << endl;

    Start = clock();
//call sort function here
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    cout << "Elapsed runtime: " << elapsedTime << endl;

    Start = clock();
//call sort function here
    InsertionSort(arr3, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    cout << "Elapsed runtime: " << elapsedTime << endl;
    return 0;
}

void Quicksort_midpoint(int numbers[], int i, int k) {

}

void Quicksort_medianOfThree(int numbers[], int i, int k){

}

void InsertionSort(int numbers[], int numbersSize){

}
