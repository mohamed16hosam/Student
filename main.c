#include <stdio.h>
#include <stdlib.h>

struct Student {
char stname [20] ; //character array for student name //
int stid ; //student id //
int stbirthday ; //student birthday //
int stbirthmon ; //student birth month //
int stbirthyear ; //student birth year //
int stscore ; //student score of last year //
};

struct Node {
    struct Node* next;//pointer to structure
    struct Student student1;
};


void printList(struct Node* head)
{    struct Node* tmp = head;
    printf("Linked List:\n");
    printf("Name\t\tid\t birthdate\tlastyearscore\n");
    while (tmp != NULL) {
        printf("%s\t", tmp->student1.stname);
        printf("%d\t ", tmp->student1.stid);
        printf("%d/", tmp->student1.stbirthday);
        printf("%d/", tmp->student1.stbirthmon);
        printf("%d\t", tmp->student1.stbirthyear);
        printf("%d\n", tmp->student1.stscore);
        tmp = tmp->next;

    }
    printf("\n");
}

struct Node* createNode(int id,char name[20] ,int day_birth,int month_birth,int year_birth,int l_yearscore)
{
    // allocating space
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->student1.stname,name);
    newNode->student1.stid=id;
    newNode->student1.stbirthday=day_birth;
    newNode->student1.stscore=l_yearscore;
    newNode->student1.stbirthmon=month_birth;
    newNode->student1.stbirthyear=year_birth;
    newNode->next = NULL;
    return newNode;
}
void pushNode(struct Node** head,char name[20],struct Node** tail, int id,int day_birth,int month_birth,int year_birth,int l_yearscore)
{

    if (*head == NULL)
    {
        *head = createNode( id,name, day_birth,month_birth,year_birth,l_yearscore);
        return;
    } else {
        struct Node* tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = createNode(id,name,day_birth, month_birth, year_birth, l_yearscore);
        *tail=tmp->next;//tail points to the last node i pushed
    return;}
}
void insertfirst(struct Node **head,char name[20],int id,int day_birth,int month_birth,int year_birth,int l_yearscore)//function that returns pointer and receives pointer
{
    struct Node* second = NULL;//new node
    second = createNode(id,name,day_birth,month_birth,year_birth,l_yearscore);
    second->next=*head;

    *head=second;
    return ;
}
void insertend(struct Node **tail,char name[20],int id,int day_birth,int month_birth,int year_birth,int l_yearscore)//function that returns pointer and receives pointer
{
    struct Node* second = NULL;
    second = createNode(id,name,day_birth,month_birth,year_birth,l_yearscore);
    (*tail)->next=second;
    second->next=NULL;
    *tail=second;
    return ;
}
struct Node* findMiddleNode(struct Node* head)
{

        struct Node* slow = head;
        struct Node* fast = head->next;

        while(fast != NULL && fast->next != NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;


};

void insertAtMiddle(struct Node* head,char name[20],int id,int day_birth,int month_birth,int year_birth,int l_yearscore)
{
    struct Node* newNode = createNode(id,name,day_birth,month_birth,year_birth,l_yearscore);

    // Get the pointer pointing to the middle node in the LL
    struct Node* middleNodePtr = findMiddleNode(head);

    newNode->next = middleNodePtr->next;
    middleNodePtr->next = newNode;
};
int lengthLL(struct Node* head)
{
    int length = 0;
    struct Node* tmp = head;
    while (tmp != NULL) {
        tmp = tmp->next;
        length++;
    }
   // printf("d/n",length);
    return length;
}



void insertbyindex(struct Node** head,struct Node** tail,char name[20],int id,int day_birth,int month_birth,int year_birth,int l_yearscore,int index)
{
   struct Node* newNode = createNode(id,name,day_birth,month_birth,year_birth,l_yearscore);
   struct Node* tmp1 =*head;
   struct Node* tmp2=*head ;
   for (int i=0;i<index-1;i++)
   {   tmp2=tmp1;
       tmp1=tmp1->next;
   }
   tmp2->next=newNode;
   newNode->next=tmp1;
   }



int main()
{
 
    printf("Welcome to our program\n");
    printf("\t*THis is the linked list*\n");
    printf("size of structure of data:%d\n",sizeof(struct Student));
    printf("size of node :%d\n",sizeof(struct Node));
    struct Node* head = NULL;//pointer to linked list structure
    struct Node* tail = NULL;
    pushNode(&head,"mohamed ahmed",& tail,334,22,4,2000,84);
    pushNode(&head,"omar tarek",& tail,335,28,5,2000,100);
    int id,day_birth,month_birth,year_birth,l_yearscore,index;
    int z=1;
    char r;
    char name[100];
    printf("Choose one of the following options by entering the character beside it\n");
    printf("insert first:a\tinsert end:b\tinsert in the middle index:c\n");
    printf("insert by choosing index:d\tprint all the list:e\n");
    scanf("%c",&r);
    fflush(stdin);
   while(z){

    switch (r) {
        case 'a':{
            printf("enter the name of the student\n");
            fflush(stdin);
            gets(name);
            printf("enter the id\n");
            scanf("%d",&id);
            printf("enter the day of birth\n");
            scanf("%d",&day_birth);
            printf("enter the month of birth\n");
            scanf("%d",&month_birth);
            printf("enter the year of birth\n");
            scanf("%d",&year_birth);
            printf("enter last year score\n");
            scanf("%d",&l_yearscore);
            insertfirst(&head,name,id,day_birth,month_birth,year_birth,l_yearscore);//this is not call by reference so i have to use equal
            printf("If you want to choose any option from the above options press any number if not press zero\n");
            scanf("%d",&z);
            if(z)
            {
            printf("Choose one of the following options by entering the character beside it\n");
    printf("insert first:a\tinsert end:b\tinsert in the middle index:c\n");
    printf("insert by choosing index:d\tprint all the list:e\n");
            scanf(" %c",&r);
            }
            break;
    }
     case 'b':{
            printf("enter the name of the student\n");
            fflush(stdin);
            gets(name);
            printf("enter the id\n");
            scanf("%d",&id);
            printf("enter the day of birth\n");
            scanf("%d",&day_birth);
            printf("enter the month of birth\n");
            scanf("%d",&month_birth);
            printf("enter the year of birth\n");
            scanf("%d",&year_birth);
            printf("enter last year score\n");
            scanf("%d",&l_yearscore);
            insertend(&tail,name,id,day_birth,month_birth,year_birth,l_yearscore);
            printf("If you want to choose any option from the above options press any number if not press zero\n");
            scanf("%d",&z);
             if(z)
            {
            printf("Choose one of the following options by entering the character beside it\n");
    printf("insert first:a\tinsert end:b\tinsert in the middle index:c\n");
    printf("insert by choosing index:d\tprint all the list:e\n");
            scanf(" %c",&r);
            }
         break;
    }
         case 'c':{
            printf("enter the name of the student\n");
            fflush(stdin);
            gets(name);
            printf("enter the id\n");
            scanf("%d",&id);
            printf("enter the day of birth\n");
            scanf("%d",&day_birth);
            printf("enter the month of birth\n");
            scanf("%d",&month_birth);
            printf("enter the year of birth\n");
            scanf("%d",&year_birth);
            printf("enter last year score\n");
            scanf("%d",&l_yearscore);
            insertAtMiddle(head,name,id,day_birth,month_birth,year_birth,l_yearscore);
            printf("If you want to choose any option from the above options press any number if not press zero\n");
            scanf("%d",&z);
             if(z)
            {
            printf("Choose one of the following options by entering the character beside it\n");
    printf("insert first:a\tinsert end:b\tinsert in the middle index:c\n");
    printf("insert by choosing index:d\tprint all the list:e\n");
            scanf(" %c",&r);
            }
         break;
    }
     case 'd':{
            printf("the list has %d students\n",lengthLL(head));
            printf("enter the index starting from 1 \n");
            scanf("%d",&index);
            if((index)>lengthLL(head))
            {
                printf("the list have fewer elements choose less index\n");
            }
            else{
            printf("enter the name of the student\n");
            fflush(stdin);
            gets(name);
            printf("enter the id\n");
            scanf("%d",&id);
            printf("enter the day of birth\n");
            scanf("%d",&day_birth);
            printf("enter the month of birth\n");
            scanf("%d",&month_birth);
            printf("enter the year of birth\n");
            scanf("%d",&year_birth);
            printf("enter last year score\n");
            scanf("%d",&l_yearscore);
            if (index==1)
           {
            insertfirst(&head,name,id,day_birth,month_birth,year_birth,l_yearscore);
           }
            else if(index==(lengthLL(head)))
           {
           insertend(&tail,name,id,day_birth,month_birth,year_birth,l_yearscore) ;
           }
           else{
            insertbyindex(&head,&tail,name,id,day_birth,month_birth,year_birth,l_yearscore,index);
           }
            }
            printf("If you want to choose any option from the above options press any number if not press zero\n");
            scanf("%d",&z);
             if(z)
            {
            printf("Choose one of the following options by entering the character beside it\n");
    printf("insert first:a\tinsert end:b\tinsert in the middle index:c\n");
    printf("insert by choosing index:d\tprint all the list:e\n");
            scanf(" %c",&r);
            }
         break;
    }
     case 'e':{
    printList(head);
    printf("If you want to choose any option from the above options press any number if not press zero\n");
    scanf("%d",&z);
     if(z)
            {
    printf("Choose one of the following options by entering the character beside it\n");
    printf("insert first:a\tinsert end:b\tinsert in the middle index:c\n");
    printf("insert by choosing index:d\tprint all the list:e\n");
                        scanf(" %c",&r);
            }
         break;
    }


    }}
   printList(head);
    
    
    return 0;
}



