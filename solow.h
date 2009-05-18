#ifndef SOLOW_H
#define SOLOW_H

/*
 *  solow.h
 *  Mothur
 *
 *  Created by Thomas Ryabin on 5/13/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "calculator.h"

/* This class implements the solow calculator on single group. 
 It is a child of the calculator class. */

/***********************************************************************/

class Solow : public Calculator  {
	
public: 
	Solow(int size) : m(size), Calculator("solow", 1, false) {};
	EstOutput getValues(SAbundVector*);	
	EstOutput getValues(vector<SharedRAbundVector*>) {return data;};
private:
	int m;
};


/***********************************************************************/

#endif