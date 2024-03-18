#include <iostream>
#include <vector>
using namespace std;
void gray(int n, vector<string>& list){
    if (n == 1){
        list[0] = "0";
        list[1] = "1";
        return;
    }

    gray(n-1,list);

    for (int i = pow(2,n-1); i < pow(2, n); ++i) {
        list[i] = list[pow(2,n)-1-i];
    }

    for (int i = 0; i < pow(2, n - 1); ++i) {
        list[i] = "0"+list[i];
    }
    for (int i = pow(2, n - 1); i < pow(2, n); ++i) {
        list[i] = "1"+list[i];
    }
}

int main(){
    int n;
    cin >> n;
    vector<string> list(pow(2,n));

    gray(n,list);
    
    for(auto s :list){
        cout<<s<<endl;
    }
    
    return 0;
}