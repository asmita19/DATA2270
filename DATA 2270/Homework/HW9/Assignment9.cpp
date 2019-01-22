#include <vector>
#include "Graph.hpp"
#include <fstream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

Graph::Graph(){};

Graph::~Graph(){};

void Graph::addEdge(std::string v1, std::string v2, int distance){
    vertex * tempv1 = findVertex(v1);
    vertex * tempv2 = findVertex(v2);
    Edge edg1;
    edg1.distance = distance;
    edg1.v = tempv2;
    tempv1 -> Edges.push_back(edg1);
}


void Graph::addVertex(std::string name){
    vertex temp;
    temp.name = name;
    temp.district = -1;
    temp.visited = false;
    vertices.push_back(temp);
}

void Graph::displayEdges(){
	for(int i = 0; i < int(vertices.size()); i++)={
        cout<< vertices[i].district <<":" <<vertices[i].name<<"-->";
        for(int j = 0; j < int(vertices[i].adj.size()); j++){
            cout<<vertices[i].adj[j].v->name;
            cout<< " (" << vertices[i].adj[j].distance << " miles)";
            if (j != int(vertices[i].adj.size()-1)){
                cout<<"***";
            }
        }
        cout << endl;
    }
}

void Graph::setAllVerticesUnvisited(){
  for(int i=0;i<vertices.size();i++){
    vertices[i].visited=false;
  }
}

vertex *Graph::findVertex(std::string name){
  for(int i=0;i<vertices.size();i++){
    if (vertices[i].name==name){
      return &vertices[i];
    }
  }
}

void Graph::assignDistricts(){
  int newDistrict=0;
  setAllVerticesUnvisited();
  for(int i=0;i<vertices.size(); i++){
    if(vertices[i].district==0){
      newDistrict++;
      BFTraversalLabel(vertices[i].name, newDistrict);
    }
  }
}

void Graph::BFTraversalLabel(std::string startingCity, int distID){
  queue<string> q;
  vertex *start= findVertex(startingCity);
  start->visited=true;
  start->district=distID;
  q.push (start->name);
  while(!q.empty()){
    string s=q.front();
    q.pop();
    vertex *tex=findVertex(s);
    for (int x=0; x<tex->Edges.size();x++){
      if(!tex->Edges[x].v->visited){
        tex->Edges[x].v->visited=true;
        tex->Edges[x].v->district=distID;
        q.push(tex->Edges[x].v->name);
      }
    }
  }
}


void Graph::printDFS(){
    setAllVerticesUnvisited();
    for (int i=0; i<vertices.size();i++){
        if (vertices[i].visited==false)
            DFTraversal(&vertices[i]);
    }
}
void Graph::DFTraversal(vertex *v){
    v->visited=true;
    cout<<v->name<<endl;
    for (int x = 0; x < v->Edges.size(); x++){
        if(v->Edges[x].v->visited==false){
          DFTraversal(v->Edges[x].v);
        }
    }
}


int main(int argc, char *argv[]){
  Graph g;
  ifstream myfile(argv[1]);
  string line, city, distance;
  vector <string> cities;
  getline(myfile,line);
  stringstream ss(line);
  getline(ss,city,',');
  
  while(getline(ss,city,',')){
    g.addVertex(city);
    cities.push_back(city);
  }
  
  while(getline(myfile,line)){
    stringstream ss(line);
    getline(ss,city,',');
    int i=0;
    
    while(getline(ss,distance,',')){
      if(stoi(distance)>0){
        g.addEdge(city,cities[i],stoi(distance));
        cout<<" ... Reading in "<<city<<" -- "
        <<cities[i]<<" -- "<<distance<<endl;
      }
      i++;
    }
  }
  g.assignDistricts();
  g.displayEdges();
}
