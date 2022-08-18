#include <iostream>
#include "map.h"
#include <fstream>

using namespace std;

Map::Map(int num_stores) {
    
    //make all distances 0
    
    for(int i = 0; i < num_stores + 1; i++) {
        for(int j = 0; j < num_stores; j++) {
            arr[i][j] = 0;
            
        }
    }
}

void Map::prompt(int num_stores) {
    string s;
    cout << "Enter a file that has your map info or type 'manual' to manually enter the map now: ";
    cin >> s;
    if(s == "manual") {
        fill_map_cmdLine(); //enter map through cmd line

    } else { //enter map through txt file
        bool cmd_line_file_success = handleMapFile(s);
        while (!cmd_line_file_success) {
            cout << "Enter a file that has your map info or type 'manual' to manually enter the map now: ";
            cin >> s;
            cmd_line_file_success = handleMapFile(s);
        }
        cout << "Map is filled!" << endl;
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Now you are the customer." << endl;
    cout << "You have decided to take your date to the fanciest shopping mall there is. " << endl;
    cout << "But you need to look like you know what you're doing, better not get lost..." << endl;
    cout << "Time to use NaviShop!" << endl;
    start_experience(num_stores);
    
}

void Map::start_experience(int num_stores) {
    int start;
        
    cout << "Which store are you near now? ";
    cin >> start;
    dijkstra(start, num_stores);
    
}

bool Map::handleMapFile(string filename) {
    // check if file was properly opened using is_open
    // if file doesn’t exist or you don’t have permission to open file

    ifstream instream;
    instream.open(filename);
    if (not instream.is_open()) { //check if able to open file
        cerr << "Error: Unable to read: " << filename << endl;
        return false;
    } else {
        while(not instream.eof()) {
            fill_map_from_file(instream);
        }
    }
    instream.close();

    return true;
}

void Map::fill_map_cmdLine() {
    bool quit = false;
    string cont;
    int start;
    int end;
    int length;

    //command line input
    while(!quit) {
       cout << "Add store? ";
       cin >> cont;

       if(cont == "yes") {
            cout << "Start: ";
            cin >> start;
            cout << "End: ";
            cin >> end;
            cout << "Length: ";
            cin >> length;
            arr[start][end] = length;
            arr[end][start] = length;
            cout << endl;
       } else {

           quit = true;
       }
    }
}

void Map::fill_map_from_file(std::istream &in) {
    string s;
    int length = 0;
    in >> s;
    
    int start = int(s[0]) - 48;
    int end = int(s[2]) - 48;
    if(s.length() > 3) {
        length = string_to_int(s.substr(4));
    }

    arr[start][end] = length;
    arr[end][start] = length;
}

int Map::string_to_int(string s) {
        
    //declare and initialize variable that will integer values from strings
    //will be added to
    int new_num = 0;
    
        
    //loop through each character in string
    for (size_t i = 0; i < s.length(); ++i) {    
        //test if the character is an integer and if so, add it to new_num
        if (s[i] >= 48 and s[i] < 58) {
            new_num = new_num * 10 + (int(s[i]) - 48);
        }
        
    }
    return new_num;    
}

void Map::print_map(int num_stores) {
    for(int i = 0; i < num_stores + 1; i++) {
        for(int j = 0; j < num_stores; j++) {
            if(arr[i][j] != 0) {
                cout << "Distance from store " << i << " and store " << j << " is " << arr[i][j] << endl;
            }
        }
    }
}

void Map::find_path(int start, int end, int num_stores, int path) {

    //find 1st nonzero value
    int col = find_1st_nonzero_col(start, num_stores);
    //if value's col != end
    if(col != end) {
        cout << col  << ", ";
        path = path + arr[start][col];
        find_path(col, end, num_stores, path);
    } else if(col == end) {
        path = path + arr[start][col];
        cout << col << " is the path " << endl;
        return;
    } else { //repeat with next nonzero value
        find_path(find_1st_nonzero_col(start + 1, num_stores), end, num_stores, path);
    }
}
/*
void Map::find_path_reverse(int start, int end, int num_stores, int path) {
    //find 1st nonzero value
    int col = find_1st_nonzero_col_reverse(start);
    //if value's col != end
    if(col != end) {
        cout << col  << ", ";
        path = path + arr[start][col];
        find_path_reverse(col, end, num_stores, path);
    } else if(col == end) {
        path = path + arr[start][col];
        cout << col << " is the path with a length of " << path << endl;
        return;
    } else { //repeat with next nonzero value
        find_path_reverse(find_1st_nonzero_col_reverse(start - 1), end, num_stores, path);
    }
}*/

int Map::find_1st_nonzero_col(int row, int num_stores) {
    //cout << "Calling find_1st_nonzero_col in row " << row << "for " << num_stores << " stores." << endl;
    for(int i = row + 1; i < num_stores; i++) {
        //cout << "checking " << i << endl;
        if(arr[row][i] != 0) {
                return i;
            }
    }
    return 0;
}

int Map::find_1st_nonzero_col_reverse(int row) {
    //cout << "Calling find_1st_nonzero_col in row " << row << "for " << num_stores << " stores." << endl;
    for(int i = row - 1; i > 0; i--) {
        //cout << "checking " << i << endl;
        if(arr[row][i] != 0) {
                return i;
            }
    }
    return 0;
}

/*
void Map::printSolution(int dist[], int num_stores)
{
    printf("Vertex   Distance from Source\n");
    int min = INT_MAX;
    for (int i = 0; i < num_stores; i++) {
        //printf("%d \t\t %d\n", i, dist[i]);
    }
    int end;
    cout << "End: ";
    cin >> end;
    cout << "The distance of the fastest path to " << end << " is " << dist[end] << endl;
	
}*/

// Function to print shortest path from source to j using
// parent array
void Map::printPath(int parent[], int j)
{
    // Base Case : If j is source
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    cout << j << " ";
}
 
// A utility function to print the constructed distance
// array
void Map::printSolution(int dist[], int num_stores, int parent[], int src)
{
    string ans;
    cout << "Do you want to see the map from your perspective to see your options(map), or do you have a specific path in mind(path)? ";
    cin >> ans;

    int end;
    if(ans == "path") {
        cout << "What is your destination? ";
        cin >> end;
       
        cout << src << " ";
        printPath(parent, end);
        cout << " is the path you must take with a distance of " << dist[end] << endl;

    } else if(ans == "map") {
        cout << "Full Map in Reference to You: " << endl;
        cout << "Vertex\t Distance\tPath";
        for (int i = 1; i <= num_stores; i++) {
            printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i],
               src);
            printPath(parent, i);
        }
    } else {
        cout<< "That wasn't one of the options" << endl;
    }

    cout << endl;
    cout << "Would you like to continue exploring or leave the complex (continue/leave)? ";
    cin >> ans;
    if(ans == "continue") {
        start_experience(num_stores);
    } else {
        cout << "Okay! Thanks for visiting! Hope your date went well ;) " << endl;
    }
    
    cout << endl;
}

int Map::minDistance(int dist[], bool sptSet[], int num_stores)
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 1; v <= num_stores; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void Map::dijkstra(int src, int num_stores)
{
    
    //int V = num_stores;
    int dist[num_stores]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[num_stores]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Parent array to store shortest path tree
    int parent[num_stores];


    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 1; i <= num_stores; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;  
        parent[i] = -1; 
    }
        
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    // Find shortest path for all vertices
    for (int count = 0; count < num_stores; count++) {
        
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet, num_stores);
        
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 1; v <= num_stores; v++) {
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && arr[u][v] && dist[u] != INT_MAX && dist[u] + arr[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + arr[u][v];
            }
                
        }   
    }
 
    // print the constructed distance array
    printSolution(dist, num_stores, parent, src);
}



