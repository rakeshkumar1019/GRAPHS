#include<iostream>
#include<queue>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;

vector<int>* getPathBfs(int** edges,int n,int sv,int lv){
	queue<int> q;
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	
	q.push(sv);
	visited[sv]=true;
	unordered_map<int,int> parent;
	bool done=false;
	
	while(!q.empty() && !done){
		int currentVertex=q.front();
		q.pop();
		for(int i=0;i<n;i++){
			if(edges[currentVertex][i]==1 && !visited[i]){
				q.push(i);
				parent[i]=currentVertex;
				visited[i]=true;
				
				if(i==lv){
					done=true;
					break;
				}
			}
		}
		
		
	} 
	
	if(!done){
		return NULL;
	}else{
		vector<int>* output=new vector<int>();
		int current=lv;
		output->push_back(lv);
		while(current!= sv){
			current=parent[current];
			output->push_back(current);
			
		}
		return output;
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
	int sv,lv;
	cin>>sv>>lv;
	
	vector<int>* output=getPathBfs(edges,n,sv,lv);
	
	if(output!=NULL){
		for(int i=0;i<output->size();i++){
			cout<<output->at(i)<<" ";
		}
		delete output;
	}
	
	
	//delete 2d array
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}
