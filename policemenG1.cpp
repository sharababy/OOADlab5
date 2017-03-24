#include <iostream>

using namespace std;

#define MAT_SIZE 5

int current;

void maxVertex(int matrix[],int definiteVertex[]);

void printResult(int matrix[]);

void resetMatrix(int matrix[] ,int value);

void checkTriangle(int matrix[],int definiteVertex[]);

int matContains(int matrix[] , int check1, int check2 ,int check3);

void removeDuplicates(int definiteVertex[]);

int main(int argc, char const *argv[])
{
        
    int matrix[] = {

0, 1, 1, 0, 1, 
1, 0, 0, 1, 1, 
1, 0, 0, 1, 1, 
0, 1, 1, 0, 1, 
1, 1, 1, 1, 0
    
    };



    int definiteVertex[MAT_SIZE];

    /* Start Algo*/

    /*Step 1*/resetMatrix(definiteVertex , -1);
    /*Step 2*/maxVertex(matrix,definiteVertex);
    /*Step 3*/checkTriangle(matrix,definiteVertex);
    /*Step 4*/removeDuplicates(definiteVertex);
    /*Step 5*/printResult(definiteVertex);

    /*End Algo*/

    return 0;
}

void maxVertex(int matrix[],int maxVertexList[]){

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

void checkTriangle(int matrix[],int definiteVertex[]){


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

                        int ch1 = matContains(definiteVertex,i,j,k);

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
                    }
                }
            }
        }
    }
}

void printResult(int matrix[]){

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

void resetMatrix(int matrix[] ,int value){

        for (int i = 0; i < MAT_SIZE; ++i)
    {
       
            matrix[i] = value;
        
    }

}


int matContains(int matrix[] , int check1, int check2 ,int check3){

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


void removeDuplicates(int definiteVertex[]){

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        for (int j = i+1; j < MAT_SIZE; ++j)
        {
            if (definiteVertex[i] == definiteVertex[j])
            {
                definiteVertex[j] = -1;
            }
        }
    }
}
