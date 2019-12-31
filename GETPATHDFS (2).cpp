#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int>* getPath(int** edges,int n,int sv,int lv){
	bool* visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	
	if(sv==lv){
		vector<int>* output1;
		output1->push_back(lv);
		return output1;
	}
	
	visited[sv]=true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i]==1 && !visited[i]){
			       vector<int>* outputsmall = getPath(edges,n,i,lv);
			       if(outputsmall!=NULL){
			       	outputsmall->push_back(sv);
			       	return outputsmall;
				   }
		}
	}
	
	
	return NULL;
}

int main(){
	int n,e;
	cin>>n>>e;
	int** edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int [n];
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
	
  vector<int>* output=getPath(edges,n,sv,lv);

	
	if(output!=NULL){
		for(int i=0;i<output->size();i++){
		cout<<output->at(i)<<" ";
	    }	
	}
	

	
	
	
	
	//deleting 2d array
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
	
}


