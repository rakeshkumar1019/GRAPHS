#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool printBFS(int** edges,int n,int sv,bool* visited,int lv){
 queue<int> pendingVertex;
 pendingVertex.push(sv);
 visited[sv]=true;
 while(!pendingVertex.empty()){
 	int currentVertex=pendingVertex.front();
 	pendingVertex.pop();
// 	cout<<currentVertex<<" ";
	if(currentVertex==lv){
 			return true;
		 }
	 for(int i=0;i<n;i++){
	 	if(edges[currentVertex][i]==1 && !visited[i]){
	 		pendingVertex.push(i);
			 visited[i]=true;
		 }
	 }
	 
	 
 }
	 

return false;	
	
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
    int sv,lv;
	cin>>sv>>lv;
	
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	
   if(printBFS(edges,n,sv,visited,lv)){
   	cout<<"true";
   }else{
   	cout<<"false";
   }
	
}
