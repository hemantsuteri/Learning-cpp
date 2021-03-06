#include <iostream>
using namespace std;
void merge(int a[],int si,int mid,int ei)
{
    int n=mid-si+1;    int m=ei-mid;
    int left[n];       int right[m];
    
    for(int i=0;i<n;i++)   left[i]=a[si+i];
    for(int i=0;i<m;i++)   right[i]=a[mid+1+i];
   
    int i=0,    j=0,    k=si;
    
    while(i<n && j<m)
    {
        if(left[i]<=right[j])
            a[k++]=left[i++];
        else
            a[k++]=right[j++];
    }
    while(i<n)      a[k++]=left[i++];
    while(j<m)      a[k++]=right[j++];
}
void mergesort(int a[],int si,int ei)
{
    if(si>=ei)  {return;}
    int mid = si+(ei-si)/2;
    mergesort(a,si,mid);
    mergesort(a,mid+1,ei);
    merge(a,si,mid,ei);
}

int main()
{
    int a[]={1,3,2,4};
    mergesort(a,0,3);
    for(int i=0;i<4;i++)   cout<<a[i]<<",";
    return 0;
}
