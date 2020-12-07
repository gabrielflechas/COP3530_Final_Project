#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;

void selectionSort(int arr[], int size) {
    int minVal;
    int temp;

    clock_t start = clock();
    for (int i = 0; i < size; i++) {
        minVal = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minVal]) {
                minVal = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minVal];
        arr[minVal] = temp;
    }
    clock_t end = clock();
    clock_t timeElapsed = end - start;
    std::cout << (float)timeElapsed / CLOCKS_PER_SEC << " seconds" << std::endl;
}

void bubbleSort(int arr[], int size) {
    int temp;
    bool check = true;
    clock_t start = clock();
    while (check == true) {
        check = false;
        for (int i = 0; i < size; i++) {
            if (i != size - 1) {
                if (arr[i] > arr[i + 1]) {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                    check = true;
                }
            }
        }
    }
    clock_t end = clock();
    clock_t timeElapsed = end - start;
    std::cout << (float)timeElapsed / CLOCKS_PER_SEC << " seconds" << std::endl;
}

void swap(int* a, int* b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

int partition(int array[], int low, int  high) {
    int pivot = array[low]; int up = low; int down = high;

    while (down > up) {
        for (int i = up; i < high; i++) {
            if (array[up > pivot]) {
                break;
                up = up + 1;
            }
        }
        for (int i = up; i > low; i--) {
            if (array[down] < pivot) {
                break;
                down = down - 1;
            }
        }
        if (up < down) {
            swap(array[up], array[down]);
            swap(array[low], array[down]);
        }
    }
    return down;
}

quickSort(int arr[], int low, int high) {
  clock_t start = clock();
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
    clock_t end = clock();
    clock_t timeElapsed = end - start;
    std::cout << (float)timeElapsed / CLOCKS_PER_SEC << " seconds" << std::endl;
}

int main()
{
    cout << "Welcome to our Sorting Algorithm Comparison Program\n";
    cout << "What kind of dataset would you like to analyze?\n";
    cout << "1. Left Skew\n";
    cout << "2. Right Skew\n";
    cout << "3. Unskewed\n";
    cout << "Enter number option\n";

    int input;
    cin >> input;

    // GET ARRAY
    const int size = 100000;
    int arr[size];
    
    srand(time(nullptr));
    ofstream myfile ("data.csv");
    if (myfile.is_open())
    {
        for(int i = 0; i < size; i++){
            myfile << rand() <<" \n";
        }
        myfile.close();
    }
    else cout << "Unable to open file";

    ifstream infile("data.csv");
    if (infile.is_open())
    {
        string line;
        int i = 0;
        while (getline(infile,line))
        {
            arr[i]=stoi(line);
            i++;
        }
        infile.close();
    }

    cout << "Alright, which sorting algorithm(s) would you like to run?\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Quick Sort\n";
    cout << "5. All of the above\n";
    cout << "Enter number option\n";

    int input2;
    cin >> input2;

    if (input2 == 1)
    {
        bubbleSort(arr, size);
    }
    else if (input2 == 2)
    {
        selectionSort(arr, size);

    }
    else if (input2 == 3)
    {
        //display sorting times for merge sort
    }
    else if (input2 == 4)
    {
       quickSort(arr, 0, size-1);
    }
    else if (input2 == 5)
    {
        //display sorting times for all of the above
        bubbleSort(arr, size);
        selectionSort(arr, size);
        //displayQuickSortTime();
    }
    return 0;
}