#ifndef INPUTDATA_H
#define INPUTDATA_H

#include "mothur.h"
#include "ordervector.hpp"
#include "sharedlistvector.h"
#include "sharedordervector.h"
#include "listvector.hpp"


class InputData {
	
public:
	InputData(string, string);
	InputData(string, string, string);
	~InputData();
	ListVector* getListVector();
	SharedListVector* getSharedListVector();
	OrderVector* getOrderVector();
	SharedOrderVector* getSharedOrderVector();
	SAbundVector* getSAbundVector();
	RAbundVector* getRAbundVector();
	vector<SharedRAbundVector*> getSharedRAbundVectors();
	
private:
	string format;
	ifstream fileHandle;
	DataVector* input;
	ListVector* list;
	SharedListVector* SharedList;
	OrderVector* output;
	SharedOrderVector* SharedOrder;
	SAbundVector* sabund;
	RAbundVector* rabund;
	map<string,int> orderMap;
};


#endif
