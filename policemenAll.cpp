#include <iostream>

using namespace std;

#define MAT_SIZE 5

int current;

void maxVertexG1(int matrix[],int definiteVertex[]);

void printResultG1(int matrix[]);

void resetMatrixG1(int matrix[] ,int value);

void checkTriangleG1(int matrix[],int definiteVertex[]);

int matContainsG1(int matrix[] , int check1, int check2 ,int check3);

void removeDuplicatesG1(int definiteVertex[]);

void maxVertexG2(int matrix[MAT_SIZE][MAT_SIZE],int maxVertexList[]);

void resetMatrixG2(int matrix[MAT_SIZE] ,int value);

void printResultG2(int matrix[MAT_SIZE]);

int findMaxG2(int sumArray[]);

int eraseG2(int sumArray[],int max,int matrix[MAT_SIZE][MAT_SIZE]);


int main(int argc, char const *argv[])
{
	
	current = 0;
	int matrix2[MAT_SIZE][MAT_SIZE] = {

			{0, 1, 1, 0, 1}, 
			{1, 0, 0, 1, 1}, 
			{1, 0, 0, 1, 1}, 
			{0, 1, 1, 0, 1}, 
			{1, 1, 1, 1, 0}
    
    };

    int matrix1[] = {

0, 1, 1, 0, 1, 
1, 0, 0, 1, 1, 
1, 0, 0, 1, 1, 
0, 1, 1, 0, 1, 
1, 1, 1, 1, 0
    
    };

    int definiteVertex[MAT_SIZE];

    /*Greedy1*/

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

                for (int k = 0; k < MAT_SIZE; ++k)
                {
                    if(
                        
                            (matrix[MAT_SIZE*i + k]) == 1
                            && 
                            (matrix[MAT_SIZE*j + k]) == 1
                    ){
                         // i,j,k are a triangle

                        /*cout<<"i: "<<i<<" j: "<<j<<" k: "<<k;*/

                        int ch1 = matContainsG1(definiteVertex,i,j,k);

                        /*cout<<" val: "<<ch1<<endl;*/

                        if( ch1 == 0){
                            definiteVertex[current] = i;
                            current++;
                            definiteVertex[current] = j;
                            current++;
                        }
                        else if (ch1 == 6)
                        {
                            definiteVertex[current] = j;
                            current++;
                        }
                        else if (ch1 == 5)
                        {

                            definiteVertex[current] = i;
                            current++;
                        }
                        else if (ch1 == 4)
                        {

                            definiteVertex[current] = i;
                            current++;
                        }

                        removeDuplicatesG1(definiteVertex);
                    }
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


int matContainsG1(int matrix[] , int check1, int check2 ,int check3){

    int one=0,two=0,three=0,value;

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
            else if (value == check3)
            {
                three = 1;
            }
        
    }

    if (one == 1  && two == 1 && three == 1)
    {
        return 7;
    }
    else if(one == 1  && two == 0 && three == 0){
        return 6;
    }
    else if(one == 0  && two == 1 && three == 0){
        return 5;
    }
    else if(one == 0  && two == 0 && three == 1){
        return 4;
    }
    else if(one == 1  && two == 1 && three == 0){
        return 3;
    }
    else if(one == 0  && two == 1 && three == 1){
        return 2;
    }
    else if(one == 1  && two == 0 && three == 1){
        return 1;
    }

    return 0;
}


void removeDuplicatesG1(int definiteVertex[]){

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = i+1; j < MAT_SIZE; ++j)
        {
            if (definiteVertex[i] == definiteVertex[j])
            {
               for (int k = j+1; k < MAT_SIZE; ++k)
               {
                    definiteVertex[k-1] = definiteVertex[k];
               }
               definiteVertex[MAT_SIZE-1] = -1;
            }
        }
    }
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
