#include <stdio.h>
int cost[10][10];

void route(int start_node, int lim)
{
    int i,j, nextNode, count = 1, prev[10], visited[10], distance[10];

    // set initial value
    for (i = 0; i < lim; i++)
    {
        if (i == start_node)
        {
            visited[i] = 1;
            distance[i] = 0;
            prev[i] = start_node;
        }
        else
        {
            visited[i] = 0;
            distance[i] = cost[start_node][i];
            prev[i] = start_node;
        }
    }
    // check for distance
    while (count < lim - 1)
    {
        int min_distance = 99;
        for (i = 0; i < lim; i++)
        {
            if (distance[i] < min_distance && !visited[i])
            {
                min_distance = distance[i];
                nextNode = i; // nextnode gives the node at minimum distance
            }
        }
        // check if a better path exists through nextnode
        visited[nextNode] = 1;
        for (i = 0; i < lim; i++)
            if (!visited[i])
                if (min_distance + cost[nextNode][i] < distance[i])
                {
                    distance[i] = min_distance + cost[nextNode][i];
                    prev[i] = nextNode;
                }
        count++;
        // print the path and distance of each node
        for (i = 0; i < lim; i++)
        {
            if (i != start_node)
            {
                printf("\n\nDistance of node %d => %d", i, distance[i]);
                printf("\nPath :: %d", i);
                j = i;
                do
                {
                    j = prev[j];
                    printf(" <-- %d", j);
                } while (j != start_node);
            }
        }
    }
}
    void main()
    {
        int i, j, lim, start_node;

        // get total num of nodes
        printf("Enter the total number of nodes : ");
        scanf("%d", &lim);

        // get cost matrix
        printf("Enter the cost matrix, set 99 for infinity");
        for (i = 0; i < lim; i++)
        {
            for (j = 0; j < lim; j++)
            {
                printf("\ndistance b/w %d - %d : ", i, j);
                scanf("%d", &cost[i][j]);
            }
        }
        printf("\nCost matrix is : \n");
        for (i = 0; i < lim; i++)
        {
            for (j = 0; j < lim; j++)
            {
                printf("%d      ", cost[i][j]);
            }
            printf("\n");
        }

        // get nodes
        printf("\nEnter the starting node : ");
        scanf("%d", &start_node);

        route(start_node, lim);
    }