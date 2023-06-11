#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

ll n;

void merge(ll a[], ll l, ll m, ll r)
{
	ll i=l;		//starting index for left subarray
	ll j=m+1;	//starting index for right subarray
	ll k=l;		//starting index for temporary array
	
	ll temp[n+10];	//temporary array
	
	while(i<=m && j<=r)
	{
		if(a[i]<=a[j])
		{
			//temp.push_back(a[i]);
			temp[k]=a[i];	//a[i] smaller than a[j]
			i++;
			k++;
		}
		else
		{
			//temp.push_back(a[j]);
			temp[k]=a[j];
			j++;
			k++;
		}
	
	}
	
	while(i<=m)
	{
		//temp.push_back(a[i]);
		temp[k]=a[i];
		i++;
		k++;
	}
	
	while(j<=r)
	{
		//temp.push_back(a[j]);
		temp[k]=a[j];
		j++;
		k++;
	}
	
	for(ll i=l;i<=r;i++)
	{
		a[i]=temp[i];
		//temp.pop_back();
	}
}

void MergeSort(ll a[], ll l, ll r)
{
		if(l<r)
		{
			ll m=l +( r-l)/2;
			//ll m=(l+r)/2;
			MergeSort(a,l,m);
			MergeSort(a,m+1,r);
			merge(a,l,m,r);
		}
}

/*
void printArr(ll a[], ll s)
{
	for(ll i=0;i<s;i++)
	{
		cout<<a[i]<<"\n";
	}
}
*/

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	scanf("%d", &n);
	ll a[n+10];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a[i]);
	}
	MergeSort(a, 0, n-1);
	for(ll i=0;i<n;i++)
	{
		printf("%d\n", a[i]);
	}
}