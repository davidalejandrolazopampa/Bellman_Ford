#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <cmath>
#include "edge.h"
#include "Tag.h"
template<typename V, typename E>
class Graph; 

template <typename G>
class Vertex {
    typedef typename G::VV V;
    typedef typename G::EdgeSeq EdgeSeq;
    typedef typename G::edge edge;
    typedef typename G::vertex vertex;
    typedef typename G::tag tag;


    EdgeSeq edges;

    edge* findEdge(Vertex<G>* start, Vertex<G>* end){
        if(edges.empty()){
            return nullptr;
        }
        for (auto it=edges.begin(); it != edges.end(); ++it)
            if((*it)->vertexes[0] == start and (*it)->vertexes[1] == end ){
                return *it;
            }
        return nullptr;
    }

    void deleteEdgespecific(Vertex<G>* start, Vertex<G>* end){
        auto temp = findEdge(start,end);
        for (auto it=edges.begin(); it != edges.end(); ++it)
            if((*it) == temp ){
                this->edges.erase(it);
                delete temp;
                return;
            }
    }

    void deleteEdges(){
        if(!(edges.empty())){
            for (auto it=edges.begin(); it != edges.end(); ++it) {
                delete (*it);}
            edges.clear();
             return;
        }
    }

public:

    unordered_map<vertex*, tag*> dijkstra;
    unordered_map<vertex*, tag*> bellman;

    int id{};
    V data;
    double x,y;

    Vertex()= default;

    Vertex(int id,V data): id(id),data(data){}

    explicit Vertex(int id): id(id){}

    explicit Vertex(V data): data(data){}

    ~Vertex(){
        deleteEdges();
    }

    template<typename, typename>
    friend class Graph; 
};

#endif
