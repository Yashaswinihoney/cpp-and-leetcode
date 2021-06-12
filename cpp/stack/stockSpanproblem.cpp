#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> stockspan(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int> > s;
    for(int price=prices.begin();){
        int days=1;
        while (!s.empty() && s.top().first<=price)
        {
            days+=s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}
int main(){
    vector<int> vect;
    vect.push_back(100);
    vect.push_back(80);
    vect.push_back(60);
    vect.push_back(70);
    vect.push_back(60);
    vect.push_back(75);
    vect.push_back(85);
    vector<int> res=stockspan(vect);
    for(auto i : res)
        cout<<i<<" ";
    cout<<"\n";

}