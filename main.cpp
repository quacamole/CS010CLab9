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

    for (int i = 0; i < NUMBERS_SIZE; ++i) {
        arr1[i] = 0 + rand() % (NUMBERS_SIZE - 0 + 1);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000; //clock per milliseconds
    clock_t Start = clock();
    //call sort function here
    Quicksort_midpoint(arr1, 0, NUMBERS_SIZE);
    clock_t End = clock();
    int elapsedTime = (End - Start) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    cout << "Elapsed runtime: " << elapsedTime << endl;

    Start = clock();
    //call sort function here
    Quicksort_medianOfThree(arr2, 0, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    cout << "Elapsed runtime: " << elapsedTime << endl;

    Start = clock();
    //call sort function here
    InsertionSort(arr3, NUMBERS_SIZE);
    End = clock();
    elapsedTime = (End - Start) / CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.

    cout << "Elapsed runtime: " << elapsedTime << endl;
    return 0;
}

void Quicksort_midpoint(int numbers[], int i, int k) {
    if (i >= k)
    {
        return;
    }

    int recMid = partition_midpoint(numbers, i, k);

    Quicksort_midpoint(numbers, i, recMid);
    Quicksort_midpoint(numbers, recMid + 1, k);
}

int partition_midpoint(int numbers[], int i, int k)
{
    int mid = numbers[(i + k) / 2];
    bool done = false;

    while (!done)
    {
        while (numbers[i] < numbers[mid])
        {
            i++;
        }
        while (numbers[k] > numbers[mid])
        {
            k--;
        }

        if (i >= k)
        {
            done = true;
        }
        else
        {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            i++;
            k--;
        }
    }

    return k;
}

void Quicksort_medianOfThree(int numbers[], int i, int k) {
    if (i >= k)
    {
        return;
    }

    int recMid = partition_medianOfThree(numbers, i, k);

    Quicksort_midpoint(numbers, i, recMid);
    Quicksort_midpoint(numbers, recMid + 1, k);
}

int partition_medianOfThree(int numbers[], int i, int k)
{
    int mid = numbers[(i + k) / 2];
    bool done = false;

    int pivot;

    if (((numbers[i] > numbers[k]) && numbers[i] < mid) || (numbers[i] > mid && numbers[i] < numbers[k]))
    {
        pivot = numbers[i];
    }
    else if (((numbers[k] > numbers[i]) && numbers[k] < mid) || (numbers[k] > mid && numbers[k] < numbers[i]))
    {
        pivot = numbers[k];
    }
    else
    {
        pivot = mid;
    }

    while (!done)
    {
        while (numbers[i] < pivot)
        {
            i++;
        }
        while (numbers[k] > pivot)
        {
            k--;
        }

        if (i >= k)
        {
            done = true;
        }
        else
        {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;

            i++;
            k--;
        }
    }

    return k;
}

void InsertionSort(int numbers[], int numbersSize) {

}
