#include "nctypes.h"
//Count number of m-words on alphabet n with exactly k distinct characters
u64 pwr(u64 x, u64 n){
	u64 xx=1;
	for (u64 i = 0; i < n; i+=1)
	{
		xx*=x;
	}
	return xx;
}

void NOfSubStrsWithKdistinctsEls(u64 alphabetLen, u64 wordLen, u64 subAlphabetLen, u64 *numb){
	u64 combsOfi=1,combsOfSubi=1,*NOfSubA,*NOfWords,*NOfAllWords;
	NOfSubA=numb+0x2000;
	NOfWords=numb+0x1000;
	NOfAllWords=numb;

	for (u32 i = 0; i < subAlphabetLen; i++)
	{
		combsOfi=combsOfi*(alphabetLen-i)/(i+1);
		NOfSubA[i]=combsOfi;
		
		NOfWords[i]=pwr(i+1,wordLen);

		combsOfSubi=1;
		for (u32 n = 0; n < i; n+=1)
		{
			combsOfSubi=combsOfSubi*(i+1-n)/(n+1);
			NOfWords[i]-=NOfWords[n]*combsOfSubi;
		}
		
		NOfAllWords[i]=NOfWords[i]*combsOfi;
	}
}
