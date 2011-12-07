#include "FSCommon.h"
#include <math.h>

char* itoa (int i) {
	char*  target;
        long l= log10(i);
	target=(char *) malloc(l);
	snprintf(target,l,"%d",i);
	return target;
}
