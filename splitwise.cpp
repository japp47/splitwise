#include <iostream>
#include <set>
using namespace std;

int main(){

    int no_of_txn, friends;
    cin>>no_of_txn>>friends;

    int x,y,amount;

    //make a 1 d array to srtire the each person will habve to take at the end
    int net[10000] = {0};
    
    while(no_of_txn--){
        cin >>x >> y>> amount;
        net[x]-=amount;
        net[y]+=amount; 
    }

    multiset<int> m; //sorted and elements of same value

    //init a list & sort it
    for(int i = 0; i<friends;i++){
        if(net[i]!=0){
            m.insert(net[i]);
        }
    }
    //pop out two person from left and right and try to settle them
    int count = 0;
    while(!m.empty()){
        auto left = m.begin();
        auto right = prev(m.end()); //m.end()-1

        int debit = *left;
        int credit = *right;

        //erase 
        m.erase(left);
        m.erase(right);
        //settlement
        int settlement = min(-debit, credit);
        count++;
        //settlement amount fro donor to acceptor
        //one of them becomes 0

        debit += settlement;
        credit-= settlement;
        if(debit!=0){
            m.insert(debit);

        }
        if(credit!=0){
            m.insert(credit);
            
        }
    }
    cout << count<<endl;
return 0;

}
