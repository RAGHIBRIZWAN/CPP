#include <iostream>
using namespace std;

void recsum(int arr[],int size,int targetSum,int i,int j){

    if (i > size - 1) {
        return;
    }

    if (j > size) {
        ++i;
        j = i + 1;
    }

    if (arr[i]+arr[j] == targetSum)
    {
        cout<<"("<<i<<","<<j<<")";
    }
    else{
        recsum(arr,size,targetSum,i,j+1);
    }
    
}

int main(){
    int arr[] = {1,2,3,4,5};
    int target = 7;

    recsum(arr,5,target,0,1);
    return 0;
}
