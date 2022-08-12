#include "nctypes.h"

u64 pwr(u64 x, u64 n){
	u64 xx=1;
	for (u64 i = 0; i < n; i+=1)
	{
		xx*=x;
	}
	return xx;
}

u64 *countOfWordsK_LenAlphaBet(u64 wordLen, u64 alphabetLen, u64 *K, u64 *countOfWords){
	if(alphabetLen>wordLen){return 0;}
	u64 lim=0, z_in_n=1;

	for (u64 n = 0; n < alphabetLen; n+=1)
	{
		countOfWords[n]=pwr(n+1,wordLen);
		K[n]=countOfWords[n];

		for (u64 z = 0; z < n; z+=1)
		{
			z_in_n = 1;
			//printf("%llu %llu % llu\n:", (n+1), (n-z), (z+1));

			for(u64 zc=0;zc<(z+1);zc+=1){
				z_in_n*=((n+1)-zc);
				z_in_n/=(zc+1);
			}
			//printf("%llu\n", z_in_n);

			countOfWords[n]-=countOfWords[z]*z_in_n;
			if(n==(alphabetLen-1)){
				K[lim]=z_in_n;
				lim+=1;
			}
		}
		K[lim]=1;
	}
	for (u64 i = 0; i < alphabetLen; i+=1)
	{
		countOfWords[i]*=K[i];
	}
	//printf("\n\n");
	return countOfWords;
}
