
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int FIFO(int n,vector<int> v,int st){


	int thm=0;

	int pos = st;
	printf(" %d ---  ",st);
	for (int i = 0; i < n; ++i)
	{
		thm += abs(pos-v[i]);
		pos = v[i];
		printf(" %d ---  ",v[i]);
	}

	printf("\n");

	printf("\ntotal head movement (THM) of the disk is %d\n\n",thm);

	return thm;


}


int SSTF(int n,vector<int> v,int st){


	int thm=0;

	int pos = st;

	vector<bool> vis(n,false);

	
	printf(" %d ---  ",st);
	for (int i = 0; i < n; ++i)
	{

		int minn = INT_MAX,minn_ind = -1;

		for(int j=0;j<n;j++){

			if(!vis[j] && abs(pos-v[j])<minn){
				minn = abs(pos-v[j]);
				minn_ind = j;
			}
		}

		thm += minn;
		vis[minn_ind] = true;
		pos = v[minn_ind];
		printf(" %d ---  ",v[minn_ind]);
	}
	printf("\n");

	printf("\ntotal head movement (THM) of the disk is %d\n\n",thm);

	return thm;


}





int SCAN(int n,vector<int> v,int st,char dir){

	if(dir=='R'){

		int thm=0;

		// int pos = st;

		// vector<bool> vis(n,false);

		// for (int i = 0; i < n; ++i)
		// {

		// 	int minn = INT_MAX,minn_ind = -1;

		// 	for(int j=0;j<n;j++){

		// 		if(!vis[j] && abs(pos-v[j])<minn){
		// 			minn = abs(pos-v[j]);
		// 			minn_ind = j;
		// 		}
		// 	}

		// 	thm += minn;
		// 	vis[minn_ind] = true;
		// 	pos = v[minn_ind];
		// }


		// return thm;

		v.push_back(st);
		
		n=n+1;
		int i,j,temp;
		for(i=0;i<n;i++)   
		{
			for(j=i;j<n;j++)
			{
				if(v[i]>v[j])
				{
					temp=v[i];
					v[i]=v[j];
					v[j]=temp;
				}
			}
		}
		int maxx = v[n-1],dloc;
		for(i=0;i<n;i++)   
		{
			if(st==v[i]) { 
				dloc=i; 
				break;  
			}
		}
		
		
		for(i=dloc;i<n;i++)
		{
			printf(" %d -- ",v[i]);
		}
		if(v[n-1]!=199) 
		printf(" 199 --  ");

		for(i=dloc-1;i>=0;i--)
		{
			printf(" %d ---  ",v[i]);
		}
		
		thm=(199-st)+(199-v[0]);
		printf("\n");
		printf("\ntotal head movement (THM) of the disk is %d\n\n",thm);
		return thm;

	}else{

		int thm=0;

		// int pos = st;

		// vector<bool> vis(n,false);

		// for (int i = 0; i < n; ++i)
		// {

		// 	int minn = INT_MAX,minn_ind = -1;

		// 	for(int j=0;j<n;j++){

		// 		if(!vis[j] && abs(pos-v[j])<minn){
		// 			minn = abs(pos-v[j]);
		// 			minn_ind = j;
		// 		}
		// 	}

		// 	thm += minn;
		// 	vis[minn_ind] = true;
		// 	pos = v[minn_ind];
		// }


		// return thm;

		v.push_back(st);
		
		n=n+1;
		int i,j,temp;
		for(i=0;i<n;i++)   
		{
			for(j=i;j<n;j++)
			{
				if(v[i]>v[j])
				{
					temp=v[i];
					v[i]=v[j];
					v[j]=temp;
				}
			}
		}
		int maxx = v[n-1],dloc;
		for(i=0;i<n;i++)   
		{
			if(st==v[i]) { 
				dloc=i; 
				break;  
			}
		}
		for(i=dloc;i>=0;i--)
		{
			printf(" %d ---  ",v[i]);
		}
		printf(" 0 --  ");
		
		for(i=dloc+1;i<n;i++)
		{
			printf(" %d -- ",v[i]);
		}
		thm=st+maxx;
		printf("\n");
		printf("\ntotal head movement (THM) of the disk is %d\n\n",thm);
		return thm;

	}

}


int CSCAN(int n,vector<int> v,int st,char dir){

if(dir=='L'){




	int thm=0;

	// int pos = st;

	// vector<bool> vis(n,false);

	// for (int i = 0; i < n; ++i)
	// {

	// 	int minn = INT_MAX,minn_ind = -1;

	// 	for(int j=0;j<n;j++){

	// 		if(!vis[j] && abs(pos-v[j])<minn){
	// 			minn = abs(pos-v[j]);
	// 			minn_ind = j;
	// 		}
	// 	}

	// 	thm += minn;
	// 	vis[minn_ind] = true;
	// 	pos = v[minn_ind];
	// }


	// return thm;

	v.push_back(st);
	
	n=n+1;
	int i,j,temp;
	for(i=0;i<n;i++)   
	{
		for(j=i;j<n;j++)
		{
			if(v[i]>v[j])
			{
				temp=v[i];
				v[i]=v[j];
				v[j]=temp;
			}
		}
	}
	int maxx = v[n-1],dloc;
	for(i=0;i<n;i++)   
	{
		if(st==v[i]) { 
			dloc=i; 
			break;  
		}
	}
	
	
	
	for(i=dloc;i>=0;i--)
	{
		printf(" %d -- ",v[i]);
	}
	if(v[0]!=0) 
		printf(" 0 --  ");

	if(v[n-1]!=199) 
		printf(" 199 --  ");
	

	for(i=n-1;i>dloc;i--)
	{
		printf(" %d ---  ",v[i]);
	}

	thm=(st)+(199-v[dloc+1]);
	printf("\n");
	printf("\ntotal head movement (THM) of the disk is %d\n\n",thm);

	return thm;



}else{

	int thm=0;

	// int pos = st;

	// vector<bool> vis(n,false);

	// for (int i = 0; i < n; ++i)
	// {

	// 	int minn = INT_MAX,minn_ind = -1;

	// 	for(int j=0;j<n;j++){

	// 		if(!vis[j] && abs(pos-v[j])<minn){
	// 			minn = abs(pos-v[j]);
	// 			minn_ind = j;
	// 		}
	// 	}

	// 	thm += minn;
	// 	vis[minn_ind] = true;
	// 	pos = v[minn_ind];
	// }


	// return thm;

	v.push_back(st);
	
	n=n+1;
	int i,j,temp;
	for(i=0;i<n;i++)   
	{
		for(j=i;j<n;j++)
		{
			if(v[i]>v[j])
			{
				temp=v[i];
				v[i]=v[j];
				v[j]=temp;
			}
		}
	}
	int maxx = v[n-1],dloc;
	for(i=0;i<n;i++)   
	{
		if(st==v[i]) { 
			dloc=i; 
			break;  
		}
	}
	
	
	
	for(i=dloc;i<n;i++)
	{
		printf(" %d -- ",v[i]);
	}
	if(v[n-1]!=199) 
		printf(" 199 --  ");
	if(v[0]!=0)
		printf(" 0 --  ");

	for(i=0;i<dloc;i++)
	{
		printf(" %d ---  ",v[i]);
	}

	thm=(199-st)+v[dloc-1];
	printf("\n");
	printf("\ntotal head movement (THM) of the disk is %d\n\n",thm);

	return thm;



	}


}

int main(int argc, char const *argv[])
{
	


	int size_q;
	printf("No of elements: \n");
	cin >> size_q;

	vector<int> v;

	for (int i = 0; i < size_q; ++i)
	{
		printf("Element %d :\n",i+1);
		int j;
		cin >> j;
		v.push_back(j);
	}


	printf("starting position: \n");
	int st;
	cin >> st;

	// cout << "------------------- FIFO -------------------" << endl;
	// FIFO(size_q,v,st);
	// cout << "------------------- SSTF -------------------" << endl;
	// SSTF(size_q,v,st);
	// cout << "------------------- SCAN - Left -------------------" << endl;
	// SCAN(size_q,v,st,'L');
	// cout << "------------------- SCAN - Right -------------------" << endl;
	// SCAN(size_q,v,st,'R');
	// cout << "------------------- CSCAN - Left -------------------" << endl;
	// CSCAN(size_q,v,st,'L');
	// cout << "------------------- CSCAN - Right -------------------" << endl;
	// CSCAN(size_q,v,st,'R');

	cout << "------------------- FIFO -------------------" << endl;
	// FIFO(size_q,v,st);

	cout << "\n Seek Time : " << 5*FIFO(size_q,v,st) << endl;


	cout << "------------------- SSTF -------------------" << endl;
	// SSTF(size_q,v,st);
	cout << "\n Seek Time : " << 5*SSTF(size_q,v,st) << endl;


	cout << "------------------- SCAN - Left -------------------" << endl;
	// SCAN(size_q,v,st,'L');
	cout << "\n Seek Time : " << 5*SCAN(size_q,v,st,'L') << endl;


	cout << "------------------- SCAN - Right -------------------" << endl;
	// SCAN(size_q,v,st,'R');
	cout << "\n Seek Time : " << 5*SCAN(size_q,v,st,'R') << endl;

	cout << "------------------- CSCAN - Left -------------------" << endl;
	// CSCAN(size_q,v,st,'L');
	cout << "\n Seek Time : " << 5*CSCAN(size_q,v,st,'L') << endl;
	cout << "------------------- CSCAN - Right -------------------" << endl;
	// CSCAN(size_q,v,st,'R');
	cout << "\n Seek Time : " << 5*CSCAN(size_q,v,st,'R') << endl;


	return 0;
}

