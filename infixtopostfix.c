/*
Name: GAURAV SINHA

 Write a program to perform following operations on stack.
a) Create functions for push and pop operations of stack.
b) Write a function to convert an infix expression to postfix expression. Pass a one dimensional character array P to the function as input (infix exp) and return character array Q (postfix exp). Test your program for following input
P : ( A – (B / C ) * D + E ) * F % G
c) Write a function for the evaluation of a given postfix expression. For testing pass the postfix expression Q of part b and supply following set of values. A = 90, B = 50, C = 2, D = 3, E = 1, F = 2, G = 5 
*/

#include<stdio.h>
#include<string.h>
#define n 50

int top = -1;
char stack[n];
char postfix[n];
void calculate(char c);
void push(char item);
char pop();
int opera_dec(char symbol);
int priority(char symbol);

int main()
{
 int i, j;
 char infix[n];
 char item, x;
 
 printf(" Enter the infix expression in Infix enclosed in parentheses: \n");
 gets(infix);
	
 i=0;
 j=0;
 item=infix[i++];
 while(item != '\0')
 {
  if(item == '(')
  {
   push(item);
  }
  else if((item >= 'A'  && item <= 'Z') || (item >= 'a' && item <= 'z'))
  {
   postfix[j++] = item;
  }
  else if(opera_dec(item) == 1)
  {
   x=pop();
   while(opera_dec(x) == 1 && priority(x) >= priority(item))
   {
    postfix[j++] = x;
    x = pop();
   }
   push(x);
   push(item);			
  }
  else if(item == ')')
  {
   x = pop();
   while(x != '(')
   {
    postfix[j++] = x;
    x = pop();
   }
  }
  else
  {
   printf(" Invalid Arithmetic Expression.\n");
  }
  item = infix[i++];
 }
  postfix[j++] = '\0';
  printf("Arithmetic expression in Postfix notation: ");
  puts(postfix);
/*top=-1;
for(i=0;i<strlen(postfix);i++)
 {
  if(postfix[i]>='0' && postfix[i]<='9')
  {
   push(i);
  }
  if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || 
  postfix[i]=='/' || postfix[i]=='^' || postfix[i]=='%')
  {
   calculate(postfix[i]);
  }
 }

 printf("Result :: %d",stack[top]);
*/
 return 0;
}

void push(char item)
{
 if(top >= n-1)
 {
  printf("\nStack Overflow. Push not possible.\n");
 }
 else
 {
  top = top+1;
  stack[top] = item;
 }
}

char pop()
{
 char item = NULL;
 if(top <= -1)
 {
  printf("Stack Underflow\n");
 }
 else
 {
  item = stack[top];
  stack[top] = NULL;
  top = top-1;
 }
 return(item);
}

int opera_dec(char symbol)
{
 if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-'|| symbol =='%')
 {
  return 1;
 }
 else
 {
  return 0;
 }
}

int priority(char symbol)
{
 if(symbol == '^')
 {
  return(3);
 }
 else if(symbol == '*' || symbol == '/' || symbol =='%')
 {
  return(2);
 }
 else if(symbol == '+' || symbol == '-')
 {
  return(1);
 }
 else
 {
  return(0);
 }
}
void calculate(char c)
{
 int a,b,ans;
 a=stack[top];
 stack[top]='\0';
 top--;
 b=stack[top];
 stack[top]='\0';
 top--;
 switch(c)
 {
  case '+':
  ans=b+a;
  break;
  case '-':
  ans=b-a;
  break;
  case '*':
  ans=b*a;
  break;
  case '/':
  ans=b/a;
  break;
  case '^':
  ans=b^a;
  break;
  case '%':
  ans=a%b;
  break;
  default:
  ans=0;
 }
 top++;
 stack[top]=ans;
}


