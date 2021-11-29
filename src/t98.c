#include "common.h"

int counter = 0;
 
int main(void)
{

	int k = 0, n = 0, p = 0;
	printf("n: ");
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n+1; i++)
	{

		arr[i] = i;

	}

	printf("k: ");
	scanf_s("%d", &k);

	srand(time(NULL));
	p = rand()%n ;

	printf("proch'nost oreha : %d", p);

	int result = binarySearch(arr, 0, n - 1, p);

	

	
	if (result == -1)
		printf("Elementa v massive nety");
	else
		 printf("kol - vo shagov % d",counter);
	free(arr);
	return 0;
}

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
		{
			counter++;
			return mid;
		}
			
			

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x) 
		{
			counter++;
			return binarySearch(arr, l, mid - 1, x);
		}
			

		// Else the element can only be present
		// in right subarray
			counter++;
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}