
//this function finds the shortest path from the source vertex
void dijkstra(struct Graph* g, int src)
{
    int V = g->V;
    int distance[V];
    int parent[V];
    struct MinHeap* minHeap = createMinHeap(V);
    for (int v = 0; v < V; ++v)
    {
        parent[0]=-1;
        distance[v] = INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, distance[v]);
        minHeap->pos[v] = v;
    }
    // extracting  first  element making source vertex as 0 distance and alll other intially infinite
    minHeap->array[src] = newMinHeapNode(src, distance[src]); 
    minHeap->pos[src]   = src;
    distance[src] = 0;
    decreaseKey(minHeap, src, distance[src]); 
    minHeap->size = V;
    // In the following loop, min heap contains all nodes
    // whose shortest distance is not yet finalized.
    while (!isEmpty(minHeap))
    {
        // Extract the vertex with minimum distance value
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;
        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their distance values
        struct AdjListNode* p = g->array[u].head;
        while (p != NULL)
        {
            int v = p->destination;

            // If shortest distance to v is not finalized yet, and distance to v
            // through u is less than its previously calculated distance
            if (isInMinHeap(minHeap, v) && distance[u] != INT_MAX &&
                                          p->weight + distance[u] < distance[v])
            {
                parent[v]=u;
                distance[v] = distance[u] + p->weight;
                // update distance value in min heap also
                decreaseKey(minHeap, v, distance[v]);
            }
            p = p->next;
        }
    }
   printSolution(distance, V,parent);
}