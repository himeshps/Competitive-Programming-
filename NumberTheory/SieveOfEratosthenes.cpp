int is_prime[1000001]

void seive(){
	int maxN=1000000;

	for(int i=1;i<=maxN;++i){isPrime[i]=1;}

	for(int i=2;i*i<=maxN;++i){
		if(is_prime[i]){
			for(int j=i*i;j<=maxN;j+=i){
				isPrime[j]=0;
			}
		}
	}
}

//O(N log(log N)) Time Complexity
