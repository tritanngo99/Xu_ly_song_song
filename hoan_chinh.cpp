#include<bits/stdc++.h>
#include<pthread.h>
#include <unistd.h>
using namespace std;
#define ll long long 
//#define NUM_THREADS 2
#define maxn 1200000
#define _step (ll)(maxn/NUM_THREADS)
ll mang_so_luong_luong[5]={1,2,4,6,8};
ll NUM_THREADS;
struct boba{
	ll a;
	ll b;
	ll c;
} mang[maxn];
void* f(void* thread_id){
	ll id;
	id = (ll) thread_id;
	for(ll k=id*_step;k<(id+1)*_step;k++) mang[k].c=mang[k].a+mang[k].b;
	printf("Hello from thread %lld of %lld\n",id,NUM_THREADS);
	return NULL;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(ll j=0;j<maxn;j++) scanf("%lld",&mang[j].a);
	for(ll j=0;j<maxn;j++) scanf("%lld",&mang[j].b);
	
//	for(ll j=0;j<5;j++) printf("%lld ",mang[j].a);
//	printf("\n");
//	for(ll j=0;j<5;j++) printf("%lld ",mang[j].b);
//	printf("\n");
	for(ll z=1;z<=5;z++){
	printf("Voi so luong luong la: %lld\n",mang_so_luong_luong[z-1]);
	NUM_THREADS = mang_so_luong_luong[z-1];
	pthread_t threads[NUM_THREADS];
	ll rc;
	ll i;
	for(i=0;i<NUM_THREADS;i++){
		rc= (ll)pthread_create(&threads[i],NULL,f,(void*)i);
		if(rc){
			cout<<"fail";
			exit(-1);
		}
	}
	for(i=0;i<NUM_THREADS;i++){
		pthread_join(threads[i],NULL);
	}
//	sleep(1);
	for(ll k=0;k<maxn;k++) printf("%lld ",mang[k].c);
	printf("\n");
	cout<<"Time : "<<clock()*1000/CLOCKS_PER_SEC<<"ms\n";
	cout<<"------------------------\n";
	}
	pthread_exit(NULL);
	return 0;
}
