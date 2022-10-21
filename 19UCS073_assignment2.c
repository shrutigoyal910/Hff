// 19UCS073
// SHUBHAM AGRAWAL
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define INT_MAX 2147483647

/* Sample input for 1st part
    3
    60 100 120
    10 20 30
    50
*/
/* Sample output for 1st part
    220
*/

/* Sample input for 2nd part 
    5
    9 87 1 22 34
    3
*/
/* Sample output for 2nd part
    22
*/

/*************************Q1  0/1 Knapsack ************************/

// Function to return maximum of two numbers
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// function to solve 0-1 knapsack
void knapsack()
{
    printf("\n");

    printf("Enter number of elements in the weigth array: ");
    int n;
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter the weights of elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter knapsack bag capacity: ");
    int W;
    scanf("%d", &W);

    printf("\n");

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    printf("Max value when bag capacity is %d and number of items is %d: ", W, n);
    printf("%d\n", dp[n][W]);
}


/*********** Deterministic linear time selection algorithm: finding kth samllest element in an unsorted array **************/

// Function to merge array with two pointer approach
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function for merge sort
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to find median of array
int findMedian(int arr[], int n)
{
    mergeSort(arr, 0, n - 1);
    return arr[n / 2];
}

// Function to swap elements 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find partition in array
int partition(int arr[], int l, int r, int x)
{
    int i;
    for (i = l; i < r; i++)
        if (arr[i] == x)
            break;
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}


// Function to find Kth smallest element
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;

        // DIVIDING ARRAY INTO N/5 GROUPS OF 5 ELEMENT EACH  
        int i, median[(n + 4) / 5];
        for (i = 0; i < n / 5; i++)
        {
            // SORTING EACH ELEMENT USING MERGE SORT
            median[i] = findMedian(arr + l + i * 5, 5);
        }
        if (i * 5 < n)
        {
            median[i] = findMedian(arr + l + i * 5, n % 5);
            i++;
        }

        int medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, 0, i - 1, i / 2);

        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    return INT_MAX;
}

// Driver function
void findKthSmallest()
{
    printf("\n");
    printf("Enter number of elements in an array: ");
    int n;
    scanf("%d", &n);

    printf("Enter the array: ");
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k:");
    int k;
    scanf("%d", &k);

    printf("Kth smallest element is: %d\n", kthSmallest(arr, 0, n - 1, k));
}


// Driver code
/*************************************************************************/

int main()
{
    printf("Options\n");
    printf("1. 0/1 knapsack problem\n");
    printf("2. kth smallest element in an array\n");

    printf("\n");
    printf("Enter your option: ");
    int option;
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        knapsack();
        break;

    case 2:
        findKthSmallest();
        break;

    default:
        printf("No such option available\n");
        break;
    }

    return 0;
}