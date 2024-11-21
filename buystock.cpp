#include<iostream>
#include<vector>
using namespace std;

int maxprofit(vector<int>& prices){
    int maxpro = 0 , bestbuy = prices[0];
        int n = prices.size();
        for(int i =1;i<n;i++){
                if(prices[i]> bestbuy){
                    maxpro = max(maxpro, prices[i] - bestbuy);
                }
                bestbuy = min(bestbuy,prices[i]);
        }
        return maxpro;
}


int main(){
    vector<int> prices = {7,1,2,3,4,5};
    
    cout<<maxprofit(prices);
    return 0;
}