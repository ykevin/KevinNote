
#include "config.h"

extern char *strlwr(char *src)
{
        char *begin;

        begin = src;
    
        while(*src)
        {   
                if(isupper(*src))
                        *src += 32; 
                src++;
        }   

//      printf("begin:%s--\n", begin);
        return begin;
}

extern char *Trim(char *src)
{
        int i;
        char *begin = src;
        while(src[i] != '\0')
        {   
                if(src[i] != ' ')
                        break;
                else
                        begin++;
                i++;
        }   
        for(i = strlen(src) - 1; i >= 0; i--)
        {   
                if(src[i] != ' ')
                        break;
                else
                        src[i] = '\0';
        }   
        return begin;

}

extern void strrpl(char* pDstOut, char* pSrcIn, const char* pSrcRpl, const char* pDstRpl)
{ 
        char* pi = pSrcIn; 
        char* po = pDstOut; 

        int nSrcRplLen = strlen(pSrcRpl); 
        int nDstRplLen = strlen(pDstRpl); 

        char *p = NULL; 
        int nLen = 0;  

        do  
        {   
                p = strstr(pi, pSrcRpl); 
                if(p != NULL) 
                {   
                        nLen = p - pi; 
                        memcpy(po, pi, nLen);

                        memcpy(po + nLen, pDstRpl, nDstRplLen); 
                }   
                else 
                {   
                        strcpy(po, pi); 
                        break;
                }   

                pi = p + nSrcRplLen; 
                po = po + nLen + nDstRplLen; 

        } while (p != NULL); 
}


extern int Ini_Parser(dictionary *ini, char *section,  char *keyname, char *key)
{
	char *find;
	char *value;
	find = malloc(100 * sizeof(char));
	memset(find, 0, 100);
	strcpy(find, section);
	strcat(find, ":");
	strcat(find, keyname);
//	strcat(find, "\0");

	value = iniparser_getstring(ini, find, 	NULL);
	
#if DEBUG
	
	printf("%s vaule %s : %s--------------- \n",find, keyname, value);
#endif
	if((value == NULL) || (strlen(value) > 10))
		return 0;
	else 
	{
		if((strcmp(strlwr(value), key) == 0))
			return -1;
	}
	
	free(find);
	return 0;
}


extern int convert_u2g(char *from_charset, char *to_charset, char *inbuf, int inlen, char *outbuf, int outlen)
{
	iconv_t cd;
	int rc;
	char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open(to_charset,from_charset);
	if (cd==0) 
		return -1;
	memset(outbuf, 0, outlen);
	if (iconv(cd,pin,&inlen,pout,&outlen) == -1)
	{
		printf("kevin is convert_u2g fail\n"); 
		return -1;
	}
	iconv_close(cd);
	return 0;
}
