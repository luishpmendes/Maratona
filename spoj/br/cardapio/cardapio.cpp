#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <cstdlib>
#include <climits>
#include <cstring>

#ifndef INFINITE
#define INFINITE INT_MAX
#endif

#ifndef NIL
#define NIL INT_MIN
#endif

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
    int v;
    Graph G = (Graph) malloc (sizeof * G);
    G->V = V;
    G->E = 0;
    G->adj = (myLink *) malloc (V * sizeof (myLink));

    for(v = 0; v < V; v++) {
        G->adj[v] = NULL;
    }

    return G;
}

void GRAPHdestroy (Graph G) {
    int v;
    for(v = 0; v < G->V; v++) {
        myLink cur, next;
        for(cur = G->adj[v]; cur != NULL; cur = next) {
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

Graph DIGRAPHtranspose(Graph G) {
    Graph H;
    int u;

    H = GRAPHinit(G->V);

    for(u = 0; u < G->V; u++) {
        myLink l;
        for(l = G->adj[u]; l != NULL; l = l->next) {
            DIGRAPHinsertE(H, EDGE(l->v, u, l->w));
        }
    }

    return H;
}

void DAGTopologicalSortDfsVisit(Graph G, int u, int color[], myLink * tsl) {
    myLink l;

    color[u] = GRAY;

    for(l = G->adj[u]; l != NULL; l = l->next) {
        if(color[l->v] == WHITE) {
            DAGTopologicalSortDfsVisit(G, l->v, color, tsl);
        }
    }

    color[u] = BLACK;

    (*tsl) = NEW(u, 0, (*tsl));
}

void DAGtopologicalSortDfs(Graph G, myLink * tsl) {
    int u;
    int * color;

    color = (int *) malloc(G->V * sizeof(int));

    for(u = 0; u < G->V; u++) {
        color[u] = WHITE;
    }

    for(u = 0; u < G->V; u++) {
        if(color[u] == WHITE) {
            DAGTopologicalSortDfsVisit(G, u, color, tsl);
        }
    }

    free(color);
}

void DAGtopologicalSort(Graph G, int ts[]) {
    myLink l = NULL, next = NULL;
    int i = 0;

    DAGtopologicalSortDfs(G, &l);

    while(l != NULL) {
        ts[i] = l->v;
        next = l->next;
        free(l);
        l = next;
        i++;
    }
}

void DIGRAPHstronglyConnectedComponentsDfsVisit(Graph G, int scc[], int ncc, int u, int color[]) {
    myLink l;

    color[u] = GRAY;

    for(l = G->adj[u]; l != NULL; l = l->next) {
        if(color[l->v] == WHITE) {
            DIGRAPHstronglyConnectedComponentsDfsVisit(G, scc, ncc, l->v, color);
        }
    }

    color[u] = BLACK;

    if(scc != NULL) {
        scc[u] = ncc;
    }
}

void DIGRAPHconnectedComponentsDfs(Graph G, int scc[], int f[], int * ncc) {
    int u, i;
    int * color;

    color = (int *) malloc(G->V * sizeof(int));

    for(u = 0; u < G->V; u++) {
        color[u] = WHITE;
        if(scc != NULL) {
            scc[u] = -1;
        }
    }

    (*ncc) = 0;

    for(i = 0; i < G->V; i++) {
        u = f[i];
        if(color[u] == WHITE) {
            DIGRAPHstronglyConnectedComponentsDfsVisit(G, scc, (*ncc)++, u, color);
        }
    }

    free(color);
}

int DIGRAPHstronglyConnectedComponents(Graph G, int scc[]) {
    int ncc = 0;
    int * f = (int *) malloc(G->V * sizeof(int));
    Graph H;

    DAGtopologicalSort(G, f);
    H = DIGRAPHtranspose(G);
    DIGRAPHconnectedComponentsDfs(H, scc, f, &ncc);

    GRAPHdestroy(H);
    free(f);

    return ncc;
}

int main () {
    int n, c = 0;

    while (cin >> n) {
        c++;
        int qtd = 0;
        map <string, int> M;
        vector <pair <pair<int, int>, pair<int, int> > > V;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1;
            cin >> s2;

            int b1, b2;

            if (s1[0] == '!') {
                b1 = 0;
                s1.erase(0, 1);
            } else {
                b1 = 1;
            }

            if (s2[0] == '!') {
                b2 = 0;
                s2.erase(0, 1);
            } else {
                b2 = 1;
            }

            if (M.find(s1) == M.end()) {
                M[s1] = qtd++;
            }
            if (M.find(s2) == M.end()) {
                M[s2] = qtd++;
            }

            V.push_back(make_pair(make_pair(M[s1], b1), make_pair(M[s2], b2) ) );
        }

        Graph G;

        G = GRAPHinit(2 * qtd);

        for (unsigned int i = 0; i < V.size(); i++) {
            // (A, B)
            int idA = V[i].first.first;
            int bA = V[i].first.second;
            int idB = V[i].second.first;
            int bB = V[i].second.second;

            // !A -> B
            //adj[(1-bA)*qtd+idA][bB*qtd+idB] = 1;
            DIGRAPHinsertE(G, EDGE((1-bA)*qtd+idA, bB*qtd+idB, 1));
            // !B -> A
            //adj[(1-bB)*qtd+idB][bA*qtd+idA] = 1;
            DIGRAPHinsertE(G, EDGE((1-bB)*qtd+idB, bA*qtd+idA, 1));
        }

        int * scc;

        scc = (int *) calloc (2 * (qtd + 10) + 10, sizeof (int));

        DIGRAPHstronglyConnectedComponents(G, scc);

        int flag = 0;

        for (int i = 0; i < qtd; i++) {
            if (scc[i] == scc[qtd + i]) {
                flag = 1;
                break;
            }
        }

        cout << "Instancia " << c << '\n';
        if (flag) {
            cout << "nao\n";
        } else {
            cout << "sim\n";
        }
        cout << '\n';

        free(scc);

        GRAPHdestroy(G);
    }

    return 0;
}