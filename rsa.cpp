#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gap " "
#define ln endl
// vector<ll>splitM(string m,int s) {
//     vector<ll>chunks;
//     int count = m.length();
//     for (int i = 0; i < count; i+=s){
//         string chunk = m.substr(i,s);
//         chunks.push_back(stoll(chunk));
//         cout<<chunks.back()<<ln;
//     }
//     return chunks;
    
// }


//By the Method of Exponential Squaring (O(log Exp))
ll modExp(ll mes,ll exp,ll n) {
    // cout<<ln<<"Entering"<<ln;
    mes = mes % n;
    ll result = 1;
    while(exp>0) {
        if(exp&1)
            result = (result * mes) % n;
        
        mes = (mes*mes)%n;
        exp = exp >> 1;
    }
    // cout<<result<<ln;
    return result;
}

int main() {
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // cout<<"hello"<<ln;
    string m;
    ll e,d,n;
    cin>>m>>e>>d>>n;
    // cout<<m<<gap<<e<<gap<<d<<gap<<n;
    vector<ll>chunkM;
    int chunkS=to_string(n).length()-1;

    //splitting the message
    // chunkM=splitM(m,chunkS);
    cout<<"Original Message is : "<<m<<ln;

    //splitting the message in anotherway & printing chunk by chunk
    cout<<"Splitting the Message : ";
    for(int i=0;i<m.length();i+=chunkS) {
        string chunk = m.substr(i,chunkS);
        chunkM.push_back(stoll(chunk));
        cout<<chunkM.back()<<gap;
    }
    cout<<ln<<"After Encrytion Chunk by Chunk : ";
    // cout<<ln<<"Total Blocks = "<<chunkM.size();
    vector<ll>chunkE;
    //chunk by chunk encryption : Ci = Mi^e % n;
    for(int i=0;i<chunkM.size();i++) {
        // cout<<ln<<i;
        ll temp = modExp(chunkM[i],e,n);
        chunkE.push_back(temp);
        cout<<chunkE.back()<<gap;
    }

    vector<ll> chunkD;
    cout<<ln<<"After Dencrytion Chunk by Chunk : ";
    //chunk by chunk decryption : Pi = Ci^d % n;
    for(int i=0;i<chunkE.size();i++) {
        // cout<<ln<<i;
        ll temp = modExp(chunkE[i],d,n);
        chunkD.push_back(temp);
        cout<<chunkD.back()<<gap;
    }
    //Altogether The Decrypted Message
    cout<<ln<<"Altogether The Decrypted Message : ";
    for(auto m:chunkD)
        cout<<m;
}