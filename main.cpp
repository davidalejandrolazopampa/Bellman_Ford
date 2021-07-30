#include <iostream>
#include "graph.h"
using namespace std;
void prueba_examen()
{
    auto graph = new Graph<string,double>(false);
    graph->insertVertex("A");
    graph->insertVertex("B");
    graph->insertVertex("C");
    graph->insertVertex("D");
    graph->insertVertex("E");


    graph->createEdgebydata("A", "B", 2 );
    graph->createEdgebydata("A", "C", 1 );
    graph->createEdgebydata("A", "D", 4);

    graph->createEdgebydata("B", "A", 2 );
    graph->createEdgebydata("B", "D", 3 );
    graph->createEdgebydata("B", "E", 4);

    graph->createEdgebydata("C", "A", 1 );
    graph->createEdgebydata("C", "D", 2 );

    graph->createEdgebydata("D", "A", 4);
    graph->createEdgebydata("D", "B", 3);
    graph->createEdgebydata("D", "C", 2);
    graph->createEdgebydata("D", "E", 2);

    graph->createEdgebydata("E", "B", 4);
    graph->createEdgebydata("E", "D", 2);


    cout << "BellmanFord"<<endl<<endl;
    auto bellman = graph->floyd_warshall();
}
void prueba_expo()
{
    auto graph = new Graph<string,int>(true);
    graph->insertVertex("A");
    graph->insertVertex("B");
    graph->insertVertex("C");
    graph->insertVertex("D");
    graph->insertVertex("E");
    graph->createEdgebydata("A", "B", -1 );
    graph->createEdgebydata("A", "C", 4 );

    graph->createEdgebydata("B", "C", 3 );
    graph->createEdgebydata("B", "D", 2 );
    graph->createEdgebydata("B", "E", 2 );

    graph->createEdgebydata("D", "B", 1 );
    graph->createEdgebydata("D", "C", 5 );

    graph->createEdgebydata("E", "D", -3 );

    cout << "BellmanFord"<<endl<<endl;
    auto bellman1 = graph->BellmanFord("A", "E");
}
int main(int argc, char *argv[]) {
    cout << "Iniciar Pruebas" << endl<<endl;

    prueba_examen();
    //prueba_expo();

    return EXIT_SUCCESS;
}
