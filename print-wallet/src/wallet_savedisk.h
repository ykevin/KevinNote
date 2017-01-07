#ifndef __WALLET_SAVEDISK_H__
#define __WALLET_SAVEDISK_H__

#define	SRC	" "
#define DST	"\\ "	

#include "config.h"

extern void Detect_Disk(Wallet *bdx);
extern int Savedisk_Addr(Wallet *bdx, int num);
static int Creat_AddrDir(char *disk_path);
extern int SaveDisk_IniFile(Wallet *bdx, int num);
static int Create_Qrencode(char *m_addrcmd, char *m_privcmd, char *addrfile, char *privfile);





#endif  /*__WALLET_SAVEDISK_H__*/
