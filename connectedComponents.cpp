//disjoint graph and bfs and dfs

#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

void printDFS(int** edges,int n,int sv,bool* visited,vector<int> & res){
//	cout<<sv<<" ";
    res.push_back(sv);
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i]==1){
			if(visited[i]){
				continue;
			}
			printDFS(edges,n,i,visited,res);
           
		}
	}
	
	
}


void DFS(int**edges,int n){
    
    vector<int> res;
    
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
	visited[i]=false;
	}
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
		
			printDFS(edges,n,i,visited,res); 
			
			 sort(res.begin(),res.end());
            for(int i=0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
            cout<<endl;
            res.erase(res.begin(),res.end());
			
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
 
	
	
	//deleteing 2d array
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}
