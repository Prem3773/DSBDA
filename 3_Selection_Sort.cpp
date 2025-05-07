#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;
        
        // Find minimum element in unsorted part
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap if minimum element found
        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    vector<int> arr;
    int num;
    
    cout << "Enter numbers (end with -1): ";
    while(cin >> num && num != -1) {
        arr.push_back(num);
    }
    
    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    
    selectionSort(arr);
    
    cout << "\nSorted array: ";
    for(int x : arr) cout << x << " ";
    
    return 0;
}