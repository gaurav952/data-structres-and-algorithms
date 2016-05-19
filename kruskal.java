/*
Name: Gaurav Sinha	

Problem Statement :    Write a program to find Minimal spanning tree of a graph using Kruskal’s algorithm. 
*/
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class KruskalsAlgorithm
{
    private List<Edge> edges;//Collection Of Edges
    private int numberOfVertices;
    public static final int MAX_VALUE=999;
    private int visited[];
    private int spanningTree[][];
    
    //constructor
    public KruskalsAlgorithm(int numberOfVertices)
    {
        this.numberOfVertices=numberOfVertices;
        edges=new LinkedList<Edge>();
        visited=new int[numberOfVertices+1];
        spanningTree=new int[numberOfVertices+1][numberOfVertices+1];
    }
    public void kruskalAlgorithm(int adjacencyMatrix[][])
    {
        boolean finished=false;
        for(int source=1;source<=numberOfVertices;source++)
        {
            for(int destination=1;destination<=numberOfVertices;destination++)
            {
                if(adjacencyMatrix[source][destination]!=MAX_VALUE && source!=destination)
                {
                    Edge edge=new Edge();
                    edge.sourceVertex=source;
                    edge.destinationVertex=destination;
                    edge.weight=adjacencyMatrix[source][destination];
                    adjacencyMatrix[destination][source]=MAX_VALUE;
                    edges.add(edge);
                }
            }
        }
        Collections.sort(edges,new EdgeComparator());//Sort the Edges on the basis of weight
        CheckCycle checkCycle=new CheckCycle();//Object Creation
        for(Edge edge:edges)
        {
            spanningTree[edge.sourceVertex][edge.destinationVertex]=edge.weight;
            spanningTree[edge.destinationVertex][edge.sourceVertex]=edge.weight;
            if(checkCycle.checkCycle(spanningTree,edge.sourceVertex))
            {
                spanningTree[edge.sourceVertex][edge.destinationVertex]=0;
                spanningTree[edge.destinationVertex][edge.sourceVertex]=0;
                edge.weight=-1;
                continue;
            }
            visited[edge.sourceVertex]=1;
            visited[edge.destinationVertex]=1;
            for(int i=0;i<visited.length;i++)
            {
                if(visited[i]==0)
                {
                    finished=false;
                    break;
                }
                else
                    finished=true;
            }
            if(finished)
                break;
        }
        System.out.println("The Spanning Tree is: ");
        for(int i=1;i<=numberOfVertices;i++)
            System.out.print("\t"+i);
        System.out.println();
        for(int source=1;source<=numberOfVertices;source++)
        {
            System.out.print(source+"\t");
            for(int destination=1;destination<=numberOfVertices;destination++)
            {
                System.out.print(spanningTree[source][destination]+"\t");
            }
            System.out.println();
        }
    }
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        System.out.println("Enter the number Of Vertices: ");
        int numberOfVertices=d.nextInt();
        System.out.println("Enter the Weighted Matrix For the Graph");
        int adjacencyMatrix[][]=new int[numberOfVertices+1][numberOfVertices+1];
        for(int i=1;i<=numberOfVertices;i++)
        {
            for(int j=1;j<=numberOfVertices;j++)
            {
                adjacencyMatrix[i][j]=d.nextInt();
                if(i==j)
                {
                    adjacencyMatrix[i][j]=0;
                    continue;
                }
                if(adjacencyMatrix[i][j]==0)
                    adjacencyMatrix[i][j]=MAX_VALUE;
            }
        }
        KruskalsAlgorithm kruskalAlgorithm=new KruskalsAlgorithm(numberOfVertices);//Object Creation
        kruskalAlgorithm.kruskalAlgorithm(adjacencyMatrix);//Calling
        d.close();
    }
}
//Definition Of Edge
class Edge
{
    int sourceVertex;
    int destinationVertex;
    int weight;
}
class EdgeComparator implements Comparator<Edge>
{
    @Override
    public int compare(Edge edge1,Edge edge2)
    {
        if(edge1.weight<edge2.weight)
            return -1;
        if(edge1.weight>edge2.weight)
            return 1;
        return 0;
    }
}
class CheckCycle
{
    private Stack<Integer> stack;//To implement to Check for the presence of Cycle
    private int adjacencyMatrix[][];
    public CheckCycle()
    {
        stack=new Stack<Integer>();
    }
    public boolean checkCycle(int adjacency_matrix[][],int source)
    {
        boolean cyclePresent=false;
        int number_of_nodes=adjacency_matrix[source].length-1;
        adjacencyMatrix=new int[number_of_nodes+1][number_of_nodes+1];
        for(int sourceVertex=1;sourceVertex<=number_of_nodes;sourceVertex++)
        {
            for(int destination=1;destination<=number_of_nodes;destination++)
                adjacencyMatrix[sourceVertex][destination]=adjacency_matrix[sourceVertex][destination];
        }
        int visited[]=new int[number_of_nodes+1];
        int element=source;
        int i=source;
        visited[source]=1;
        stack.push(source);
        while(!stack.isEmpty())
        {
            element=stack.peek();
            i=element;
            while(i<=number_of_nodes)
            {
                if(adjacencyMatrix[element][i]>=1 && visited[i]==1)
                {
                    if(stack.contains(i))
                    {
                        cyclePresent=true;
                        return cyclePresent;
                    }
                }
                if(adjacencyMatrix[element][i]>=1 && visited[i]==0)
                {
                    stack.push(i);
                    visited[i]=1;
                    adjacencyMatrix[element][i]=0;
                    adjacencyMatrix[i][element]=0;
                    element=i;
                    i=1;
                    continue;
                }
                i++;
            }
            stack.pop();
        }
        return cyclePresent;
    }
    
}
