/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	
	if (arr == NULL || len <= 0)
		return NULL;
	int i, k = 0, l = 0, temp1, temp2, *a,t;
	res = (int*)malloc(sizeof(int)* 6);
	for (i = 0; i < len - 1;)
	{
		if ((arr[i + 1] * 1.0 / arr[i] * 1.0) == (arr[i + 2] * 1.0 / arr[i + 1] * 1.0))
		{
			t = arr[i + 1] / arr[i];
			temp1 = i;
			for (k = i + 1; (arr[k + 1] * 1.0 / arr[k] * 1.0) == t && k<len - 1; k++);
			temp2 = k;
			i = k;
		}
		else if ((arr[i + 1] - arr[i]) == (arr[i + 2] - arr[i + 1]))
		{
			t = arr[i + 1] - arr[i];
			a[l] = i; l++;
			for (k = i + 1; (arr[k + 1] - arr[k]) == t && k<len - 1; k++);
			a[l] = k; l++;
			i = k;
		}
		else
			i++;
	}
	a[l] = temp1;
	a[l + 1] = temp2;


	return a;

}