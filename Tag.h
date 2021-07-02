#ifndef GRAPHS_SOMOS_CACAHUATES_DIJKSTRA_H
#define GRAPHS_SOMOS_CACAHUATES_DIJKSTRA_H

template <typename G>
class Tag {
    typedef typename G::vertex vertex;

public:
    Tag()= default;;
    Tag(int distance,vertex* from, int iteration, int valueToFrom ) : distance(distance), from(from), iteration(iteration), valueToFrom(valueToFrom){};
    int distance = INFINITY;
    vertex* from = nullptr;
    int iteration = 0;
    int valueToFrom = 0;

    ~Tag()= default;;

};
#endif //GRAPHS_SOMOS_CACAHUATES_DIJKSTRA_H
