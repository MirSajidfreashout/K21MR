// A data structure competition has been conducted and the marks of all students are stored in random order in an array. Suppose the scored marks by the students in non-increasing order is K1, K2,….KN. Write to program to find the third highest scored marks by the student. The size of array should be greater than 0 and less than equal to 20. If size is not in the mention range than program should display “Invalid array size” without asking for the other inputs.
// Input Format
// Your program should take the three types of inputs. First will represent size of array, second will represent elements of array and third will be the 3rd largest element.
// Constraints
// The length of array (L) should be 0 < L <=20
// Output Format
// Should display the 3rd largest element or “Not sufficient elements” if number of elements will be less than 3.
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    int n;
    cin>>n;
    if (n > 20 || n < 1){ 
        cout<<"Invalid array size";
        return 0;
    }
    int arr[n];
    for(int i= 0; i < n; i++) cin>>arr[i];
    
    if(n < 3) {
        cout<<"Not sufficient elements";
        return 0;
    }
    
    int trips[3] = {0};
    
    for(int i = 0; i < n; i++){
        if (arr[i] >= trips[0]){
            trips[2] = trips[1];
            trips[1] = trips[0];
            trips[0] = arr[i];
        }
        else if(arr[i] > trips[1]){
            trips[2] = trips[1];
            trips[1] = arr[i];
        }
        else if(arr[i] > trips[2]){
            trips[2] = arr[i];
        }
    }
    cout<<trips[2];
    
    return 0;
}