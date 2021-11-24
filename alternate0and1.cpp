#include <iostream>
using namespace std;

void seg(int* arr,int n){
    int odp = 1 ,evp = 0;
    // odd has + , evp has -ve;
    int arr2[n];
    
    for (int i = 0; i < n; i++) {
        if(arr[i] >= 0 && odp >= 0 ){
    
            
            arr2[odp] = arr[i];
            
            if(odp&1)
            odp+=2;
            else odp-=2;
            
            if(odp == n+1 && n%2 == 0){
                
                odp = n-2;
            }
            else if(odp == n && n&1 ){
                
                odp = n-1;
            }
            
                
        }    
    }
    for (auto i : arr2) {
            cout<<i<<" ";
        }
        cout<<endl;
    
    
    for (int i = 0; i < n; i++) {
        if(arr[i] < 0 && evp >= 0  ){
    
            arr2[evp] = arr[i];
            
            if( !(evp&1) )
            evp+=2;
            else evp-=2;
            
            if(evp == n && n%2 == 0)evp = n-1;
            else if(evp == n+1 && n&1 )evp = n-2;
            
        }    
    }
        
        for (auto i : arr2) {
            cout<<i<<" ";
        }
        return;
}

int main() {
    
	int n =  10;
	int arr[n];
	
	for (int i = 0; i < n; i++) {
	    cin>>arr[i];
	}
	
	seg(arr,n);
    
    
	
	return 0;
}