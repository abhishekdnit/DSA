// Graph Adjacency matrix representation by using structures,pointers & arrays

#include <stdio.h>
//#include <bits/stdc++.h>
#include<malloc.h>

struct Graph
{
    int V;
    int E;
    int **Adj; // This double pointer stores the address of 2D array.

};

struct Graph * AdjMatrix()
{

int u,v,i;
struct Graph *G;

G=(struct Graph *)malloc(sizeof(struct Graph));

printf("Enter the no. of nodes & edges : ");
scanf("%d %d",&G->V,&G->E);

while(getchar()!='\n');
//printf("Before for loop");

G->Adj=(int**) malloc(sizeof(int)*(G->V * G->V));    // for creating int blocks of total no. of nodes or elements of array

for(i=0;i<(G->V * G->V);i++)
G->Adj[i]=(int*)malloc(sizeof(int));

for(u=0;u<G->V;u++)                 // storing 0 in all the nodes.
{
    //printf("%d ",u);
    for(v=0;v<G->V;v++)
    {
        //printf("%d ",v);
       G->Adj[u][v]=0;
    }

}



for(i=0;i<G->E;i++)
{
    printf("Enter the nodes in pair which connects an edge : ");
    scanf("%d %d",&u,&v);
    G->Adj[u][v]=1;
    G->Adj[v][u]=1;

}

printf("Adjacency Matrix : \n");
for(u=0;u<G->V;u++)
{
    {
    for(v=0;v<G->V;v++)
    printf("%4d",G->Adj[u][v]);
    printf("\n");
    }
}

return G ;

}

int main()
{
    AdjMatrix();
}
