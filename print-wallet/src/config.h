#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <wiringPi.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <mntent.h>
#include <sys/vfs.h>
#include <malloc.h>
#include <iconv.h>
#include <iniparser.h>

#define		PRINT	6

#define		TRUE	1
#define		FALSE	0


/*define wallet gpio*/
#define BUTTON_PIN      4
#define LED_PIN         5
#define BUZZER          1

/**/
#define		SIZE	1024

#define CBIT            0x01
#define SBIT		0x02

/*define disk path*/
#define  DISK           "/dev/sd"

#define  PASSWD_PATH	"/home/pi/.wallet/passwd.ini"
#define  PRIV_PATH	"/home/pi/.wallet/priv.ini"

#define  DEBUG		0
#define  TEST    	1


static int s_fd;
static int pflag = 0;

typedef struct {
	int fd;   		//system init fd
	int disk;		//count disk num
	int upass;
//	int onbip38;
	int printnum;   	// print wallet number
	int printcount;
	int onltc;      	// or ltc
	char *privkey; 	 	//btc or ltc privkey
	char *address;   	//btc or ltc address
	char *passwd;    	//bip38 password
	char *inipasswd;     //rand passwd
	char *pbip38;    	//bip38 privkey
	char *udisk[12]; 	//disk  path	
	char *upath;            //wallet.ini file path
	char *title;
	char *corp;        	//corp name
	char *url;              //url name
}Wallet;


#endif /*__CONFIG_H__*/
