#include<iostream>
using namespace std;
int main()
{
	int array[8][8];
	
	int arr[8];
	
	cout<<"Enter Numbers To Place Queens:";
	for(int i=0;i<8;i++)
	{
	cin>>arr[i];
	}
	
	for(int i=0;i<8;i++)
      {
      	for(int j=0;j<8;j++)
      	{
      		if (arr[i]==j)
      		{
      			cout<<"Q";
	    	}else
	    	{
	    		cout<<".";
			}
	    }
	  cout<<endl;
      }
}
