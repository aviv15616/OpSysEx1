#include "GraphBuilder.hpp"
#include <iostream>
#include <sstream>

	
vector<vector<vector<int>>> GraphBuilder::constructAdj(int V , int& x) {
    vector<vector<vector<int>>> adj(V);

    while (true) {
        cout << "Enter an edge (format: u v weight) or -1 -1 -1 to stop: ";
        string line;
        getline(cin, line);

        istringstream iss(line);
        int u, v, weight;

        if (!(iss >> u >> v >> weight) || !iss.eof()) {
            
            cerr << "Invalid input! Please enter exactly three integers separated by spaces." << endl;
			x++;
            if (x == 3) {
                cerr << "Too many invalid attempts. Returning to main menu." << endl;
                break;
            }
            continue;
        }

       

        if (u == -1 && v == -1 && weight == -1) {
            break;
        }

        if (u < 0 || u >= V || v < 0 || v >= V) {
            
            cerr << "Error: Vertex index out of range! Must be between 0 and " << V - 1 << "." << endl;
			x++;
            if (x == 3) {
                cerr << "Too many invalid attempts. Returning to main menu." << endl;
                break;
            }
            continue;
        }

        if (u == v) {
            
            cerr << "Error: Self-loops are not allowed (u != v)." << endl;
            
            continue;
        }

        if (weight < 0) {
            
            cerr << "Error: Dijkstra does not support negative weights." << endl;
            
            continue;
        }

        bool edgeExists = false;
        for (auto& neighbor : adj[u]) {
            if (neighbor[0] == v) {
                edgeExists = true;
                cout << "Edge between " << u << " and " << v << " already exists with weight " << neighbor[1] << "." << endl;
                cout << "Do you want to update it to weight " << weight << "? (y/n): ";

                string response;
                getline(cin, response);

                if (response == "y" || response == "Y") {
                    neighbor[1] = weight;
                    for (auto& reverseNeighbor : adj[v]) {
                        if (reverseNeighbor[0] == u) {
                            reverseNeighbor[1] = weight;
                            break;
                        }
                    }
                    cout << "Edge updated." << endl;
                } else {
                    cout << "Edge not updated." << endl;
                }

                break;
            }
        }

        if (!edgeExists) {
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
			x=0;
        }
    }

    return adj;}
