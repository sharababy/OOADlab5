#include <iostream>

using namespace std;

#define MAT_SIZE 5

int current;

void complementGraph(int matrix[MAT_SIZE][MAT_SIZE]);

void maxVertex(int matrix[MAT_SIZE][MAT_SIZE],int maxVertexList[]);

void resetMatrix(int matrix[MAT_SIZE] ,int value);

void printResult(int matrix[MAT_SIZE]);

int findMax(int sumArray[]);

int erase(int sumArray[],int max,int matrix[MAT_SIZE][MAT_SIZE]);

void complementArray(int definiteVertex[],int finalSet[]);

void fillSet(int finalSet[]);


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
    int finalSet[MAT_SIZE]; // matrix containing complement of definiteVertex

    /* Start Algo*/


        /*Step 0*/complementGraph(matrix);

          for (int i = 0; i < MAT_SIZE; ++i)
        {
            for (int j = 0; j < MAT_SIZE; ++j)
            {
                cout<<matrix[i][j]<<",";
            }
            cout<<endl;
        }
    /*Step 1*/resetMatrix(definiteVertex , -1);
    /*Step 2*/maxVertex(matrix,definiteVertex);
    /*Step 4*/fillSet(finalSet);
    /*Step 5*/complementArray(definiteVertex,finalSet);
    /*Step 6*/printResult(finalSet);

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
    if (max != 0)
    {
        maxVertexList[current] = erase(sumArray,max,matrix);
        current++;
        maxVertex(matrix,maxVertexList); 
    }
    else{
    	   	
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

    cout<<"Max Friend Set : ";

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


void complementArray(int definiteVertex[],int finalSet[])
{

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        finalSet[ definiteVertex[i] ] = -1;
    }


}


void fillSet(int finalSet[]){

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        finalSet[i] = i;
    }
}


void complementGraph(int matrix[MAT_SIZE][MAT_SIZE])
{

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = 0; j < MAT_SIZE; ++j)
        {

            if (i!=j)
            {
                if (matrix[i][j] == 1)
                {
                    matrix[i][j] = 0;
                }
                else{
                    matrix[i][j] = 1;

                }
            }
        }
    }
}

