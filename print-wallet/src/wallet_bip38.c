
#include <Python.h>
#include "wallet_bip38.h"

extern int GetDisk_Password(Wallet *bdx,  dictionary *ini)
{
	char *vaule;

	vaule = iniparser_getstring(ini, "btcbip38:password", NULL);
#if DEBUG
	printf("vaule pass : %s--------------- \n", vaule);
#endif
	if((vaule ==  NULL) || (strlen(vaule) ==0 ))
	{
		memset(bdx->passwd, 0, 128);
		strcpy(bdx->passwd, " ");
		memset(bdx->inipasswd, 0, 128);
		strcpy(bdx->inipasswd, " ");
	}
	else if(strlen(vaule) > 128)
		return -1;
	else
	{
		strcpy(bdx->passwd, vaule);
		strcpy(bdx->inipasswd, vaule);
	}

	return 0;
//	printf("bdx->passwd:%s---\n", bdx->passwd);

	
}

extern void GetDisk_Configfile(Wallet *bdx)
{
	int i;
	char config[100];
	for(i = 0; i <  bdx->disk; i++ )
	{
		memset(config, 0, sizeof(config));
		strcpy(config, bdx->udisk[i]);
		strcat(config, "wallet.ini");
		if(access(config, R_OK) != -1)
		{
			bdx->upath = malloc(1024 * sizeof(char));
			memset(bdx->upath, 0, 1024);
			strcpy(bdx->upath, config);
#if DEBUG
			printf("bdx->upath : %s\n", bdx->upath);
#endif
			break;
		}
	}
}

extern void Rand_Password(Wallet *bdx)
{
	int i, x;
	char pass[PLEN];
	char P[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	srand(time(NULL) + rand());
	for(i = 0; i < PLEN-1; i++)
	{
		x = rand() % (sizeof(P) -1);
		pass[i] = P[x];
	}
	pass[i] = 0;
	memset(bdx->passwd, 0, 100);
	strcpy(bdx->passwd, pass);
}

extern void FreeFile()
{
	FILE *fp = NULL;
	fp = fopen(PRIV_PATH, "w+");
	if(fp == NULL)
	{
		fprintf(stderr, "free priv.ini fail\n");
	}
	fclose(fp);
	
	fp = fopen(PASSWD_PATH, "w+");
	if(fp == NULL)
	{
		fprintf(stderr, "free pass.ini fail\n");
	}
	fclose(fp);
}

static int Bip38_Writefile(Wallet *bdx)
{
	FILE *fp = NULL;
	fp = fopen(PRIV_PATH, "w");
	if(fp == NULL)
	{
		printf("open and creat priv.ini fail\n");
		return -1;
	}
	fwrite(bdx->privkey, strlen(bdx->privkey), 1, fp);
	fclose(fp);


	fp = fopen(PASSWD_PATH, "w");
	if(fp == NULL)
	{
		printf("open and creat pass.ini fail\n");
		return -1;
	}
	fwrite(bdx->passwd, strlen(bdx->passwd), 1, fp);
	fclose(fp);
	
	return 0;
}

extern int Bip38_Encrypt(Wallet *bdx)
{
	char *bip38=NULL;
	PyObject *pName, *pModule, *pDict, *pFunc;

	Bip38_Writefile(bdx);

	Py_Initialize();

	if ( !Py_IsInitialized() ) 
	{   
		return -1; 
	}   
	PyRun_SimpleString("import sys"); 
	PyRun_SimpleString("sys.path.append('/usr/local/lib/encryptwallet')"); 

	pName = PyString_FromString("bip38_encode"); 
	pModule = PyImport_Import(pName); 
	if ( !pModule ) 
	{   
		printf("can't find bip38_encode.py\n"); 
		return -1; 
	}   

	pDict = PyModule_GetDict(pModule);
	if ( !pDict )
	{
		return -1;
	}

	pFunc = PyDict_GetItemString(pDict, "get_privkey");
	if ( !pFunc || !PyCallable_Check(pFunc) )
	{
		printf("can't find function get_privkey\n");
		return -1;
	}

	PyObject *result = PyEval_CallObject(pFunc, NULL);

	PyArg_Parse(result, "s", &bip38);

	strcpy(bdx->pbip38, bip38);

	Py_Finalize();

	return 0;
}

