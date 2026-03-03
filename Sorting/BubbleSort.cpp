//Bubble sort

#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {5, 2, 9, 1, 3};
    int temp;

    // Bubble Sort start from here
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5 - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Printing sorted array
    cout << "Sorted Array: ";
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

