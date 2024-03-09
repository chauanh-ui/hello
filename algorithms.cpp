#include <bits/stdc++.h>
using namespace std;
// a[] = 9, 10, 5 , 6 , 2 , 4 , 1, 8. The starting index is 1.
const int numberOfElements = 9;
int a[] = { 0, 9, 10, 5 , 6 , 2 , 4 , 1, 8};
int sortedArr[] = {0, 1,2,3,5,6,7,8,10,12,13,15,16,19,19,20,24};
int arr[] = {0, 7, 4, 3, 8, 1, 5, 4, 2};
// function to find the greatest number in the array. It take the array as parameter,
// and return the max value
int maxElement(const int* a);

// function use linear search approach to find an elements. If the element is in the array,
// return its first index, else return 0;
int linearSearch(const int* a, int numberToSearch);

int binarySearch(const int* sortedArr, int numberToSearch);

void bubbleSort(int* a);

string addBinary(string s1, string s2);

int ternarySearch(const int *sortedArr, int x);

void binaryInsertionSort(int* arr) {
    // sap xep giam dan
    int pos;
    for (int j = 2; j < numberOfElements; j++) {
        int x = a[j];
        int lo = 1;
        int hi = j - 1;
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (x > arr[m]) {
                hi = m - 1;
            }
            else {
                lo = m;
            }
        }
        if (x < a[lo]) {
            pos = lo + 1;
        } else {
            pos = lo;
        }
        for (int i = j - 1; i >= pos; i--) {
            a[i + 1] = a[i];
        }
        a[pos] = x;
    }
}

int main() {
    cout << "Hello ";
    binaryInsertionSort(arr);
    for (int i = 1; i <= 8; i++) {
        cout << arr[i] << " ";
    }
    cout << "World";
}

int maxElement(const int* a) {
    int max = a[1];
    for(int i = 2; i <= numberOfElements; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

int linearSearch(const int* a, int numberToSearch) {
    /* use for loop
    for (int i = 1; i <= numberOfElements; i++) {
        if (a[i] == numberToSearch) {
            return i;
        }
    }
    return 0;
    */
    // use while loop
    int i = 1, location = 0;
    while (i <= numberOfElements && a[i] != numberToSearch) {
        i++;
    }
    // if found, return the index.
    if (i <= numberOfElements) {
        location = i;
    }
    // else return 0 to indicate that the element is not in the array.
    else {
        location = 0;
    }
    return location;

}

int binarySearch(const int* sortedArr, int numberToSearch) {
    int i = 1, j = numberOfElements;
    while (i <= j) {
        int mid = (i + j) / 2; // l + (r - l) /2;
        if (a[mid] == numberToSearch) return mid;
        else if (a[mid] < numberToSearch) {
            i = mid + 1;
        }
        else {
            j = mid - 1;
        }
    }
    return 0;
    /*
    binarySearch
    start:       (3, 1, 2, 3, 3, 3, 4, 5, 6, 7, 8, 9)
    i = 1, j = 12, m = 6 => a[m] = 3 = numberToSearch => j = 6;
    i = 1, j = 6, m = 3 => a[m] = 2 < numberToSearch => i = 3;
    i = 3, j = 6, m = 4 => a[4] = 3 = numberToSearch => i = 4;
    */
}

void bubbleSort(int* a) {
    for (int i = 1; i <= numberOfElements - 1; i++) {
        for (int j = 1; j <= numberOfElements - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void insertionSort(int *a) {
    for (int j = 2; j <= numberOfElements; j++) {
        int i = 1;
        while (a[j] > a[i]) {
            i++;
        }
        int m = a[j];
        for (int k = 0; k <= j - i + 1; k++) {
            a[j - k] = a[j - k - 1];
        }
        a[i] = m;
    }
}

/*
Binary Number
*/

string convertToBinary(int n) {
    if (n == 0) return "0";
    string ans = "";
    while (n > 0) {
        int rem = n % 2; // rem = 0 or rem = 1;
        ans = (char) rem + ans;
        n /= 2;
    }
    return ans;
}

string addBinary(string s1, string s2) {
    // n1 == n2
    int n = s1.length();
    int tmp,dv, nho(0);
    string ans = "";
    for (int i = n - 1; i >= 0; i--) {
        tmp = (s1[i] - '0') + (s2[i] - '0') + nho; // cai nay co the vuot qua 2
        dv = tmp % 2;
        nho = tmp / 2;
        ans = char(dv + '0') + ans;
    }
    if (nho) {
        ans = "1" + ans;
    }
    return ans;
}

int ternarySearch(const int *sortedArr, int x) {
    int i = 1;
    int j = 16;
    while (i < j) {
        int m1 = i + (j - i + 1) / 3;
        int m2 = m1 + (j - i + 1) / 3;
        if (x > sortedArr[m2]) {
            i = m2 + 1;
        } else {
            if (x > sortedArr[m1]) {
                i = m1 + 1;
                j = m2 - 1;
            } else {
                j = m1 - 1;
            }
        }
    }
    int location;
    if (x == sortedArr[i]) {
        location = i;
    } else location = 0;
    return location;
}









