int* dijkstra(Grafo *p, int u){ //O(|V|+|E| lg(|V|))
int *pai = (int*) malloc(p->n * sizeof(int));
PQ *Fila = pq_criar(p->n);//Heap de MIN
int v;
for(v = 0; v < p->n; v++){//O(|V|lg|V|)
pai[v] = -1;
pq_adicionar(Fila, v, INT_MAX); //O(lg|V|)
}
pai[u] = u;
muda_prioridade(Fila, u, 0);
while(!pq_vazia(Fila)){ //O(|E|lg|V|)
t_item aux = pq_extrai_minimo(Fila);
int v = aux.idx;
int dist_v = prioridade(Fila, v);//dist[v]
if(dist_v == INT_MAX) break;
No* t;
for(t = p->L[v]; t!=NULL; t = t->prox){
//atualiza as distancias para cada vizinho de v
int w = t->v; //valor na lista
int peso = t->peso; //c(v,w)
if(dist_v + peso < prioridade(Fila, w)){//dist[w]
muda_prioridade(Fila, w, dist_v+peso);//O(lg|V|)
pai[w] = v;
}
}
}
pq_destruir(&Fila);
return pai;
}