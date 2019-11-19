#include "../include/dynamic_array.hpp"
#include<stdlib.h>
//#include"main.cpp"
using namespace std;

//Given just for reference. Only the class name and function names should match.
class dynamic_array_implementation : public dynamic_array
{
private:
    int size;
    int capacity;
    int *arr;
    double increase_factor;
    double decrease_factor;

public:
    dynamic_array_implementation();
    int get_size();
    int get_capacity();
    void set_increase_factor_table_size(double);
    void set_load_factor_reduction(double);
    void append(int);
    void pop();
    int get(int);
    ~dynamic_array_implementation();
};


dynamic_array_implementation::dynamic_array_implementation()
{
    size = 0;
    capacity = 0;
    increase_factor = 2;
    decrease_factor = 0.25;
}
int dynamic_array_implementation::get_size()
{
    return size;
}
int dynamic_array_implementation::get_capacity()
{
    return capacity;
}

void dynamic_array_implementation::set_increase_factor_table_size(double increase_factor)
{  
	this->increase_factor=increase_factor;
	return;
}
void dynamic_array_implementation::set_load_factor_reduction(double decrease_factor)
{   
	this->decrease_factor=decrease_factor;
        return;
}

void dynamic_array_implementation::append(int element)
{ 	
	if(capacity==0)
	{
	//set_increase_factor_table_size(increase_factor);
	capacity++;
	arr = (int*)malloc(capacity * sizeof(int));
	}
	else if(size == capacity )
	{
	int *temp;
	capacity=capacity*increase_factor;
	temp = (int*)malloc(capacity*sizeof(int));
	for(int i = 0 ; i<size ; i++)
		{
		temp[i]=arr[i];
		}
	free(arr);
	//set_increase_factor_table_size(increase_factor);
	//arr = (int*)malloc((increase_factor * capacity) * sizeof(int));
	arr = temp;
	//free(temp);
	}
	arr[size++] = element;
}

void dynamic_array_implementation::pop()
{
	if(size > 0)
	{
	size = size-1;
	if(size >0)
	{
		if(size == (capacity * decrease_factor) )
		{
		//set_load_factor_reduction(decrease_factor);
		int *temp;
		capacity = capacity*(decrease_factor * increase_factor);
		temp = (int*)malloc(capacity*sizeof(int));
		for(int i = 0 ; i<size ; i++)
			{
			temp[i]=arr[i];
			}
		free(arr);
		//set_increase_factor_table_size(increase_factor);
		//arr = (int*)malloc(( increase_factor * capacity) * sizeof(int));
		arr = temp;
		
		//free(temp);
		}
	}
	else if(size == 0 )
	{
		capacity =0;
	}
	}
	
}


int dynamic_array_implementation::get(int index)
{
    return *(arr+index);
}

dynamic_array_implementation::~dynamic_array_implementation()
{
    if (capacity > 0)
    {
        delete[] arr;
    }

}
