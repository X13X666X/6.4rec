#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void PrintArray(const double* array, const int size, int index = 0) {
    if (index >= size) {
        cout << endl;
        return;
    }
    cout << setw(8) << array[index] << " ";
    PrintArray(array, size, index + 1);
}

int CountZeroElements(const double* array, const int size, int index = 0) {
    if (index >= size) {
        return 0;
    }
    return (array[index] == 0.0 ? 1 : 0) + CountZeroElements(array, size, index + 1);
}

int FindMinIndex(const double* array, const int size, int index = 0, int minIndex = 0) {
    if (index >= size) {
        return minIndex;
    }
    if (array[index] < array[minIndex]) {
        minIndex = index;
    }
    return FindMinIndex(array, size, index + 1, minIndex);
}

double SumAfterMin(const double* array, const int size, int minIndex, int index = 0) {
    if (index <= minIndex) {
        return SumAfterMin(array, size, minIndex, index + 1);
    }
    if (index >= size) {
        return 0;
    }
    return array[index] + SumAfterMin(array, size, minIndex, index + 1);
}

void SortOddIndicesByAbs(double* array, const int size, int i = 1, int j = 1) {
    if (i >= size) {
        return;
    }
    if (j >= size) {
        SortOddIndicesByAbs(array, size, i + 2, i + 2);
        return;
    }
    if (j > i && j % 2 == 1 && abs(array[j]) < abs(array[i])) {
        double temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    SortOddIndicesByAbs(array, size, i, j + 2);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Array size must be positive!" << endl;
        return 1;
    }

    double* array = new double[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        if (cin.fail()) { // Перевірка на некоректний ввід
            cout << "Invalid input. Please enter numeric values." << endl;
            delete[] array;
            return 1;
        }
    }

    cout << "Original array: " << endl;
    PrintArray(array, n);

    int zeroCount = CountZeroElements(array, n);
    cout << "Number of zero elements: " << setw(8) << zeroCount << endl;

    int minIndex = FindMinIndex(array, n);
    double sum = SumAfterMin(array, n, minIndex);
    cout << "Sum of elements after the minimum: " << setw(8) << sum << endl;

    SortOddIndicesByAbs(array, n);
    cout << "Array after sorting odd indices by absolute values: " << endl;
    PrintArray(array, n);

    delete[] array;
    return 0;
}
