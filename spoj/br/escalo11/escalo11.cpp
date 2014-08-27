#include <cstdio>
#include <cstdlib>
#include <queue>

#ifndef WHITE
#define WHITE 0
#endif

#ifndef GRAY
#define GRAY  1
#endif

#ifndef BLACK
#define BLACK 2
#endif

using namespace std;

typedef struct {
    int u; /* edge source */
    int v; /* edge destination */
    int w; /* edge weight */
} Edge;

typedef struct graph * Graph;

typedef struct node * myLink;

struct node {
    int v; /* vertex destination */
    int w; /* edge weight */
    myLink next;
};

struct graph {
    int V; /* |V| */
    int E; /* |E| */
    myLink * adj; /* adjacency lists */
};

Edge EDGE (int u, int v, int w) {
    Edge e;
    e.u = u;
    e.v = v;
    e.w = w;
    return e;
}

myLink NEW (int v, int w, myLink next) {
    myLink x = (myLink) malloc (sizeof * x);
    x->v = v;
    x->w = w;
    x->next = next;
    return x;
}

Graph GRAPHinit (int V) {
    Graph G = (Graph) malloc (sizeof * G);
    G->V = V;
    G->E = 0;
    G->adj = (myLink *) malloc (V * sizeof (myLink));
    for (int v = 0; v < V; v++) {
        G->adj[v] = NULL;
    }
    return G;
}

void GRAPHdestroy (Graph G) {
    for (int v = 0; v < G->V; v++) {
        myLink next;
        for (myLink cur = G->adj[v]; cur != NULL; cur = next) {
            next = cur->next;
            free(cur);
        }
        G->adj[v] = NULL;
    }
    free(G->adj);
    G->adj = NULL;
    G->V = 0;
    G->E = 0;
    free(G);
}

void DIGRAPHinsertE (Graph G, Edge e) {
    G->adj[e.u] = NEW (e.v, e.w, G->adj[e.u]);
    G->E++;
}

int GRAPHisAcyclicRec(Graph G, int u, int color[]) {
    color[u] = GRAY;
    for (myLink l = G->adj[u]; l != NULL; l = l->next) {
        if (color[l->v] == GRAY) {
            return 0;
        } else if (color[l->v] == WHITE) {
            if (GRAPHisAcyclicRec(G, l->v, color) == 0) {
                return 0;
            }
        }
    }
    color[u] = BLACK;
    return 1;
}

int GRAPHisAcyclic(Graph G) {
    int * color;
    color = (int *) malloc(G->V * sizeof(int));
    for (int u = 0; u < G->V; u++) {
        color[u] = WHITE;
    }
    for (int u = 0; u < G->V; u++) {
        if (color[u] == WHITE) {
            if (GRAPHisAcyclicRec(G, u, color) == 0) {
                free(color);
                return 0;
            }
        }
    }
    free(color);
    return 1;
}

int main () {
    int n, m;
    scanf(" %d", &n);
    scanf(" %d", &m);
    Graph G;
    G = GRAPHinit(n);
    int * in = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf(" %d", &u);
        scanf(" %d", &v);
        DIGRAPHinsertE(G, EDGE(u, v, 1));
        in[v]++;
    }
    if (GRAPHisAcyclic(G) == 1) {
        priority_queue<int> heap;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                heap.push(-i);
            }
        }
        while (!heap.empty()) {
            int u = -heap.top();
            heap.pop();
            printf("%d\n", u);
            for(myLink l = G->adj[u]; l != NULL; l = l->next) {
                int v = l->v;
                in[v]--;
                if (in[v] == 0) {
                    heap.push(-v);
                }
            }
        }
    } else {
        printf("*\n");
    }
    free(in);
    GRAPHdestroy(G);
    return 0;
}
