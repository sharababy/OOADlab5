#include <iostream>

using namespace std;

#define MAT_SIZE 5

int current;

void maxVertex(int matrix[MAT_SIZE][MAT_SIZE],int maxVertexList[]);

void resetMatrix(int matrix[MAT_SIZE] ,int value);

void printResult(int matrix[MAT_SIZE]);

int findMax(int sumArray[]);

int erase(int sumArray[],int max,int matrix[MAT_SIZE][MAT_SIZE]);

int main(int argc, char const *argv[])
{
	current = 0;
	int matrix[MAT_SIZE][MAT_SIZE] = {

			{0, 1, 1, 0, 1}, 
			{1, 0, 0, 1, 1}, 
			{1, 0, 0, 1, 1}, 
			{0, 1, 1, 0, 1}, 
			{1, 1, 1, 1, 0}
    
    };

    int definiteVertex[MAT_SIZE];

    /* Start Algo*/

    /*Step 1*/resetMatrix(definiteVertex , -1);
    /*Step 2*/maxVertex(matrix,definiteVertex);
    /*Step 3*/printResult(definiteVertex);

    /*End Algo*/


	return 0;
}


void maxVertex(int matrix[MAT_SIZE][MAT_SIZE],int maxVertexList[]){

    int sum=0,max;

    int sumArray[MAT_SIZE];


    for (int i = 0; i < MAT_SIZE; ++i)
    {
        sum = 0;
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            sum += matrix[i][j];
        }
        sumArray[i] = sum;

    }
    max =findMax(sumArray);
    cout<<max<<endl;
    if (max != 0)
    {
        maxVertexList[current] = erase(sumArray,max,matrix);
        current++;
        maxVertex(matrix,maxVertexList); 
    }
    else{
    	cout<<"Hello"<<endl;
    	   	
    }

    //printResult(maxVertexList);

}


void resetMatrix(int matrix[MAT_SIZE] ,int value){

    for (int i = 0; i < MAT_SIZE; ++i)
    {   	  
            matrix[i] = value;
    }

}

void printResult(int matrix[MAT_SIZE]){

    cout<<"Policeman On : ";

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        if (matrix[i] != -1)
        {
            cout<<matrix[i]<<" ";
        }
    }
    cout<<endl;


}

int findMax(int sumArray[]){

	int max=sumArray[0];

	for (int i = 0; i < MAT_SIZE; ++i)
	{
		if (max<sumArray[i])
		{
			max = sumArray[i];
		}
	}

	
	return max;
}

int erase(int sumArray[],int max,int matrix[MAT_SIZE][MAT_SIZE]){

	for (int i = 0; i < MAT_SIZE; ++i)
	{
		if (max == sumArray[i])
		{
			for (int j = 0; j < MAT_SIZE; ++j)
			{
				matrix[i][j] = 0;
				matrix[j][i] = 0;
			}

			return i;
		}
	}

	return -1;
}
