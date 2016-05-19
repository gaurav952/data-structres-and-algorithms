/*
Name: Gaurav Sinha

Problem Statement:    Write a program to find shortest path between all the source destination pairs (All pairs shortest path Floyd’s algorithm). 
*/
import java.util.Scanner;
public class AllPairsShortestPathProblem
{
    private int distanceMatrix[][];
    private int numberOfVertices;
    public static final int INF=999;
    
    //constructor
    public AllPairsShortestPathProblem(int numberOfVertices)
    {
        this.numberOfVertices=numberOfVertices;
        distanceMatrix=new int[numberOfVertices+1][numberOfVertices+1];
    }
    public void AllPairsShortestPath(int adjacency_matrix[][])
    {
        for(int i=1;i<=numberOfVertices;i++)
        {
            for(int j=1;j<=numberOfVertices;j++)
            {
                distanceMatrix[i][j]=adjacency_matrix[i][j];
            }
        }
        for(int intermediate=1;intermediate<=numberOfVertices;intermediate++)
        {
            for(int source=1;source<=numberOfVertices;source++)
            {
                for(int destination=1;destination<=numberOfVertices;destination++)
                {
                    if(distanceMatrix[source][intermediate]+distanceMatrix[intermediate][destination]<distanceMatrix[source][destination])
                        distanceMatrix[source][destination]=distanceMatrix[source][intermediate]+distanceMatrix[intermediate][destination];
                }
            }
        }
        for(int source=1;source<=numberOfVertices;source++)
        {
            for(int destination=1;destination<=numberOfVertices;destination++)
            {
                System.out.print(distanceMatrix[source][destination]+"\t");
            }
            System.out.println();
        }
    }
    
        public static void main(String args[])
        {
            Scanner d=new Scanner(System.in);
            System.out.println("Enter the number Of Vertices in the graph");
            int NumberOfVertices=d.nextInt();
            System.out.println("Enter the Weighted Matrix For the Graph");
            int adjacency_matrix[][]=new int[NumberOfVertices+1][NumberOfVertices+1];
            
            for(int source=1;source<=NumberOfVertices;source++)
            {
                for(int destination=1;destination<=NumberOfVertices;destination++)
                {
                    adjacency_matrix[source][destination]=d.nextInt();
                    if(source==destination)
                    {
                        adjacency_matrix[source][destination]=0;
                        continue;
                    }
                    if(adjacency_matrix[source][destination]==0)
                    {
                        adjacency_matrix[source][destination]=INF;
                    }
                }
            }
            System.out.println("The transitive Closure Of the Graph is: ");
            AllPairsShortestPathProblem Floyds=new AllPairsShortestPathProblem(NumberOfVertices);//Object Creation
            Floyds.AllPairsShortestPath(adjacency_matrix);//Calling Of Method
            d.close();
        }
}
