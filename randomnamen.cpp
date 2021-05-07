
#include <stdio.h>
#include <stdlib.h>
#include "randomnamen.h"


int *makerandomlist(int howmany)
{
	int *sourcetable;
	int *resulttable;
	int choice;

	//hieronder reserveer ik een gedeelte van het geheugen voor de 'sourcetable'. Het gedeelte van het geheugen wat ik reserveer is zo groot als 'howmany * het aantal bytes nodig voor een integer.
	sourcetable = (int *)malloc(howmany * sizeof(int));
	resulttable = (int *)malloc(howmany * sizeof(int));
	//(! (sourcetable !=0) is hetzelfde als (!sourcetable)
	if ((! (sourcetable != 0)) || (!resulttable))
	{
		printf ("out of memory");
		abort();
	}


	// vullen van de sourcetable;  een aantal keer(beginconditie;eindconditie; tussenstap)
	for (int i = 0;i < howmany; i++)
	{
		//*(sourcetable + i) = i; is het zelfde als:
		sourcetable[i] = i;	
	}
	
	//vullen van de resulttable
	for (int i = 0;i < howmany; i++) 
	{
	//een random plaats in de sourcetable kiezen en op plaats i in de resulttable zetten
		choice = rand() %(howmany - i);
		resulttable[i] = sourcetable[choice];
		//aansluiten van de sourcetable
		for (int j = choice; j < (howmany - 1 -i);j++)
		{
			sourcetable[j] = sourcetable[j+1];

		}

	}

	free(sourcetable);

	return resulttable;
}

char const *getextensie (char const *oldname)
{
	char const *ext;
	
	ext = oldname;
	
	while (*ext)
	{
		ext++;
	}

	while ((ext > oldname)&& (*ext !='.'))
	{
		ext--;
	}
	return ext;
}



char *makename (char const *foldername,int nr, char const *extensie)
{
	char *name;
	
	name = (char *)malloc (2000*sizeof(char));
	if (!name)
	{
		printf ("out of memory");
		abort();
	}

	sprintf (name,"%s/%08d%s", foldername,nr,extensie);
	return name;
}

