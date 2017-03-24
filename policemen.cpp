#include <iostream>

using namespace std;

#define MAT_SIZE 5

int current;

void maxVertex(int matrix[],int definiteVertex[]);

void printResult(int matrix[]);

void resetMatrix(int matrix[] ,int value);

void checkTriangle(int matrix[],int definiteVertex[]);

int matContains(int matrix[] , int check1, int check2 ,int check3);

int main(int argc, char const *argv[])
{
        
    int matrix[MAT_SIZE * MAT_SIZE] = {

        0,0,0,0,1,0,0,1,1,0,0,1,0,1,1,0,1,1,0,1,1,0,1,1,0
    };



    int definiteVertex[MAT_SIZE];

    /* Start Algo*/

    /*Step 1*/resetMatrix(definiteVertex , -1);
    /*Step 2*/maxVertex(matrix,definiteVertex);
    /*Step 3*/checkTriangle(matrix,definiteVertex);
    /*Step 4*/printResult(definiteVertex);

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
            sum += matrix[MAT_SIZE*i + j];
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

            max = sum;
        }
    }

    printResult(maxVertexList);

}

void checkTriangle(int matrix[],int definiteVertex[]){

    int tri[3];


    /*

    for each edge (u, v):
        for each vertex w:
            if (v, w) is an edge and (w, u) is an edge:
                return true
    return false
    
    */

    for (int i = 0; i < MAT_SIZE; ++i)
    {
        tri[0] = i;
        for (int j = 0; j < MAT_SIZE; ++j)
        {
            if ( (matrix[MAT_SIZE*i] + j) == 1)
            {
                // i,j is an edge
                tri[1] = j;

                for (int k = 0; k < MAT_SIZE; ++k)
                {
                    if(
                        
                            (matrix[MAT_SIZE*i] + k) == 1
                            && 
                            (matrix[MAT_SIZE*j] + k) == 1
                    ){
                         // i,j,k are a triangle

                        int ch1 = matContains(definiteVertex,i,j,k);

                        if( ch1 == 0){
                            definiteVertex[current] = i;
                            current++;
                            definiteVertex[current] = j;
                            current++;
                        }
                        else if (ch1 == 6)
                        {
                            cout<<"He 1"<<endl;
                            definiteVertex[current] = j;
                            current++;
                        }
                        else if (ch1 == 5)
                        {
                            cout<<"He 2"<<endl;

                            definiteVertex[current] = i;
                            current++;
                        }
                        else if (ch1 == 4)
                        {
                            cout<<"He 3"<<endl;

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
        for (int j = 0; j < MAT_SIZE; ++j)
        {

            value = matrix[MAT_SIZE*i + j];
            if ( value == check1)
            {
                one = 1;
            }
            if (value == check2)
            {
                two = 1;
            }
            if (value == check2)
            {
                three = 1;
            }
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