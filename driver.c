  
// Driver program to test above functions 
int main() 
{  
    int V,v,src,des,wt;
printf("Enter the no. of Vertices\n");
scanf("%d",&V);
struct Graph* graph = createGraph(V); 
while(1)
{
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	printf("Enter the destination vertex\n");
	scanf("%d",&des);
	printf("Enter the weight attached to the edge\n");
	scanf("%d",&wt);
	 addEdge(graph, src, des,wt);
	//Enter -1 to terminate
	if(src==-1 || des==-1)
	break;	
}
printf("Enter the starting vertex\n");
scanf("%d",&v);
dijkstra(graph, v); 
  
    return 0;

} 