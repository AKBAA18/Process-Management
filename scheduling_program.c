#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//This is the creation of structure with pid , duration , priority , state as elements 
typedef struct process
{
  int pid;
  int duration;
  int priority;
  char * name;
  struct process *ptr;
}process;
//Here ai have created another struct and from this I have created the sorted linkedlist 
typedef struct process1
{
        int pid;
        int duration;
        int priority;
        char * name;
        struct process1 *ptr;
}process1;


//Here I have declared the function used in this program  
void setprocess(process * );
void printprocess(process *);
void newprintprocess(process1 *);
process1 *  rearrangeprocess(process *);
void process_starts(process1 *);

int main()
{
  //creating nodes 
  process * check;
  process * node1= (process * )malloc(sizeof(process));
  process * node2= (process * )malloc(sizeof(process));
  process * node3= (process * )malloc(sizeof(process));
  process * node4= (process * )malloc(sizeof(process));
  process * node5= (process * )malloc(sizeof(process));
  node1->ptr=node2;
  node2->ptr=node3;
  node3->ptr=node4;
  node4->ptr=node5;
  node5->ptr=NULL;
  check=node1;
  setprocess(check);//here we are setting the ll
  check=node1;
  printprocess(check);//here we are printing the ll 
  check=node1;

  //creating another struct pointer variable fror another struct 
  process1 * ncheck;
  ncheck =rearrangeprocess(check);//here I am returning and storing the arranged queue  
  printf("\nThe sorted queue is \n");
  newprintprocess(ncheck);//here I am printing the new sorted linkedlist 

  //here the time slicing function call happedn 
  printf("The process completion ststus is  \n");
  process_starts(ncheck);
  newprintprocess(ncheck);//here I am linkedlist after the time slice happens 



  return 0;
}
//here I am doing the insertion / by getting input 
void setprocess(process * q)
{
  process * head;
  head=q;
  for(int i=0;i<5;i++)
  {
    printf("Enter the pid of the process ");
    scanf("%d" , &q->pid);
    printf("Enter the duration of process ins seconds ");
    scanf("%d" , &q->duration );
    printf("Enter the priority ");
    scanf("%d" , &q->priority);
    printf("Enter the state of the process ");
    q->name=(char * )malloc(10*sizeof(char));
    scanf("%s" ,q->name);
    q=q->ptr;
    printf("\n");
  }
}
//We are printing the first un sorted linked list 
void printprocess(process *q)
{
  for(int i=0;i<5;i++)
  {
    printf("Process %d \n",i+1);
    printf("Pid : %d \n" ,q->pid);
    printf("Duration required in seconds : %d\n", q->duration);
    printf("Priority NO : %d\n" , q->priority);
    printf("State of process  : %s\n", q->name);
    printf("\n\n");
    q=q->ptr;
  }
}
//We are printing the newly created linked loist which containf the sorted priority 
void newprintprocess(process1 *q)
{
        process1 *savehead=q;
  for(int i=0;i<5;i++)
        {
                printf("Process %d \n",i+1);
                printf("Pid : %d \n" ,q->pid);
                printf("Duration required in seconds : %d\n", q->duration);
                printf("Priority NO : %d\n" , q->priority);
                printf("State of process  : %s\n", q->name);
                printf("\n\n");
                q=q->ptr;
        }
  q=savehead;
}
//This is the function uswed for sorting 
process1 *rearrangeprocess(process *q) {
      process1 *ncheck ; //created this variable for string the starting node  
     //Here I have created a linked list from another structure 
      process1 *nnode1 = (process1 *)malloc(sizeof(process1));
      process1 *nnode2 = (process1 *)malloc(sizeof(process1));
      process1 *nnode3 = (process1 *)malloc(sizeof(process1));
      process1 *nnode4 = (process1 *)malloc(sizeof(process1));
      process1 *nnode5 = (process1 *)malloc(sizeof(process1));

      nnode1->ptr = nnode2;
      nnode2->ptr = nnode3;
      nnode3->ptr = nnode4;
      nnode4->ptr = nnode5;
      nnode5->ptr = NULL;

  ncheck = nnode1; // keeping thw address of the first node 

      for (int i = 0; i < 5 && q != NULL; i++) {
          if (q->priority == 1) {
                nnode1->pid = q->pid;
                nnode1->duration = q->duration;
                nnode1->priority = q->priority;
                nnode1->name=(char *)malloc(10*sizeof(char));//this is the error in prev code allocated memory 
          strcpy((nnode1->name),(q->name));
          } 
    else if (q->priority == 2) {
                nnode2->pid = q->pid;
                nnode2->duration = q->duration;
                nnode2->priority = q->priority;
                nnode2->name=(char *)malloc(10*sizeof(char));
          strcpy((nnode2->name),(q->name));
          } 
    else if (q->priority == 3) {
                nnode3->pid = q->pid;
                nnode3->duration = q->duration;
                nnode3->priority = q->priority;
                nnode3->name=(char *)malloc(10*sizeof(char));
          strcpy((nnode3->name),(q->name));
          } 
    else if (q->priority == 4) {
                nnode4->pid = q->pid;
                nnode4->duration = q->duration;
                nnode4->priority = q->priority;
                nnode4->name=(char *)malloc(10*sizeof(char));
      strcpy((nnode4->name),(q->name));
          }
          else if (q->priority == 5) {
                nnode5->pid = q->pid;
                nnode5->duration = q->duration;
                nnode5->priority = q->priority;
                nnode5->name=(char *)malloc(10*sizeof(char));
          strcpy((nnode5->name),(q->name));
    }
          q = q->ptr;
      }
      return ncheck; // returning the address of first node 
}

//This is the function for updating the time stamp by user given time 
void process_starts(process1 *q)
{
  int timeslice;
        printf("Enter the timeslice \n");
        scanf("%d" , &timeslice);
  for(int i=0;i<5;i++)
  {	if(q->duration>=2)
    {
      q->duration=q->duration-2;
    }
    if(q->duration<=0)
    {
      strcpy((q->name),"Completed");
    }
    else{
      strcpy((q->name),"Inprogress");
    }
    q=q->ptr;
  }
}	
