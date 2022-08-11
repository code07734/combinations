u64 pwr(u64 x, u64 n){
	u64 xx=1;
	for (u64 i = 0; i < n; i+=1)
	{
		xx*=x;
	}
	return xx;
}

u64 *countOfWordsK_LenAlphaBet(u64 m, u64 k, u64 *K, u64 *L){
	if(k>m){return 0;}
	u64 lim=0, z_in_n=1;

	for (u64 n = 0; n < k; n+=1)
	{
		L[n]=pwr(n+1,m);
		K[n]=L[n];

		for (u64 z = 0; z < n; z+=1)
		{
			z_in_n = 1;
			//printf("%llu %llu % llu\n:", (n+1), (n-z), (z+1));

			for(u64 zc=0;zc<(z+1);zc+=1){
				z_in_n*=((n+1)-zc);
				z_in_n/=(zc+1);
			}
			//printf("%llu\n", z_in_n);

			L[n]-=L[z]*z_in_n;
			if(n==(k-1)){
				K[lim]=z_in_n;
				lim+=1;
			}
		}
		K[lim]=1;
	}
	for (u64 i = 0; i < k; i+=1)
	{
		L[i]*=K[i];
	}
	//printf("\n\n");
	return L;
}
