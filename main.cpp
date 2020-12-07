#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
using namespace std;

void selectionSort(int arr[], int size) {
    int minVal;
    int temp;
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
}

void bubbleSort(int arr[], int size) {
    int temp;
    bool check = true;
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
}

void merge(int arr[], int l,int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int a[n1], b[n2];

    for(int i = 0; i < n1; i++)
        a[i]=arr[l+i];
    for(int i = 0; i < n2; i++)
        b[i]=arr[m+1+i];
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=b[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int partition(int array[], int low, int  high) {
    int pivot = array[low]; int up = low; int down = high;

    while (down > up) {
        for (int i = up; i < high; i++) {
            if (array[up] > pivot) {
                break;
            }
            up = up + 1;
        }
        for (int i = high; i > low; i--) {
            if (array[down] < pivot) {
                break;
            }
             down = down - 1;
        }
        if (up < down) {
            swap(array[up], array[down]);
            swap(array[low], array[down]);
        }
    }
    return down;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    cout << "Welcome to our Sorting Algorithm Comparison Program\n";
    cout << "What kind of dataset would you like to analyze?\n";
    cout << "1. Random\n";
    cout << "2. Binomial Distribution\n";
    cout << "3. Geometric Distribution\n";
    cout << "Enter number option\n";

    int input;
    cin >> input;

    // GET ARRAY
    const int size = 100000;
    int arr[size];
    
    random_device rd;
    mt19937 gen(rd());
    
    srand(time(nullptr));
    ofstream myfile ("data.csv");
    if (myfile.is_open())
    {
        if(input==1){
            for(int i = 0; i < size; i++){

                myfile << rand() <<" \n";
            }
        }
        else if (input==2){
            int t;
            double p;
            cout << "Enter an integer value for t distribution (where 0 <= t): ";
            cin >> t;
            cout << "Enter a double value for p distribution (where 0.0 <= p <= 1.0): ";
            cin >> p;
            binomial_distribution<> distr(t, p);
            for(int i = 0; i < size; i++){

                myfile << distr(gen) <<" \n";
            }

        }
        else if (input==3){
            double p;
            cout << "Enter a double value for p distribution (where 0.0 <= p <= 1.0): ";
            cin >> p;
            geometric_distribution<> distr(p);
            for(int i = 0; i < size; i++){

                myfile << distr(gen) <<" \n";
            }
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
        auto t1 = chrono::high_resolution_clock::now();
        bubbleSort(arr, size);
        auto t2 = chrono::high_resolution_clock::now();
        cout << "Bubble Sort took " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds\n";
    }
    else if (input2 == 2)
    {
        auto t1 = chrono::high_resolution_clock::now();
        selectionSort(arr, size);
        auto t2 = chrono::high_resolution_clock::now();
        cout <<"Selection Sort took " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    }
    else if (input2 == 3)
    {
        auto t1 = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, size-1);
        auto t2 = chrono::high_resolution_clock::now();   
        cout << "Merge Sort took "
              << chrono::duration_cast<chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
    }
    else if (input2 == 4)
    {
        auto t1 = chrono::high_resolution_clock::now();
        quickSort(arr, 0, size-1);
        auto t2 = chrono::high_resolution_clock::now();   
        cout << "Quick Sort took "
              << chrono::duration_cast<chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
    }
    else if (input2 == 5)
    {
        //display sorting times for all of the above
        auto t1 = chrono::high_resolution_clock::now();
        bubbleSort(arr, size);
        auto t2 = chrono::high_resolution_clock::now();
        cout << "Bubble Sort took " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds\n";
        
        t1 = chrono::high_resolution_clock::now();
        selectionSort(arr, size);
        t2 = chrono::high_resolution_clock::now();
        cout <<"Selection Sort took " << chrono::duration_cast<chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

        t1 = chrono::high_resolution_clock::now();
        mergeSort(arr, 0, size-1);
        t2 = chrono::high_resolution_clock::now();   
        cout << "Merge Sort took "
              << chrono::duration_cast<chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
        
        t1 = chrono::high_resolution_clock::now();
        quickSort(arr, 0, size-1);
        t2 = chrono::high_resolution_clock::now();   
        cout << "Quick Sort took "
              << chrono::duration_cast<chrono::milliseconds>(t2-t1).count()
              << " milliseconds\n";
    }
    return 0;
}
