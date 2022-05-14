#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    clock_t start = clock();

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

    for (int i = 0; i < 100000; i++)
        cout << array[i] << endl;

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed << "s";

    return 0;
}

