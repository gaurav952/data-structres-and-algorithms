/*
Name: Gaurav Sinha


Problem Statement :    Write a program to traverse various nodes of a given graph using stack as an intermediate data structure (DFS). 
*/
import java.util.Scanner;
import java.util.Stack;

public class DFSImplement
{
    private Stack<Integer> stack;//To implement DFS
    
    //constructor
    public DFSImplement()
    {
        stack=new Stack<Integer>();
    }
    //To implement DFS
    public void dfs(int adjacency_matrix[][],int source)
    {
        int numberOfNodes=adjacency_matrix[source].length-1;
        int visited[]=new int[numberOfNodes+1];
        int element=source;
        int i=source;
        System.out.print(element+"\t");
        visited[source]=1;
        stack.push(i);
        while(!stack.isEmpty())
        {
            element=stack.peek();//returns the top of the stack
            i=element;
            while(i<=numberOfNodes)
            {
                if(adjacency_matrix[element][i]==1 && visited[i]==0)
                {
                    //if the node is possible to visit and has not been visited till now
                    visited[i]=1;
                    stack.push(i);
                    element=i;
                    i=1;
                    System.out.print(element+"\t");
                    continue;
                }
                i++;
            }
            stack.pop();
        }
    }
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        System.out.println("Enter the number of nodes in the Graph");
        int numberOfNodes=d.nextInt();
        System.out.println("Enter the Adjacency Matrix");
        int adjacency_matrix[][]=new int[numberOfNodes+1][numberOfNodes+1];
        for(int i=1;i<=numberOfNodes;i++)
        {
            for(int j=1;j<=numberOfNodes;j++)
                adjacency_matrix[i][j]=d.nextInt();
        }
        System.out.println("Enter the source for the Graph");
        int source=d.nextInt();
        System.out.println("DFS Traversal For the Graph is given by");
        DFSImplement dfs=new DFSImplement();//Object Creation
        dfs.dfs(adjacency_matrix, source);//Calling Of method
        d.close();
    }//End of main
}//End of class
