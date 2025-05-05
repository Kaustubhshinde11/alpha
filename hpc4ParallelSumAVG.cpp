#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <climits>

using namespace std;

int main(){
    
    int n;
    cout << "Enter the size of array ?" << endl;
    cin >> n;
    
    int data[n];
    
    cout << "Enter the array values: " << endl;
    
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        data[i] = m;
    }
    
    int max_val = INT_MIN;
    int min_val = INT_MAX;
    int sum = 0;
    
    #pragma omp parallel for reduction(min:min_val) reduction(max:max_val) reduction(+:sum)
    for(int j=0; j<n; j++){
        
        if(data[j] < min_val){
            
            min_val = data[j];
        }
        
        if(data[j] > max_val){
            
            max_val = data[j];
        }
        
        sum += data[j];
    }
    
    float avg = float(sum)/n;
    
    cout << "The maximum element is: " << max_val << endl;
    cout << "The minimum element is: " << min_val << endl;
    cout << "The sum is: " << sum << endl;
    cout << "The average is: "<< avg << endl;
    
    return 0;
}
