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

struct student *claass ; int N ;
void makingdynamicarray ()
{
    claass=(struct student*) calloc ((N),sizeof(struct student)) ;
    for (int i=0;i<=N-1;i++)
    {
        printf("Enter the student name: ") ;
        scanf("%s",(claass+i)->stname) ;
        printf("Enter the student id: ") ;
        scanf("%d",&(claass+i)->stid) ;
        printf("Enter the student birthday: ") ;
        scanf("%d",&(claass+i)->stbirthday) ;
        printf("Enter the student birth month: ") ;
        scanf("%d",&(claass+i)->stbirthmon) ;
        printf("Enter the student birth year: ") ;
        scanf("%d",&(claass+i)->stbirthyear) ;
        printf("Enter the student last year score: ") ;
        scanf("%d",&(claass+i)->stscore) ;
        printf("\n\n") ;
    }
}
void insertbegin ()
{   N++ ;
    realloc(claass, sizeof(struct student)*(N)) ;
    int i ;
    for (i=N-1;i>=1;i--)
    {
        claass[i]=claass[i-1] ;
    }
        printf("Enter the student name: ") ;
        scanf("%s",(claass[0]).stname) ;
        printf("Enter the student id: ") ;
        scanf("%d",&(claass[0]).stid) ;
        printf("Enter the student birthday: ") ;
        scanf("%d",&(claass[0]).stbirthday) ;
        printf("Enter the student birth month: ") ;
        scanf("%d",&(claass[0]).stbirthmon) ;
        printf("Enter the student birth year: ") ;
        scanf("%d",&(claass[0]).stbirthyear) ;
        printf("Enter the student last year score: ") ;
        scanf("%d",&(claass[0]).stscore) ;
        printf("\n\n") ;
}
void insertend ()
{       N++ ;
        realloc(claass, sizeof(struct student)*(N)) ;
        printf("Enter the student name: ") ;
        scanf("%s",(claass[N-1]).stname) ;
        printf("Enter the student id: ") ;
        scanf("%d",&(claass[N-1]).stid) ;
        printf("Enter the student birthday: ") ;
        scanf("%d",&(claass[N-1]).stbirthday) ;
        printf("Enter the student birth month: ") ;
        scanf("%d",&(claass[N-1]).stbirthmon) ;
        printf("Enter the student birth year: ") ;
        scanf("%d",&(claass[N-1]).stbirthyear) ;
        printf("Enter the student last year score: ") ;
        scanf("%d",&(claass[N-1]).stscore) ;
        printf("\n\n") ;
}
void insertmid ()
{   if(N<=1){printf("There is no middle\n\n") ; return ;} ;
    N++ ; int k ;printf("Enter the position you want:") ; scanf("%d",&k) ;printf("\n\n") ;
   realloc(claass, sizeof(struct student)*(N)) ;
    int i ;
    for(i=N-1;i>k;i--)
    {
        claass[i]=claass[i-1] ;
    };
        printf("Enter the student name: ") ;
        scanf("%s",(claass[k]).stname) ;
        printf("Enter the student id: ") ;
        scanf("%d",&(claass[k]).stid) ;
        printf("Enter the student birthday: ") ;
        scanf("%d",&(claass[k]).stbirthday) ;
        printf("Enter the student birth month: ") ;
        scanf("%d",&(claass[k]).stbirthmon) ;
        printf("Enter the student birth year: ") ;
        scanf("%d",&(claass[k]).stbirthyear) ;
        printf("Enter the student last year score: ") ;
        scanf("%d",&(claass[k]).stscore) ;
        printf("\n\n") ;
}

int main()
{   
    printf("Welcome to our program\n") ;
    int x ;
    printf("Enter the number of students :") ; scanf("%d" ,&N) ;
    makingdynamicarray() ;
    printf("Press\n1)if you want to insert a student at the beginning\n2)if you want to insert at the middle\n3)if you want to insert at the end\n\n") ;
    scanf("%d",&x) ;printf("\n\n") ;
    switch(x){
    case(1):insertbegin() ;break ;
    case(2):insertmid() ; break ;
    case(3):insertend() ;break ;

    };
    for(int i=0;i<=N-1;i++) {
        printf("The name of student %d ",(i+1));printf("is: %s \n",((claass[i])).stname) ;
        printf("The id of student %d ",(i+1));printf("is: %d \n",((claass[i])).stid) ;
        printf("The birthday of student %d ",(i+1));printf("is: %d \n",((claass[i])).stbirthday) ;
        printf("The birth month of student %d ",(i+1));printf("is: %d \n",((claass[i])).stbirthmon) ;
        printf("The birth year of student %d ",(i+1));printf("is: %d \n",((claass[i])).stbirthyear) ;
        printf("The last year score of student %d ",(i+1));printf("is: %d \n\n",((claass[i])).stscore) ;
    }
    return 0;
}
