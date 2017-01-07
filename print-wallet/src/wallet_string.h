#ifndef __WALLET_STRING__
#define __WALLET_STRING__

extern int convert_u2g(char *from_charset, char *to_charset, char *inbuf, int inlen, char *outbuf, int outlen);
extern int Ini_Parser(dictionary *ini, char *section,  char *keyname, char *key);
extern void strrpl(char* pDstOut, char* pSrcIn, const char* pSrcRpl, const char* pDstRpl);
extern char *Trim(char *src);
extern char *strlwr(char *src)


#endif //__WALLET_STRING__
