#include<iostream>
#define infinite 9999
using namespace std;
class graph{

public:
    int numberOfNodes;
    int graphAdjMatrix[20][20]; //not good way for declaration
    void acceptGraph();
    void displayGraph();
    int calculateDistance();
};

void graph ::acceptGraph(){

    cout<<"Enter the number of nodes";
    cin>>numberOfNodes;

    int sNode,eNode;
     for(sNode=1;sNode<=numberOfNodes;sNode++){
        for(eNode=1;eNode<=numberOfNodes;eNode++){
           graphAdjMatrix[sNode][eNode]=infinite;
        }
    }

    //accepting input edge wise
    for(sNode=1;sNode<=numberOfNodes;sNode++){
        for(eNode=sNode+1;eNode<=numberOfNodes;eNode++){
            cout<<"Do we have edge for" <<sNode<<" to"<< eNode<<" vertices? if yes enter weight, if no enter"<<infinite;
            cin>>graphAdjMatrix[sNode][eNode];
        }
    }
}

void graph ::displayGraph(){
    int sNode,eNode;
    //displaying input edge wise
    cout<<"Content of graph in matrix format";
    for(sNode=1;sNode<=numberOfNodes;sNode++){
        cout<<"\n";
        for(eNode=1;eNode<=numberOfNodes;eNode++){

            cout<<graphAdjMatrix[sNode][eNode]<<" ";
        }

    }
}

int graph::calculateDistance(){
    int vertex,visited[20], minDist[20];
    for(vertex=1;vertex<=numberOfNodes;vertex++){
        visited[vertex]=0;
        minDist[vertex]=infinite;
    }
    int source, dest;
    cout<<"Enter source and destination vertex";
    cin>>source;
    cin>>dest;
    visited[source]=1;
    minDist[source]=0;
    int startDist,tempSource;
   int tempDist,cost,minCost=0;
   while(source!=dest){

    cost=infinite;
    startDist=minDist[source];
    for(int eNode=1;eNode<=numberOfNodes;eNode++){
        tempDist = startDist+graphAdjMatrix[source][eNode];
        if(tempDist<minDist[eNode]){
            minDist[eNode]=tempDist;
            if(minDist[eNode]<cost)
            {
                cost=minDist[eNode];
                tempSource=eNode;
            }

        }
    }
    source=tempSource;
    visited[source]=1;
    minDist[source]=0;
    minCost=minCost+cost;

   }

    return minCost;
}

int main(){
    int minCost;
    graph graphObj;
    graphObj.acceptGraph();
    graphObj.displayGraph();
    minCost=graphObj.calculateDistance();
    cout<<"Min. dist"<<minCost;
    return 0;
}
