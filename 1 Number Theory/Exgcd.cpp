#define pii pair<int, int>
pii exgcd(int a, int b){
    if(b == 0) return mp(1, 0);
    pii ans = exgcd(b, a % b);
    return mp(ans.S, ans.F - a / b * ans.S);
}