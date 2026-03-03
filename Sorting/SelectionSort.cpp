#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {5, 2, 9, 1, 3};
    int min, temp;

    for(int i = 0; i < 5; i++)
    {
        min = i;

        for(int j = i + 1; j < 5; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "Selection Sorted Array: ";
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

