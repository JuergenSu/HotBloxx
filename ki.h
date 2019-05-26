#include "spielfeld.h"
#include "block.h"
#include <iostream>
using namespace std;

#ifndef _KI
#define _KI

class ki_spl
{
private :
	spielfeld* spf;
	block* spb;
public:
	ki_spl(spielfeld* ,block* );
	void setSpielfeld(spielfeld*);
	void setBlock(block*);
	void invoke();
};






#endif