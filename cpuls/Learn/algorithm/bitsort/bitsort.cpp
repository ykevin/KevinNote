
/*****位图排序法**********/

#include <memory>
#include <iostream>
#include <string.h>

using namespace std;

#define BYTESIZE 8

void SetBit(unsigned char *data,int pos)
{
	for (int i=0;i<pos/BYTESIZE;i++)
	{
		data++;
	}

	*data=(*data)|(0x01<<(pos%BYTESIZE));
}

void BitmapSort(int data[],int n)
{
	int i;
	if (NULL==data || n<=0)
	{
		return;
	}

	int max=data[0];
	for (i=1;i<n;i++)
	{
		if (data[i]>max)
		{
			max=data[i];
		}
	}

	int iByteNum=max/BYTESIZE+1;

	unsigned char *p=new unsigned char[iByteNum];
	unsigned char *q=p;
	memset(p,0,iByteNum);
	int *temp=new int[n];
	int num=0;

	for(i=0;i<n;i++)
	{
		SetBit(p,data[i]);
	}
	for (i=0;i<iByteNum;i++)
	{
		for (int j=0;j<BYTESIZE;j++)
		{
			if (((*p)&(0x1<<j))==(0x1<<j))
			{
				temp[num]=i*BYTESIZE+j;
				num++;
			}
		}
		p++;
	}
	memcpy(data,temp,sizeof(int)*n);
	delete []q;
	delete []temp;
}

int main()
{
	int data[]={8,7,1,2,4,5,12,11,10};
	BitmapSort(data,9);
	for (int i=0;i<9;i++)
	{
		cout<<data[i]<<" ";
	}

	cout << endl;

	return 0;
}
