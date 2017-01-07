#ifndef	__WALLET_PRINT_H__
#define __WALLET_PRINT_H__

#include "config.h"

#define LINE_LEN	32

#define UTF     "utf-8"
#define GBK     "gbk"
#define GB2312  "gb2312"
#define OUTLEN  128

typedef struct {
        int lang;
        char *btitle[2];
        char *bmtitle[2];
        char *ltitle[2];
        char *lmtitle[2];
        char *addr[2];
        char *priv[2];
        char *bip38priv[2];
        char *corp[2];
        char *url[2];
        char *passwd[2];
        char *pwderr[2];
}Local;

Local lbdx = { 
        0,  
        {"自由从这里开始", "Bitcoin is freedom"},
        {"比特币纸钱包", "Bitcoin Wallet"},
        {"自由从这里开始", "Litecoin is freedom"},
        {"莱特币纸钱包", "Litecoin Wallet"},
        {"地址: ", "Address: "},
        {"私钥: ", "Privkey: "},
        {"*私钥: ", "*Privkey: "},
        {"佛山币定行科技有限公司", "Foshan Bidingxing Tech.Co.,Ltd."},
        {"http://www.bidingxing.com", "http://www.bidingxing.com"},
        {"密码: ", "Password: "},
        {"错误: 密码不能超过128个字符，请重置", "Error: The password can't more than 128 byte, Please reset."},
};

static void Init_Printer(int fd);
static void Set_Space(int fd);
static void Set_Color(int fd);
static void Set_Center(int fd);
static void Set_Line(int fd, int line);
static void Print_Char(int fd, unsigned char *address, char *buffer);
static void Print_Qrcode(int fd, const unsigned char *code);
static void Print_Line(int fd, char line);
static void Print_Title(int fd, char *title);
static void Print_AddrRoutine(Wallet *bdx, Local *ext);
static void Print_PrivRoutine(Wallet *bdx, Local *ext);
static void Print_Bip38(Wallet *bdx, Local *ext);
static void Print_Passwd(Wallet *bdx, Local *ext);
static void Savedisk_All(Wallet *bdx);
static void SaveDisk_Ini(Wallet *bdx);
extern void GetPrint_Num(Wallet *bdx, dictionary *ini);
extern void Print_Error(Wallet *bdx, Local *ext);
extern int Config_Wallet(Wallet *bdx);
extern void Lack_Paper(int fd);
extern int Detect_Print(int fd);
extern int GetSys_Config(Wallet *bdx, Local *ext, dictionary *ini);
extern int Print_Wallet(Wallet *bdx, Local *ext, dictionary *ini);

#endif /*__WALLET_PRINT_H__*/
