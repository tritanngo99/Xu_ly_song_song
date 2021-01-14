#include<bits/stdc++.h>
#include<pthread.h>
#include <unistd.h>
using namespace std;
#define ll long long 
#define NUM_THREADS 8
void* f(void* thread_id){
	ll id;
	id = (ll) thread_id;
	printf("HW! Thread ID, %lld\n",id);
	pthread_exit(NULL);
}
int main(){
	//freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	pthread_t threads[NUM_THREADS];
	ll rc;
	ll i;
	for(i=0;i<NUM_THREADS;i++){
		cout<<"Main(): creating thread, "<<i<<endl;
		rc= (ll)pthread_create(&threads[i],NULL,f,(void*)i);
		pthread_join(threads[i],NULL);
		if(rc){
			cout<<"fail";
			exit(-1);
		}
	}
	sleep(1);
	cout<<"Time : "<<clock()*1000/CLOCKS_PER_SEC<<"ms\n";
	pthread_exit(NULL);
	return 0;
}
