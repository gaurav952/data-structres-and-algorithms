/*
Name: Gaurav Sinha

Problem Statement :    Write a program to find Minimal spanning tree of a graph using Prim’s algorithm. 
*/
import java.util.Scanner;
public class PrimsAlgorithm
{
    private boolean settled[];
    private boolean unsettled[];
    private int numberOfVertices;
    private int adjacencyMatrix[][];
    private int key[];//To hold the key for each of the vertices
    private int parent[];//To hold the parent of each of the vertices
    public static final int INF=999;
    
    public PrimsAlgorithm(int numberOfVertices)
    {
        this.numberOfVertices=numberOfVertices;
        unsettled=new boolean[numberOfVertices+1];
        settled=new boolean[numberOfVertices+1];
        adjacencyMatrix=new int[numberOfVertices+1][numberOfVertices+1];
        key=new int[numberOfVertices+1];
        parent=new int[numberOfVertices+1];
    }
    //Returns how many unsettled Nodes Left
    public int getUnsettledCount(boolean unsettled[])
    {
        int count=0;
        for(int i=0;i<unsettled.length;i++)
        {
            if(unsettled[i])
                count++;
        }
        return count;
    }
    public void primsAlgorithm(int adjacencyMatrix[][])
    {
        int evaluationVertex;
        //Copying of an Array into Another(GLOBAL) Array
        for(int source=1;source<=numberOfVertices;source++)
        {
            for(int destination=1;destination<=numberOfVertices;destination++)
            {
                this.adjacencyMatrix[source][destination]=adjacencyMatrix[source][destination];
            }
        }
        for(int i=1;i<=numberOfVertices;i++)
        {
            key[i]=INF;
        }
        key[1]=0;
        unsettled[1]=true;
        parent[1]=1;
        
        while(getUnsettledCount(unsettled)!=0)
        {
            evaluationVertex=getMinimumKeyVertexFromUnsettled(unsettled);
            unsettled[evaluationVertex]=false;
            settled[evaluationVertex]=true;
            evaluateNeighbours(evaluationVertex);
        }
    }
    private int getMinimumKeyVertexFromUnsettled(boolean unsettled2[])
    {
        int min=Integer.MAX_VALUE;
        int node=0;
        for(int vertex=1;vertex<=numberOfVertices;vertex++)
        {
            if(unsettled[vertex]==true && key[vertex]<min)
            {
                node=vertex;
                min=key[vertex];
            }
        }
        return node;
    }
    public void evaluateNeighbours(int evaluationVertex)
    {
        for(int destinationVertex=1;destinationVertex<=numberOfVertices;destinationVertex++)
        {
            if(settled[destinationVertex]==false)
            {
                if(adjacencyMatrix[evaluationVertex][destinationVertex]!=INF)
                {
                    if(adjacencyMatrix[evaluationVertex][destinationVertex]<key[destinationVertex])
                    {
                        key[destinationVertex]=adjacencyMatrix[evaluationVertex][destinationVertex];
                        parent[destinationVertex]=evaluationVertex;
                    }
                    unsettled[destinationVertex]=true;
                }
            }
        }
    }
    public void printMST()
    {
        System.out.println("SOURCE : DESTINATION = WEIGHT");
        for(int vertex=2;vertex<=numberOfVertices;vertex++)
        {
            System.out.println(parent[vertex]+"\t:\t"+vertex+"\t=\t"+adjacencyMatrix[parent[vertex]][vertex]);
        }
    }
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        System.out.println("Enter the number of Vertices");
        int number_of_vertices=d.nextInt();
        System.out.println("Enter thr weighted Matrix For the Graph");
        int adjacency_matrix[][]=new int[number_of_vertices+1][number_of_vertices+1];
        for(int i=1;i<=number_of_vertices;i++)
        {
            for(int j=1;j<=number_of_vertices;j++)
            {
                adjacency_matrix[i][j]=d.nextInt();
                if(i==j)
                {
                    adjacency_matrix[i][j]=0;
                    continue;
                }
                if(adjacency_matrix[i][j]==0)
                    adjacency_matrix[i][j]=INF;
            }
        }
        PrimsAlgorithm prims=new PrimsAlgorithm(number_of_vertices);//Object Creation
        prims.primsAlgorithm(adjacency_matrix);//Calling
        prims.printMST();//Calling
        d.close();
    }//End Of Main
}//End of Class
