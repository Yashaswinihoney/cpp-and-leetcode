/*#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int count=0;
        for(int i=1;i<=n;i++){
            if(floor(log10(i)+1)==1){
                count++;
            }
            else{
                int r=i%10;
                while(i){
                    if(r!=i%10){
                        break;
                    }
                    i=i/10;
                }
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}*/

#include <iostream>

using namespace std;

int main()
{long long t,n,p=0;
cin>>t;
while(t--)
{long long cnt=0,s;
p=9;
    cin>>n;
    while(n>p)
    {p=p*10+9;
    cnt++;}
    s=cnt*9+n/(p/9);
    cout<<s<<'\n';

}
    return 0;
}
