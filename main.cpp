#include <iostream>
#include <vector>
using namespace std;
void gray(int n, vector<string>& list){
    //终止条件
    if (n == 1){
        list[0] = "0";
        list[1] = "1";
        return;
    }

    //递归
    gray(n-1,list);

    //生成下方对称数组
    for (int i = pow(2,n-1); i < pow(2, n); ++i) {
        list[i] = list[pow(2,n)-1-i];
    }

    //上半部分球迷添加0
    for (int i = 0; i < pow(2, n - 1); ++i) {
        list[i] = "0"+list[i];
    }
    //下半部分前面添加1
    for (int i = pow(2, n - 1); i < pow(2, n); ++i) {
        list[i] = "1"+list[i];
    }
}

int main(){
    int n;
    cout<<"请输入格雷码位数:";
    cin >> n;
    vector<string> list(pow(2,n));

    gray(n,list);
    
    for(auto s :list){
        cout<<s<<endl;
    }
    
    return 0;
}