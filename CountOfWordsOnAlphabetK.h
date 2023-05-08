#include "nctypes.h"

u64 pwr(u64 x, u64 n){
	u64 xx=1;
	for (u64 i = 0; i < n; i+=1)
	{
		xx*=x;
	}
	return xx;
}

void CountOfWordsOnAlphabetK(u64 alphabetLen, u64 wordLen, u64 subAlphabetLen, u64 *count){
	u64 combsOfi=1,combsOfSubi=1,*countOfSubA,*countOfWords,*countOfAllWords;
	countOfSubA=count+0x2000;
	countOfWords=count+0x1000;
	countOfAllWords=count;

	for (u32 i = 0; i < subAlphabetLen; i++)
	{
		combsOfi=combsOfi*(alphabetLen-i)/(i+1);
		countOfSubA[i]=combsOfi;
		
		countOfWords[i]=pwr(i+1,wordLen);

		combsOfSubi=1;
		
		for (u32 n = 0; n < i; n+=1)
		{
			combsOfSubi=combsOfSubi*(i+1-n)/(n+1);
			countOfWords[i]-=countOfWords[n]*combsOfSubi;
		}
		
		countOfAllWords[i]=countOfWords[i]*combsOfi;
	}
}
