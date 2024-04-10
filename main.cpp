#include <iostream>

#include "cppBasis.cpp"
# include "1array/StackAndQueue/StackAndQueue.h"
#include "2sorting/bubbleSort.cpp"
#include "2sorting/insertionSort.cpp"
#include "2sorting/selectionSort.cpp"
#include "2sorting/mergeSort.cpp"
#include "2sorting/quickSort.cpp"
#include "2sorting/utilities.cpp"
#include "0algorithm/binarySearch.cpp"
#include "0algorithm/localPeak.cpp"
#include "6unionFind/quickUnion.hpp"
#include "6unionFind/weightedUnion.hpp"
#include "6unionFind/pathCompressionWeightedUnion.hpp"
#include "7graph/linkedListGraph.h"
#include "7graph/AdjacencyListGraph.h"
using namespace std;

int main(){
    LinkedListGraph* g = new LinkedListGraph(10);
    AdjacencyListGraph* a = new AdjacencyListGraph(10);
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 3);
    g->addEdge(2, 4);
    g->addEdge(3, 4);

    g->addEdge(5, 6);
    g->printGraph();

    a->addEdge(0, 1);
    a->addEdge(0, 2);
    a->addEdge(1, 3);
    a->addEdge(2, 4);
    a->addEdge(3, 4);

    a->addEdge(5, 6);
    a->printGraph();

    // List<int> output;
    // a->DFS(0, output, true);
    // for (output.start(); !output.end(); output.next()){
    //     cout << output.current();
    // }

    cout << "???";
    cout << g->nComponents();


    return 0;
}