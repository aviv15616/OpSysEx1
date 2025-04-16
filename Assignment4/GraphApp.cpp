#include "GraphBuilder.hpp"
#include "Dijkstra.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <climits>
using namespace std;

int main() {
    int x = 0;

    while (true) {
        string input;
        cout << "Do you want to check a new graph? (y/n): ";
        getline(cin, input);

        if (input.length() != 1) {
            x++;
            cerr << "Invalid input. Please enter a single character: 'y' or 'n'." << endl;
            if (x == 3) {
                cerr << "You have entered invalid input 3 times. Exiting the program." << endl;
                break;
            }
            continue;
        }

        char choice = input[0];

        if (choice == 'n' || choice == 'N') {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        } else if (choice == 'y' || choice == 'Y') {
            x = 0;
            int V;

            while (true) {
				if (x == 3) {
					cerr << "You have entered invalid input 3 times. Exiting the program." << endl;
					break;
				}
                cout << "Enter number of vertices (positive integer): ";
                string line;
                getline(cin, line);
                stringstream ss(line);
				
				
                if (!(ss >> V) || (ss.peek() != EOF) || V <= 0) {
					x++;
                    cerr << "Invalid input. Please enter a single positive integer with no extra characters." << endl;
					
                } else {
                    break;
                }
            }
			if (x == 3) {
				break;
			}
			x=0;

            auto adj = GraphBuilder::constructAdj(V , x);

            int src;
            while (true) {
				if (x == 3) {
					break;
				}
			
				cout << "Enter source vertex (0 to " << V - 1 << "): ";
				cin >> src;
			
				if (cin.fail() || src < 0 || src >= V) {
					x++;
					cerr << "Invalid input. Please enter a number between 0 and " << V - 1 << "." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				} else {
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					x = 0;  // קלט תקין → איפוס
					break;
				}
			}
			if (x != 3) {
				
			

            vector<int> distances = Dijkstra::run(V, adj, src);

            cout << "Shortest distances from vertex " << src << ":\n";
            for (int i = 0; i < V; ++i) {
                if (distances[i] == INT_MAX)
                    cout << "To " << i << ": INF\n";
                else
                   cout << "To " << i << ": " << distances[i] << "\n";
            }x=0;
		 }
        } else {
            x++;
            cerr << "Invalid input. Please enter 'y' or 'n'." << endl;
            if (x == 3) {
                cerr << "You have entered invalid input 3 times. Exiting the program." << endl;
                break;
            }
        }
    }

    return 0;
}
