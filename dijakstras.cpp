///complexity O(ElogV)
////run online
//finding shortest path



#include<bits/stdc++.h>
using namespace std;
template<typename T>
class graph{
	unordered_map<T,list<pair<T,int >>> m;
public:
		void addEdge(T u,T v,int dist,bool bidir=true){
			m[u].push_back(make_pair(v,dist));
			if(bidir){
				m[v].push_back(make_pair(u,dist));
			}
		}
		
		void printAdj(){
			for(auto i:m){
				cout<<i.first<<" -> "<<" ";
				for(auto j:i.second){
					cout<<"("<<j.first<<","<<j.second<<")"<<" ";
				}
				cout<<endl;
			}
		} 
		
		void dijakstra(T src){
			map<T,int> dist;
			for(auto i:m){
				dist[i.first]=INT_MAX;
			}
		
			
			set<pair<int,T>> s;
				dist[src]=0;
			
			s.insert(make_pair(0,src));
			//while this set is not empty'
			while(!s.empty()){
				//s.begin is pointer so, * means values
				auto p=*(s.begin());
				int nodedist=p.first;
				T node=p.second;
				
				s.erase(s.begin());
				
				for(auto childpair:m[node]){
					
					if(nodedist+childpair.second<dist[childpair.first]){
						//fisrt find if it is present in set if it is update it
						//in set we cannot update so we have to delete first and then insert
						//here we are using set because it already sorted in nauture with according first element
						auto f=s.find(make_pair(dist[childpair.first],childpair.first));
						if(f!=s.end()){
							s.erase(f);
						}
						
						dist[childpair.first]=nodedist+childpair.second;
						s.insert(make_pair(dist[childpair.first],childpair.first));
						
					}
				}
				
				
				
			
			}
			
			
				for(auto d:dist){
				    cout<<d.first<<" "<<d.second<<endl;
				}
			
		}
	
};
int main(){
// 	graph<string> india;
// 	india.addEdges("Amritsar","Delhi",1);
// 	india.addEdges("Amritsar","Jaipur",4);
// 	india.addEdges("Jaipur","Delhi",2);
// 	india.addEdges("Jaipur","Mumbai",8);
// 	india.addEdges("Bhopal","Agra",2);
// 	india.addEdges("Mumbai","Bhopal",3);
// 	india.addEdges("Agra","Delhi",1);
// 	india.printAdj();
 
// 	india.dijakstra("Amritsar");
 
 
 
//  graph<int> g;
//  g.addEdges(1,2,1);
//  g.addEdges(1,3,4);
//  g.addEdges(2,3,1);
//  g.addEdges(3,4,2);
//  g.addEdges(1,4,7);
//  g.dijakstra(1);
graph<int> g;
//int n,e;
//cin>>n>>e;
//
//for(int i=0;i<e;i++){
//    int u,v,dist;
//    cin>>u>>v>>dist;
//    if(dist==0)continue;
//    g.addEdges(u,v,dist);
//}
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
g.dijakstra(0);



	
	
}

