#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, rank;
    vector<int> size;
    int components;
    int maxSize;

public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        components = n;
        maxSize = 1;
        
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if(px != py) {
            components--;
            if(rank[px] < rank[py]) {
                swap(px, py);
            }
            parent[py] = px;
            size[px] += size[py];
            maxSize = max(maxSize, size[px]);
            
            if(rank[px] == rank[py]) {
                rank[px]++;
            }
        }
    }
    
    int getComponents() { return components; }
    int getMaxSize() { return maxSize; }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }
    
    cout << dsu.getComponents() << " " << dsu.getMaxSize() << endl;
    
    return 0;
}
/*
code thuần C:
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *parent, *rank, *size;
    int components;
    int maxSize;
} DSU;

void dsu_init(DSU *dsu, int n) {
    dsu->parent = (int*)malloc((n + 1) * sizeof(int));
    dsu->rank = (int*)malloc((n + 1) * sizeof(int));
    dsu->size = (int*)malloc((n + 1) * sizeof(int));
    dsu->components = n;
    dsu->maxSize = 1;
    
    for(int i = 0; i <= n; i++) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
        dsu->size[i] = 1;
    }
}

int dsu_find(DSU *dsu, int x) {
    if(dsu->parent[x] == x) return x;
    return dsu->parent[x] = dsu_find(dsu, dsu->parent[x]);
}

void dsu_unite(DSU *dsu, int x, int y) {
    int px = dsu_find(dsu, x);
    int py = dsu_find(dsu, y);
    
    if(px != py) {
        dsu->components--;
        if(dsu->rank[px] < dsu->rank[py]) {
            int temp = px;
            px = py;
            py = temp;
        }
        dsu->parent[py] = px;
        dsu->size[px] += dsu->size[py];
        dsu->maxSize = dsu->maxSize > dsu->size[px] ? dsu->maxSize : dsu->size[px];
        
        if(dsu->rank[px] == dsu->rank[py]) {
            dsu->rank[px]++;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    DSU dsu;
    dsu_init(&dsu, n);
    
    for(int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        dsu_unite(&dsu, x, y);
    }
    
    printf("%d %d\n", dsu.components, dsu.maxSize);
    
    free(dsu.parent);
    free(dsu.rank);
    free(dsu.size);
    
    return 0;
}
*/