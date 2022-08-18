class Map {
    public:
        Map(int num_stores);
        void print_map(int num_stores);
        void fill_map_cmdLine();
        void fill_map_from_file(std::istream &in);
        void find_path(int start, int end, int num_stores, int path);
        void find_path_reverse(int start, int end, int num_stores, int path);
        int find_1st_nonzero_col(int row, int num_stores);
        int find_1st_nonzero_col_reverse(int row);
        bool handleMapFile(std::string filename);
        void cmdLine(int num_stores);
        int string_to_int(std::string s);
        void prompt(int num_stores);
        void start_experience(int num_stores);
        bool handleStoreFile(std::string filename);
        void fill_stores_from_file(std::istream &in, int count);

        void printSolution(int dist[], int num_stores, int parent[], int src);
        void printPath(int parent[], int j);
        void dijkstra(int src, int num_stores);
        int minDistance(int dist[], bool sptSet[],  int num_stores);
    private:
        int arr[100][100];//HARDCODED
        std::string stores[20];//hardcoded
        
};
