#include <iostream>
using namespace std;

int main(){
    int arr[] = {5,4,3,2,1};
    int target = 5,sum;

    for (int i = 0; i < 5; i++)
    {
        sum = 0;
        for (int j = i+1; j < 5; j++)
        {
            sum = i+j;
            if (sum == target)
            {
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            }
            
        }
        
    }
    
}
