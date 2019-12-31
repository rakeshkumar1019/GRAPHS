#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMinVertex(bool* visited,int* weight,int n){
	int minVertex=-1;
	for(int i=0;i<n;i++){
		if(!visited[i] && (minVertex==-1 || weight[i]<weight[minVertex])){
			minVertex=i;
		}
	}
	
	return minVertex;
	
}

void prims(int** input,int n){
	int* parent=new int[n];
	bool* visited=new bool[n];
	int* weight=new int[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
		weight[i]=INT_MAX;
	}
	weight[0]=0;
	parent[0]=-1;
	
	for(int i=0;i<n;i++){
		//finding mimum vertex which not visisted yet
		int minVertex=findMinVertex(visited,weight,n);
		visited[minVertex]=true;
		for(int j=0;j<n;j++){
			if(input[minVertex][j]>0 && !visited[j]){
				if(input[minVertex][j]<weight[j]){
					weight[j]=input[minVertex][j];
					parent[j]=minVertex;
				}
			}
		}
		
	}
	
	for(int i=1;i<n;i++){
		if(i<parent[i]){
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}else{
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;	
		}
	}
	
	
}
int main(){
	int n,e;
	cin>>n>>e;
	int** input=new int*[n];
	for(int i=0;i<n;i++){
		input[i]=new int[n];
		for(int j=0;j<n;j++){
			input[i][j]=-1;
		}
	}
	
	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		input[u][v]=w;
		input[v][u]=w;
	}
	
	prims(input,n);
	
	
	
	//deleteing 2d array
	for(int i=0;i<n;i++){
		delete [] input[i];
	}
	delete [] input;
}
