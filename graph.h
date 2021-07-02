#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include "vertex.h"
#include "edge.h"
#include "Tag.h"
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <limits>

using namespace std;

template<typename V, typename E>
class Graph {
public:
    typedef V VV;
    typedef E EE;
    typedef Graph<V, E> self;
    typedef Vertex<self> vertex;
    typedef Edge<self> edge;
    typedef vector<vertex* > VertexSeq;
    typedef list<edge* > EdgeSeq;
    typedef Tag<self> tag;


private:
    VertexSeq nodes;
    bool esDirigido = false;

    bool hasEdge(vertex* start, vertex* end){
        if((nodes.empty())){ return false;}
        for (int i = 0; i < nodes.size(); ++i) {
            vertex* temp = nodes[i];
            if(temp->findEdge(start, end)){
                return true;
            }
        }
        return false;
    }

    bool createEdge(vertex* tempStartVertex, vertex* tempEndVertex, E data){
        if(tempStartVertex and tempEndVertex){
            edge* tempStarttoEndEdge = new edge(tempStartVertex,tempEndVertex,data);
            tempStartVertex->edges.push_back(tempStarttoEndEdge);
            if(!esDirigido){
                edge* tempEndtoStartEdge = new edge(tempEndVertex,tempStartVertex,data);
                tempEndVertex->edges.push_back(tempEndtoStartEdge);
            }
            return true;
        } else{
            return false;
        }
    };

    self* crearMenorcamino(vertex* tempEnd,unordered_map<vertex*, tag*> etiqueta){
        vertex* temp = tempEnd;
        vertex* newVertexBefore;
        auto newGraph = new self(esDirigido);
        while (temp){
            newVertexBefore = temp;
            temp = etiqueta[temp]->from;
            if (temp and newVertexBefore){
                cout << newVertexBefore->data << " --> " << temp->data << endl;
                (*newGraph)(newVertexBefore->data, temp->data) = etiqueta[newVertexBefore]->valueToFrom;
            }
        }
        return newGraph;
    }

    void killnodes(){
        vertex* temp;
        for (int i = 0; i < nodes.size(); ++i) {
            temp = nodes[i];
            delete temp;
        }
        nodes.clear();
    }
public:

    Graph()= default;;
    explicit Graph(bool dirigido){this->esDirigido = dirigido;};

    ~Graph(){
        killnodes();
    };

    bool insertVertex(V data){
        if (!(findVertexdata(data))){
            auto *temp = new vertex(data);
            nodes.push_back(temp);
            return true;
        }else{
            return false;
        }
    };

    bool createEdgebydata(V start, V end, E data){
            vertex* tempStartVertex = findVertexdata(start);
            vertex* tempEndVertex = findVertexdata(end);
        if(hasEdge(tempEndVertex,tempStartVertex)){ return false;}
        return createEdge(tempStartVertex,tempEndVertex,data);
    };

    bool createEdge(V start, V end){
            vertex* tempStartVertex = findVertexdata(start);
            vertex* tempEndVertex = findVertexdata(end);

            if(tempStartVertex and tempEndVertex){
                edge* tempStarttoEndEdge = new edge(tempStartVertex,tempEndVertex);

                tempStartVertex->edges.push_back(tempStarttoEndEdge);
                if(!esDirigido){
                    edge* tempEndtoStartEdge = new edge(tempEndVertex,tempStartVertex);
                    tempEndVertex->edges.push_back(tempEndtoStartEdge);
                }
                return true;
            } else{
                return false;
            }
    };

    vertex* findVertexdata(V data){
        if((nodes.empty())){ return nullptr;}
        for (int i = 0; i < nodes.size(); ++i) {
            vertex* temp = nodes[i];
            if(temp->data == data){
                return temp;
            }
        }
        return nullptr;
    }

    vertex* findVertexId(int id){
        if((nodes.empty())){ return nullptr;}
        for (int i = 0; i < nodes.size(); ++i) {
            vertex* temp = nodes[i];
            if(temp->id == id){return temp;}
        }
        return nullptr;
    }

    E& operator()(V start, V end){

        vertex* tempStart = findVertexdata(start);
        vertex* tempEnd = findVertexdata(end);

        if(!tempStart){
            insertVertex(start);
        }
        if(!tempEnd){
            insertVertex(end);
        }

        tempStart = findVertexdata(start);
        tempEnd = findVertexdata(end);

        edge* tempEdge = tempStart->findEdge(tempStart,tempEnd);
        if(tempEdge){
            return (tempEdge->data);
        } else{
            createEdge(start,end);
            tempEdge = tempStart->findEdge(tempStart,tempEnd);
            return (tempEdge->data);
        }
    };

    bool empty() {
        return nodes.empty();
    };

    void clear() {
        for (auto i : nodes) {
            delete i;
        }
        nodes.clear();
    }

    void size() {
        cout << "#de Vertices: " << nodes.size() << endl;
        int num = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            num += (nodes[i])->edges.size();
        }
        if(esDirigido){
            cout << "#de Aristas: " << num << endl;
        }else{
            cout << "#de Aristas: " << num/2 << endl;

        }
    }

   self* BellmanFord(V from, V to){
        vertex *tempStart = findVertexdata(from);
        vertex *tempEnd = findVertexdata(to);
        if (!tempStart or !tempEnd)throw "No existe el vertice";
        if(tempStart->bellman.empty() or tempStart->bellman.size() != nodes.size()) {
            unordered_map<vertex *, tag *> etiqueta;
            vector<vertex *> NoVistos;
            for (int j = 0; j < nodes.size(); ++j) {
                etiqueta[nodes[j]] = new Tag<self>(1000, nullptr, 0, 0);
            }
            (etiqueta[tempStart])->distance = 0;
            for (int j = 0; j < nodes.size(); ++j) {
                for (int i = 0; i < nodes.size(); ++i) {
                    expandirBF(etiqueta, nodes[i]);
                }
            }
            tempStart->bellman = etiqueta;
        }
        return crearMenorcamino(tempEnd,tempStart->bellman);
    }

    void expandirBF(unordered_map<vertex*, tag*> &etiqueta, vertex* tempVertex){
        if(tempVertex and !(tempVertex->edges).empty()) {
            for (auto it = tempVertex->edges.begin() ; it != tempVertex->edges.end(); ++it) {
                auto tempEdge = *it;
                auto tempVto = tempEdge->vertexes[1];
                int distan;
                if(!etiqueta[tempVertex]){
                    distan = 0;
                }else{
                    distan = etiqueta[tempVertex]->distance;
                }
                tag* tempTag = new Tag<self>( distan + tempEdge->data, tempVertex,0, tempEdge->data);

                if(tempTag->distance < etiqueta[tempVto]->distance ){
                    etiqueta[tempVto] = tempTag;
                }else if (tempTag->distance == etiqueta[tempVto]->distance){
                    if(etiqueta[tempVertex]->iteration+1 < etiqueta[tempVto]->iteration){
                        etiqueta[tempVto] = tempTag;
                    }
                }
            }
        }
    }

};

typedef Graph<string, double> graph;

#endif