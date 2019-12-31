//disjoint graph and bfs and dfs

#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

void printBFS(int** edges,int n,int sv,bool* visited){
	queue<int> pendingVertex;
	pendingVertex.push(sv);
	while(!pendingVertex.empty()){
		int currentVertex=pendingVertex.front();
		pendingVertex.pop();
		cout<<currentVertex<<" ";
		
		for(int i=0;i<n;i++){
			if(i==sv){
				continue;
			}
			
			if(edges[sv][i]==1 && !visited[i]){
				pendingVertex.push(i);
				visited[i]=true;
			}
		}
	}
}




void BFS(int** edges,int n){
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printBFS(edges,n,i,visited);
		}
	}
	
		//deleting visited array
	delete [] visited;
	
}

void printDFS(int** edges,int n,int sv,bool* visited){
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
			printDFS(edges,n,i,visited);
		}
	}
	
	
}


void DFS(int**edges,int n){
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
	visited[i]=false;
	}
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printDFS(edges,n,i,visited);
		}
	}
	
	//deleting visited array
	delete [] visited;
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
	
	//input edges
	for(int i=0;i<e;i++){
		int f,l;
		cin>>f>>l;
		edges[f][l]=1;
		edges[l][f]=1;
	}
	
	DFS(edges,n);
	cout<<endl;
	BFS(edges,n);
	
	
	//deleteing 2d array
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}
