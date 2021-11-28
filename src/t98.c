#include "common.h"

int binarySearch(int arr[], int l, int r, int x,int counter,int k)
{

    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            counter++;
            return binarySearch(arr, l, mid - 1, x,counter,k);

        // Else the element can only be present
        // in right subarray
            counter++;
        return binarySearch(arr, mid + 1, r, x,counter,k);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

int binary_search(int* arr, int size, int target)
{
    int index, power;

    for (power = 1; power < size; power <<= 1);

    for (index = 0; power; power >>= 1)
        if (index + power < size && arr[index + power] <= target)
            index += power;

    if (arr[index] == target)
        return index;
    return -1;
}


int main(void)
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 0;
    int counter = 0;
    printf("n: ");
    scanf("%d", &n);
    printf("k: ");
    scanf("%d", &k);
    int p = rand(0, n);
    int x = 10;
    int result = binary_search(arr,n-1,p)
    int counter = binarySearch(arr, 0, n - 1, x,k);
    if (counter == -1) 
    {
        printf("Takoe ne vozhmozhno");
    }
    else
    {
        if(counter <= k)
        printf("Prochnost'oreha ravna %d\n Kolichestvo popitok %d",counter,result);
    }
         
    return 0;
}