
#include "wallet_print.h"
#include "wallet_bip38.h"


extern int Detect_Print(int fd)
{
        char buf[8];
        int state[2];

        buf[0] = 0x1B;
        buf[1] = 0x76;

        write(fd, buf, 2);
        usleep(600000);
        read(fd,state, 2);
#if DEBUG
        printf("state : %d\n", state[0]&CBIT);
#endif

        return state[0]&CBIT;
}

extern void Lack_Paper(int fd)
{
        int i;
        while(Detect_Print(fd))
        {
                for(i=0; i<3; i++)
                {
                        digitalWrite(LED_PIN, 0);
                        sleep(1);
                        digitalWrite(LED_PIN, 1);
                        usleep(500000);
                }
                sleep(3);
        }
        digitalWrite(LED_PIN, 0);
}

static void Init_Printer(int fd)
{
        unsigned char print[5];

        //init printer
        print[0] = 0x1B;
        print[1] = 0x40;
        write(fd, print, 2);

        //set LineSpacing
        print[0] = 0x1B;
        print[1] = 0x31;
        print[2] = 0x00;
        write(fd, print, 3);

        //disable Print in reverse order
        print[0] = 0x1B;
        print[1] = 0x63;
        print[2] = 0x00;
        write(fd, print, 3);


}

static void Set_Line(int fd, int line)
{
        unsigned char print[5];
        print[0] = 0x1B;
        print[1] = 0x64;
        print[2] = line;
#if TEST
        write(fd, print, 3);
#endif
}

static void Set_Space(int fd)
{
        unsigned char print[10];
        int i;
        for(i = 0; i < 10; i++)
        {
                print[i] = 0x00;
        }
#if TEST
        write(fd, print, 10);
#endif
}

static void Set_Color(int fd)
{
        //depth print color
        unsigned char color[5];
        color[0] = 0x1B;
        color[1] = 0x72;
        color[2] = 0x2B;
        color[3] = 0xF4;
        color[4] = 0x00;
#if TEST
        write(fd, color, 5);
#endif

}

static void Set_Center(int fd)
{
        //set Center display
        unsigned char print[5];
        print[0] = 0x1B;
        print[1] = 0x61;
        print[2] = 0x01;
#if TEST
        write(fd, print, 3);
#endif
}

static void Print_Qrcode(int fd, const unsigned char *code)
{
        unsigned char qrcode[100], print[5];
        int i, len;

        len = strlen(code);

        Set_Center(fd);

        print[0] = 0x1D;
        print[1] = 0x57;
        print[2] = 0x06;
        write(fd, print, 3);

        memset(qrcode, 0x00, 100);
        qrcode[0] = 0x1D;
        qrcode[1] = 0x6B;
        qrcode[2] = 0x20;
        qrcode[3] = 0x06;
        qrcode[4] = 0x01;
	
        for(i=5; i < (len+5); i++ )
        {
  	        qrcode[i] = code[i-5];
        }
        qrcode[len+5] = 0x00;

#if TEST
        write(fd, qrcode, (len+6));
#endif
        Set_Line(fd, 1);
}


static void Print_Title(int fd, char *title)
{
        char buf[8];
        buf[0] = 0x1c;
        buf[1] = 0x26;
        write(fd, buf, 2);

        Set_Color(fd);
        Set_Color(fd);
        Set_Color(fd);
        Set_Center(fd);
#if TEST
        write(fd, title, strlen(title));
#endif
        Set_Line(fd, 1);
}

static void Print_Char(int fd, unsigned char *address, char *buffer)
{
	int i;
        int len;
        unsigned char addr[100];
        len = strlen(buffer);
        sprintf(addr, "%s%s", buffer, address);
//	printf("addr : %s\n", addr);
        len = strlen(addr);
#if TEST
        write(fd, addr, len);
#endif
        Set_Line(fd, 1);
}

static void Print_Line(int fd, char line)
{
        unsigned char print[50];
        int i;

        for(i=0; i<LINE_LEN; i++)
        {
                print[i] = line;
        }
        print[i+1] = 0x0D;

        Set_Center(fd);
#if TEST
        write(fd, print, LINE_LEN);
#endif

}


extern void GetPrint_Num(Wallet *bdx, dictionary *ini)
{
	int value; 
	
	value = iniparser_getint(ini, "system:printnum", -1);
#if DEBUG
	
	printf(" printnum vaule: %d--------------- \n",value);
#endif
	
	bdx->printnum = value;
}

static void Print_AddrRoutine(Wallet *bdx, Local *ext)
{
        Init_Printer(bdx->fd);
        Set_Line(bdx->fd, 1);

	if(bdx->onltc)
	{
        	Print_Title(bdx->fd, bdx->title);
        	Print_Title(bdx->fd, ext->lmtitle[ext->lang]);
	}
	else
	{
        	Print_Title(bdx->fd, bdx->title);
        	Print_Title(bdx->fd, ext->bmtitle[ext->lang]);
	}

	Print_Line(bdx->fd, '-');
	Print_Qrcode(bdx->fd, bdx->address);

	Init_Printer(bdx->fd);
	Print_Char(bdx->fd, bdx->address, ext->addr[ext->lang]);
	Set_Line(bdx->fd, 1);
	Print_Line(bdx->fd, '-');
	Set_Line(bdx->fd, 1);

}

static void Print_PrivRoutine(Wallet *bdx, Local *ext)
{
	Print_Qrcode(bdx->fd, bdx->privkey);

	Init_Printer(bdx->fd);
	Print_Char(bdx->fd, bdx->privkey, ext->priv[ext->lang]);
	Set_Line(bdx->fd, 1);

	Print_Line(bdx->fd, '-');
	Print_Title(bdx->fd, bdx->corp);
	Print_Title(bdx->fd, bdx->url);

	if(bdx->printnum > 1)
	{
		Set_Line(bdx->fd, 2);
		Print_Line(bdx->fd, '*');
		Set_Line(bdx->fd, 2);
	}
	else
		Set_Line(bdx->fd, 4);

}

static void Print_Bip38(Wallet *bdx, Local *ext)
{
	Init_Printer(bdx->fd);
	Print_Qrcode(bdx->fd, bdx->pbip38);

	Init_Printer(bdx->fd);
	Print_Char(bdx->fd, bdx->pbip38, ext->bip38priv[ext->lang]);


	Print_Line(bdx->fd, '-');
	Print_Title(bdx->fd, bdx->corp);
	Print_Title(bdx->fd, bdx->url);
}


static void SaveDisk_Ini(Wallet *bdx)
{
	int i;
	for(i = 0; i < bdx->disk; i++)
	{
		SaveDisk_IniFile(bdx, i);
	}
}

static void Savedisk_All(Wallet *bdx)
{
	int i;
	for(i = 0; i < bdx->disk; i++)
	{
		Savedisk_Addr(bdx, i);
	}
}


static void Print_Passwd(Wallet *bdx, Local *ext)
{
	Print_Line(bdx->fd, '-');
	Set_Line(bdx->fd, 4);	
	Init_Printer(bdx->fd);
	Print_Char(bdx->fd, bdx->passwd, ext->passwd[ext->lang]);

}

extern void Print_Error(Wallet *bdx, Local *ext)
{
        Init_Printer(bdx->fd);
        Set_Line(bdx->fd, 1);
	Print_Char(bdx->fd, ext->pwderr[ext->lang], "");
	Set_Line(bdx->fd, 4);	
}

extern void GetPrint_Title(Wallet *bdx, Local *ext, dictionary *ini)
{
	char *value, *corp, *url, *title;

	if(ini)
	{
		value = iniparser_getstring(ini, "system:company", NULL);
	//	printf("value : %d----%s\n", strlen(value), value);
		if((value == NULL) || (strlen(value) == 0))
			strcpy(bdx->corp, ext->corp[ext->lang]);
		else
		{
			corp = malloc(OUTLEN * sizeof(char));
			memset(corp, 0, OUTLEN);
			if(convert_u2g(GBK, GB2312, value, strlen(value), corp, OUTLEN))
			{
				if(convert_u2g(UTF, GB2312, value, strlen(value), corp, OUTLEN))
					strcpy(bdx->corp, ext->corp[ext->lang]);
				else
					strcpy(bdx->corp, corp);
			}
			else	
				strcpy(bdx->corp, corp);
			free(corp);
		}

		value = iniparser_getstring(ini, "system:url", NULL);
		if((value == NULL) || (strlen(value) == 0))
			strcpy(bdx->url, ext->url[ext->lang]);
		else
		{
			url = malloc(OUTLEN * sizeof(char));
			memset(url, 0, OUTLEN);
			if(convert_u2g(	GBK, GB2312, value, strlen(value), url, OUTLEN))
			{
				if(convert_u2g(UTF, GB2312, value, strlen(value), url, OUTLEN))
					strcpy(bdx->url, ext->url[ext->lang]);
				else
					strcpy(bdx->url, url);
			}
			else
				strcpy(bdx->url, url);
			free(url);
		}

		value = iniparser_getstring(ini, "system:title", NULL);
		if((value == NULL) || (strlen(value) == 0))
		{
			if(bdx->onltc)
				strcpy(bdx->title, ext->ltitle[ext->lang]);
			else
				strcpy(bdx->title, ext->btitle[ext->lang]);
		}
		else
		{
			title = malloc(OUTLEN * sizeof(char));
			memset(title, 0, OUTLEN);
			if(convert_u2g(	GBK, GB2312, value, strlen(value), title, OUTLEN))
			{
				if(convert_u2g(UTF, GB2312, value, strlen(value), title, OUTLEN))
				{
					if(bdx->onltc)
						strcpy(bdx->title, ext->ltitle[ext->lang]);
					else
						strcpy(bdx->title, ext->btitle[ext->lang]);
				}
				else
					strcpy(bdx->title, title);
			}
			else
				strcpy(bdx->title, title);
			free(title);
		}

	}
	else
	{
		strcpy(bdx->corp, ext->corp[ext->lang]);
		strcpy(bdx->url, ext->url[ext->lang]);
		if(bdx->onltc)
			strcpy(bdx->title, ext->ltitle[ext->lang]);
		else
			strcpy(bdx->title, ext->btitle[ext->lang]);
	}

}

extern int Config_Wallet(Wallet *bdx)
{
	Local *ext;
	dictionary *ini;
	int i, ret;	

	ext = &lbdx;
	ext->lang  = 0;	

	Init_Data(bdx);
	Detect_Disk(bdx);
	GetDisk_Configfile(bdx);
	GetSys_Config(bdx, ext, ini);

	
	for(i=0; i < bdx->printnum; i++)
	{
		bdx->printcount = i;
		Print_Wallet(bdx, ext, ini);
		if(bdx->printnum > 1)
		{
			sleep(15);
		}

		printf("-----------------------------------------------------------------------------------\n\n\n");
	}

	if(bdx->upath)
	{
		iniparser_freedict(ini);
		free(bdx->upath);
		FreeFile();
	}

	Free(bdx);
}


extern int GetSys_Config(Wallet *bdx, Local *ext, dictionary *ini)
{
	int vaule;

	if(bdx->upath)
	{
		ini = iniparser_load(bdx->upath);
		if(ini == NULL)
		{
			fprintf(stderr, "cannot parse file: %s\n", bdx->upath);
		}
		else
		{
		  	vaule  = Ini_Parser(ini, "system", "coins", "ltc");
			if(vaule)
				bdx->onltc = 1;

		  	vaule  = Ini_Parser(ini, "system", "local", "en");
			if(vaule)
				ext->lang = 1;

			if(!bdx->onltc)
			{
				vaule  = Ini_Parser(ini, "btcbip38", "enablebip38", "true");
				if(vaule)
				{
					if(GetDisk_Password(bdx, ini) < 0)
					{
						Print_Error(bdx, ext);
						return -1;
					}	
				}
					
			}
			GetPrint_Num(bdx, ini);
			if(bdx->printnum <= 0)
				bdx->printnum = 1;
			GetPrint_Title(bdx, ext, ini);
		}
		iniparser_freedict(ini);
	}
	else
		GetPrint_Title(bdx, ext, NULL);
		

}

/*print wallet for wallet*/
extern int Print_Wallet(Wallet *bdx, Local *ext, dictionary *ini)
{
	int randprint = 0;
	int value;

	Addr_Generation(bdx);
	
	Print_AddrRoutine(bdx, ext);

	if(bdx->upath)
	{
		ini = iniparser_load(bdx->upath);
		if(ini == NULL)
		{
			fprintf(stderr, "cannot parse file: %s\n", bdx->upath);
		}
		else
		{
			if(!bdx->onltc)
			{

				value = Ini_Parser(ini, "btcbip38", "enablebip38", "true");
				if(value)
				{
					bdx->upass = 1;
					if(strcmp(bdx->inipasswd, " ") == 0)
					{
						Rand_Password(bdx);
						randprint = 1;
					}
					Bip38_Encrypt(bdx);
					Print_Bip38(bdx, ext);

					value = Ini_Parser(ini, "btcbip38", "printpasswd", "false");
					if(value)
					{
						if(randprint)
							Print_Passwd(bdx, ext);	

					}
					else
						Print_Passwd(bdx, ext);	

					if(bdx->printnum > 1)
					{
						Set_Line(bdx->fd, 2);
						Print_Line(bdx->fd, '*');
						Set_Line(bdx->fd, 2);
					}
					else
						Set_Line(bdx->fd, 4);
					if(bdx->printnum > 1)
					{				
						Print_Line(bdx->fd, '*');
					}
				}
				else
					Print_PrivRoutine(bdx, ext);

			}
			else
			{
				Print_PrivRoutine(bdx, ext);
			}

			value = Ini_Parser(ini, "system", "savedisk", "false");
			if(!value)
				Savedisk_All(bdx);


			if(bdx->printnum > 1)
				SaveDisk_Ini(bdx);

		}
	}
	else if(bdx->disk)
	{
		Print_PrivRoutine(bdx, ext);
		Savedisk_All(bdx);

	}
	else
		Print_PrivRoutine(bdx, ext);

	free(bdx->privkey);
	free(bdx->address);


	return 0;
}
