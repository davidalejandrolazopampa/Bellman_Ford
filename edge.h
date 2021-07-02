#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

using namespace std;

template<typename G>
class Edge {
private:
    typedef typename G::EE E;
    typedef typename G::vertex vertex;
public:
    E data;
    vertex* vertexes[2];

    Edge()=default;

    explicit Edge(E data) : data(data){}

    Edge(vertex* from, vertex* to){
        this->vertexes[0]=from;
        this->vertexes[1]=to;
    }

    Edge(vertex* from, vertex* to,E data) : data(data){
        this->vertexes[0]=from;
        this->vertexes[1]=to;
    }

    ~Edge()= default;
    template<typename, typename>
    friend class Graph;
};

#endif
