#pragma once
// #include "/Users/luigiliu/Desktop/programming/Algorithm/1array/linkedList/LinkedList.h"

// #include "../1array/linkedList/linkedList.h"
#include "../1array/StackAndQueue/StackAndQueue.h"
#include <iostream>

using namespace std;


class AdjacencyListGraph {
	private:
		int** _al; // adjaceny list
		int _nv; // number of nodes
		bool *_visited;
		int _nVisited;

		void _resetVisited() {
			for (int i = 0; i < _nv; i++) _visited[i] = false;
			_nVisited = 0;
		};
		void _setVisited(int node) {
			if (_visited[node] == false)
				_nVisited++;
			_visited[node] = true;
		};
		bool _isVisited(int node) {
			return _visited[node];
		};


	public: 
		AdjacencyListGraph(int n) {
			_al = new int*[n];
			for(int i = 0; i < n; ++i){
    			_al[i] = new int[n];
			}
			_nv = n;
			_visited = new bool[n];
			_resetVisited();
		};
		~AdjacencyListGraph() {
			delete[] _al;
			delete[] _visited;
		}

		void addEdge(int s, int d){
			_al[s][d] = 1;
		};
		void printGraph() {
			for (int i=0; i < _nv; i++) {
				cout << "Node " << i << ":";
				for (int j = 0; j < _nv; j++){
					if (_al[i][j] == 1) cout << " " << j;
				}
				cout << endl;

			}
		};

		void DFS(int s, List<int>& output, bool resetVisited) {
			if (resetVisited){this->_resetVisited();}
			this->_setVisited(s);
			output.insertTail(s);
			for (int i=0; i< _nv; i++){
				if (_al[s][i] == 1){
					if (!this->_isVisited(i)){
						this->_setVisited(i);
						DFS(i, output, false);
					}
				}
			}
		};

		void BFS(int s, List<int>& output, bool resetVisited) {
			
			Queue<int> q;
			int current;
			if (resetVisited){this->_resetVisited();}
			
			q.enqueue(s);
			this->_setVisited(s);
			
			while (!q.empty()){
				current = q.dequeue();
				output.insertTail(current);
				for (int i=0; i< _nv; i++){
					if (_al[current][i] == 1){
						if (!this->_isVisited(i)){
							this->_setVisited(i);
							q.enqueue(i);
						}
					}
				}
			}
		};

		int nComponents() {
			int i, res=0;
			List<int> output;
			for (i=0; i<this->_nv; i++){
				if (this->_isVisited(i)){continue;}
				this->BFS(i, output, false);
				res++;
				if (this->_nVisited == this->_nv){
					return res;
				}
			}
			return res;
		};		
};

// do strong connected graph