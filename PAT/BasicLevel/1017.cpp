/**
 * 1017 A除以B 大数相除
 */ 
#include <iostream>
#include <cstring>
using namespace std;

int main (void){
    char bigNum [1000];
    int real_bignum[1000];
    int devideNum;
    cin>>bigNum>>devideNum;
    int big_num_length=strlen(bigNum);
    
    //将接收到的数组，倒序放到int类型的数组中。
    for(int j=0,i=big_num_length-1;i>0;i--)
        real_bignum[j++]=bigNum[i]-'0';

    return 0;
}