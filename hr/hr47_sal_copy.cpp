
#include <stdio.h>
#include <stdlib.h>
 
struct Node {
    int val;
    struct Node * next;
};
 
// Adds a new edge, u --> v, to adjacencyList[u]
struct Node * add(struct Node * head, int vertex)
{
    struct Node * traverse = (struct Node *) malloc(sizeof(struct Node));
     
    traverse->val = vertex;
    traverse->next = head;
     
    return traverse;
}
 
// The Breadth First Search Algorithm procedure. Takes empty parent and level
// arrays and fills them with corresponding values that we get while applying BFS
void breadthFirstSearch(struct Node * adjList[], int vertices, int parent[], int level[])
{
    struct Node * temp;
    int i, par, lev, flag = 1;
     
    lev = 0;
    level[1] = lev;
     
    while (flag) 
    {
        flag = 0;
        for (i = 1; i <= vertices; ++i) 
        {
            if (level[i] == lev) 
            {
                flag = 1;
                temp = adjList[i];
                par = i;
                 
                // Exploring all the adjacent vertices
                while (temp != NULL) {
                    if (parent[temp->val] != 0) {
                        // A level for this is already set
                        temp = temp->next;
                        continue;
                    }
                     
                    level[temp->val] = lev + 1;
                    parent[temp->val] = par;
                    printf("%d    %d      %d  %d\n",temp->val,par,lev,i);
                    temp = temp->next;
                }
            }
        }
         
        ++lev;
    }
}
 
// Replaces the value of an edge (u -->) v to (u --> v')
// Traverses the entire list of adjacencyList[u] => O(|E|) operation
// Here, "v" is stored as "oldVertex" and "v'" is stored as "newVertex"
void replace(struct Node * head, int oldVertex, int newVertex)
{
    struct Node * traverse = head;
     
    // Search for the occurence of 'oldVertex'
    while (traverse->next != NULL) {
        if (traverse->val == oldVertex) {
            break;
        }
         
        traverse = traverse->next;
    }
     
    // replace it with the new value
    traverse->val = newVertex;
}
 
// Prints the Adjacency List from vertex 1 to |V|
void printAdjacencyList(struct Node * adjList[], int vertices)
{
    int i;
     
    // Printing Adjacency List
    printf("\nAdjacency List -\n");
    for (i = 1; i <= vertices; ++i) {
        printf("%d -> ", i);
         
        struct Node * temp = adjList[i];
 
        while (temp != NULL) {
            printf("%d -> ", temp->val);
            temp = temp->next;
        }
         
        printf("NULL\n");
    }
}
 
// A recursive procedure to print the shortest path. Recursively
// looks at the parent of a vertex till the 'startVertex' is reached
void printShortestPath(int parent[], int currentVertex, int startVertex)
{
    if (currentVertex == startVertex) {
        printf("%d ", currentVertex);
    } else if (parent[currentVertex] == 0) {
        printShortestPath(parent, startVertex, startVertex);
        printf("%d ", currentVertex);
    } else {
        printShortestPath(parent, parent[currentVertex], startVertex);
        printf("%d ", currentVertex);
    }
}
 
int main()
{
    int vertices, edges, i, j, v1, v2;
     
    vertices = 100;     // For a 10X10 board
     
    // We will make the Adjacency List's size
    // (|V| + 1) so that we can use it 1-indexed
    struct Node * adjList[vertices + 1];
     
    int parent[vertices + 1];   // Just like 'adjList' -> Size = |V| + 1
    int level[vertices + 1];    // Just like 'adjList' -> Size = |V| + 1
     
    for (i = 0; i <= vertices; ++i) {
        // Initialising our arrays
        adjList[i] = NULL;
        parent[i] = 0;
        level[i] = -1;
    }
     
    // Initially we will add edges (a move) from
    // one location to another location as if
    // there were no snakes or ladders at all
    for (i = 1; i <= vertices; ++i) {
         
        // From vertex 'i', add a path to
        // the next 6 locations possible
        for (j = 1; j <= 6 && j + i <= vertices; ++j) {
            adjList[i] = add(adjList[i], i + j);
            ++edges;
        }
    }
 
    int ladderCount, snakeCount;
     
    printf("Enter the Number of Ladders -  ");
    scanf("%d", &ladderCount);
     
    printf("Enter the Ladder Edges -\n");
    // Dealing with Ladder Edges (v1 ---> v2)
    for (i = 0; i < ladderCount; ++i) {
        scanf("%d%d", &v1, &v2);
         
        // If the ladder can affect any position, it is
        // the previously 6 possible moves of v1
        j = v1 - 6;
         
        if (j < 1) {
            j = 1;
        }
         
        // So we make a correction in those vertices
        for (; j < v1; ++j) {
            // Replacing Vertex v1 by v2
            replace(adjList[j], v1, v2);
        }
    }
     
    printf("Enter the Number of Snakes - ");
    scanf("%d", &snakeCount);
 
    printf("Enter the Snake Edges -\n");
    // Dealing with Snakes Edges
    for (i = 0; i < snakeCount; ++i) {
        scanf("%d%d", &v1, &v2);
         
        // If the snake can affect any position, it is
        // the previously 6 possible moves of v1
        j = v1 - 6;
         
        if (j < 1) {
            j = 1;
        }
         
        // So we make a correction in those vertices
        for (; j < v1; ++j) {
            // Replacing Vertex v1 by v2
            replace(adjList[j], v1, v2);
        }
    }
     
    breadthFirstSearch(adjList, vertices, parent, level);
    printf("\nNumber of Moves required = %d\n", level[vertices]);
     
    if (level[vertices] != -1) {
        // Printing the shortest path from vertex 1
        // to the last vertex 100 (vertices)
        printShortestPath(parent, vertices, 1);
    }
     
    return 0;
}