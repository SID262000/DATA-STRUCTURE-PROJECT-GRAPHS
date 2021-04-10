
// adjacency list node
struct AdjListNode* newAdjListNode(int destination, int weight)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
// creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* g = (struct Graph*) malloc(sizeof(struct Graph));
    g->V = V;
    g->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        g->array[i].head = NULL;
    return g;
}

void addEdge(struct Graph* g, int src, int destination, int weight)
{
    //add edge to the directed graph only one side is required.
    struct AdjListNode* newNode = newAdjListNode(destination, weight);
    newNode->next = g->array[src].head;
    g->array[src].head = newNode;
}

// create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(int v, int distance)
{
    struct MinHeapNode* minHeapNode =
           (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->distance = distance;
    return minHeapNode;
}
// create a Min Heap 
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap =
         (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (int *)malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array=
         (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
//swapping required for the min heap
void swapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
//this function is hepify (min heap)
void minHeapify(struct MinHeap* minHeap, int index)
{
    int smallest, leftindex, rightindex;
    smallest = index;
    leftindex = 2 * index + 1;
    rightindex = 2 * index + 2;
    if (leftindex < minHeap->size &&
        minHeap->array[leftindex]->distance < minHeap->array[smallest]->distance )
      smallest = leftindex;
    if (rightindex < minHeap->size &&
        minHeap->array[rightindex]->distance < minHeap->array[smallest]->distance )
      smallest = rightindex;
    
    struct  MinHeapNode *smallestNode = minHeap->array[smallest];
    struct MinHeapNode *indexNode = minHeap->array[index];
    minHeap->pos[smallestNode->v] = index;
    minHeap->pos[idxNode->v] = smallest;
    swapNode(&minHeap->array[smallest], &minHeap->array[index]);
    minHeapify(minHeap, smallest);
}
// to check the minheap is empty or not
int isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}

// function to extract minimum node from heap
// so that when each vertex number the distance is min it takes and update it .
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
    struct MinHeapNode* root_1 = minHeap->array[0];
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    // Update position of last node
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root_1;
}

// function decrease the key because the each time when u extract the min heap it should be removed . 
void decreaseKey(struct MinHeap* minHeap, int v, int distance) 
{
    // Get the index of v in  heap array
    int i = minHeap->pos[v];
    minHeap->array[i]->distance = distance;
    // Travel up while the complete tree is not hepified.
    while (i && minHeap->array[i]->distance < minHeap->array[(i - 1) / 2]->distance) 
    {
        // Swap this node with its parent
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
        // move to parent index
        i = (i - 1) / 2;
    }
}
int isInMinHeap(struct MinHeap *minHeap, int v) 
{
   if (minHeap->pos[v] < minHeap->size)
     return 1;
   return 0;
   //this function to check it is min heap or not...
}

//  print the solution
int printSolution(int distance[], int n,
                      int parent[])
{
    int src = 0;
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < n; i++)
        {
        printf("\n%d -> %d \t\t %d\t\t%d ",
                      src, i, distance[i], src);
        printPath(parent, i);
    }
}

int index(int a,int parent[])
{
	int i;
	for(i=0;;i++)
		if(parent[i]==a)
			return i;
}
void printPath(int parent[], int j) 
{ 
int i;
for(;parent[j]!=-1;j=parent[j]);
for(i=index(j,parent);index(i,parent)!=-1;i=index(i,parent))
	printf("%d",i);
} 