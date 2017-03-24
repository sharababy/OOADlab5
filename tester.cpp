#include <iostream>

using namespace std;

#define MAT_SIZE 5

void removeDuplicates(int definiteVertex[]);

int main(){
	
	int arr[] = {1,2,2,2,4};

	removeDuplicates(arr);
	removeDuplicates(arr);

	for (int i = 0; i < MAT_SIZE; ++i)
	{
		cout<<arr[i]<<" ";
	}

}

void removeDuplicates(int definiteVertex[]){

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
