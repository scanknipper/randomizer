#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "randomnamen.h"
#include "copyfile.h"



int main(int argc, char **argv)
{
	int *randomnummers;
	char const *foldername = "randomized";
	char const *extensie;
	FILE *outputfile;
	char *randomname;

	if (argc <= 1)
	{
		printf("uitleg\n");
		exit(0);	
	} 

	if (mkdir(foldername, S_IRWXU | S_IRWXG | S_IRWXO))
	{
		printf("cannot make folder 'randomized'\n");
		exit(1);	
	}



	outputfile = fopen("randomized/mapping.txt", "w");

	if (!outputfile)
	{
		printf("cannot open mapping\n");
		exit(1);
	}

	randomnummers = makerandomlist(argc - 1);
	
	for (int i = 1; i < argc; i++)
	{
		extensie = getextensie (argv[i]);
		randomname = makename(foldername, randomnummers[i-1], extensie);
		copyfile(argv[i], randomname);	
		fprintf(outputfile,"%08d\t%s\n",randomnummers[i-1],argv[i]);
		free(randomname);	
	}
	fclose(outputfile);
	free(randomnummers);
	return 0;

}
