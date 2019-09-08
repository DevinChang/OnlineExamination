//
// Created by devinchang on 2019/9/7.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;


// 素性检测
bool is_prime(int n){
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0)
            return false;
    }
    return n != 1;
}

// 约数枚举
vector<int> divisor(int n){
    vector<int> res;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i)
                res.push_back(n / i);
        }
    }
}

// 整数分解
map<int, int> prime_factor(int n){
    map<int, int> res;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            ++res[i];
            n /= i;
        }
    }
    if(n != 1)
        res[n] = 1;
    return res;
}


// 埃氏筛法
const int MAX_N = 0x7fffffff;
int prime[MAX_N];
bool isprime[MAX_N];

int seive(int n){
    int p = 0;
    for(int i = 0; i <= n; ++i){
        isprime[i] = true;
    }
    isprime[0] = isprime[1] = false;
    for(int i = 2; i <= n; i++){
        if(isprime[i]){
            prime[p++] = i;
            for(int j = 2 * i; j <= n; j += i){
                isprime[j] = false;
            }
        }
    }
    return p;
}

// 区间筛法
// 思路：b以内的合数的最小质因数一定不超过根号b,先做好[a,根号b)的表和[a,b)的表,然后从[2,根号b)的表中
// 筛得素数的同时,也将其倍数从[a,b)的表中划去,最后剩下的就是区间[a,b)内的素数了
typedef long long ll;
bool isprime2[MAX_N];
bool isprimesmall[MAX_N];

void segment_sieve(ll a, ll b){
    for(int i = 0; (ll)i * i < b; i++)
        isprimesmall[i] = true;
    for(int i = 0; i < b - a; i++)
        isprime2[i] = true;

    for(int i = 2; (ll)i * i < b; i++){
        if(isprimesmall[i]){
            for(int j = 2 * i; (ll)j * j < b; j += i)
                isprimesmall[j] = false;
            for(ll j = max(2LL, (a + i - 1)/ i) * i; j < b; j += i)
                isprime2[j - a] = false;
        }
    }
}


int main(){

    return 0;
}

