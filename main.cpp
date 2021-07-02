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
    graph->insertVertex("F");
    graph->insertVertex("G");

    graph->createEdgebydata("A", "B", 2 );
    graph->createEdgebydata("A", "C", 1 );
    graph->createEdgebydata("A", "E", 0.5);

    graph->createEdgebydata("B", "A", 2 );
    graph->createEdgebydata("B", "C", 0.5 );
    graph->createEdgebydata("B", "D", 2);
    graph->createEdgebydata("B", "E", 3);

    graph->createEdgebydata("C", "A", 1 );
    graph->createEdgebydata("C", "B", 0.5 );
    graph->createEdgebydata("C", "G", 1);

    graph->createEdgebydata("D", "B", 2);
    graph->createEdgebydata("D", "F", 2);
    graph->createEdgebydata("D", "G", 3);

    graph->createEdgebydata("E", "A", 0.5);
    graph->createEdgebydata("E", "B", 3);
    graph->createEdgebydata("E", "F", 2);

    graph->createEdgebydata("F", "E", 2);
    graph->createEdgebydata("F", "D", 2);
    graph->createEdgebydata("F", "G", 1);

    graph->createEdgebydata("G", "C", 1);
    graph->createEdgebydata("G", "D", 3);
    graph->createEdgebydata("G", "F", 1);

    graph->createEdgebydata("D", "B", 19);
    graph->createEdgebydata("D", "A", 42);

    graph->createEdgebydata("A", "B", 5);

    cout << "BellmanFord"<<endl<<endl;
    auto bellman = graph->BellmanFord("D", "A");
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
