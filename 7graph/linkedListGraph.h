#pragma once
// #include "/Users/luigiliu/Desktop/programming/Algorithm/1array/linkedList/LinkedList.h"

// #include "../1array/linkedList/linkedList.h"
#include "../1array/StackAndQueue/StackAndQueue.h"
#include <iostream>

using namespace std;


class LinkedListGraph {
	private:
		List<int>* _al; // adjaceny list
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
		LinkedListGraph(int n) {
			_al = new List<int> [n];
			_nv = n;
			_visited = new bool[n];
			_resetVisited();
		};
		~LinkedListGraph() {
			delete[] _al;
			delete[] _visited;
		}

		void addEdge(int s, int d){
			_al[s].insertHead(d);
		};
		void printGraph() {
			for (int i=0; i < _nv; i++) {
				cout << "Node " << i << ":";
				for (_al[i].start(); !_al[i].end(); _al[i].next())
					cout << " " << _al[i].current();
				cout << endl;

			}
		};

		void DFS(int s, List<int>& output, bool resetVisited) {
			if (resetVisited){this->_resetVisited();}
			this->_setVisited(s);
			output.insertTail(s);
			for (this->_al[s].start(); !this->_al[s].end(); this->_al[s].next()){
				if (!this->_isVisited(_al[s].current())){
					this->_setVisited(_al[s].current());
					DFS(_al[s].current(), output, false);
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
				for (this->_al[current].start(); !this->_al[current].end(); this->_al[current].next()){
					if (!this->_isVisited(_al[current].current())){
						q.enqueue(_al[current].current());
						this->_setVisited(_al[current].current());
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