//////////////////////////////////////////
//score.c
//////////////////////////////////////////
//implémentation des fonctions de gestion 
//du score
//////////////////////////////////////////
//Crée le : 10-10-2015 
//Par : momole02
//////////////////////////////////////////


#include <stdlib.h>
#include <stdio.h>
#include "score.h"
#include "filename.h"

u32 LoadHiScore()
{
	FILE * fp ; 
	u32 score ; 
	
	fp = fopen("data/hi.score" , "rb");
	if(!fp)
	  {
	    char * s_score = buildFilenameFromHome("/.snake/data/hi.score");
	    fp = fopen(s_score,"rb");
	    free(s_score);
	      if(!fp)
		return 0;
	    
	  }
	
	fread(&score , sizeof(u32) , 1 , fp );
	fclose(fp);
	return score ;
	
}

void SaveHiScore(u32 score)
{
	FILE * fp ; 
	
	fp = fopen("data/hi.score" , "wb");
	if(!fp)
	  {
	    char * s_score = buildFilenameFromHome("/.snake/data/hi.score");
	    fp = fopen(s_score,"rb");
	    free (s_score);
	      if(!fp)
		return ;
	  }
		
	fwrite(&score , sizeof(u32) , 1 , fp );
	fclose(fp);
}
