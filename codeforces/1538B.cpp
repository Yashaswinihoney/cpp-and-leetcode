#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int len;
    cin>>len;
    while(len--){
        int n;
        cin>>n;

        vector<int> nums;
        int sum=0;
        int avg;

        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            nums.push_back(num);
            sum+=num;
        }

        if(n==1){
            cout<<0<<endl; 
            continue;
        }

        avg=sum/n;
        if(sum%n){
            cout<<-1<<endl;
            continue;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]-avg>0) 
                count++;
        }
        cout<<count<<endl;
    }
    return 0;
}