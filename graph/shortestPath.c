/*
 * Dijkstra �㷨
 * ÿһ������һ���µ�Ŀ�Ķ�������·��
 * ˼�룺��һ�����·����û�е���Ķ����У�ѡ��һ�����Բ������·����Ŀ�Ķ��㡣
 * author:whc
 * date:2015.7.30
 */
 #include <list>
 using namespace std;
 
 #define MAX_E 10
 #define MAX_V 5
 #define INF   -1
 
 typedef struct Edge{
	 int from;
	 int to;
	 int weight;
 }Edge;
  
Edge e[MAX_E]; 
int G[MAX_V+1][MAX_V+1];

bool shortestPaths(int srcVertex,int *distanceFromSrc,int *path){
	if(srcVertex<1 || srcVertex>MAX_V)
		return false;
	list<int> reachVertex;
	for(int i=0; i<MAX_V; i++){
		distanceFromSrc[i] = G[srcVertex][i];
		if(distanceFromSrc[i] == INF)
			path[i] = -1;
		else{
			path[i] = srcVertex;
			reachVertex.push_back(i);
		}
	}
	distanceFromSrc[srcVertex] = 0;
	path[srcVertex] = 0;
	
	//update distanceFromSrc and path.
	while(!reachVertex.empty()){
		//find the min in the distanceFromSrc
		list<int>::iterator it;
		int min = reachVertex.front();
		for(it=reachVertex.begin()+1; it!=reachVertex.end();it++){
			if(distanceFromSrc[*it] < distanceFromSrc[min])
				min = *it;
		}
		
		//the next path is to the vertices of min.
		reachVertex.remove(min);
		for(int i=1; i<MAX_V; i++){
			if(G[min][i]!=INF &&(path[i]==-1 || distanceFromSrc[i]>distanceFromSrc[min]+G[min][i])){
				distanceFromSrc[i] = distanceFromSrc[min] + G[min][i];
				if(path[i] == -1)
					reachVertex.push_back(i);
				path[i] = min;
			}
		}
	}
}
 