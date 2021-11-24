#include <iostream>
#include <bits/stdc++.h>
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

void findTrip(int* arr,int n,int t){
    
    sort(arr,arr+n);
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // int i = 0 ,j = n-1 , s = 0;
    int arr2[1000][3];
    int c= 0;
    for (int i = 0; i < n - 2 ; i++) {
        
        
        int j = i + 1;
        int k = n - 1;
        
        while( j < k ){
            
            if(arr[i] + arr[j] + arr[k] == t ){
                arr2[c][0] = arr[i];
                arr2[c][1] = arr[j];
                arr2[c++][2] = arr[k];
                j++,k--;
            }else if(arr[i] + arr[j] + arr[k] < t )j++;
            else k--;
            
        }
        
    }
    
    for(int i =0 ; i < c ; i++){
        cout<<arr2[i][0]<<" "<<arr2[i][1]<<" "<<arr2[i][2]<<endl;
    }
    
    
    
 return;   
}

int main() {
    
	int n =  10;
	int arr[n];
	
	for (int i = 0; i < n; i++) {
	    cin>>arr[i];
	}
	
// 	seg(arr,n);
    int t;cin>>t;
    findTrip(arr,n ,t);
    
    
	
	return 0;
}