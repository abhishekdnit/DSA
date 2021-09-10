//Insertion sort-> If previous element > Key-> shift that element 1 position right.If previous < Key-> put Key element after that element.
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int A[]={6,5,3,8,7,2,1,4};
    int n,i,j,k;                // k is key here.
    n=sizeof(A)/sizeof(A[0]);


    for(i=1;i<n;i++)            // Loop for first i sub-array sorting, intution is 1st element (0th) is sortred, So, i=1.
    {
        k=A[i];                 // Key element to compare with previous elements of sorted sub-array & insert A[i] into its proper position in sorted A[0....i-1]
        j=i-1;
        while(k<A[j] && j>=0)   // To compare previous element from i & shifting elements in right side in each iteration
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=k;               // Putting Key element in its right position
    }

    for(i=0;i<n;i++)
    {
        cout<<A[i]<<"  ";
    }
}


