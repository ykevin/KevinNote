#ifndef	__WALLET_INIT_H__
#define	__WALLET_INIT_H__

#include "config.h"

static volatile int globalCounter = 0;
static int flag = 0;

static int  Init_Serial(void);
static int  Init_System(void);
extern void Buzzer(int n1time, int n2time);
extern void Addr_Generation(Wallet * bdx);

#endif	/*__WALLET_INIT_H__*/
