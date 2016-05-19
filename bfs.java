/*
Name: Gaurav Sinha

Problem Statement:    Write a program to find approachable nodes from a given source of a given graph using queue as an intermediate data structure (BFS). 
*/
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BFSImplement
{
    private Queue<Integer> queue;//For implementation of BFS
    //constructor
    public BFSImplement()
    {
        queue=new LinkedList<Integer>();
    }
    public void bfs(int adjacency_matrix[][],int source)
    {
        int numberOfNodes=adjacency_matrix[source].length-1;
        int visited[]=new int[numberOfNodes+1];//to contain which nodes have been visited
        int i,element;
        visited[source]=1;
        queue.add(source);
        
        while(!queue.isEmpty())
        {
            element=queue.remove();
            i=element;
            System.out.print(i+"\t");
            while(i<=numberOfNodes)
            {
                if(adjacency_matrix[element][i]==1 && visited[i]==0)
                {
                    //if path possible and the node had not been visited before, add it to the queue
                    visited[i]=1;
                    queue.add(i);
                }
                i++;
            }
        }
    }
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        System.out.println("Enter the number Of Nodes in the graph");
        int numberOfNodes=d.nextInt();
        System.out.println("Enter the adjacency Matrix");
        int adjacency_matrix[][]=new int[numberOfNodes+1][numberOfNodes+1];
        for(int i=1;i<=numberOfNodes;i++)
        {
            for(int j=1;j<=numberOfNodes;j++)
            {
                adjacency_matrix[i][j]=d.nextInt();
            }
        }
        System.out.println("Enter the source From where to start");
        int source=d.nextInt();
        System.out.println("The BFS Traversal Of the Graph is: ");
        BFSImplement bfs=new BFSImplement();//Object Creation
        bfs.bfs(adjacency_matrix, source);//Calling of method
        d.close();
    }//End of Main
}//End of Class
