
#include <bits/stdc++.h>
#include <vector>
using namespace std;
 
void mg(int *arr ,int i , int j,int m){
    
    int s1 = m - i + 1;
    int s2 = j - m ;
    int a1[ s1 ];
    int a2[ s2 ];
    
    for(int s = 0 ; s < s1 ; s++)
        a1[s] = arr[ s + i ];
    
    for(int s = 0 ; s < s2 ; s++)
        a2[s] = arr[ s + m + 1];
    
    
    int fp = 0 , sp = 0 ;
    int arrp = i;
    while(fp < s1 && sp < s2 ){
        
        if( a1[ fp ] < a2[ sp ] ){
            arr[ arrp++ ] = a1[fp++];
        }else arr[ arrp++ ] = a2[sp++];
    }
    
    while(fp < s1 ){
        arr[ arrp++ ] = a1[fp++];
    }
    
    while(sp<s2){
        arr[ arrp++ ] = a2[sp++];
    }
    
    return;
}
 
void ms(int *arr,int i , int j){
    
    if(i>=j)return;
    
    int m = (i+j)/2;
    
    ms(arr,i,m);
    ms(arr,m+1,j);
    mg(arr,i,j,m);
    
return;
}

int part(int *arr,int i , int j){
    
    int piv = arr[j];
    int l = i;
    // 40 20 22 25
    // 0  1   2  3
    for (int s =i ; s <= j - 1 ; s++) {
        if(arr[s] < piv ){
            // l++;
            swap(arr[s] , arr[l++] );
        }
    }
    
    swap(arr[l] , arr[j] );
    return l;
}
 
void qs(int* arr,int i ,int j ){
    
    // if( i >= j )return;
     
     if(i<j){
         
    int p = part( arr,i,j );
    qs(arr,i,p-1);
    qs(arr,p+1,j);
    
     }
     
     
    return;
}
 
int main(){
    
    int n;
    cin>>n;
    int arr[n];
    
    for(int i = 0 ; i< n ;i++)
        cin>>arr[i];
        
    // ms(arr,0,n-1);
    qs(arr,0,n-1);
    
    cout<<"MERGED ARR : "<<endl;
    for(auto i:arr)cout<<i<<" ";
    


}