// Graph representation by Adjacency matrix using arrays..

#include<stdio.h>

#define max 20
int adj[max][max];
int n;

int main()
{
    int max_edge,orig,dest,i,j;
    char graph_type;

    printf("Enter the no. of nodes/vertices of Graph: ");
    scanf("%d",&n);

    //fflush(stdin);
    printf("Enter whether the graph is directed/undirected (d/u) :");
    while(getchar()!='\n');  // for flushing the input buffer
    scanf("%c",&graph_type);
    //graph_type=getchar();
    //printf("Enter whether the graph is directed/undirected (d/u) :");

    if(graph_type=='u')
        max_edge=n*(n-1)/2;
    else
        max_edge=n*(n-1);


    for(i=1;i<=max_edge;i++)
    {
        printf("\nEnter the edge %d ( 0 0 to quit) : ",i);
        scanf("%d %d",&orig,&dest);

        if(orig==0 && dest==0)
        break;

        if(orig>n || dest>n || orig<=0 ||dest<=0)
        {
            printf("Invalid edge..");
            i--;
        }
        else
        {
            adj[orig][dest]=1;
            if(graph_type=='u')
                adj[dest][orig]=1;

        }

    }

    printf("Adjacency matrix is : \n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        printf("%4d",adj[i][j]);
        printf("\n");
    }
return 0;
}
