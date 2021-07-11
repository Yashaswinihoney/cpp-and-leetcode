/*#include<iostream>
using namespace std;

int search(int arr[],int s, int e, int x){
    int i=0;
    for(int i=s;i<e;i++){
        if(arr[i]==x) 
            return i;
    }
    return i;
}
int preindex=0;

void postorder(int in[], int pre[], int s, int e){
    if(s>e){
        return;
    }
    int index=search(in, s,e,pre[index++]);
    postorder(in, pre,s,index-1);
    postorder(in, pre,index+1, e);
    cout<<in[index++]<<" ";
}

int main(){
    int in[]={4,2,5,1,3,6};
    int pre[]={1,2,3,5,3,6};
    int n=6;
    postorder(in, pre,0,n-1);
    return 0;
}*/
// C++ program to print Postorder
// traversal from given Inorder
// and Preorder traversals.
#include <iostream>
using namespace std;

int preIndex = 0;

int search(int arr[], int startIn,int endIn, int data)
{
	int i = 0;
	for (i = startIn; i < endIn; i++)
	{
		if (arr[i] == data)
		{
			return i;
		}
	}
	return i;
}
void printPost(int in[], int pre[],int inStrt, int inEnd)
{
	if (inStrt > inEnd)
	{
		return;
	}

	// Find index of next item in preorder
	// traversal in inorder.
	int inIndex = search(in, inStrt, inEnd,pre[preIndex++]);

	// traverse left tree
	printPost(in, pre, inStrt, inIndex - 1);

	// traverse right tree
	printPost(in, pre, inIndex + 1, inEnd);

	// print root node at the end of traversal
	cout << in[inIndex] << " ";
}

// Driver code
int main()
{
	int arr[] = {4, 2, 5, 1, 3, 6};
	int pre[] = {1, 2, 4, 5, 3, 6};
	int len = sizeof(arr)/sizeof(arr[0]);
	printPost(arr, pre, 0, len - 1);
}

// This code is contributed by SHUBHAMSINGH10

