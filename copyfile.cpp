#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "copyfile.h"



int copyfile(char const *fromfile, char const *tofile)
{
	char buffer[5000];

	sprintf(buffer, "cp %s %s", fromfile,tofile);

	return system(buffer);
}
