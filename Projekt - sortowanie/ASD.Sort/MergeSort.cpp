
#include <iostream>
#include <fstream>

using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    int array[100000];
    ifstream file;
    file.open("plik.txt", ios::in);

    if (!file.good())
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < 100000; i++)
            file >> array[i];
    }

    file.close();

    clock_t start = clock();

    mergeSort(array, 0, 99999);

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    /*for (int i = 0; i < 100000; i++)
        cout << array[i] << endl;*/

    cout << "Czas: " << elapsed << "s   ";

    clock_t start2 = clock();

    mergeSort(array, 0, 99999);

    clock_t end2 = clock();

    double elapsed2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Czas: " << elapsed2 << "s";

    return 0;
}