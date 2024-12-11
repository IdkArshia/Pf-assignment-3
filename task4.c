#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int *ratings;
	int totalScore;
	
}Employee;


void inputEmployees(int **ratings,int numEmployees,int numPeriods)
{
	
	int i,j;
	
	for(i=0;i<numEmployees;i++)
	{
		printf("for employee%d:\n",i+1);
		for(j=0;j<numPeriods;j++)
		{
			do
			{
				printf("enter rating for evaluation%d: ",j+1);
			    scanf("%d",*ratings+j+(numPeriods*i));
			    if(*(*ratings+j+(numPeriods*i))>10 || *(*ratings+j+(numPeriods*i))<1)
			    {
			    	printf("invalid input, rating must be between 1 and 10\n");
			    	
				}
			}while(*(*ratings+j+(numPeriods*i))>10 || *(*ratings+j+(numPeriods*i))<1);
			
		}
	}
}

void displayPerformance(int **ratings,int numEmployees,int numPeriods)
{
	printf("\t----------PERFORMANCE CHART----------");
	int i,j;
	for(i=0;i<numEmployees;i++)
	{
		printf("\nemployee%d:\n",i+1);
		for(j=0;j<numPeriods;j++)
		{
			printf("\tevaluation%d: %d\n ",j+1,*(*ratings+j+(numPeriods*i)));
		}
	}
	printf("------------------------------------------------");
}

int findEmployeeOfTheYear(int **ratings,int numEmployees,int numPeriods)
{
	int i,j,maxi;
	int total=0;
	int maxtotal=0;
	for(i=0;i<numEmployees;i++)
	{
		total=0;
		for(j=0;j<numPeriods;j++)
		{
			total=total+(*(*ratings+j+(numPeriods*i)));		
		}
		if(total>maxtotal)
		{
			maxtotal=total;
			maxi=i;
		}		
	}
	return maxi;
	
}

int findHighestRatedPeriod(int **ratings,int numEmployees,int numPeriods)
{
	int i,j,maxP;
	int maxTotal=0;
	int total=0;
	for(i=0;i<numEmployees;i++)
	{
		total=0;
		for(j=0;j<numPeriods;j++)
		{
			total=total+ (*(*ratings +i+(numPeriods*j)));
		}
		if(total>maxTotal)
		{
			maxTotal=total;
			maxP=j;
		}
	}
	return maxP;
}

int findWorstPerformingEmployee(int **ratings,int numEmployees,int numPeriods)
{
	int i,j,Li;
	int total=0;
	int Ltotal=30;
	for(i=0;i<numEmployees;i++)
	{
		total=0;
		for(j=0;j<numPeriods;j++)
		{
			total=total+(*(*ratings+j+(numPeriods*i)));		
		}
		if(total<Ltotal)
		{
			Ltotal=total;
			Li=i;
		}		
	}
	return Li;
	
}
int main()
{
	
	int numEmployees, numPeriods,i,j;
	printf("enter number of employees: ");
	scanf("%d",&numEmployees);
	printf("enter number of evaluations: ");
	scanf("%d",&numPeriods);
	Employee emp;
	emp.ratings=(int*)calloc(numEmployees * numPeriods, sizeof(int));
	inputEmployees(&emp.ratings,numEmployees,numPeriods);
	displayPerformance(&emp.ratings,numEmployees,numPeriods);
	int bestemp=findEmployeeOfTheYear(&emp.ratings,numEmployees,numPeriods);
	printf("\nemployee of the year is employee no.%d\n",bestemp+1);
	int worstEmp = findWorstPerformingEmployee(&emp.ratings,numEmployees,numPeriods);
	printf("Worst performing employee is employee no.%d\n",worstEmp+1);
	int bestRating = findHighestRatedPeriod(&emp.ratings,numEmployees,numPeriods);
	printf("Highest rated period was period no.%d",bestRating);
	free(emp.ratings);
	
}

