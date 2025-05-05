#include <iostream>
#include <ctime>
#include <omp.h>

using namespace std;

void sequentialBubbleSort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void parallelBubbleSort(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{
		int phase = i%2;
			
		#pragma omp parallel for
		for(int j=phase; j<n-1; j+=2)
		{
			if(arr[j] > arr[j+1])
			{
				swap(arr[j], arr[j+1]);
			}
		}
	}
}



int main()
{
	cout<<"Enter the number of elements in array:";
	int n;
	cin>>n;

	int original[n];

	for(int i=0; i<n; i++)
	{
		cout<<"Enter the element number "<<i+1<<":";
		cin>>original[i];
	}

	//printing original array
	for(int i=0; i<n; i++)
        {
                cout<<original[i]<<", ";
        }
	cout<<endl;

	
	//making 2 copies of original array, so to use for sequential and parallel bubble sort  
	int arr1[n], arr2[n];	
	for(int i=0; i<n; i++)
	{
		arr1[i] = original[i];
		arr2[i] = original[i];
	}

	//sequential sort timing
	double s_start = omp_get_wtime();
	sequentialBubbleSort(arr1, n);
	double s_end = omp_get_wtime();
	
	for(int i=0; i<n; i++)
	{
		cout<<arr1[i]<<", ";
	}
	cout<<endl;

	cout<<"Time taken by sequential bubble sort:"<<s_end-s_start<<"seconds."<<endl;


	//parallel sort timing
	double p_start = omp_get_wtime();
	parallelBubbleSort(arr2, n);
	double p_end = omp_get_wtime();

	for(int i=0; i<n; i++)
	{
		cout<<arr2[i]<<", ";
	}
	cout<<endl;

	cout<<"Time taken by parallel bubble sort:"<<p_end-p_start<<"seconds."<<endl;
}
