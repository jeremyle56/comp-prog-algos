// coordinates -> (compressed coordinates).
map<int, int> coordMap;

void compress(vector<int>& values) {
    for (int v : values) coordMap[v] = 0;
    int cId = 0;
    for (auto it = coordMap.begin(); it != coordMap.end(); ++it) it->second = cId++;
    for (int& v : values) v = coordMap[v];
}