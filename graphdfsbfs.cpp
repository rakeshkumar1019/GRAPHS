#include<bits/stdc++.h>
#include<queue>
#include<iostream>
using namespace std;



//depth for search 
void print(int**edges,int n,int sv,bool* visited){
	cout<<sv<<"->";
	
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i]==1){
			if(visited[i]){
				continue;
			}
			print(edges,n,i,visited);
		}
		
	}
}
//breadth for search
void printBFS(int** edges,int n,int sv){
 queue<int> pendingVertex;
 bool * visited=new bool[n];
 for(int i=0;i<n;i++){
 visited[i]=false;
 }
 
 pendingVertex.push(sv);
 visited[sv]=true;
 while(!pendingVertex.empty()){
 int currentVertex=pendingVertex.front();
 pendingVertex.pop();
 cout<<currentVertex<<"->" ;
 for(int i=0;i<n;i++){
 if(currentVertex==i){
 continue;
 }
 if(edges[currentVertex][i]==1 && !visited[i]){
 pendingVertex.push(i);
 visited[i]=true;
 }
 }

 }
}


int main(){
	// no of vertex(n) and edges(e)
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
		//first and last index means (first->last) edge
		int f,l;
		cin>>f>>l;
		edges[f][l]=1;
		edges[l][f]=1;
	}
	
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
//DFS SEARCH/TRAVESAL
	print(edges,n,0,visited);
//BFS SEARCH/TRAVELSAL
cout<<endl;
printBFS(edges,n,0);
	
	
	
	
	//delete 2d array because of dynamic array
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
	
	
}
