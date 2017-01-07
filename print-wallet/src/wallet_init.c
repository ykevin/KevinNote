
#include "wallet_init.h"

extern void Buzzer(int n1time, int n2time)
{
        usleep(n1time);
        digitalWrite(BUZZER, FALSE);
        usleep(n2time);
        digitalWrite(BUZZER, TRUE);
}

static void  State_Led(void)
{
        char buf[8];
        int state[2];
        int ret, i, count;
        buf[0] = 0x1B;
        buf[1] = 0x76;

        for(i=0; i<10; i++)
        {
                digitalWrite(LED_PIN, 0);
                usleep(200000);
                digitalWrite(LED_PIN, 1);
                usleep(200000);
        }

        count = 0;
        while(TRUE)
        {
                write(s_fd, buf, 2);
                digitalWrite(LED_PIN, 0);
                usleep(200000);
                digitalWrite(LED_PIN, 1);
                usleep(200000);
		ret =read(s_fd,state, 8);
		if(pflag)
		{
			if(!(state[0]&SBIT))
			{
				count++;
				if(count == 4)
				{
					pflag = 0;
					break;
				}
			}
		}
        }

        digitalWrite(LED_PIN, FALSE);

        for(i=0; i<3; i++)
	{
                Buzzer(300000, 300000);
        }
        flag = 0;
	
	pthread_exit(0);
}



/*produce bitcoin private and address*/
extern void Addr_Generation(Wallet *bdx)
{
        FILE *fp;
        char buf[100] = {0};
        char str[3][100];
	int i = 0;

	bdx->privkey = malloc(100 * sizeof(char));
	bdx->address = malloc(100 * sizeof(char));
	memset(bdx->privkey, 0, 100);
	memset(bdx->address, 0, 100);
	
	if(bdx->onltc)
	{
		if((fp = popen("/usr/bin/vanitygen -X 48 L", "r")) == NULL)
		{
			fprintf (stderr, "Unable to init vanitygen: %s\n", "error");
			exit(1);
		}
	}
	else
	{
		if((fp = popen("/usr/bin/vanitygen 1", "r")) == NULL)
		{
			fprintf (stderr, "Unable to init vanitygen: %s\n", "error");
			exit(1);
		}
	}

        while(fgets(buf, 100, fp) != NULL) {
                strcpy(str[i], buf);
                i++;
        }

        strncpy(bdx->address, str[1]+9, 34);
        strncpy(bdx->privkey, str[2]+9, 51);

#if DEBUG
	printf("address: %s\n", bdx->address);
	printf("privkey: %s\n", bdx->privkey);
#endif

        pclose(fp);

}

/*init serial*/
static int Init_Serial(void)
{
        int fd;
        if((fd = serialOpen("/dev/ttyAMA0", 9600)) < 0)
        {
                fprintf (stderr, "Unable to open serial device: %s\n", "error") ;
                return -1 ;
        }

        return fd;
}

extern void Init_Data(Wallet *bdx)
{

	bdx->pbip38 = malloc(100 * sizeof(char));
	bdx->passwd = malloc(128 * sizeof(char));
	bdx->inipasswd = malloc(128 * sizeof(char));
	bdx->corp = malloc(128 * sizeof(char));
	bdx->url = malloc(128 * sizeof(char));
	bdx->title = malloc(128 * sizeof(char));
	memset(bdx->pbip38, 0, 100);
	memset(bdx->passwd, 0, 128);
	memset(bdx->title, 0, 128);
	memset(bdx->corp, 0, 128);
	memset(bdx->url, 0, 128);

	bdx->upath = NULL;
	bdx->disk = 0;
	bdx->upass = 0;
	bdx->onltc = 0;
	bdx->printnum = 1;
}



extern void Free(Wallet *bdx)
{
	int i;
	for(i = 0; i < bdx->disk; i++ )
	{
		free(bdx->udisk[i]);
	}
	free(bdx->corp);
	free(bdx->title);
	free(bdx->url);
	free(bdx->pbip38);
	free(bdx->passwd);
	free(bdx->inipasswd);
	free(bdx);
}



/*generate print wallet interrupt*/
void Print_Interrupt (void)
{
	Wallet *bdx;
        pthread_t ptid;
        int pr_state;

	bdx = (Wallet *)malloc(sizeof(Wallet));
	bdx->fd = s_fd;

        if(digitalRead(BUTTON_PIN) == 0)
        {
                delay(100);
                if((digitalRead(BUTTON_PIN) == 0) && (flag ==0))
                {
			
                        pr_state = Detect_Print(bdx->fd);
                        if(pr_state)
                        {
                                Lack_Paper(bdx->fd);
                                return ;
                        }
                        else
                        {
								pthread_create(&ptid, NULL, (void *)State_Led, NULL);
                                flag = 1;
                                ++globalCounter;
								Config_Wallet(bdx);
								pflag = 1;
                        }
                }
        }
}

static int Init_System()
{
        int i;
        pthread_t ptid;

        s_fd = Init_Serial();

        if (wiringPiSetup () == -1)
        {
                fprintf (stdout, "Unable to start wiringPi: %s\n", "error") ;
                return -1 ;
        }

                //set interrupt detect sate
        if (wiringPiISR (BUTTON_PIN, INT_EDGE_FALLING, &Print_Interrupt) < 0)
        {
                fprintf (stderr, "Unable to setup ISR: %s\n", strerror (errno)) ;
                return -1 ;
        }

//	sleep(4);
        pinMode(LED_PIN, OUTPUT);
        pinMode(BUZZER, OUTPUT);
        digitalWrite(LED_PIN, FALSE);

        for(i=0; i<3; i++)
        {
                Buzzer(300000, 300000);
        }
}

int main(int argc, char *argv[])
{
    
        int myCounter = 0 ;
 

        Init_System();

        while(TRUE)    
        {   
                printf ("Waiting ... \n") ;
                fflush (stdout) ;
                while (myCounter == globalCounter)
                        delay (100) ;
                printf (" Done. counter: %5d\n", globalCounter) ;
                myCounter = globalCounter ;
        }   

        return 0;
}

