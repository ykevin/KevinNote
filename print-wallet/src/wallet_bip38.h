#ifndef	__WALLET_BIP38_H__
#define	__WALLET_BIP38_H__

#include "config.h"

#define PLEN	7

extern int Bip38_Encrypt(Wallet *bdx);
extern void Rand_Password(Wallet *bdx);
static int Bip38_Writefile(Wallet *bdx);
extern int GetDisk_Password(Wallet *bdx, dictionary *ini);
extern void GetDisk_Configfile(Wallet *bdx);
extern void FreeFile();

#endif /*__WALLET_BIP38_H__*/
