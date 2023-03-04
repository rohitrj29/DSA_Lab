#include "node.h"
BOOL IsLower_GM(int id1, int id2)
{
	int grp1,grp2;
	grp1=id1%10000;
	grp2=id2%10000;
	int mem1,mem2;
	mem1=(id1/10000)%1000;
	mem2=(id2/10000)%1000;
	if(grp1<grp2){
		return TRUE;
	}
	else{
		if(grp1==grp2 && mem1<mem2){
				return TRUE;
		}
		return FALSE;
	}
}
