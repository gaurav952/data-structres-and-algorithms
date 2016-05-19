/*
Name: Gaurav Sinha


Problem Statement:    Write a program to implement concept of hashing. Design a menu based interface to call different functions for collision handling techniques. 
*/
import java.util.Scanner;
import java.math.*;
//This is a class for Linear Probing Of Hash Table
class LinearProbingHashTable
{
    private int currentSize,maxSize;
    private String[] keys;
    private String[] vals;
    
    public LinearProbingHashTable(int capacity)//constructor
            {
                currentSize=0;
                maxSize=capacity;
                keys=new String[maxSize];
                vals=new String[maxSize];
            }
    public void makeEmpty()//Function to clear Hash Table
    {
        currentSize=0;
        keys=new String[maxSize];
        vals=new String[maxSize];
    }
    public int getSize()//Function to get size of Hash Table
    {
        return currentSize;
    }
    public boolean isFull()//Function to check if Hash Table is Full
    {
        return currentSize==maxSize;
    }
    public boolean isEmpty()//Function to check if Hash Table is Empty
    {
        return getSize()==0;
    }
    public boolean contains(String key)//Function to check if Hash Table contains a Key
    {
        return get(key)!=null;
    }
    private int hash(String key)//Function to get Hash Code of a given Key
    {
        return key.hashCode()%maxSize;
    }
    public void insert(String key,String val)//Function to insert a key-value pair
    {
        int tmp=hash(key);
        int i=tmp;
        do
        {
            if(keys[i]==null)
            {
                keys[i]=key;
                vals[i]=val;
                currentSize++;
                return ;
            }
            if(keys[i].equals(key))
            {
                vals[i]=val;
                return ;
            }
            i=(i+1)%maxSize;
        }while(i!=tmp);
    }
    public String get(String key)//Function to get value for a given key
    {
        int i=hash(key);
        while(keys[i]!=null)
        {
            if(keys[i].equals(key))
                return vals[i];
            i=(i+1)%maxSize;
        }
        return null;
    }
    public void remove(String key)//Function to remove key and its value
    {
        if(!contains(key))
            return ;
        int i=hash(key);
        //Find Position of Key and delete
        while(!key.equals(keys[i]))
            i=(i+1)%maxSize;
        keys[i]=vals[i]=null;
        //Rehash all Keys
        for(i=(i+1)%maxSize;keys[i]!=null;i=(i+1)%maxSize)
        {
            String tmp1=keys[i],tmp2=vals[i];
            keys[i]=null;
            vals[i]=null;
            currentSize--;
            insert(tmp1,tmp2);
        }
        currentSize--;
        
    }
    //Function to print Hash Table
    public void printHashTable()
    {
        System.out.println("\n Hash Table:");
        for(int i=0;i<maxSize;i++)
        {
            if(keys[i]!=null)
                System.out.println(keys[i]+" "+vals[i]);
        }
        System.out.println();
    }
}
//End of Class Linear Probing Technique for Hashing
//This is a class for Quadratic Probing in Hashing
class QuadraticProbingHashTable
{
    private int currentSize,maxSize;
    private String[] keys;
    private String[] vals;
    
    public QuadraticProbingHashTable(int capacity)//constructor
    {
        currentSize=0;
        maxSize=capacity;
        keys=new String[maxSize];
        vals=new String[maxSize];
    }
    public void makeEmpty()//Function to clear Hash Table
    {
        currentSize=0;
        keys=new String[maxSize];
        vals=new String[maxSize];
    }
    public int getSize()//Function to get size of Hash Table
    {
        return currentSize;
    }
    public boolean isFull()//Function to check if Hash Table is Full
    {
        return currentSize==maxSize;
    }
    public boolean isEmpty()//Function to check if Hash Table is Empty
    {
        return getSize()==0;
    }
    public boolean contains(String key)//Function to check if Hash Table contains a key
    {
        return get(key)!=null;
    }
    private int hash(String key)//Function to get Hash Code of a Key
    {
        return key.hashCode()%maxSize;
    }
    public void insert(String key,String val)//Function to insert Key-value pairs in Hash Table
    {
        int tmp=hash(key);
        int i=tmp,h=1;
        do
        {
            if(keys[i]==null)
            {
                keys[i]=key;
                vals[i]=val;
                currentSize++;
                return ;
            }
            if(keys[i].equals(key))
            {
                vals[i]=val;
                return ;
            }
            i=(i+h*h)%maxSize;
            h++;
        }while(i!=tmp);
    }
    public String get(String key)//Function to get value for a given Key
    {
        int i=hash(key);
        int h=1;
        while(keys[i]!=null)
        {
            if(keys[i].equals(key))
                return vals[i];
            i=(i+h*h)%maxSize;
            h++;
        }
        return null;
    }
    public void remove(String key)//Function to remove a Key and it's value
    {
        if(!contains(key))
            return ;
        int i=hash(key),h=1;
        //Find position of Key and delete
        while(!key.equals(keys[i]))
            i=(i+h*h++)%maxSize;
        keys[i]=vals[i]=null;
        //Rehash all keys
        for(i=(i+h*h++)%maxSize;keys[i]!=null;i=(i+h*h++)%maxSize)
        {
            String tmp1=keys[i],tmp2=vals[i];
            keys[i]=null;
            vals[i]=null;
            currentSize--;
            insert(tmp1,tmp2);
        }
        currentSize--;
        
    }
    //Function to print Hash Table
    public void printHashTable()
    {
        System.out.println("\n Hash Table:");
        for(int i=0;i<maxSize;i++)
        {
            if(keys[i]!=null)
                System.out.println(keys[i]+" "+vals[i]);
        }
        System.out.println();
    }
}
//End of quadratic Probing Hashing
//Start of Double Hashing
class HashEntry
{
    //hash Entries as key-value pairs
    String key;
    int value;
    
    //constructor
    HashEntry(String key,int value)
    {
        this.key=key;
        this.value=value;
    }
    
}
class HashTable//class for Hash Table
{
    private int TABLE_SIZE;
    private int size;
    private HashEntry[] table;
    private int primeSize;
    
    //constructor
    public HashTable(int ts)
    {
        size=0;
        TABLE_SIZE=ts;
        table=new HashEntry[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++)
            table[i]=null;
        primeSize=getPrime();
    }
    //Function to get prime number less than table size for myhash2 function
    public int getPrime()
    {
        for(int i=TABLE_SIZE-1;i>=1;i--)
        {
            int fact=0;
            for(int j=2;j<=(int)Math.sqrt(i);j++)
            {
                if(i%j==0)
                    fact++;
            }
            if(fact==0)
                return i;
        }
        //Return a prime number
        return 3;
    }
    //Function to get size(no of key-value pairs) of Hash Table
    public int getSize()
    {
        return size;
    }
    //Function to check if Hash Table is empty
    public boolean isEmpty()
    {
        return size==0;
    }
    //Function to clear Hash Table
    public void makeEmpty()
    {
        size=0;
        for(int i=0;i<TABLE_SIZE;i++)
            table[i]=null;
    }
    //Function to get value of a key
    public int get(String key)
    {
        int hash1=myhash1(key);
        int hash2=myhash2(key);
        while(table[hash1]!=null && !table[hash1].key.equals(key))
        {
            hash1 +=hash2;
            hash1 %=TABLE_SIZE;
        }
        return table[hash1].value;
    }
    //Function to insert a key-value pair
    public void insert(String key,int val)
    {
        if(size==TABLE_SIZE)
        {
            System.out.println("Table is Full");
            return;
        }
        int hash1=myhash1(key);
        int hash2=myhash2(key);
        while(table[hash1]!=null)
        {
            hash1 +=hash2;
            hash1 %=TABLE_SIZE;
        }
        table[hash1]=new HashEntry(key,val);
        size++;
    }
    //Function to remove a key
    public void remove(String key)
    {
        int hash1=myhash1(key);
        int hash2=myhash2(key);
        while(table[hash1]!=null && !table[hash1].key.equals(key))
        {
            hash1 +=hash2;
            hash1 %=TABLE_SIZE;
        }
        table[hash1]=null;
        size--;
    }
    //Function myhash which gives a hash value for a given string
    private int myhash1(String x)
    {
        int hashVal=x.hashCode();
        hashVal %=TABLE_SIZE;
        if(hashVal<0)
        {
            hashVal +=TABLE_SIZE;
        }
        return hashVal;
    }
    //Function myhash for double Hashing
    private int myhash2(String x)
    {
        int hashVal=x.hashCode();
        hashVal %=TABLE_SIZE;
        if(hashVal<0)
        {
            hashVal +=TABLE_SIZE;
        }
        return primeSize-hashVal*primeSize;
    }
    //Function to print Hash Table
    public void printHashTable()
    {
        System.out.println("\nHash Table");
        for(int i=0;i<TABLE_SIZE;i++)
        {
            if(table[i]!=null)
                System.out.println(table[i].key+" "+table[i].value);
        }
    }
}
//End Of Double Hashing
//Chaining Method of Hashing
class LinkedHashEntry
{//Class for Hash Entries Having links for each bucket
    String key;
    int value;
    LinkedHashEntry next;
    
    //constructor
    LinkedHashEntry(String key,int value)
    {
        this.key=key;
        this.value=value;
        this.next=null;
    }
}
class HashTable1
{
    private int TABLE_SIZE;
    private int size;
    private LinkedHashEntry[] table;
    
    //constructor
    public HashTable1(int ts)
    {
        size=0;
        TABLE_SIZE=ts;
        table=new LinkedHashEntry[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++)
        {
            table[i]=null;
        }
    }
    //Function to get number of Key Value Pairs
    public int getSize()
    {
      return size;
    }
    //Function to clear Hash Table
    public void makeEmpty()
    {
        for(int i=0;i<TABLE_SIZE;i++)
            table[i]=null;
    }
    //Function to get value of a key
    public int get(String key)
    {
        int hash=myhash(key)%TABLE_SIZE;
        if(table[hash]==null)
            return -1;
        else
        {
            LinkedHashEntry entry=table[hash];
            while(entry!=null && !entry.key.equals(key))
                entry=entry.next;
            if(entry==null)
                return -1;
            else
                return entry.value;
        }
    }
    //Function to insert a key-value pair
    public void insert(String key,int value)
    {
        int hash=(myhash(key)%TABLE_SIZE);
        if(table[hash]==null)
            table[hash]=new LinkedHashEntry(key,value);
        else
        {
            LinkedHashEntry entry=table[hash];
            while(entry.next!=null && !entry.key.equals(key))
                entry=entry.next;
            if(entry.key.equals(key))
                entry.value=value;
            else
                entry.next=new LinkedHashEntry(key,value);
        }
        size++;
    }
    //Function to delete a key and it's value
    public void remove(String key)
    {
        int hash=myhash(key)%TABLE_SIZE;
        if(table[hash]!=null)
        {
            LinkedHashEntry prevEntry=null;
            LinkedHashEntry entry=table[hash];
            while(entry.next!=null && !entry.key.equals(key))
            {
                prevEntry=entry;
                entry=entry.next;
            }
            if(entry.key.equals(key))
            {
                if(prevEntry==null)
                    table[hash]=entry.next;
                else
                    prevEntry.next=entry.next;
                size--;
            }
        }
    }
    //Function myhash which gives a hash value for a given String
    private int myhash(String x)
    {
        int hashVal=x.hashCode();
        hashVal %=TABLE_SIZE;
        if(hashVal<0)
            hashVal +=TABLE_SIZE;
        return hashVal;
    }
    //Function to print Hash Table
    public void printHashTable()
    {
        for(int i=0;i<TABLE_SIZE;i++)
        {
            System.out.print("\nBucket: "+(i+1)+": ");
            LinkedHashEntry entry=table[i];
            while(entry!=null)
            {
                System.out.print(entry.value+" ");
                entry=entry.next;
            }
        }
    }
}
//End of Chaining method of Hashing
public class HashingImplement
{
    public static void main(String args[])
    {
        Scanner d=new Scanner(System.in);
        System.out.println("Hash Table Test:\n\n ");
        int choice;
        do
        {
        System.out.println("Enter Size ");
        System.out.println("But Before That Enter Your Choice For Which Type of Hashing Technique to use!!!!");
        System.out.println("1-Linear Probing \n2-Quadratic Probing \n3-Chaining Method \n4-Double Hashing \n0-To QUIT..");
        choice=d.nextInt();
        switch(choice)
        {
            case 0:
                System.out.println("Quiting From the Procedure");
                break;
            case 1:
                LinearProbingHashTable l1=new LinearProbingHashTable(d.nextInt());
                char ch;
                do
                {
                    System.out.println("Hash Table Operations For Linear Probing");
                    System.out.println("1-Insert\n2-Remove\n3-Get\n4-Clear\n5-size");
                    int choice1=d.nextInt();
                    switch(choice1)
                    {
                        case 1:
                            System.out.println("Enter Key and Value to be inserted");
                            l1.insert(d.next(),d.next());
                            break;
                        case 2:
                            System.out.println("Enter the Key for which data has to be removed");
                            l1.remove(d.next());
                            break;
                        case 3:
                            System.out.println("Enter the key for which data has to be retrieved");
                            System.out.println("Value== "+l1.get(d.next()));
                            break;
                        case 4:
                            l1.makeEmpty();
                            System.out.println("\nHash Table cleared\n");
                            break;
                        case 5:
                            System.out.println("Size= "+l1.getSize());
                            break;
                        default:
                            System.out.println("Wrong Entry\n");
                    }
                    l1.printHashTable();
                    System.out.println("\nDo you want to continue or not(Type Y or N)");
                    ch=d.next().charAt(0);
                }while(ch=='Y'||ch=='y');
                System.out.println("Linear Probing Analysed. Procedure Linear Probing ends");
                break;
            case 2:
                QuadraticProbingHashTable q1=new QuadraticProbingHashTable(d.nextInt());
                char ch1;
                do
                {
                    System.out.println("Hash Table Operations For Quadratic Probing");
                    System.out.println("1-Insert\n2-Remove\n3-Get\n4-Clear\n5-size");
                    int choice2=d.nextInt();
                    switch(choice2)
                    {
                        case 1:
                            System.out.println("Enter Key and Value to be inserted");
                            q1.insert(d.next(),d.next());
                            break;
                        case 2:
                            System.out.println("Enter the Key for which data has to be removed");
                            q1.remove(d.next());
                            break;
                        case 3:
                            System.out.println("Enter the key for which data has to be retrieved");
                            System.out.println("Value== "+q1.get(d.next()));
                            break;
                        case 4:
                            q1.makeEmpty();
                            System.out.println("\nHash Table cleared\n");
                            break;
                        case 5:
                            System.out.println("Size= "+q1.getSize());
                            break;
                        default:
                            System.out.println("Wrong Entry\n");
                    }
                    q1.printHashTable();
                    System.out.println("\nDo you want to continue or not(Type Y or N)");
                    ch1=d.next().charAt(0);
                }while(ch1=='Y' || ch1=='y');
                System.out.println("Quadratic Probing Analysed.Procedure Of Quadratic Probing ends");
                break;
            case 3:
                HashTable1 h1=new HashTable1(d.nextInt());
                char ch2;
                do
                {
                    System.out.println("Hash Table Operations on Chaining Method For Hashing");
                    System.out.println("1-Insert\n2-Remove\n3-Get\n4-Clear\n5-size");
                    int choice2=d.nextInt();
                    switch(choice2)
                    {
                        case 1:
                            System.out.println("Enter Key and Value to be inserted");
                            h1.insert(d.next(),d.nextInt());
                            break;
                        case 2:
                            System.out.println("Enter the Key for which data has to be removed");
                            h1.remove(d.next());
                            break;
                        case 3:
                            System.out.println("Enter the key for which data has to be retrieved");
                            System.out.println("Value== "+h1.get(d.next()));
                            break;
                        case 4:
                            h1.makeEmpty();
                            System.out.println("\nHash Table cleared\n");
                            break;
                        case 5:
                            System.out.println("Size= "+h1.getSize());
                            break;
                        default:
                            System.out.println("Wrong Entry\n");
                    }
                    h1.printHashTable();
                    System.out.println("\nDo you want to continue or not(Type Y or N)");
                    ch2=d.next().charAt(0);
                }while(ch2=='Y' || ch2=='y');
                System.out.println("Chaining Process Analysed. Procedure Ends");
                break;
            case 4:
                HashTable ht=new HashTable(d.nextInt());
                char ch3;
                do
                {
                    System.out.println("Hash Table Operations For Double Hahsing Technique");
                    System.out.println("1-Insert\n2-Remove\n3-Get\n4-Clear\n5-size");
                    int choice3=d.nextInt();
                    switch(choice3)
                    {
                        case 1:
                            System.out.println("Enter Key and Value to be inserted");
                            ht.insert(d.next(),d.nextInt());
                            break;
                        case 2:
                            System.out.println("Enter the Key for which data has to be removed");
                            ht.remove(d.next());
                            break;
                        case 3:
                            System.out.println("Enter the key for which data has to be retrieved");
                            System.out.println("Value== "+ht.get(d.next()));
                            break;
                        case 4:
                            ht.makeEmpty();
                            System.out.println("\nHash Table cleared\n");
                            break;
                        case 5:
                            System.out.println("Size= "+ht.getSize());
                            break;
                        default:
                            System.out.println("Wrong Entry\n");
                    }
                    ht.printHashTable();
                    System.out.println("\nDo you want to continue or not(Type Y or N)");
                    ch3=d.next().charAt(0);
                }while(ch3=='Y' || ch3=='y');
                System.out.println("Double Hashing Analysed.Procedure Ends");
                break;
            default:
                System.out.println("Wrong Choice Entered!!");
        }
        }while(choice!=0);
        System.out.println("Procedures Finished. End of Menu driven Program!!");
    }//End Of main
}//End of Class
//End Of Hashing
