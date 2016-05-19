/*
Name: Gaurav Sinha

Problem Statement:    Write a program to find shortest path from a given source to all the approachable nodes (Single source shortest path Dijkstra’s algorithm). 
*/
import java.util.HashSet;
import java.util.Set;//Sets are used to implement Djkstras Algorithm
import java.util.Scanner;
import java.util.Iterator;

public class ShortestPathProblem
{
    private int distances[];
    private Set<Integer> settled;
    private Set<Integer> unsettled;
    private int numberOfNodes;
    private int adjacencyMatrix[][];

    //constructor
    public ShortestPathProblem(int numberOfNodes)
    {
        this.numberOfNodes=numberOfNodes;
        distances=new int[numberOfNodes+1];
        adjacencyMatrix=new int[numberOfNodes+1][numberOfNodes+1];
        settled=new HashSet<Integer>();
        unsettled=new HashSet<Integer>();
    }
    public void DijkstrasAlgorithm(int adjacency_matrix[][],int source)
    {
        int evaluationNode;
        int adjacencyMatrix[][]=new int[numberOfNodes+1][numberOfNodes+1];
        //Make a copy of the adjacency Matrix
        for(int i=1;i<=numberOfNodes;i++)
        {
            for(int j=1;j<=numberOfNodes;j++)
                adjacencyMatrix[i][j]=adjacency_matrix[i][j];
        }
        //Set the distances of nodes to INFINITY equivalent of Largest value possible as Integer
        for(int i=1;i<=numberOfNodes;i++)
            distances[i]=Integer.MAX_VALUE;
        unsettled.add(source);//add initially source to unsettled set of data
        distances[source]=0;//Set the distance of source Node to be 0
        while(!unsettled.isEmpty())
        {
            evaluationNode=getNodeWithMinimumDistanceFromUnsettled();
            unsettled.remove(evaluationNode);
            settled.add(evaluationNode);
            evaluateNeighbours(evaluationNode);
        }
    }
    //Return the node with Minimum Distance From Unsettled Node
    private int getNodeWithMinimumDistanceFromUnsettled()
    {
        int min;
        int node=0;
        
        Iterator<Integer> iterator=unsettled.iterator();
        node=iterator.next();
        min=distances[node];
        for(int i=1;i<=distances.length;i++)
        {
            if(unsettled.contains(i))
            {
                if(distances[i]<=min)
                {
                    min=distances[i];
                    node=i;
                }
            }
        }
        return node;
    }
    //Set the shortest Route Between the source and destination Node
    private void evaluateNeighbours(int evaluationNode)
    {
        int edgeDistance=-1;
        int newDistance=-1;
        
        for(int destinationNode=1;destinationNode<=numberOfNodes;destinationNode++)
        {
            if(!settled.contains(destinationNode))
            {
                if(adjacencyMatrix[evaluationNode][destinationNode]!=Integer.MAX_VALUE)
                {
                    edgeDistance=adjacencyMatrix[evaluationNode][destinationNode];
                    newDistance=distances[evaluationNode]+edgeDistance;
                    if(newDistance<distances[destinationNode])
                        distances[destinationNode]=newDistance;
                    unsettled.add(destinationNode);
                }
            }
        }
    }
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        System.out.println("Enter the number of vertices in the Graph");
        int numberOfNodes=d.nextInt();
        int adjacency_matrix[][]=new int[numberOfNodes+1][numberOfNodes+1];
        System.out.println("Enter the weighted Matrix For the Graph");
        for(int i=1;i<=numberOfNodes;i++)
        {
            for(int j=1;j<=numberOfNodes;j++)
            {
                adjacency_matrix[i][j]=d.nextInt();
                if(i==j)
                {
                    adjacency_matrix[i][j]=0;
                    continue;
                }
                if(adjacency_matrix[i][j]==0)
                {
                    adjacency_matrix[i][j]=Integer.MAX_VALUE;
                }
            }
        }
        System.out.println("Enter the source");
        int source=d.nextInt();
        System.out.println("Enter the destination");
        int destination=d.nextInt();
        ShortestPathProblem djk=new ShortestPathProblem(numberOfNodes);//Object Creation
        djk.DijkstrasAlgorithm(adjacency_matrix,source);//Calling Of Method
        System.out.println("The Shortest Path From "+source+" to "+destination+" is: ");
        System.out.println(djk.distances[destination]);
        d.close();
    }//End of Main
}//End of Class
