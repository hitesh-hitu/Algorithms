#include "survival_of_the_fittest.hpp"
#include <vector>
#include <iostream>
using namespace std; 

 
  	
class survival_of_the_fittest_implementation : public survival_of_the_fittest
{
public:
    	vector<double> solve(int, int, int);
 	void make_table(void);
	vector<double> x;
	vector<vector<double>> y;
	vector<vector<vector<double>>> z;
	vector<vector<vector<vector<double>>>> dp;
 	vector<double> cal(int,int,int);
 	double cal1;
	vector<double> g1,g2;
	double total;
}; 




void survival_of_the_fittest_implementation :: make_table(void)
{
 for(int i=0; i<3; i++)
 {

	x.push_back(0);
 }
 for(int j=0; j<101; j++)
 {
	y.push_back(x);
 }
 for(int k=0; k<101; k++)
 {
	z.push_back(y);
 }
 for(int l =0; l<101; l++)
 {
	dp.push_back(z);
 }

}
vector<double> survival_of_the_fittest_implementation::cal(int a,int p,int k)
{	double total=a*p + p*k + k*a;
	if(a==p && p==k && k==a && a==0)
	{	g1.clear();
		g1.push_back(0);
		g1.push_back(0);
		g1.push_back(0);
		/*g1.push_back((a*k)/total);
		g1.push_back((p*a)/total);
		g1.push_back((p*k)/total);*/
   		return g1;
   	}
   	else
   	{    	g1.clear();
   		if(a==0)
   		{ 	
   			if(p!=0)
   			{	g1={0,1,0};
   				//g1.push_back(0);
				//g1.push_back(1);
				//g1.push_back(0);
				
   			}
   			else
   			{	g1={0,0,1};
   				/*g1.push_back(0);
				g1.push_back(0);
				g1.push_back(1);*/
				
			}
			return g1;
		}
		
		if(p==0)
   		{	
   			if(k!=0)
   			{	g1 = {0,0,1};
   				/*g1.push_back(0);
				g1.push_back(0);
				g1.push_back(1);*/
   			}
   			else
   			{	g1 = {1,0,0};
   				/*g1.push_back(1);
				g1.push_back(0);
				g1.push_back(0);*/
			}
			return g1;
		}
		
		if(k==0)
   		{		
   			if(a!=0)
   			{	g1 = {1,0,0};
   				/*g1.push_back(1);
				g1.push_back(0);
				g1.push_back(0);*/
   			}
   			else
   			{	g1 = {0,1,0};
   				/*g1.push_back(0);
				g1.push_back(1);
				g1.push_back(0);*/
			}
			return g1;
		}
		
		else
		{
		 double total=a*p + p*k + k*a;
		 
		 for(int i=0; i<3; i++)
		 {	cal1 = k*a*dp[a-1][p][k][i] + a*p*dp[a][p-1][k][i] + p*k*dp[a][p][k-1][i];
		 	g1.push_back(cal1/total);
		 }
		 return g1;
	        }
	}
}	

vector<double> survival_of_the_fittest_implementation:: solve(int a,int p,int k)
{	int i,j,l;
	make_table();
	for ( i=0; i<a+1; i++)
	{
		for( j=0; j<p+1; j++)
		{
			for( l=0 ; l<k+1; l++)
			{	
				dp[i][j][l]=cal(i,j,l);
				

				
			}

		
		}

	}
	return dp[a][p][k];
}


