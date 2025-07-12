#include <iostream>         // Include for input/output operations
#include <chrono>          // Include for high-precision timing
#include <cstdlib>         // Include for random number generation
#include <limits>          // Include for input buffer clearing
#include <string>          // Include for string handling
#include <algorithm>       // Include for std::min
#include <time.h>          // Include for time function

using namespace std;

// Generate N random integers between 0 and 999
void generateRandomNumbers(int arr[], int n) {
    srand(time(0));        // Seed random number generator with current time
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Assign random number to each array element
    }
}

// Display all elements in the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print each element with a space
    }
    cout << endl;          // New line after array display
}

// Copy source array to destination array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];  // Copy each element to preserve original array
    }
}

// Sort array using Quick Sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {      // Check if there are elements to sort
        int pivot = arr[high]; // Use last element as pivot
        int i = low - 1;     // Index of smaller element
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) { // If current element is smaller or equal
                i++;           // Increment index of smaller element
                swap(arr[i], arr[j]); // Swap elements
            }
        }
        swap(arr[i + 1], arr[high]); // Place pivot in its correct position
        int pi = i + 1;        // Partition index
        quickSort(arr, low, pi - 1); // Recursively sort left part
        quickSort(arr, pi + 1, high); // Recursively sort right part
    }
}

// Merge two sorted subarrays in Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray
    int* L = new int[n1];    // Temporary left array
    int* R = new int[n2];    // Temporary right array
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i]; // Copy left subarray
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i]; // Copy right subarray
    }
    int i = 0, j = 0, k = left; // Indices for merging
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {    // Compare and merge in order
            arr[k] = L[i];     // Add from left array
            i++;
        } else {
            arr[k] = R[j];     // Add from right array
            j++;
        }
        k++;
    }
    while (i < n1) {           // Copy remaining left elements
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {           // Copy remaining right elements
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;                // Free left array memory
    delete[] R;                // Free right array memory
}

// Recursively sort array using Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {      // Check if there are elements to sort
        int mid = left + (right - left) / 2; // Find middle index
        mergeSort(arr, left, mid); // Sort left half
        mergeSort(arr, mid + 1, right); // Sort right half
        merge(arr, left, mid, right); // Merge sorted halves
    }
}

// Search for target using Binary Search (recursive)
int binarySearch(int arr[], int first, int last, int tar) {
    if (first > last) {      // Base case: target not found
        return -1;
    }
    int mid = first + (last - first) / 2; // Calculate middle index
    if (tar == arr[mid]) {   // Target found at middle
        return mid;
    }
    if (tar < arr[mid]) {    // Search left half
        return binarySearch(arr, first, mid - 1, tar);
    }
    return binarySearch(arr, mid + 1, last, tar); // Search right half
}

// Search for target using Exponential Search
int exponentialSearch(int arr[], int n, int tar) {
    if (n == 0) {            // Empty array case
        return -1;
    }
    if (arr[0] == tar) {     // Target at start
        return 0;
    }
    int i = 1;               // Start with range of 1
    while (i < n && arr[i] <= tar) { // Double range until target exceeded
        i *= 2;
    }
    int bound = std::min(i, n - 1); // Bound within array size
    return binarySearch(arr, i / 2, bound, tar); // Binary search in range
}

// Main menu for user interaction
void menu() {
    int n = 0, target, index;
    int* arr = nullptr;      // Dynamic array pointer
    bool arrayGenerated = false; // Track if array is generated

    while (true) {
        cout << "\n=== DSA Assignment Menu ===\n";
        cout << "1. Generate random numbers\n";
        cout << "2. Quick Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Binary Search\n";
        cout << "5. Exponential Search\n";
        cout << "6. Display Array\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.clear();           // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 7) break;

        switch (choice) {
            case 1: {
                cout << "Enter the number of random integers to generate: ";
                cin >> n;
                if (cin.fail() || n <= 0) { // Validate input
                    cout << "Please enter a positive number.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                if (arr != nullptr) delete[] arr; // Free previous array
                arr = new int[n];      // Allocate new array
                generateRandomNumbers(arr, n);
                cout << "Generated numbers: ";
                displayArray(arr, n);
                arrayGenerated = true;
                break;
            }
            case 2: {
                if (!arrayGenerated) {
                    cout << "Please generate numbers first (Option 1).\n";
                    break;
                }
                int* temp = new int[n]; // Temporary array for sorting
                copyArray(arr, temp, n);
                auto before = std::chrono::high_resolution_clock::now(); // Start time
                quickSort(temp, 0, n - 1);
                auto after = std::chrono::high_resolution_clock::now(); // End time
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(after - before);
                cout << "Sorted Array (Quick Sort): ";
                displayArray(temp, n);
                cout << "Quick Sort Time: " << duration.count() / 1000000.0 << " seconds\n";
                delete[] temp;         // Free temporary array
                break;
            }
            case 3: {
                if (!arrayGenerated) {
                    cout << "Please generate numbers first (Option 1).\n";
                    break;
                }
                int* temp = new int[n];
                copyArray(arr, temp, n);
                auto before = std::chrono::high_resolution_clock::now();
                mergeSort(temp, 0, n - 1);
                auto after = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(after - before);
                cout << "Merge Sort Time: " << duration.count() / 1000000.0 << " seconds\n";
                cout << "Sorted Array (Merge Sort): ";
                displayArray(temp, n);
                delete[] temp;
                break;
            }
            case 4: {
                if (!arrayGenerated) {
                    cout << "Please generate numbers first (Option 1).\n";
                    break;
                }
                cout << "Enter the number to search: ";
                cin >> target;
                if (cin.fail()) {
                    cout << "Invalid input. Try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                int* temp = new int[n];
                copyArray(arr, temp, n);
                mergeSort(temp, 0, n - 1); // Sort for binary search
                auto before = std::chrono::high_resolution_clock::now(); // Start time
                index = binarySearch(temp, 0, n - 1, target);
                auto after = std::chrono::high_resolution_clock::now(); // End time
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(after - before);
                cout << "Binary Search Index: " << (index == -1 ? "Not Found" : to_string(index)) << endl;
                cout << "Binary Search Time: " << duration.count() << " microseconds (" 
                     << duration.count() / 1000.0 << " milliseconds)\n";
                delete[] temp;
                break;
            }
            case 5: {
                if (!arrayGenerated) {
                    cout << "Please generate numbers first (Option 1).\n";
                    break;
                }
                cout << "Enter the number to search: ";
                cin >> target;
                if (cin.fail()) {
                    cout << "Invalid input. Try again.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                int* temp = new int[n];
                copyArray(arr, temp, n);
                mergeSort(temp, 0, n - 1); // Sort for exponential search
                auto before = std::chrono::high_resolution_clock::now(); // Start time
                index = exponentialSearch(temp, n, target);
                auto after = std::chrono::high_resolution_clock::now(); // End time
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(after - before);
                cout << "Exponential Search Index: " << (index == -1 ? "Not Found" : to_string(index)) << endl;
                cout << "Exponential Search Time: " << duration.count() << " microseconds (" 
                     << duration.count() / 1000.0 << " milliseconds)\n";
                delete[] temp;
                break;
            }
            case 6: {
                if (!arrayGenerated) {
                    cout << "Please generate numbers first (Option 1).\n";
                    break;
                }
                cout << "Current Array: ";
                displayArray(arr, n);
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    if (arr != nullptr) delete[] arr; // Free array memory
}

int main() {
    menu();                // Start the menu interface
    return 0;              // End program successfully
}
