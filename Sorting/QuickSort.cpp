#include <iostream>
using namespace std ;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int party(int arr[], int left , int right ){
    int pivot = (arr[left] + arr[right] ) / 2;

    int i = left - 1;

    for (int j = left ; j < right; j++){
        if (arr[j] < pivot){
            i++;

            swap(arr[i] , arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(int arr[], int left , int right){
    if( left < right ) {
        int pi = party(arr,left,right);

        quickSort(arr , left , pi - 1);

        quickSort(arr , pi + 1 , right);
    
    }
}

void printArray(int arr[], int size){
    for(int i = 0 ; left < size ; i++){
        cout<<arr[i]<< " ";
    }
}


int main(){

    int el;
    cout << "enter size of array ";
    cin >> el;


    int arr[el];

    cout << "Enter " << el << "elements" << endl;

    for (int i = 0 ; i < el ; i++){
        cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr , 0 , size - 1);

    cout << "sorted array ";
    printArray(arr , size);

    return 0;

}
