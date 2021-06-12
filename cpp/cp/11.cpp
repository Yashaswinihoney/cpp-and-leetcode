/*#include<iostream>
#include<set>
#include<iterator>
#include<cmath>
using namespace std;
int main()
{
    int n;
    set<int> s;
    s.insert(4);
    s.insert(7);
    cin>>n;
    int l=log10(n) +1;
    while (l/10)
    {
        int r=l%10;
        if(s.find(r)!=s.end()){
            
        }
        else{
            cout<<"NO";
            return 0;
        }
        l=l/10;
    }
    cout<<"YES";
    return 0;
}*/

#include <iostream>
int main() {
    int i=0;
    char c;
    while(std::cin >> c)i+=(c=='4'||c=='7');
    std::cout << ((i==4||i==7)?"YES":"NO");
}