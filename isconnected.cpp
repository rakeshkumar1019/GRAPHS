#include<bits/stdc++.h>
using namespace std;
void printBFS(int** edges,int n,int sv,bool* visited){
	cout<<sv<<" ";
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i]==1){
			if(visited[i]){
				continue;
			}
			printBFS(edges,n,i,visited);
		}
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	int** edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
		   edges[i][j]=0;	
		}
	}
	
	for(int i=0;i<e;i++){
		int f,l;
		cin>>f>>l;
		edges[f][l]=1;
		edges[l][f]=1;
		
	}
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	
	printBFS(edges,n,0,visited);
	
	int torf=1;
	for(int i=0;i<n;i++){
	   if(visited[i]==false){
	   torf=0;
	   break;
	   }	    
	   
	}
	(torf==1)? cout<<"true": cout<<"false";
	
	
}
