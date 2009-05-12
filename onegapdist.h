#ifndef ONEGAPDIST_H
#define ONEGAPDIST_H
/*
 *  onegapdist.h
 *  Mothur
 *
 *  Created by Sarah Westcott on 5/7/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "dist.h"


/**************************************************************************************************/

class oneGapDist : public Dist {
	
public:
	void calcDist(Sequence A, Sequence B){
		
		int difference = 0;
		int openGapA = 0;
		int openGapB = 0;
		int minLength = 0;
		int start = 0;
		
		for(int i=0;i<A.getLength();i++){
			if(A.getUnaligned()[i] == '.' && B.getUnaligned()[i] == '.'){
			}
			else{
				start = i;
				break;
			}
		}
		for(int i=start;i<A.getLength();i++){
			if((A.getUnaligned()[i] == '-' || B.getUnaligned()[i] == '-') && (A.getUnaligned()[i] == '.' || B.getUnaligned()[i] == '.')){}
			else if(A.getUnaligned()[i] == '-' && B.getUnaligned()[i] != '-' && B.getUnaligned()[i] != '.'){
				if(openGapA == 0){
					difference++;
					minLength++;
					openGapA = 1;
					openGapB = 0;
				}
			}
			else if(A.getUnaligned()[i] != '-' && B.getUnaligned()[i] == '-' && A.getUnaligned()[i] != '.'){
				if(openGapB == 0){
					difference++;
					minLength++;
					openGapA = 0;
					openGapB = 1;
				}
			}
			else if(A.getUnaligned()[i] != '-' && B.getUnaligned()[i] != '-'){
				if(A.getUnaligned()[i] != B.getUnaligned()[i]){
					difference++;
					minLength++;
					openGapA = 0;
					openGapB = 0;
				}
				else{
					minLength++;
					openGapA = 0;
					openGapB = 0;
				}
			}
			else if(A.getUnaligned()[i] == '.' && B.getUnaligned()[i] == '.'){
				break;
			}
		}
		if(minLength == 0)	{	dist = 1.0000;							}
		else				{	dist = (double)difference / minLength;	}
	}
	
};

/**************************************************************************************************/

#endif