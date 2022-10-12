# Traversal

## Traversing an array

```cpp
#include<iostream>
using namespace std;
int main()
{
    int i,arr[5]; //declare array of size 5 and counter
    cout<<"Enter 5 elements: ";
    for(int i=0;i<5;i++) //loop for array input
    cin>>arr[i]; //if foor loop has one action then curly braces are optional
    cout<<"The array elements are: ";
    for(i=0;i<5;i++) //loop for array output
    cout<<arr[i]<<" ";
    return 0;
}
```

---

## Sum of prime numbers in an array

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, arr[5], sum=0; //initialise counter
    cout<<"Enter array elements: ";
    for(i=0;i<5;i++) 
    {
        cin>>arr[i]; //take array input
    }
    for(i=0;i<5;i++) //iterate for prime
    {
        bool isPrime = true; 
        for(int j=2;j<arr[i];j++) //check for prime condition
        {
            if(arr[i]%j == 0)
            {
                isPrime = false; //co-prime found
                break;
            }
        }
        if(isPrime)
        sum+=arr[i]; //add prime value to sum
    }
    cout<<"The sum of all elements in the array is: "<<sum;
    return 0;
}
```

---

# Insertion and Deletion

## Insertion of new element in an array

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100], n, ele, k;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element and index number: ";
    cin>>ele>>k;
    for(int i=n-1;i>=k-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[k-1]=ele;
    for(int i=0;i<n+1;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
```

---

## Deletion of an element in an array

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100], n, k;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter index number: ";
    cin>>k;
    for(int i=k;i<n;i++) //initialise counter to given index
    {
      arr[i]=arr[i+1]; //shift leftwards
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
```

---

## Deletion of a specific element

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, element;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to delete: ";
    cin>>element;
    int j;
    for(j=0;j<n;j++)
        if(arr[j]==element)
            break;
    if(j<n)
    {
        n=n-1;
        for(int k=j;k<n;k++)
        {
            arr[k]=arr[k+1];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
```

---

# Searching

## Linear Search

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, element, pos = -1; // initialise counter
    cout << "Enter number of elements: ";
    cin >> n; // array count input
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // array elements input
    }
    cout << "Enter element to be seached: ";
    cin >> element; // key input
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element) // comparison of key with each item of the array
        {
            pos = i; // key is found
            break;   // break out of the loop
        }
    }
    if (pos == -1) // loop is over and element is still not found
    {
        cout << "Element not found.";
    }
    else
    {
        cout << "Element found at position " << pos + 1;
    }
    return 0;
}
```

---

## Binary Search

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, element, pos = -1;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to be searched: ";
    cin>>element;
    int start = 0, end = n-1;
    int mid = (start + end )/2;
    while(start<=end)
    {
        if(arr[mid]==element)
        {
            pos = mid;
            break;
        }
        if(arr[mid] > element)
        {
            end = mid - 1;
        }
        if(arr[mid] > element)
        {
            start = mid + 1;
        }
        (mid = start + end )/2;
    }
    if(pos == -1)
    {
        cout<<"Element is not present in the array.";
    }
    else
    {
        cout<<"Element is present at the position "<<pos+1;
    }
    return 0;
}
```

---

# Sorting

## Bubble Sort

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cout << "Enter number of elements: ";
 cin >> n;
 int arr[n];
 cout << "Enter array elements: ";
 for (int i = 0; i < n; i++)
 {
  cin >> arr[i];
 }
 // ALWAYS USE (n-1) IN BOTH LOOPS
 for (int i = 0; i < n - 1; i++) // outer loop
 {
  for (int j = 0; j < n - 1 - i; j++) // inner loop
  {
   if (arr[j] > arr[j + 1]) // swapping elements
   {
    swap(arr[j], arr[j + 1]);
   }
  }
 }
 cout << "The sorted array is: ";
 for (int i = 0; i < n; i++)
 {
  cout << arr[i] << " ";
 }
}
```

---

## Selection Sort

```cpp
#include <bits/stdc++.h>
#define el endl
using namespace std;
int main()
{
 int n;
 cout << "Enter number of elements: ";
 cin >> n;
 int arr[n];
 cout << "Enter array elements: ";
 for (int i = 0; i < n; i++)
 {
  cin >> arr[i];
 }
 int minIndex;
 for (int i = 0; i < n - 1; i++)
 {
  minIndex = i;
  for (int j = i + 1; j < n; j++)
  {
   if (arr[j] < arr[minIndex])
    minIndex = j;
   // if (minIndex != i)
    swap(arr[minIndex], arr[i]);
  }
 }
 cout << "The sorted array is: ";
 for (int i = 0; i < n; i++)
 {
  cout << arr[i] << " ";
 }
}
```

---

## Insertion Sort

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: "; // array size input
    cin >> n;
    int arr[n];
    cout << "Enter array elements: "; // array input
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int i, j, minVal;       // initialize counter and minimum value variables
    for (i = 0; i < n; i++) // iterate over the array (outer loop)
    {
        minVal = arr[i]; // set minVal to first element
        j = i - 1;
        while (j >= 0 && arr[j] > minVal) // if elements are greater than minVal
        {
            arr[j + 1] = arr[j]; // then shift the elements
            j = j - 1;
        }
        arr[j + 1] = minVal; // re-initialize minVal
    }
    for (int i = 0; i < n; i++) // print the array
        cout << arr[i] << " ";
    return 0;
}
```
