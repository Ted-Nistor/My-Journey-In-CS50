// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    //bubble sort with a counter and a temporary variable to
    // store the values when swapped.
    int temp;
    int counter = -1;
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0 ; i < n ; i++)
        {
            if (array[i] > array[i + 1])
            {
                counter++;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    return array[n - 1];
}
