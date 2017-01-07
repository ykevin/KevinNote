
#include "wallet_savedisk.h"


/*detect system usb storage */
extern void Detect_Disk(Wallet *bdx)
{

	FILE* mount_table;
	struct mntent *mount_entry;
	struct statfs s;
	mount_table = NULL;
	
	mount_table = setmntent("/etc/mtab", "r");

	if (!mount_table)
	{
		fprintf(stderr, "set mount entry error\n");
	}

	while (TRUE)
	{
		const char *device;
		const char *mount_point;
		if (mount_table) {
			mount_entry = getmntent(mount_table);
			if (!mount_entry) {
				endmntent(mount_table);
				break;
			}
		}
		else
			continue;
		device = mount_entry->mnt_fsname;
		mount_point = mount_entry->mnt_dir;

		if (statfs(mount_point, &s) != 0)
		{
			fprintf(stderr, "statfs failed!\n");
			continue;
		}
		if(strncmp(device, DISK, strlen(DISK)) == 0)
		{
			bdx->udisk[bdx->disk] = (char *)malloc(1024*sizeof(char));
			memset(bdx->udisk[bdx->disk], 0, 1024);
			strcpy(bdx->udisk[bdx->disk], mount_point);
			strcat(bdx->udisk[bdx->disk], "/");
#if DEBUG
			printf("path : %s\n", bdx->udisk[bdx->disk]);
#endif
			bdx->disk += 1; 
		}
	}
}



static int Creat_AddrDir(char *disk_path)
{
	int count;
	count = 0;
	do{
		if(count == 2)
		{
			fprintf(stderr, "create addr dir fail\n");
			return -1;	
		}
		if(access(disk_path, F_OK | R_OK | W_OK) < 0)
		{
			mkdir(disk_path, 0755);
			count++;
			
		}
		
	}while(access(disk_path, F_OK | R_OK | W_OK) < 0);

	return 0;
}

static int Create_Qrencode(char *m_addrcmd, char *m_privcmd, char *addrfile, char *privfile)
{
	int count, count1;
	char paddr[1024];
	char ppriv[1024];

	/* Disk blank detect*/	
	strrpl(paddr, addrfile, DST, SRC);
	strrpl(ppriv, privfile, DST, SRC);
	

	count = 0;
	count1 = 0;
	do
	{
		if((count == 2) || (count1 == 2))
		{
			fprintf(stderr, "create qrencode image fail\n");
			return -1;
		}
		if(access(paddr, F_OK) < 0)
		{
//			printf("m_addrcmd: %s ----%d\n", m_addrcmd, count);
			system(m_addrcmd);
			count++;
		}
		if(access(ppriv, F_OK) < 0)
		{
//			printf("m_privcmd: %s ----%d\n", m_privcmd, count1);
			system(m_privcmd);
			count1++;
		}
		usleep(1000);	
		
	}while((access(paddr, F_OK) < 0) || (access(ppriv, F_OK) < 0));
	
	return 0;
}

extern int SaveDisk_IniFile(Wallet *bdx, int num)
{
	int count;
	char *ini_path;
	FILE *inifp;
	char *entry;
	char *section = "[address]\r\n";
	
	ini_path = malloc(512 * sizeof(char));
	entry = malloc(128 * sizeof(char));
	memset(ini_path, 0, 512);
	memset(entry, 0, 128);
	strcpy(ini_path, bdx->udisk[num]);
	strcat(ini_path, "address.ini");

	printf("ini_path : %s\n", ini_path);

	count = 0;
	do{
		if(count == 2)
		{
			fprintf(stderr, "create address.ini fail\n");
			return -1;	
		}
		if((inifp = fopen(ini_path, "a+")) == NULL)
			count++;
			
		
	}while(access(ini_path, F_OK) < 0);

	if(bdx->printcount == 0)
	{	
		fwrite(section, strlen(section), 1, inifp);
	}
	sprintf(entry, "addr%d=%s\r\n", bdx->printcount, bdx->address);
#if DEBUG
	printf("entry : %s\n", entry);
#endif
	fwrite(entry, strlen(entry), 1, inifp);
	

	fclose(inifp);
	free(ini_path);
	free(entry);

	return 0;
}

/*save wallet to usb stroage*/
extern int Savedisk_Addr(Wallet *bdx, int num)
{
	FILE *w_fp;
	int count, count1;
	char disk_path[512], text_path[512], addrfile[512], privfile[512];

	/*Qrencode config*/
	char m_addrcmd[512] = "/usr/bin/qrencode -o ";
	char m_privcmd[512] = "/usr/bin/qrencode -o ";
	char m_size[10]=" -s 8 ";

	/*BTC config*/
	char m_text1[100]="######################################################################\r\n";
	char m_text2[100]="## It's time to plan B \r\n";
	char m_text3[100]="## https://bitcoin.org/ \r\n";
	char m_text4[100]="## https://www.bidingxing.com\r\n";
	char m_text5[100]="## https://blockchain.info/address/";
	char m_text6[100]="######################################################################\r\n";
	char m_text7[100]="address=";
	char m_text8[100]="privkey=";
	char m_text9[100]="password=";
	char m_text10[100]="*privkey=";

	/*LTC config*/
	char m_text11[100]="## https://litcoin.org/ \r\n";
	char m_text12[100]="## https://block-explorer.com/address/";	
	char m_text13[100]="\r\n";

	char udisk[1024];


	memset(disk_path, 0, 512);
	memset(text_path, 0, 512);
	memset(addrfile, 0, 512);
	memset(privfile, 0, 512);
	strcpy(disk_path, bdx->udisk[num]);
	strcat(disk_path, bdx->address);
//	printf("disk_path : %s\n", disk_path);

	if(Creat_AddrDir(disk_path) < 0)
	{
		fprintf(stderr, "create addr dir fail\n");
		return -1;
	}

	strcat(disk_path, "/");
	strrpl(udisk, disk_path, SRC, DST);
	strcpy(privfile, udisk);
	strcat(privfile, "Privkey.png");

	strcat(m_privcmd, privfile);
	strcat(m_privcmd, m_size);

	strcpy(addrfile, udisk);
	strcat(addrfile, "Address.png");
	strcat(m_addrcmd, addrfile);
	strcat(m_addrcmd, m_size);

	strcpy(text_path, disk_path);
	strcat(text_path, "Wallet.txt");

	if((w_fp = fopen(text_path, "w")) == NULL)
	{
		perror("fopen:");
		return -1;
	}


	if(bdx->onltc)
	{
		strcat(m_text12, bdx->address);
		strcat(m_text7, bdx->address);

		fprintf(w_fp, "%s", m_text1);
		fprintf(w_fp, "%s", m_text2);
		fprintf(w_fp, "%s", m_text11);
		fprintf(w_fp, "%s", m_text4);
		fprintf(w_fp, "%s", m_text12);
		fprintf(w_fp, "%s", m_text13);
		fprintf(w_fp, "%s", m_text6);
		fprintf(w_fp, "%s", m_text7);
		fprintf(w_fp, "%s", m_text13);
	}
	else
	{
		strcat(m_text5, bdx->address);
		strcat(m_text7, bdx->address);

		fprintf(w_fp, "%s", m_text1);
		fprintf(w_fp, "%s", m_text2);
		fprintf(w_fp, "%s", m_text3);
		fprintf(w_fp, "%s", m_text4);
		fprintf(w_fp, "%s", m_text5);
		fprintf(w_fp, "%s", m_text13);
		fprintf(w_fp, "%s", m_text6);
		fprintf(w_fp, "%s", m_text7);
		fprintf(w_fp, "%s", m_text13);
	}

	if(bdx->upass)
	{
		strcat(m_privcmd, bdx->pbip38);
		strcat(m_text10, bdx->pbip38);
		fprintf(w_fp, "%s", m_text10);
		fprintf(w_fp, "%s", m_text13);
		strcat(m_text9, bdx->passwd);
		fprintf(w_fp, "%s", m_text9);
	}
	else
	{
		strcat(m_privcmd, bdx->privkey);
		strcat(m_text8, bdx->privkey);
		fprintf(w_fp, "%s", m_text8);
		fprintf(w_fp, "%s", m_text13);
	}

	fclose(w_fp);

	strcat(m_addrcmd, bdx->address);
	if(Create_Qrencode(m_addrcmd, m_privcmd, addrfile, privfile) < 0)
	{
		fprintf(stderr, "create qrencode image fail\n");
		return -1;
	}
	Buzzer(500000,  500000);

}
