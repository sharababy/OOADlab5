#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define MAT_SIZE 5

int current;

void maxVertexG1(int matrix[],int definiteVertex[]);

void printResultG1(int matrix[]);

void resetMatrixG1(int matrix[] ,int value);

void checkTriangleG1(int matrix[],int definiteVertex[]);

int matContainsG1(int matrix[] , int check1, int check2);


void maxVertexG2(int matrix[MAT_SIZE][MAT_SIZE],int maxVertexList[]);

void resetMatrixG2(int matrix[MAT_SIZE] ,int value);

void printResultG2(int matrix[MAT_SIZE]);

int findMaxG2(int sumArray[]);

int eraseG2(int sumArray[],int max,int matrix[MAT_SIZE][MAT_SIZE]);


int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int matrix2[MAT_SIZE][MAT_SIZE];

    int matrix1[MAT_SIZE*MAT_SIZE];

    for (int k = 0; k < 20; ++k)
    {

    	cout<<endl<<endl<<"Graph "<<k<<endl;

		for (int i = 0; i < MAT_SIZE; ++i)
		{
			for (int j = i; j < MAT_SIZE; ++j)
			{
				if (i==j)
				{
					matrix2[i][j] = 0;
				}
				else{
					matrix2[i][j] = rand()%2;
				}
				
				matrix2[j][i] = matrix2[i][j];
				matrix1[MAT_SIZE*i + j] = matrix2[i][j];
				matrix1[MAT_SIZE*j + i] = matrix2[i][j];
			}
		}    
		
		for (int i = 0; i < MAT_SIZE; ++i)
		{
			for (int j = 0; j < MAT_SIZE; ++j)
			{
				cout<<matrix2[i][j]<<",";
			}
			cout<<endl;
		}



    int definiteVertex[MAT_SIZE];

    /*Greedy1*/
	current = 0;

    /*Step 1*/resetMatrixG1(definiteVertex , -1);
    /*Step 2*/maxVertexG1(matrix1,definiteVertex);
    /*Step 3*/checkTriangleG1(matrix1,definiteVertex);
    cout<<" Greedy 1: "<<endl;
    /*Step 4*/printResultG1(definiteVertex);


    /*Greedy2*/
    current = 0;

    /*Step 1*/resetMatrixG2(definiteVertex , -1);
    /*Step 2*/maxVertexG2(matrix2,definiteVertex);
    cout<<" Greedy 2: "<<endl;
    /*Step 3*/printResultG2(definiteVertex);

	}

	return 0;
}


void maxVertexG1(int matrix[],int maxVertexList[]){

    int sum=0,max=0;

    current=0;

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        sum = 0;
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            sum += matrix[(MAT_SIZE*i) + j];
        }

        if (sum == max)
        {            
            maxVertexList[current] = i;
            current++;
        }
        else if(sum > max){

            for (int j = 0; j < MAT_SIZE; ++j)
            {
                maxVertexList[j] = -1;
            }
            maxVertexList[0] = i;
            current = 1;
            /*cout<<i<<" : "<<sum<<endl;*/
            max = sum;
        }
    }

    //printResult(maxVertexList);

}

void checkTriangleG1(int matrix[],int definiteVertex[]){


    /*

    for each edge (u, v):
        for each vertex w:
            if (v, w) is an edge and (w, u) is an edge:
                return true
    return false
    
    */

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            if ( (matrix[MAT_SIZE*i +j]) == 1)
            {
                // i,j is an edge

                if (matContainsG1(definiteVertex,i,j) == 0)
                {
                    definiteVertex[current] = i;
                    current++;
                }
                
            }
        }
    }
}

void printResultG1(int matrix[]){

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

void resetMatrixG1(int matrix[] ,int value){

        for (int i = 0; i < MAT_SIZE; ++i)
    {
       
            matrix[i] = value;
        
    }

}


int matContainsG1(int matrix[] , int check1, int check2){

    int one=0,two=0,value;

    for (int i = 0; i < MAT_SIZE; ++i)
    {
            value = matrix[i];
            if ( value == check1)
            {
                one = 1;
            }
            else if (value == check2)
            {
                two = 1;
            }
        
    }

    if (one == 1  && two == 1 )
    {
        return 1;
    }
    else if(one == 1  && two == 0 ){
        return 2;
    }
    else if(one == 0  && two == 1 ){
        return 3;
    }

    return 0;
}



void maxVertexG2(int matrix[MAT_SIZE][MAT_SIZE],int maxVertexList[]){

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
    max =findMaxG2(sumArray);
    if (max != 0)
    {
        maxVertexList[current] = eraseG2(sumArray,max,matrix);
        current++;
        maxVertexG2(matrix,maxVertexList); 
    }
    else{
    	   	
    }

    //printResult(maxVertexList);

}


void resetMatrixG2(int matrix[MAT_SIZE] ,int value){

    for (int i = 0; i < MAT_SIZE; ++i)
    {   	  
            matrix[i] = value;
    }

}

void printResultG2(int matrix[MAT_SIZE]){

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

int findMaxG2(int sumArray[]){

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

int eraseG2(int sumArray[],int max,int matrix[MAT_SIZE][MAT_SIZE]){

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
